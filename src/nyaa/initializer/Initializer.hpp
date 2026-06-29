#pragma once

#include "nyaa/engine/registry/Registry.hpp"

namespace nyaa::Initializer {

extern void loadSpritesheet(
    const std::string& path,
    engine::Registry& reg
);

extern void initializeAssets(
    engine::Registry& reg,
    float& progress
);

}
