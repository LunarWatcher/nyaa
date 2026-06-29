#pragma once


namespace nyaa::engine {

class Window;
/**
 * Represents an app-wide controller. Unlike standard Controllers, this controller only gets access to app-wide meta
 * events, like resize events. AppControllers do not need to forward this info to other controllers, but it can be
 * useful for updating app-wide constants, like cameras or other resolution-dependent features, without needing to
 * propagate those specific changes into every controller.
 *
 * Misc.:
 * * AppControllers are not allowed to render.
 * * All AppController events also get a `Window*` pointer, in case you're masochistic enough to have multiple windows
 *   owned by the same app.
 *
 * If an AppController is set, AppController::* is called before Controller::*
 */
class AppController {
public:
    virtual ~AppController() = default;

    virtual void onResize(Window* window, float width, float height) = 0;
};

}
