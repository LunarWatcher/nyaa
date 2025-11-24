#pragma once

#include "nyaa/common/CommonState.hpp"
#include "nyaa/engine/Controller.hpp"
#include "nyaa/map/dungeon/FloorGenerator.hpp"
#include <memory>
namespace nyaa::game {

class DungeonController : public nyaa::engine::Controller {
private:
    FloorMap state;
    std::shared_ptr<common::CommonState> commonState;

public:
    DungeonController(
        std::shared_ptr<common::CommonState> commonState
    );

    void tick(double delta) override;
    void render(double delta) override;
};

}
