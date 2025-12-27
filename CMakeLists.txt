cmake_minimum_required(VERSION 3.28)

include(FetchContent)
FetchContent_Declare(conan
    GIT_REPOSITORY https://github.com/conan-io/cmake-conan
    GIT_TAG develop2
)
FetchContent_MakeAvailable(conan)
set(CMAKE_PROJECT_TOP_LEVEL_INCLUDES ${conan_SOURCE_DIR}/conan_provider.cmake)

project(nyaa)
set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)

set (CMAKE_CXX_STANDARD 23)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

option(NYAA_LINT "Whether or not to run clang-tidy" OFF)
option(LINT_WARNINGS_ARE_ERRORS "Whether or not to set -warnings-as-errors" OFF)

set(WANT_SHADERS_GL ON CACHE STRING "" FORCE)
set(WANT_MEMFILE OFF CACHE STRING "" FORCE)
set(WANT_PHYSFS OFF CACHE STRING "" FORCE)
set(WANT_NATIVE_DIALOG OFF CACHE STRING "" FORCE)
set(WANT_VIDEO OFF CACHE STRING "" FORCE)
set(WANT_IMAGE_WEBP OFF CACHE STRING "" FORCE)
set(WANT_IMAGE_FREEIMAGE OFF CACHE STRING "" FORCE)
set(WANT_DOCS OFF)
set(WANT_DEMO OFF)
set(WANT_EXAMPLES OFF)
set(WANT_TESTS OFF)
set(WANT_POPUP_EXAMPLES OFF)
if(CMAKE_SYSTEM_PROCESSOR MATCHES "i.86" OR CMAKE_SYSTEM_PROCESSOR MATCHES "x86|AMD64")
    set (WANT_ALLOW_SSE "avx2")
else()
    set (WANT_ALLOW_SSE OFF)
endif()

# FreeImage is covered by libjpeg and libpng, which is what I'll primarily be using.
# A lot of its dependencies are (L)GPL, which I do not want to deal with
set(WANT_IMAGE_FREEIMAGE OFF)

# I do not have the skill required to do audio stuff. Turning off the audio plugin saves 
# me from having to patch all the audio files, especially when I have no idea what I
# might need
set(WANT_AUDIO OFF)

# The patch mainly does the following:
# - disables compilation checks for Freetype and Freeimage
#     - Note: FreeImage was later disabled, but the allegro patch was not removed because I couldn't be bothered.
#       This part of the patch does not need to be retained
# - correcting variable names from ALL_UPPER to all_lower, because conan's
#   find_package files differ from the native find_package
# 
# All the other dependencies currently in use are automagically resolved.
# In the event of an allegro update, or for if WANT_AUDIO is ever enabled,
# the patch needs to be altered at best or recreated at worst. 
FetchContent_Declare(allegro5
    GIT_REPOSITORY https://github.com/liballeg/allegro5
    GIT_TAG 5.2.11.1
    OVERRIDE_FIND_PACKAGE
    # PATCH_COMMAND git reset --hard && git apply ${CMAKE_CURRENT_SOURCE_DIR}/3p-patches/allegro.patch
    EXCLUDE_FROM_ALL
)
FetchContent_Declare(alui
    GIT_REPOSITORY https://github.com/LunarWatcher/alui.cpp/
    GIT_TAG master
)
# Initially tried to use this for camera stuff, but:
# 1. Allegro has so much builtin stuff for that that it doesn't make sense to use anything else
# 2. Converting from glm to a float[4][4] _and_ passing it to ALLEGRO_TRANSFORM.m is _surprisingly_ difficult, and I could not be bothered
# FetchContent_Declare(
#     glm
#     GIT_REPOSITORY https://github.com/g-truc/glm
#     GIT_TAG 1.0.2
#     EXCLUDE_FROM_ALL
# )
FetchContent_MakeAvailable(
    allegro5
    # glm
    alui
)

set (ALLEGRO_INCLUDE_DIRS
    ${allegro5_SOURCE_DIR}/include/
    ${allegro5_BINARY_DIR}/include/
    ${allegro5_SOURCE_DIR}/addons/image/
    ${allegro5_SOURCE_DIR}/addons/ttf/
    ${allegro5_SOURCE_DIR}/addons/font/
    ${allegro5_SOURCE_DIR}/addons/color/
    ${allegro5_SOURCE_DIR}/addons/primitives/
)
# Mini-patch, alui doesn't properly set include dirs.
# Not sure if there's a way to fix this on alui's side without 
# making changes that risk breaking fetchcontent.
# Maybe this is an application for find_package/overrides?
target_include_directories(alui PUBLIC ${ALLEGRO_INCLUDE_DIRS})

# Meta interface target that links with all the libraries and headers
add_library(allegro-meta INTERFACE)
target_include_directories(allegro-meta INTERFACE ${ALLEGRO_INCLUDE_DIRS})
target_link_libraries(
    allegro-meta
INTERFACE
    allegro
    allegro_primitives
    allegro_font
    allegro_color
    allegro_image
    allegro_ttf
)

configure_file(${allegro5_SOURCE_DIR}/LICENSE.txt
    ${CMAKE_CURRENT_BINARY_DIR}/LICENSES/allegro5-UNK COPYONLY)
configure_file(${alui_SOURCE_DIR}/LICENSE
    ${CMAKE_CURRENT_BINARY_DIR}/LICENSES/alui-MIT COPYONLY)
set(ASSETS
    tilesets/tiles.png
    tilesets/tiles.json

    creatures/character.png
    creatures/character.json
)
foreach(ASSET IN LISTS ASSETS)
    message(STATUS "Copying ${ASSET}")
    configure_file(assets/${ASSET} ${CMAKE_CURRENT_BINARY_DIR}/assets/${ASSET} COPYONLY)
endforeach()

if (NYAA_LINT)
    find_program(
        CLANGTIDY
        NAMES "clang-tidy" "clang-tidy.exe"
        REQUIRED
    )

    set (CLANG_TIDY_COMMAND "${CLANGTIDY}" "--config-file=${CMAKE_CURRENT_SOURCE_DIR}/.clang-tidy")
    if (LINT_WARNINGS_ARE_ERRORS)
        list (APPEND CLANG_TIDY_COMMAND  -warnings-as-errors=*)
    endif()

    if (WIN32)
        list (APPEND CLANG_TIDY_COMMAND --extra-arg=/EHsc)
    endif()

    message(STATUS "Using CLANG_TIDY_COMMAND=${CLANG_TIDY_COMMAND}")
    set(CXX_CLANG_TIDY "${CLANG_TIDY_COMMAND}")

endif()

if (NOT WIN32)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif()

add_subdirectory(src)
add_subdirectory(tests EXCLUDE_FROM_ALL)

add_custom_target(run
    COMMAND nyaa
    DEPENDS nyaa
    COMMENT "Run nyaa")
add_custom_target(test
    COMMAND tests
    DEPENDS tests
    COMMENT "Test nyaa")
# vim:ft=cmake
