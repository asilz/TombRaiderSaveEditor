#include <imgui.h>
#include <trse/Errno.hpp>
#include <trse/gui/Render.hpp>
#include <trse/saved/Campsites.hpp>

namespace TRSE
{
static const char *GetCampsiteStateName(enum CampsiteState state)
{
    switch (state)
    {
    case CampsiteState::CampsiteState_NotFound:
        return "CampsiteState_NotFound";
    case CampsiteState::CampsiteState_Found_Unlit:
        return "CampsiteState_Found_Unlit";
    case CampsiteState::CampsiteState_Discovered:
        return "CampsiteState_Discovered";
    case CampsiteState::CampsiteState_Tomb_Raided:
        return "CampsiteState_Tomb_Raided";
    default:
        break;
    }
    return nullptr;
}

}; // namespace TRSE