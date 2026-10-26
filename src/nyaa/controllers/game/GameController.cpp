#include "GameController.hpp"
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

GameController::GameController(
    const common::CommonStatePtr& state
) : commonState(state),
    gui(
        alui::GUIConfig {
            .font = commonState->engine->getRegistry().fontRegistry.getFont(
                Constants::DefaultFont
            ),
            .width = alui::Magnitude::Relative(1.f),
            .height = alui::Magnitude::Relative(1.f),
        }
    )
{
    loadGUI();
}

void GameController::loadGUI() {
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
        std::make_shared<alui::Text>(
            "I'm so good at games",
            alui::ComponentConfig {
                .flex = 1,
                .minWidth = alui::Magnitude::Relative(1)
            }
        )
    );

    gui.pushBack(layout);
}

GameController::~GameController() = default;

void GameController::render(double) {
    gui.render();
}


void GameController::tick(double) {
    gui.tick();
}

void GameController::onResize(float, float) {
    // gui.resize(width, height);
}

}
