#pragma once

#include "allegro5/transformations.h"

namespace nyaa::engine {

class Camera {
protected:
    ALLEGRO_TRANSFORM camera;
    ALLEGRO_TRANSFORM projection;

    // Dirty has to initially be true, as we don't compute the matrix until we try to apply it
    // So the default state is always dirty
    bool dirty = true;

    virtual void recompute() = 0;
public:
    virtual ~Camera() = default;
   
    virtual void translate(
        float x, float y
    ) = 0;
    virtual void translate(
        float x, float y, float z
    ) = 0;
    virtual void apply();
};

}
