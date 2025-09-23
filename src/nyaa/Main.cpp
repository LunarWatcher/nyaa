#include "nyaa/engine/Preload.hpp"
#include "nyaa/engine/Window.hpp"
int main() {
    nyaa::engine::loadEngine();

    nyaa::engine::Window window({
        .displayTitle = "Test window"
    });
    window.run();
    return 0;
}
