#pragma once

#include "nyaa/engine/Logger.hpp"
#include "nyaa/engine/native/AllegroDeleters.hpp"
#include "nyaa/engine/registry/FontRegistry.hpp"
#include "nyaa/engine/registry/SpriteRegistry.hpp"

#include <filesystem>

#include <stc/Environment.hpp>

namespace nyaa::engine {
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
    FontRegistry fontRegistry;

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
            &al_destroy_bitmap
        );
    }

    FontPtr loadFont(
        const std::string& assetRelativePath,
        int fontSize
    ) {
        auto path = getAssetPath(assetRelativePath);
        if (!std::filesystem::exists(path)) {
            logger->error("Failed to resolve {}", path);
            throw std::runtime_error("Asset loading failed");
        }
        logger->debug("Loading font {}", path);
        auto ptr = al_load_ttf_font(
            path.c_str(),
            fontSize,
            0
        );
        if (ptr == nullptr) {
            logger->error("Failed to open or parse {}", path);
            throw std::runtime_error("Asset loading failed");
        }

        return FontPtr(
            ptr,
            &al_destroy_font
        );
    }

    std::string getAssetPath(const std::string& filename) {
        return (assetDir / filename).string();
    }
};

}
