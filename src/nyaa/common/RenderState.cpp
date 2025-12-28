#include "RenderState.hpp"

namespace nyaa::common {

RenderState::RenderState() 
    : worldCam(200, 250), // TODO: this probably needs to be synced up with resolution?
      uiCam(0, 0)
{
}


}

