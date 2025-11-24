#include "OrthoCamera.hpp"

namespace nyaa::engine {

OrthoCamera::OrthoCamera(
    float top,
    float right
): top(top), right(right) {

}

void OrthoCamera::recompute() {
    // TODO: why does x,y and look_x,look_y need to be synced?
    // This also means the camera isn't actually centered, as look-at(0, 0) is in the 
    // bottom left
    // TODO: why is -right and -top needed here for x to be centered?
    al_build_camera_transform(
        &camera,
        -right / 2.0 + x, -top / 2.0 + y, 0.5, 
        -right / 2.0 + x, -top / 2.0 + y, 0,
        0, 1, 0
    );

    al_identity_transform(&projection);
    al_orthographic_transform(
        &projection,
        0, top, -1,
        right, 0, 1
    );
}


void OrthoCamera::translate(
    float x, float y
) {
    this->x = x;
    this->y = y;
    dirty = true;
}

void OrthoCamera::translate(
    float x, float y, float
) {
    translate(x, y);
}

}
