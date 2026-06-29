#pragma once

#include "nyaa/engine/NyaaEngine.hpp"

namespace nyaa::common {

struct CommonState {
    std::shared_ptr<engine::NyaaEngine> engine;
};

}
