#pragma once

#include "nyaa/engine/registry/Registry.hpp"

namespace nyaa::engine::aseprite::Loader {

void load(
    Registry& state,
    const std::string& spritesheetName
);

}
