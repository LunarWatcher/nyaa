#include "GameManager.hpp"
#include "nyaa/common/CommonState.hpp"
#include "nyaa/controllers/loading/SplashLoaderController.hpp"
#include "nyaa/engine/NyaaEngine.hpp"
#include "nyaa/engine/Window.hpp"
#include "nyaa/game/DungeonController.hpp"

namespace nyaa {

GameManager::GameManager() {
    window = std::make_shared<engine::Window>(engine::WindowOpts {
        .displayTitle = "Nyaa"
    });

    this->engine = std::make_shared<engine::NyaaEngine>();
    this->commonState = std::make_shared<common::CommonState>();
    this->commonState->engine = this->engine;
    
    // this->commonState->render.worldCam.translate(100, 100);
    window->setController(
        std::make_shared<SplashLoaderController>(
            commonState
        )
    );
}

void GameManager::run() {
    window->run();
}

}
