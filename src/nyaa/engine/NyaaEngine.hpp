#pragma once

#include "nyaa/engine/registry/Registry.hpp"
namespace nyaa::engine {

class NyaaEngine {
private:
    Registry registry;

public:
    NyaaEngine() = default;

    Registry& getRegistry() {
        return registry;
    }
};

}
