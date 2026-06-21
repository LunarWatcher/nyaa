#pragma once

#include "minilog/logger/ConsoleLogger.hpp"
#include <minilog/minilog.hpp>

namespace nyaa::engine {

// This should be global and single-instance: https://stackoverflow.com/a/79889448
inline std::unique_ptr<minilog::Logger> logger(
    new minilog::ConsoleLogger("nyaa::engine")
);

}
