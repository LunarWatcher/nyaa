#pragma once

#include "nyaa/engine/al/Camera.hpp"

namespace nyaa::engine {

class OrthoCamera : public Camera {
private:
    float top, right;
    int x = 0, y = 0;

    void recompute() override;
public:
    OrthoCamera(
        float top,
        float right
    );

    virtual void translate(
        float x, float y
    ) override;
    virtual void translate(
        float x, float y, float z
    ) override;
};

}
