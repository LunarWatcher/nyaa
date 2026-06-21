#include "minilog/logger/Logger.hpp"
#include "minilog/logger/ConsoleLogger.hpp"

namespace nyaa_detail {

inline minilog::ConsoleLogger& getLoggerInstance() {
    static minilog::ConsoleLogger logger("nyaa::engine");
    return logger;
}

}

template<class... Args>
inline constexpr void debug(
    const minilog::FormatStringWithSourceLocation& format,
    Args&&... args
) {
    nyaa_detail::getLoggerInstance().debug<Args...>(
        format,
        std::forward<Args>(args)...
    );
}

template<class... Args>
inline constexpr void info(
    const minilog::FormatStringWithSourceLocation& format,
    Args&&... args
) {
    nyaa_detail::getLoggerInstance().info<Args...>(
        format,
        std::forward<Args>(args)...
    );
}

template<class... Args>
inline constexpr void warn(
    const minilog::FormatStringWithSourceLocation& format,
    Args&&... args
) {
    nyaa_detail::getLoggerInstance().warn<Args...>(
        format,
        std::forward<Args>(args)...
    );
}

template<class... Args>
inline constexpr void error(
    const minilog::FormatStringWithSourceLocation& format,
    Args&&... args
) {
    nyaa_detail::getLoggerInstance().error<Args...>(
        format,
        std::forward<Args>(args)...
    );
}

template<class... Args>
inline constexpr void critical(
    const minilog::FormatStringWithSourceLocation& format,
    Args&&... args
) {
    nyaa_detail::getLoggerInstance().critical<Args...>(
        format,
        std::forward<Args>(args)...
    );
}

inline void setLevel(minilog::Level level) {
    nyaa_detail::getLoggerInstance().setLevel(level);
}
