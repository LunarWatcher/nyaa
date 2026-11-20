#include "nyaa/engine/aseprite/AsepriteJSON.hpp"
#include <catch2/catch_test_macros.hpp>
#include <filesystem>
#include <fstream>

#include <fixtures/PathFixture.hpp>

namespace {

/**
 * Tiles are always assumed to be 32x32, but this does not hold for entities, which differ.  
 */
TEST_CASE_METHOD(tests::PathFixture, "Verify slice positions and sizes of tiles") {
    for (auto& de : std::filesystem::recursive_directory_iterator(
            assetRoot() / "tilesets"
        )
    ) {
        auto& path = de.path();
        if (path.extension() == ".json") {
            std::ifstream f(path);
            if (!f) {
                FAIL("Failed to open " << path.string());
                return;
            }
            nlohmann::json json;
            f >> json;
            nyaa::engine::aseprite::AsepriteJSON data = json;

            for (auto& slice : data.meta.slices) {
                for (size_t i = 0; i < slice.keys.size(); ++i) {
                    auto& key = slice.keys.at(i);
                    INFO("Validating positions for slice " << slice.name << " with key (frame?) idx=" << i << ", position"
                         << key.bounds.x << "," << key.bounds.y
                         << ". Failure here almost certainly means the slices have been moved a few pixels by accident");
                    // Explanation: All the sheets are on a grid of 32, or a multiple of 32. The two planned for use at
                    // the time of writing this test is 32 (possibly upgrading to 64) and either 128 or 256 for higher
                    // resolution components.
                    // Note that two parentheses are required because this technically isn't supported by catch2, but
                    // it's the easiest way to ensure the INFO() applies to all of them.
                    REQUIRE((
                        key.bounds.x % 32 == 0
                        && key.bounds.y % 32 == 0
                        && key.bounds.w % 32 == 0
                        && key.bounds.h % 32 == 0
                    ));

                }
            }
        }
    }

}

TEST_CASE_METHOD(tests::PathFixture, "Verify that `center` is loaded") {
    auto uiAssets = assetRoot() / "ui/ui.json";

    INFO(uiAssets.string());
    REQUIRE(std::filesystem::exists(uiAssets));

    std::ifstream f(uiAssets);
    nlohmann::json j;
    f >> j;

    nyaa::engine::aseprite::AsepriteJSON data = j;

    auto slices = data.meta.slices;

    std::vector<std::pair<std::string, nyaa::engine::aseprite::Bounds>> testCases {
        {"dialog::main", {  4, 4, 56, 56 }},
        {"button::primary", { 4, 4, 24, 8 }},
    };

    for (const auto& testCase : testCases) {
        const std::string& name = testCase.first;
        const nyaa::engine::aseprite::Bounds& centerBounds = testCase.second;
        auto slice = std::find_if(
            slices.begin(),
            slices.end(),
            [&](const auto& it) {
                return it.name == name;
            }
        );

        REQUIRE(slice != slices.end());
        const auto& data = *slice;

        REQUIRE(data.name == name); // Sanity check
        REQUIRE(data.keys.at(0).center.has_value());
        REQUIRE((data.keys.at(0).center.value()) == centerBounds);
    }
}

}
