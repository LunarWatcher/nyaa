#pragma once

#include "nyaa/common/CommonState.hpp"
#include "nyaa/engine/AppController.hpp"
#include "nyaa/engine/NyaaEngine.hpp"
#include "nyaa/engine/Window.hpp"
#include <memory>
namespace nyaa {

class GameManager : public engine::AppController {
private:
    std::shared_ptr<engine::Window> window;
    std::shared_ptr<engine::NyaaEngine> engine;
    std::shared_ptr<common::CommonState> commonState;
public:
    GameManager();

    void run();

    void onResize(engine::Window *window, float width, float height) override;
};

}
