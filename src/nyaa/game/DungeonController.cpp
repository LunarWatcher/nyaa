#include "DungeonController.hpp"

#include <utility>
#include "allegro5/allegro_primitives.h"
#include "nyaa/map/dungeon/FloorGenerator.hpp"

namespace nyaa::game {

DungeonController::DungeonController(
    std::shared_ptr<common::CommonState> commonState
) : commonState(std::move(commonState)) {
    FloorGenerator gen(
        1, 200, 200
    );

    state = gen.generateFloor();
}

void DungeonController::tick(double) {

}

void DungeonController::render(double) {
    commonState->render.worldCam.apply();

    // TODO: this is shit and you should feel bad
    for (size_t y = 0; y < state.size(); ++y) {
        for (size_t x = 0; x < state.at(0).size(); ++x) {
            auto tileType = state.at(y).at(x);

            if (tileType == GeneratedTileType::FLOOR) {
                al_draw_filled_rectangle(
                    (float) x, (float) y,
                    (float) x + 1, (float) y + 1,
                    al_map_rgb(
                        60 + x * y,
                        90 + x * y,
                        120 + x * y
                    )
                );
            }
        }
    }
}

}
