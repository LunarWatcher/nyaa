#include "SplashLoaderController.hpp"
#include "alui/GUI.hpp"
#include "alui/component/FlexDirection.hpp"
#include "alui/components/ImageComponent.hpp"
#include "alui/components/Text.hpp"
#include "alui/layouts/FlexBox.hpp"
#include "nyaa/common/Constants.hpp"

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
}

void SplashLoaderController::loadAssets() {
    this->splashImage = std::make_shared<alui::ImageSlice>(
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
            this->splashImage,
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

void SplashLoaderController::render(double) {
    // commonState->render.uiCam.apply();
    gui.render();
}

void SplashLoaderController::tick(double delta) {
    gui.tick();
}

void SplashLoaderController::onResize(float width, float height) {
    gui.resize(width, height);
}

}
