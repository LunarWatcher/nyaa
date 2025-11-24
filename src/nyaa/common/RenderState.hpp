#pragma once

#include "nyaa/engine/al/OrthoCamera.hpp"

namespace nyaa::common {

struct RenderState {
    nyaa::engine::OrthoCamera worldCam;
    nyaa::engine::OrthoCamera uiCam;

    RenderState();

};

}
