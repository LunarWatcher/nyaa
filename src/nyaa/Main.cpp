#include "nyaa/core/GameManager.hpp"
#include "nyaa/engine/NyaaEngine.hpp"
#include "nyaa/engine/Preload.hpp"

#include <CLI/CLI.hpp>
#include <iostream>
#include <allegro5/allegro.h>

int main(int argc, const char* argv[]) {

    CLI::App app {
        "Undefined dungeon crawler thing",
        "nyaa"
    };

    app.add_flag_function(
        "-d,--debug",
        [](const auto&) {
            minilog::setLevel(minilog::Level::Debug);
            nyaa::engine::logger->setLevel(minilog::Level::Debug);
        },
        "Whether or not to enable verbose debug logging"
    );

    CLI12_PARSE(app, argc, argv);


    nyaa::engine::loadEngine();
    nyaa::GameManager manager;
    manager.run();

    return 0;
}
