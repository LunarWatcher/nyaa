#pragma once

#include "nyaa/common/CommonState.hpp"
#include "nyaa/engine/Controller.hpp"
#include <allegro5/allegro.h>
#include <allegro5/bitmap.h>
#include <thread>

#include "alui/GUI.hpp"
#include "alui/images/Image.hpp"

namespace nyaa {

class SplashLoaderController : public engine::Controller {
private:
    std::shared_ptr<common::CommonState> commonState;
    alui::GUI gui;

    engine::BitmapPtr splash;
    std::shared_ptr<alui::ImageSlice> splashImageSlice;

    // TODO: use in a progress bar. alui does not have one yet
    float progress = 0;

    std::thread loaderThread;

    void loadGame();

    void loadAssets();
    void loadGUI();
public:
    SplashLoaderController(
        std::shared_ptr<common::CommonState> state
    );
    ~SplashLoaderController();

    void render(double) override;
    void tick(double delta) override;
    void onResize(float width, float height) override;
};

}
