#pragma once

#include "allegro5/bitmap.h"
#include "allegro5/bitmap_draw.h"
#include "nyaa/engine/native/AllegroDeleters.hpp"
#include <cstdint>
#include <memory>
#include <vector>

namespace nyaa::engine {

/**
 * A slice represents a section of the bitmap that corresponds to one frame of the sprite. Not to be confused with
 * aseprite slices (nyaa::engine::aseprite::Slice), which corresponds to an object that compiles to many slices in
 * nyaa's setup.
 */
struct Slice {
    uint64_t x;
    uint64_t y;
    uint64_t w;
    uint64_t h;

    uint64_t duration;
};

enum class AnimationMode {
    Stop,
    Loop,
    ReverseLoop,
    Pingpong
};

/**
 * Currently just a wrapper that stores a RAII-safe ALLEGRO_BITMAP, may expand to be more complicated when spritesheet
 * packing is implemented
 */
class Spritesheet {
private:
    BitmapPtr bitmap;
public:
    Spritesheet(ALLEGRO_BITMAP* bitmap)
        : bitmap(bitmap, &al_destroy_bitmap) {}

    ALLEGRO_BITMAP* get() { return bitmap.get(); }
};

class Sprite {
private:
    std::vector<Slice> slices;
    std::shared_ptr<Spritesheet> sheet;

    const Slice& getNextSlice(
        AnimationMode mode = AnimationMode::Loop
    ) const {
        if (slices.size() == 1) {
            return slices.at(0);
        }
        int currentFrame = 0;
        // TODO: not sure how to make this work yet. Would need some form of global counter for sync I'd imagine, but
        // this kinda complicates things when this method can be called many times in a single frame. ALso can't do sync
        // against a global counter, since the frame counts may vary between animations, and theoretically with counts
        // that have an lcm > uint64
        // (but I imagine that would have to be unnaturally high frame counts?)
        auto& slice = slices.at(std::abs(currentFrame));

        // TODO: I haven't tested any of this, this is just eyeballed for later based on tags being a thing in
        // aseprite. In the actual game engine, I think it makes more sense to give the code control over the animation
        // direction rather than the source file, since this gives more flexibility for like reversing rendering or
        // doing weird graphical effects. Idk what those would be in practice, but the game hasn't been properly planned
        // yet, so we'll see :P
        switch (mode) {
        case AnimationMode::Stop:
            if (currentFrame < (int) slices.size() - 1) {
                currentFrame++;
            }
            break;
        case AnimationMode::Loop:
            if (currentFrame++ == (int) slices.size()) {
                currentFrame = 0;
            }
            break;
        case AnimationMode::ReverseLoop:
            if (currentFrame == 0) {
                currentFrame = slices.size() - 1;
            } else {
                --currentFrame;
            }
            break;
        case AnimationMode::Pingpong:
            if (currentFrame++ == (int) slices.size()) {
                currentFrame = -((int) slices.size());
            }
            break;
        }

        return slice;
    }

public:
    Sprite(
        std::vector<Slice>&& slices
    ) : slices(std::move(slices)) {}

    void render(
        float x,
        float y
    ) {
        // TODO: the utility render method currently makes getNextSlice's animation mode unsable
        const auto& slice = getNextSlice();
        // TODO: as-is, this does not allow for entities of size > 1x1. The actual output size could be derived by
        // slice.[wh] / 32 for nyaa, though it won't work well with engines where the base size isn't 32, or if I decide
        // to support multiple resolutions.
        al_draw_scaled_bitmap(
            this->sheet->get(),
            slice.x, slice.y,
            slice.w, slice.h,
            x, y,
            1, 1,
            0
        );
    }

};


}
