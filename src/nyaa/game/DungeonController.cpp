#include "DungeonController.hpp"
#include "allegro5/allegro_primitives.h"
#include "nyaa/map/dungeon/FloorGenerator.hpp"

namespace nyaa::game {

DungeonController::DungeonController() {
    FloorGenerator gen(
        1, 100, 100
    );

    state = gen.generateFloor();
}

void DungeonController::tick(double) {

}

void DungeonController::render(double) {
    // TODO: this is shit and you should feel bad
    for (int y = 0; y < state.size(); ++y) {
        for (int x = 0; x < state.at(0).size(); ++x) {
            auto tileType = state.at(y).at(x);

            if (tileType == GeneratedTileType::FLOOR) {
                al_draw_filled_rectangle(
                    x, y, x + 1, y + 1, al_map_rgb(30, 30, 30)
                );
            }
        }
    }
}

}
