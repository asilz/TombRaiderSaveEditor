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

int CampsiteID::Render(const char *label)
{
    (void)label;
    return GUI::Render(m_campsiteID, label);
}

int CampsiteData::Render(const char *label)
{
    if (ImGui::TreeNode(label))
    {
        GUI::Render(m_id, "m_id");
        GUI::Render(m_state, "m_state");
        GUI::Render(m_progressionIndex, "m_progressionIndex");
        GUI::Render(m_visited, "m_visited");
        GUI::Render(m_viewedInCampsite, "m_viewedInCampsite");
        ImGui::TreePop();
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}

int SavedCampsites::Render(const char *label)
{
    if (ImGui::TreeNode(label))
    {
        GUI::Render(currentCampsite, "currentCampsite");
        GUI::Render(forwardCampsite, "forwardCampsite");
        if (ImGui::TreeNode("campsiteData"))
        {
            for (int32_t i = 0; i < campsitesCount; ++i)
            {
                ImGui::PushID(i);
                GUI::Render(campsiteData[i], "campsiteData");
                ImGui::PopID();
            }
            ImGui::TreePop();
        }
        ImGui::TreePop();
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}
}; // namespace TRSE