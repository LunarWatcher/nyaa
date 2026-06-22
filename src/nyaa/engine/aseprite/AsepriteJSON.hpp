/** \file
 *
 * \brief This file contains JSON definitions for Aseprite's JSON export format. 
 *
 * The format itself is a best guess, as aseprite does not offer an official schema or similar these structs could've
 * been derived from. It will likely fail as the spritesheets make use of more and more aseprite features.
 */
#pragma once

#include <string>
#include <cstdint>
#include <vector>
#include <optional>
#include <nlohmann/json.hpp>

namespace nyaa::engine::aseprite {

struct Dimensions { uint64_t w, h; };
struct Position { uint64_t x, y; };

struct Bounds {
    uint64_t x, y, w, h;
};

struct Frame {
    std::string filename;
    Bounds frame;
    bool rotated;
    bool trimmed;
    Bounds spriteSourceSize;
    Dimensions sourceSize;
    // TODO: uint?
    uint64_t duration;
};

struct SliceKeys {
    uint64_t frame;
    Bounds bounds;
};

/**
 * Source data for nyaa-compatible aseprite userdata. Valid nyaa userdata is in the form
 * ```
 * nyaa
 * frames[uint32]
 * ```
 * Example:
 * ```
 * nyaa
 * 4
 * ```
 *
 * For descriptions of what the fields mean, see the docs for the corresponding fields.
 */
struct NyaaAsepriteUserData {
    /**
     * \brief The number of frames the slice exists in.
     * \note The slice MUST start at the first frame. Frame offsets are not supported at this time because it's easily
     * solvable by just making everything relative to frame 0
     * 
     * frames = 0 means available in all frames. 
     */
    uint32_t frames = 0;
};

struct Slice {
    std::string name;
    std::string colour;
    std::vector<SliceKeys> keys;
    std::optional<NyaaAsepriteUserData> userData;
};

struct AsepriteMeta {
    std::vector<Slice> slices;
};
struct AsepriteJSON {
    std::vector<Frame> frames;
    AsepriteMeta meta;
};

void from_json(const nlohmann::json& j, Dimensions& d);
void from_json(const nlohmann::json& j, Position& d);
void from_json(const nlohmann::json& j, Bounds& d);
void from_json(const nlohmann::json& j, Frame& d);
void from_json(const nlohmann::json& j, SliceKeys& d);
void from_json(const nlohmann::json& j, Slice& d);
void from_json(const nlohmann::json& j, AsepriteMeta& d);
void from_json(const nlohmann::json& j, AsepriteJSON& d);

}
