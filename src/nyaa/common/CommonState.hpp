#pragma once

#include "RenderState.hpp"
#include "nyaa/engine/NyaaEngine.hpp"

namespace nyaa::common {

struct CommonState {
    RenderState render;
    std::shared_ptr<engine::NyaaEngine> engine;
};

}
