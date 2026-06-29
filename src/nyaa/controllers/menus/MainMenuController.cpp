#include "MainMenuController.hpp"
#include "allegro5/color.h"
#include "alui/component/Component.hpp"
#include "alui/component/FlexDirection.hpp"
#include "alui/component/Magnitude.hpp"
#include "alui/components/Button.hpp"
#include "alui/layouts/FlexBox.hpp"
#include "alui/style/Style.hpp"
#include "alui/style/StyleStates.hpp"
#include "alui/style/BackgroundColourStyle.hpp"
#include "alui/style/BorderStyle.hpp"
#include "nyaa/common/Constants.hpp"
#include <cmath>

namespace nyaa {

MainMenuController::MainMenuController(
    const common::CommonStatePtr& commonState
) : gui(alui::GUIConfig {
        .font = commonState->engine->getRegistry().fontRegistry.getFont(
            Constants::DefaultFont
        ),
        .width = alui::Magnitude::Relative(1.f),
        .height = alui::Magnitude::Relative(1.f),
    }) {
    initializeGUI();
}

void MainMenuController::initializeGUI() {
    auto menuRoot = std::make_shared<alui::FlexBox>(
        alui::FlexDirection::Vertical,
        alui::ComponentConfig {
            .x = alui::Magnitude::Relative(0.3),
            .y = alui::Magnitude::Relative(0.2),
            .minWidth = alui::Magnitude::Relative(0.4),
            .maxWidth = alui::Magnitude::Relative(0.4),
        }
    );
    std::shared_ptr<alui::StyleSpec> buttonStyle = std::make_shared<alui::StyleSpec>(
        alui::StyleStates {
            .defaultState = std::make_shared<alui::BackgroundColourStyle>(
                al_map_rgb(80, 80, 80)
            ),
            .focusedState = std::make_shared<alui::BackgroundColourStyle>(
                al_map_rgb(135, 113, 46)
            )
        },
        alui::StyleStates {
            .defaultState = std::make_shared<alui::BorderStyle>(
                al_map_rgb(83, 27, 70),
                2
            ),
        }
    );

    auto title = std::make_shared<alui::Text>(
        "Nyaa~",
        alui::ComponentConfig {
            .flex {0},
        }
    );
    title->setTextColour(al_map_rgba_f(1, 1, 1, 1));

    auto btn = std::make_shared<alui::Button>(
        "Click me to do nothing",
        alui::ComponentConfig {
            .flex {0},
            .id = PlayButton,
            .padding = 8,
            .style = buttonStyle,
        }
    );
    btn->setTextColour(al_map_rgba_f(1, 1, 1, 1));
    btn->addClickListener([](alui::Component*, float, float) {
        std::cout << "Okay, it's not *nothing* nothing, but it's approximately nothing" << std::endl;
        return true;
    });

    menuRoot->push(title);
    menuRoot->push(btn);

    gui.push(menuRoot);
}

void MainMenuController::render(double) {
    gui.render();
}
void MainMenuController::tick(double) {
    gui.tick();
}

void MainMenuController::onResize(float width, float height) {
    gui.resize(width, height);
}

void MainMenuController::rawProcessEvent(const ALLEGRO_EVENT& ev) {
    gui.handleEvent(ev);
}

}
