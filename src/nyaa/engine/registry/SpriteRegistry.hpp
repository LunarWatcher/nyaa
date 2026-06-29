#pragma once

#include "nyaa/engine/sprites/Spritesheet.hpp"

#include <allegro5/bitmap_io.h>

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


}
