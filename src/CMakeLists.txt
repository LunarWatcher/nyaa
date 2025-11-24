add_library(nyaasrc STATIC 
    nyaa/common/RenderState.cpp

    nyaa/core/GameManager.cpp

    nyaa/game/DungeonController.cpp

    nyaa/map/dungeon/FloorGenerator.cpp
)
add_library(nyaaengine 
    nyaa/engine/Window.cpp

    # Submodule for allegro extensions
    nyaa/engine/al/Camera.cpp
    nyaa/engine/al/OrthoCamera.cpp
)
add_executable(nyaa nyaa/Main.cpp)

find_package(spdlog REQUIRED)
find_package(reflectcpp REQUIRED)

target_link_libraries(
    nyaaengine
PUBLIC
    allegro-meta
    alui
    spdlog::spdlog
    reflectcpp::reflectcpp
)
target_link_libraries(
    nyaasrc 
PUBLIC 
    nyaaengine
)

target_link_libraries(nyaa PUBLIC nyaasrc)

target_include_directories(nyaaengine PUBLIC ./)

# vim:ft=cmake
