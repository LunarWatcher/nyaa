#include "SplashLoaderController.hpp"
#include "alui/GUI.hpp"
#include "alui/component/FlexDirection.hpp"
#include "alui/components/ImageComponent.hpp"
#include "alui/components/Text.hpp"
#include "alui/layouts/FlexBox.hpp"
#include "nyaa/common/Constants.hpp"
#include "nyaa/initializer/Initializer.hpp"
#include "nyaa/core/GameManager.hpp"

#include "nyaa/controllers/menus/MainMenuController.hpp"

#include <chrono>
#include <thread>

namespace nyaa {

SplashLoaderController::SplashLoaderController(
    std::shared_ptr<common::CommonState> state
) : commonState(std::move(state)),
    gui(
        alui::GUIConfig {
            .font = commonState->engine->getRegistry().fontRegistry.getFont(
                Constants::DefaultFont
            ),
            .width = alui::Magnitude::Relative(1.f),
            .height = alui::Magnitude::Relative(1.f),
        }
    ),
    splash(commonState->engine->getRegistry().loadBitmap("splash.png"))
{
    loadAssets();
    loadGUI();

    this->loaderThread = std::thread(
        std::bind(
            &SplashLoaderController::loadGame,
            this
        )
    );
}

void SplashLoaderController::loadAssets() {
    this->splashImageSlice = std::make_shared<alui::ImageSlice>(
        splash.get(),
        0, 0,
        al_get_bitmap_width(splash.get()),
        al_get_bitmap_height(splash.get())
    );
}

void SplashLoaderController::loadGUI() {
    auto layout = std::make_shared<alui::FlexBox>(
        alui::FlexDirection::Horizontal,
        alui::ComponentConfig {
            .x = alui::Magnitude::Relative(0.3),
            .y = alui::Magnitude::Absolute(100),
            .minWidth = alui::Magnitude::Relative(0.4),
            .maxWidth = alui::Magnitude::Relative(0.4),
        }
    );

    layout->push(
        std::make_shared<alui::ImageComponent>(
            this->splashImageSlice,
            alui::ComponentConfig {
                .flex = 1,
                .minWidth = alui::Magnitude::Relative(1)
            }
        )
    );
    auto text = std::make_shared<alui::Text>(
        "(no, the image is centered, but the text in the image is not centered)",
        alui::ComponentConfig {
        }
    );
    text->setTextColour(al_map_rgba_f(1, 1, 1, 1));
    layout->push(text);

    gui.pushBack(layout);
}

SplashLoaderController::~SplashLoaderController() {
    if (this->loaderThread.joinable()) {
        this->loaderThread.join();
    }
}

void SplashLoaderController::render(double) {
    gui.render();
}

void SplashLoaderController::loadGame() {
    auto start = std::chrono::steady_clock::now();
    minilog::info("Asset loading started");
    Initializer::initializeAssets(this->commonState->engine->getRegistry(), progress);

    auto end = std::chrono::steady_clock::now();
    auto delta = std::chrono::duration_cast<std::chrono::milliseconds>(
        end - start
    ).count();
    minilog::info("Asset loading finished in {}ms", delta);
    if (delta < 2000) {
        minilog::info("Stalling");
        std::this_thread::sleep_for(
            std::chrono::milliseconds(2000 - delta)
        );
        minilog::info("Stalling done");
    }
    this->commonState->gameManager->transition<MainMenuController>();
}

void SplashLoaderController::tick(double) {
    gui.tick();
}

void SplashLoaderController::onResize(float width, float height) {
    gui.resize(width, height);
}

}
