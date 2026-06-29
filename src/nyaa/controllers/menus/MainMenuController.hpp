#pragma once

#include "alui/GUI.hpp"
#include "nyaa/common/CommonState.hpp"
#include "nyaa/engine/Controller.hpp"

namespace nyaa {

class MainMenuController : public engine::Controller {
private:
    const static inline auto PlayButton = 1;
    common::CommonStatePtr commonState;
    alui::GUI gui;

    void initializeGUI();
public:
    MainMenuController(
        const common::CommonStatePtr& commonState
    );
    void render(double delta) override;
    void tick(double delta) override;

    void onResize(float, float) override;
    void rawProcessEvent(const ALLEGRO_EVENT&) override;
};

}
