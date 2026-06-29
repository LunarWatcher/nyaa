#include "Initializer.hpp"
#include "nyaa/engine/aseprite/SpritesheetLoader.hpp"
#include "nyaa/engine/registry/Registry.hpp"

#include <functional>

namespace nyaa {

void Initializer::loadSpritesheet(
    const std::string& path,
    engine::Registry& reg
) {
    engine::aseprite::Loader::load(
        reg,
        path
    );
}

void Initializer::initializeAssets(engine::Registry& reg, float& progress) {
    using namespace std::placeholders;

#define Loader [](engine::Registry& reg) -> void

    std::vector<std::function<void(engine::Registry&)>> funcs = {
        Loader {
            loadSpritesheet("tilesets/tiles", reg);
        },
        Loader {
            loadSpritesheet("creatures/creatures", reg);
        }
    };

    for (auto& func : funcs) {
        func(reg);
        progress = std::min(
            100.f,
            progress + (100.f / funcs.size())
        );
    }

    progress = 100.f;
}

}
