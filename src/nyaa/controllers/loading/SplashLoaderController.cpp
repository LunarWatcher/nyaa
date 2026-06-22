#include "SplashLoaderController.hpp"

namespace nyaa {

SplashLoaderController::SplashLoaderController(
    std::shared_ptr<common::CommonState> state
) : commonState(std::move(state)),
    splash(commonState->engine->getRegistry().loadBitmap("splash.png"))
{}
}
