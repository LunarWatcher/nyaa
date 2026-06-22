#pragma once

#include "allegro5/bitmap.h"
#include <memory>
namespace nyaa::engine {

extern void deleteBitmap(ALLEGRO_BITMAP* bmp);

using BitmapPtr = std::unique_ptr<ALLEGRO_BITMAP, decltype(deleteBitmap)*>;

}
