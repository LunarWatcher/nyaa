#include "GameManager.hpp"
#include "nyaa/engine/Window.hpp"
#include "nyaa/game/DungeonController.hpp"

namespace nyaa {

GameManager::GameManager() {
    window = std::make_shared<engine::Window>(engine::WindowOpts {
        .displayTitle = "Nyaa"
    });
    window->setController(std::make_shared<game::DungeonController>());
}

void GameManager::run() {
    window->run();
}

}
