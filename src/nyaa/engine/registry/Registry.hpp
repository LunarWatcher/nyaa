#pragma once

#include "nyaa/engine/Logger.hpp"
#include "nyaa/engine/native/AllegroDeleters.hpp"
#include "nyaa/engine/sprites/Spritesheet.hpp"

#include <allegro5/bitmap_io.h>

#include <stc/Environment.hpp>
#include <filesystem>
#include <string>
#include <unordered_map>

namespace nyaa::engine {

class SpriteRegistry {
private:
    std::vector<std::shared_ptr<Spritesheet>> loadedSpritesheets;
    std::unordered_map<std::string, std::shared_ptr<Sprite>> sprites;

public:
    void addSpritesheet(
        std::shared_ptr<Spritesheet>&& spritesheet
    ) {
        loadedSpritesheets.push_back(
            std::move(spritesheet)
        );
    }

    std::shared_ptr<Sprite>& getSprite(const std::string& name) {
        return sprites.at(name);
    }

    void createSprite(
        const std::string& spriteName,
        std::vector<Slice>&& slices
    ) {
        sprites.emplace(
            spriteName,
            std::make_shared<Sprite>(
                std::move(slices)
            )
        );
    }
};

/**
 * \brief Shared state for the game that contains assets
 *
 * Also used to store many other builtin utilities.
 */
class Registry {
private:
    std::filesystem::path binaryDir = std::filesystem::path {
        stc::executablePath()
    }.parent_path();
    // TODO: the assetDir currently assumes a specific cwd, but this isn't good enough for actual deployments. It should
    // be defined wrt. the binary dir, but I'm not sure how this works with windows builds with the VS generator, since
    // that generates a dumbass structure that's almost certainly incompatible with my asset copying.
    std::filesystem::path assetDir = "./assets/";
public:
    SpriteRegistry spriteRegistry;

    BitmapPtr loadBitmap(
        const std::string& assetRelativePath
    ) {
        auto path = getAssetPath(assetRelativePath);
        if (!std::filesystem::exists(path)) {
            logger->error("Failed to resolve {}", path);
            throw std::runtime_error("Asset loading failed");
        }
        logger->debug("Loading bitmap {}", path);

        auto ptr = al_load_bitmap(
            path.c_str()
        );
        if (ptr == nullptr) {
            logger->error("Failed to open {}", path);
            throw std::runtime_error("Asset loading failed");
        }
        return BitmapPtr(
            ptr,
            deleteBitmap
        );
    }

    std::string getAssetPath(const std::string& filename) {
        return (assetDir / filename).string();
    }
};

}
