add_library(nyaasrc STATIC 
    nyaa/map/DungeonGenerator.hpp
)
add_library(nyaaengine 
    nyaa/engine/Window.cpp
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
