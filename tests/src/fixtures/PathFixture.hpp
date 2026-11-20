#pragma once

#include <filesystem>
namespace tests {

struct PathFixture {
    std::filesystem::path assetRoot() const { return "./assets"; }
};

}
