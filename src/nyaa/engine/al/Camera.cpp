#include "Camera.hpp"
#include "allegro5/transformations.h"

namespace nyaa::engine {

void Camera::apply() {
    if (dirty) {
        recompute();
        dirty = false;
    }
    al_use_projection_transform(&projection);
    al_use_transform(&camera);
}

}
