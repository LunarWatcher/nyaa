#include "SpritesheetLoader.hpp"
#include "allegro5/bitmap_io.h"
#include "nyaa/engine/Logger.hpp"
#include "nyaa/engine/aseprite/AsepriteJSON.hpp"
#include "nyaa/engine/sprites/Spritesheet.hpp"

#include <allegro5/allegro.h>
#include <nlohmann/json.hpp>
#include <fstream>

namespace nyaa::engine::aseprite {

void Loader::load(
    Registry& registry,
    const std::string& spritesheetName
) {
    auto pngPath = registry.getAssetPath(spritesheetName + ".png");
    auto jsonPath = registry.getAssetPath(spritesheetName + ".json");
    logger->info(
        "Loading aseprite-compatible spritesheet (png: {}, json: {})",
        pngPath,
        jsonPath
    );
    ALLEGRO_BITMAP* bm = al_load_bitmap(
        pngPath.c_str()
    );

    if (bm == nullptr) {
        // TODO: how do you get allegro error messages again?
        logger->error(
            "Failed to load spritesheet!"
        );
        throw std::runtime_error("Spritesheet loading failed");
    }

    nlohmann::json rawJson;
    std::ifstream f(jsonPath);
    if (!f) {
        logger->error("Failed to load supporting JSON data!");
        throw std::runtime_error("Spritesheet loading failed");
    }

    f >> rawJson;

    AsepriteJSON json = rawJson;

    auto spritesheet = std::make_shared<Spritesheet>(
        bm
    );

    for (auto& slice : json.meta.slices) {
        logger->debug("Loading slice {}", slice.name);
        auto frameCount = slice.userData.and_then(
            [](const auto& val) -> std::optional<uint32_t> {
                return val.frames;
            }
        ).value_or(0);
        if (frameCount == 0) {
            frameCount = json.frames.size();
        }

        if (slice.keys.size() != 1) {
            // I've been unable to get more keys into a single slice, so it looks like future compatibility for
            // something that doesn't currently work. Slices seem to be pretty jank as it stands right now
            throw std::runtime_error(
                std::format(
                    "Slice {} has keys of length != 1 - no clue how to handle this!",
                    slice.name
                )
            );
        }

        std::vector<nyaa::engine::Slice> engineSlices;
        engineSlices.reserve(frameCount);

        auto key = slice.keys.at(0);
        for (size_t i = 0; i < frameCount; ++i) {
            engineSlices.push_back(
                nyaa::engine::Slice {
                    .x = key.bounds.x + json.frames.at(i).frame.x,
                    .y = key.bounds.y + json.frames.at(i).frame.y,
                    .w = key.bounds.w,
                    .h = key.bounds.y,
                    .duration = json.frames.at(i).duration
                }
            );
        }

        registry.spriteRegistry.createSprite(
            slice.name,
            std::move(engineSlices)
        );
    }
}

}
