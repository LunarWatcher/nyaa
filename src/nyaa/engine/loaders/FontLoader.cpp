#include "FontLoader.hpp"

namespace nyaa::engine::font {

void Loader::load(
    int referenceId,
    Registry &registry,
    const std::string &ttfName,
    int fontSize
) {
    auto font = registry.loadFont(ttfName, fontSize);
    registry.fontRegistry.registerFont(
        referenceId,
        std::move(font)
    );
}

}
