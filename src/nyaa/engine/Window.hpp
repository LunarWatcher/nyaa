#pragma once

#include "nyaa/engine/Controller.hpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <memory>

namespace nyaa::engine {

struct WindowOpts {
    const char* displayTitle;
};

class Window {
private:
    // Allegro primitives {{{
    // These are not separated into their own, managed classes largely just to make things easier for me
    ALLEGRO_TIMER* frameTimer;
    ALLEGRO_EVENT_QUEUE* queue;
    ALLEGRO_DISPLAY* display;
    // }}}

    std::shared_ptr<Controller> controller;
public:
    Window(const WindowOpts& opts);
    ~Window();

    Window(Window&&) = delete;
    Window(Window&) = delete;

    // TODO: Transitions? maybe with a metacontroller?
    void setController(std::shared_ptr<Controller> newController) {
        this->controller = newController;
    }

    void run();
};

}
