#pragma once

#include "allegro5/events.h"

namespace nyaa::engine {

class Controller {
public:
    virtual ~Controller() = default;

    virtual void render(double delta) = 0;
    virtual void tick(double delta) = 0;
    virtual void onResize(
        float /* width */,
        float /* height */
    ) {}

    virtual void rawProcessEvent(
        const ALLEGRO_EVENT& /* ev */
    ) {}
};

}
