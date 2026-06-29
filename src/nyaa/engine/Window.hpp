#pragma once

#include "nyaa/engine/AppController.hpp"
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
    // TODO: use a unique_ptr, idiot
    ALLEGRO_TIMER* frameTimer;
    ALLEGRO_EVENT_QUEUE* queue;
    ALLEGRO_DISPLAY* display;
    // }}}

    std::shared_ptr<Controller> controller;
    AppController* appController;
public:
    Window(const WindowOpts& opts);
    ~Window();

    Window(Window&&) = delete;
    Window(Window&) = delete;

    // TODO: Transitions? This will likely require making controller a vector or queue or stack or whatever and a
    // pointer that tracks planned removals, which will likely get very spicy to implement
    void setController(std::shared_ptr<Controller>&& newController) {
        this->controller = newController;
    }

    /**
     * Used for setting an AppController. See AppController's doc for more information about the AppController's
     * semantics.
     */
    void setAppController(AppController* controller) {
        this->appController = controller;
    }

    void run();
};

}
