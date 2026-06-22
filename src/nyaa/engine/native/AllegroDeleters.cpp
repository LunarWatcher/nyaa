#include "AllegroDeleters.hpp"
#include "allegro5/bitmap.h"

namespace nyaa {

void engine::deleteBitmap(ALLEGRO_BITMAP* bmp) {
    al_destroy_bitmap(bmp);
}

}
