#pragma once

#include "nyaa/engine/Controller.hpp"
#include "nyaa/map/dungeon/FloorGenerator.hpp"
namespace nyaa::game {

class DungeonController : public nyaa::engine::Controller {
private:
    FloorMap state;

public:
    DungeonController();

    void tick(double delta) override;
    void render(double delta) override;
};

}
