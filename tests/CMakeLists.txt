add_executable(tests 
    src/meta/AssetTests.cpp
)

Include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.8.1
)

FetchContent_MakeAvailable(Catch2)

target_link_libraries(tests Catch2::Catch2WithMain)

target_link_libraries(tests nyaasrc)
target_include_directories(tests PRIVATE ./src/)

# vim:ft=cmake
