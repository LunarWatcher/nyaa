#pragma once

#include "allegro5/allegro_ttf.h"
#include "nyaa/engine/native/AllegroDeleters.hpp"
#include <allegro5/allegro_font.h>
#include <unordered_map>

namespace nyaa::engine {

class FontRegistry {
private:
    std::unordered_map<int, FontPtr> loadedFonts;

public:
    void registerFont(
        int referenceId,
        FontPtr&& font
    ) {
        // TODO: validate return value
        loadedFonts.emplace(
            referenceId,
            std::move(font)
        );
    }

    ALLEGRO_FONT* getFont(int referenceId) {
        return loadedFonts.at(referenceId).get();
    }
};

}
