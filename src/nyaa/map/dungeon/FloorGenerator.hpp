#pragma once

#include <vector>

namespace nyaa {

/**
 * Describes a generated tile type. These do not directly correspond to the kind of rendered tile, and purely describe
 * overall structure of a floor. 
 * Determining what to render is done through a separate engine.
 */
enum class GeneratedTileType {
    FLOOR,
    WALL,
    DOOR,
    // Currently unused, mainly written down because I have a vague idea of what fancy generated maps could look like.
    VOID,
    WATER
};

using FloorMap = std::vector<std::vector<GeneratedTileType>>;

/**
 * Root class in charge of generating floors (layer) of the dungeon. It's purely in charge of generating the raw
 * structure. Additional details are filled in Later:tm:.
 *
 * TODO:
 * * Figure out if it makes sense to set up some form of pipeline structure for the generation. Not sure if it makes
 *   sense, but delegating to different generators _might_ make sense
 * * Figure out if the generation method itself makes sense. I'm not currently convinced it does, it's just a very naive
 *   setup based on nothing in particular.
 *   There's almost certainly papers or other open-source games that could be used as a reference point.
 * * Tests: I'll probably want to create a root class for anything random, then `friend class SeedInjector` or something
 *   like that. Ignoring this for now, but that means this is untestable.
 *   Semi-related: I see catch2 generates seeds on a per-run basis, but I'm pretty sure that sets the seed for `rand()`,
 *   and won't affect `std::random`. The tests probably want to fix the seed on a per-case basis anyway.
 */
class FloorGenerator {
private:
    int floor;
    unsigned int maxWidth, maxHeight;

public:
    /**
     * \param floor     The index of the floor being generated
     * \param maxWidth  The max width of the floor in tiles in 2D space
     * \param maxHeight The max height of the floor in tiles in 2D space
     */
    FloorGenerator(
        int floor,
        unsigned int maxWidth,
        unsigned int maxHeight
    );

    FloorMap generateFloor();
};

}
