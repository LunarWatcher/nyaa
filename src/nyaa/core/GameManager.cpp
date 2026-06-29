#include "GameManager.hpp"
#include "nyaa/common/CommonState.hpp"
#include "nyaa/common/Constants.hpp"
#include "nyaa/controllers/loading/SplashLoaderController.hpp"
#include "nyaa/engine/NyaaEngine.hpp"
#include "nyaa/engine/Window.hpp"
#include "nyaa/engine/loaders/FontLoader.hpp"
#include "nyaa/game/DungeonController.hpp"

namespace nyaa {

GameManager::GameManager() {
    window = std::make_shared<engine::Window>(engine::WindowOpts {
        .displayTitle = "Nyaa"
    });

    this->engine = std::make_shared<engine::NyaaEngine>();
    this->commonState = std::make_shared<common::CommonState>();
    this->commonState->engine = this->engine;
    this->commonState->gameManager = this;

    // Load the default font here. We need it before we initialize the splash controller, which does the remaining
    // initialization
    nyaa::engine::font::Loader::load(
        Constants::DefaultFont,
        this->engine->getRegistry(),
        "fonts/dejavu.ttf",
        12
    );
    
    // this->commonState->render.worldCam.translate(100, 100);
    window->setAppController(this);
    transition<SplashLoaderController>();
}

void GameManager::run() {
    window->run();
}

void GameManager::onResize(engine::Window*, float, float) {
    // TODO: This was originally made to allow global cameras to be resized, but in retrospect, it makes more sense to
    // not do that.
    // The GUI now runs on the null transform, which is equivalent to pixel coords. In theory, it could make sense to
    // have a scaling system, but it likely makes more sense to put that in alui to take advantage of resolution
    // benefits. I don't know.
    // This function needs to be rethought, is all I know right now.
}

}
