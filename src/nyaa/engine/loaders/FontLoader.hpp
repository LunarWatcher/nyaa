#pragma once

#include "nyaa/engine/registry/Registry.hpp"

namespace nyaa::engine::font::Loader {

void load(
    int referenceId,
    Registry& registry,
    const std::string& ttfName,
    int fontSize
);

}
