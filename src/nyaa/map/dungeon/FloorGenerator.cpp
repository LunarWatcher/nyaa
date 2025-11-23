#include "FloorGenerator.hpp"

namespace nyaa {


FloorGenerator::FloorGenerator(
    int floor,
    unsigned int maxWidth,
    unsigned int maxHeight
) : floor(floor), maxWidth(maxWidth), maxHeight(maxHeight) {
}

// TODO: probably want to wrap the vector in a utility class of some kind
FloorMap FloorGenerator::generateFloor() {
    FloorMap m;
    m.resize(this->maxHeight);

    // dumb implementation that only generates a floor
    for (auto& row : m) {
        row.resize(this->maxWidth);
        for (auto& i : row) {
            i = GeneratedTileType::FLOOR;
        }
    }

    return m;
}

}
