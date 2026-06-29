add_library(nyaasrc STATIC
    nyaa/controllers/loading/SplashLoaderController.cpp
    nyaa/controllers/menus/MainMenuController.cpp

    nyaa/core/GameManager.cpp

    nyaa/game/DungeonController.cpp

    nyaa/initializer/Initializer.cpp

    nyaa/map/dungeon/FloorGenerator.cpp
)
add_library(nyaaengine
    nyaa/engine/Window.cpp

    # Submodule for allegro extensions
    nyaa/engine/al/Camera.cpp
    nyaa/engine/al/OrthoCamera.cpp

    # Submodule for aseprite loading
    nyaa/engine/aseprite/AsepriteJSON.cpp
    nyaa/engine/aseprite/SpritesheetLoader.cpp

    # Submodule for registry loading of builtin types
    nyaa/engine/loaders/FontLoader.cpp
)
add_executable(nyaa nyaa/Main.cpp)

find_package(nlohmann_json REQUIRED)

target_link_libraries(
    nyaaengine
PUBLIC
    allegro-meta
    alui
    nlohmann_json::nlohmann_json
    stc
    minilog
)
target_link_libraries(
    nyaasrc
PUBLIC
    nyaaengine
    CLI11::CLI11
)

target_link_libraries(nyaa PUBLIC nyaasrc)

target_include_directories(nyaaengine PUBLIC ./)

# vim:ft=cmake
