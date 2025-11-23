#include "nyaa/core/GameManager.hpp"
#include "nyaa/engine/Preload.hpp"

int main() {
    nyaa::engine::loadEngine();

    nyaa::GameManager manager;
    manager.run();
    return 0;
}
