#include "AsepriteJSON.hpp"

void nyaa::engine::aseprite::from_json(const nlohmann::json& j, Dimensions& d) {
    j.at("w").get_to(d.w);
    j.at("h").get_to(d.h);
}
void nyaa::engine::aseprite::from_json(const nlohmann::json& j, Position& d) {
    j.at("x").get_to(d.x);
    j.at("y").get_to(d.y);
}
void nyaa::engine::aseprite::from_json(const nlohmann::json& j, Bounds& d) {
    j.at("x").get_to(d.x);
    j.at("y").get_to(d.y);
    j.at("w").get_to(d.w);
    j.at("h").get_to(d.h);
}
void nyaa::engine::aseprite::from_json(const nlohmann::json& j, Frame& d) {
    j.at("filename").get_to(d.filename);
    j.at("frame").get_to(d.frame);
    j.at("rotated").get_to(d.rotated);
    j.at("trimmed").get_to(d.trimmed);
    j.at("spriteSourceSize").get_to(d.spriteSourceSize);
    j.at("sourceSize").get_to(d.sourceSize);
    j.at("duration").get_to(d.duration);
}
void nyaa::engine::aseprite::from_json(const nlohmann::json& j, SliceKeys& d) {
    j.at("frame").get_to(d.frame);
    j.at("bounds").get_to(d.bounds);
}
void nyaa::engine::aseprite::from_json(const nlohmann::json& j, Slice& d) {

    j.at("name").get_to(d.name);
    j.at("color").get_to(d.colour);
    j.at("keys").get_to(d.keys);
    auto it = j.find("data");
    if (it != j.end()) {
        std::string v = it->get<std::string>();
        if (v.starts_with("nyaa")) {
            std::stringstream ss;
            ss << v;

            NyaaAsepriteUserData userData;
            ss.seekg(4); // Skip past identifier
            ss >> userData.frames;

            d.userData = userData;
        }

    }
}
void nyaa::engine::aseprite::from_json(const nlohmann::json& j, AsepriteMeta& d) {
    j.at("slices").get_to(d.slices);
}
void nyaa::engine::aseprite::from_json(const nlohmann::json& j, AsepriteJSON& d) {
    j.at("frames").get_to(d.frames);
    j.at("meta").get_to(d.meta);
}
