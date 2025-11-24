#include "RenderState.hpp"

namespace nyaa::common {

RenderState::RenderState() 
    : uiCam(0, 0), // TODO: this probably needs to be synced up with resolution?
      worldCam(200, 250)
{
}


}

