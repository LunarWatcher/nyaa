#pragma once

#include "nyaa/common/CommonState.hpp"
#include "nyaa/engine/Controller.hpp"
#include <allegro5/allegro.h>
#include <allegro5/bitmap.h>

namespace nyaa {

class SplashLoaderController : public engine::Controller {
private:
    std::shared_ptr<common::CommonState> commonState;

    engine::BitmapPtr splash;
public:
    SplashLoaderController(
        std::shared_ptr<common::CommonState> state
    );

    void render(double) override {
        commonState->render.uiCam.apply();
        al_draw_scaled_bitmap(
            this->splash.get(),
            0,
            0,
            al_get_bitmap_width(this->splash.get()),
            al_get_bitmap_height(this->splash.get()),
            -0.5,
            -0.5,
            1,
            1,
            0
        );
    }

    void tick(double delta) override {

    }

};

}
