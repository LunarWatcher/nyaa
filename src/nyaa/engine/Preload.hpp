#pragma once

#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <spdlog/spdlog.h>

namespace nyaa::engine {

/**
 * Runs the one-time setup that's meant to be called once per binary. MUST be called prior to doing anything else.
 *
 * This is a consequence of [al_init](https://liballeg.org/a5docs/trunk/system.html#al_init), which states:
 * > It is typically wrong to call al_init anywhere except the final game binary
 *
 * And it is a fair point. If a headed mode is used in the tests, we don't want to call al_init et. al unnecessarily.
 */
inline void loadEngine() {
    spdlog::debug("loadEngine called");
    if (!al_init()) {
        spdlog::error("Failed to initialise allegro");
        auto err = al_get_errno();
        spdlog::error("Allegro error code {}", err);
        throw std::runtime_error("Allegro failure");
    }
    spdlog::debug("Loading allegro...");
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_primitives_addon();
    al_init_image_addon();
    // TODO: does color not need initialising?

    al_install_keyboard();
    al_install_mouse();
}

}
