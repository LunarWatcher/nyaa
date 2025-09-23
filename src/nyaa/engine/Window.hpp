#pragma once

#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>

namespace nyaa::engine {

struct WindowOpts {
    const char* displayTitle;
};

class Window {
private:
    // TODO: this prevents the game from running on windows, and outside a distro containing this font. A font should be
    // bundled, possibly dejavu proper, though I do see it's been abandoned.
    // Finding a FOSS font to use is going to be a whole thing if I want an updated one.
    constexpr static auto FONT = "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf";

    // Allegro primitives {{{
    // These are not separated into their own, managed classes largely just to make things easier for me
    ALLEGRO_TIMER* frameTimer;
    ALLEGRO_EVENT_QUEUE* queue;
    ALLEGRO_DISPLAY* display;
    // }}}
public:
    Window(const WindowOpts& opts);
    ~Window();

    Window(Window&&) = delete;
    Window(Window&) = delete;

    void run();
};

}
