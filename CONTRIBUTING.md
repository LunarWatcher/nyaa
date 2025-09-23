# Contributing

## Basic guidelines

### Use of generative AI is banned

Generative AI uses training data [based on plagiarism and piracy](https://web.archive.org/web/20250000000000*/https://www.theatlantic.com/technology/archive/2025/03/libgen-meta-openai/682093/), has [significant environmental costs associated with it](https://doi.org/10.21428/e4baedd9.9070dfe7), and [generates fundamentally insecure code](https://doi.org/10.1007/s10664-024-10590-1). GenAI is not ethically built, ethical to use, nor safe to use for programming applications. When caught, you will be permanently banned from contributing to the project, and any prior contributions will be checked and potentially reverted. 

### Testing policies

### Git practices

This project does not follow any particular Git practices in branch names or commit messages. Try to make your commit messages useful, though. 

When creating a pull request, open it against the `master` branch. The `master` branch serves as the main development branch.

### Code style and naming conventions

* Naming conventions (C++):
    * Filenames, class names, struct names: PascalCase
    * Variable names, function names: camelCase
    * Namespaces: Lower-case only, except for inner namespaces that act similarly to what purely static classes would in other languages, which use PascalCase.
    * Constants: SCREAMING_SNAKE_CASE

For the rest of the code style, try to match the rest of the code. No formatters are used because none of them are flexible enough to describe the code style I prefer in C++. Do note that it's suggested to break lines around 120 characters at the latest, though going past that can be acceptable in certain circumstances. This does not apply to markdown or other similar formats.

### Read the documentation

There's more documentation outside this file that details lots of general policies. This especially applies if you're planning to contribute with code; `docs/dev/` contains a lot of various policies. At the very least, it's recommended that you read:

* `docs/dev/README.md`
* `docs/dev/Project structure.md`

There may be other doc files that contain relevant information. You're not expected to read the documentation in its entirety, but it is expected that you at least try to find relevant documentation for what you're working on.

## Development setup

### Requirements

The following requirements are identical to the end-user build, detailed in the README:

* Python 3 + pip, in order to install [conan](https://conan.io)
* Git
* CMake 3.28 or newer
    * If your distro doesn't support CMake 3.28+, CMake also exists on pypi (`pip3 install cmake`)
* C++23 compiler

In addition, the following requirements may apply to development use:

## Modifying assets

### `.aseprite`-sourced assets

The main game assets were originally created in Aseprite, and will continue to be expanded there for the foreseeable future. Spritesheets are therefore only modified in the `.aseprite` files, with updates exported from aseprite to the JSON/PNG format. The JSON and PNG files are what's used by the game, while the `.aseprite` files are what's used for the creation process.

<details>
<summary>Why require a specific editor?</summary>
I'm not a fan of requiring proprietary software in an open-source project, but it's a tool that saves significant amounts of custom tooling. As far as priorietary software goes, [it's quite affordable](https://store.steampowered.com/app/431730/Aseprite/) as well. I personally massively prefer Krita, but it is not set up for spritesheets. I have been down this road with Krita and spritesheets before, and it's not workable, at least not without plugins that either don't exist, or that are no longer maintained.

I think that, one way or another, an editor-specific format would be mixed in. Preserving layers makes editing quite a bit easier in a few places, especially when the layers can be used to provide additional context about the entries in the sheet. With any of the many good, and fully free editors (notably Krita), the major difference between them and Aseprite is that Aseprite functionally requires an investment to use. 

So it's not optimal, but the time saved on not having to do custom tooling, and not making mistakes when gridding out the spritesheet by hand, is significant.
</details>

### Other assets

At the time of writing, no other asset kinds exist or are planned. You should not be adding other asset formats without clearing it with me first. 
