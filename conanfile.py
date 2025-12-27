from conan import ConanFile
import os
from conan.tools.files import copy
from pathlib import Path
import shutil

class NyaaTheUntitledGame(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"
    # TODO: will the ../ always result in copying into the build dir?
    # Is there a more reliable way to get the real cwd?
    OUTPUT_PATH = os.path.join(
        "../" + os.path.curdir,
        "LICENSES"
    )

    def requirements(self):
        self.requires("spdlog/1.15.3")
        self.requires("freetype/2.13.3")
        # TODO: Would prefer yyjson since this is a game, but I don't think
        # json is going to be written often enough for it to matter.
        # yyjson is too low level to be comfortable to deserialize, and
        # reflect-cpp is AI slop now
        # C++26 will include reflection, I think I can write my own library
        # wrapping yyjson then.
        self.requires("nlohmann_json/3.12.0")
        self.requires("libpng/1.6.53")

    def configure(self):
        self.options["spdlog"].use_std_fmt = True

    def generate(self):
        PREFERRED_LICENSES = [
            "Unlicense",
            "MIT",
            "Apache-2.0",
        ]
        # TODO: Fail build if only copyleft licenses are available
        if not os.path.isdir(self.OUTPUT_PATH):
            os.mkdir(self.OUTPUT_PATH)
        for r, dep in self.dependencies.items():
            self.output.info("Dependency {} uses license {}".format(
                dep.ref, dep.license
            ))

            license = dep.license
            if isinstance(dep.license, tuple):
                for preferred_license in PREFERRED_LICENSES:
                    for item in dep.license:
                        if preferred_license in item:
                            license = item
                            break
                    else:
                        # No match means the next license is searched
                        continue
                    # A match means the search is terminated
                    break
                else:
                    raise RuntimeError("Failed to resolve preferred license")

            self._resolve_license(
                dep, license, isinstance(dep.license, list)
            )


    def _resolve_license(self, dep, license, multi_resolve):

        source_dir = dep.package_folder

        files = []

        for p in Path(source_dir).rglob("*"):
            if not p.is_file():
                continue

            if p.name.lower().startswith((
                "license",
                "copying",
                "copyright"
            )):
                # TODO: implement multi-license resolution
                files.append(p.absolute())


        for f in files:
            shutil.copy(
                f,
                "{}/{}-{}".format(
                    self.OUTPUT_PATH,
                    dep.ref.name,
                    license
                )
            )
