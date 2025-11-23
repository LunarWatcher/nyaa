#pragma once

namespace nyaa::engine {

class Controller {
public:
    virtual void render(double delta) = 0;
    virtual void tick(double delta) = 0;
};

}
