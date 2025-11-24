#pragma once

#include "nyaa/common/CommonState.hpp"
#include "nyaa/engine/Window.hpp"
#include <memory>
namespace nyaa {

class GameManager {
private:
    std::shared_ptr<engine::Window> window;
    std::shared_ptr<common::CommonState> commonState;
public:
    GameManager();

    void run();
};

}
