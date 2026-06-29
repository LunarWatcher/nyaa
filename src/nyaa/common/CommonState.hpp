#pragma once

#include "nyaa/engine/NyaaEngine.hpp"

namespace nyaa {
class GameManager;
}

namespace nyaa::common {

struct CommonState {
    std::shared_ptr<engine::NyaaEngine> engine;
    GameManager* gameManager;
};

using CommonStatePtr = std::shared_ptr<CommonState>;

}
