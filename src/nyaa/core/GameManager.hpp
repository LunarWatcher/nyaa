#pragma once

#include "nyaa/engine/Window.hpp"
#include <memory>
namespace nyaa {

class GameManager {
private:
    std::shared_ptr<engine::Window> window;
public:
    GameManager();

    void run();
};

}
