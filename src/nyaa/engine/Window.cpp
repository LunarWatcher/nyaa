#include "nyaa/engine/Window.hpp"
#include "allegro5/display.h"
#include "allegro5/drawing.h"
#include "allegro5/events.h"
#include "allegro5/shader.h"

#include <cstring>
#include <spdlog/spdlog.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>

namespace nyaa::engine {

Window::Window(const WindowOpts& opts) {
    // TODO: not optimal, and doesn't respect vsync.
    this->frameTimer = al_create_timer(1.0 / 60.0);
    this->queue = al_create_event_queue();
    al_set_new_display_flags(
        ALLEGRO_WINDOWED
        | ALLEGRO_RESIZABLE
    );
    al_set_new_display_option(
        ALLEGRO_DEFAULT_SHADER_PLATFORM,
        ALLEGRO_SHADER_GLSL,
        ALLEGRO_REQUIRE
    );
    this->display = al_create_display(640, 480);
    al_set_window_title(this->display, opts.displayTitle);

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_timer_event_source(frameTimer));
    al_register_event_source(queue, al_get_display_event_source(display));
}

Window::~Window() {
}

void Window::run() {
    al_start_timer(frameTimer);

    ALLEGRO_EVENT ev;
    bool redraw = false;
    bool done = false;
    while (true) {
        al_wait_for_event(queue, &ev);

        switch(ev.type) { // NOLINT
        case ALLEGRO_EVENT_TIMER:
            redraw = true;
            break;

        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            done = true;
            break;
        case ALLEGRO_EVENT_DISPLAY_RESIZE:
            al_acknowledge_resize(display);
            break;
        }

        // TODO: I don't like this pattern
        if (done) {
            break;
        }

        if (redraw && al_is_event_queue_empty(queue)) {
            al_clear_to_color(ALLEGRO_COLOR(0, 0, 0));

            al_draw_filled_triangle(
                200, 200,
                300, 300,
                200, 600,
                ALLEGRO_COLOR(0.6, 0.1, 0.6)
            );

            al_flip_display();
            redraw = false;
        }
    }
}

}
