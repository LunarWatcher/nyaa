#pragma once

#include "allegro5/allegro_font.h"
#include "allegro5/bitmap.h"
#include <memory>

namespace nyaa::engine {

using BitmapPtr = std::unique_ptr<ALLEGRO_BITMAP, decltype(al_destroy_bitmap)*>;
using FontPtr = std::unique_ptr<ALLEGRO_FONT, decltype(al_destroy_font)*>;

}
