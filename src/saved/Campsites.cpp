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

int CampsiteID::Render(const char *label) { return GUI::Render<uint32_t>(m_campsiteID, "Campsite ID"); }

int CampsiteData::Render(const char *label)
{
    int err = m_id.Render(label);
    if (err)
    {
        return err;
    }
}

int SavedCampsites::Render(const char *label) { return 0; }
}; // namespace TRSE