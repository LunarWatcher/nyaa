#pragma once

namespace nyaa::engine {

class Controller {
public:
    virtual ~Controller() = default;

    virtual void render(double delta) = 0;
    virtual void tick(double delta) = 0;
};

}
