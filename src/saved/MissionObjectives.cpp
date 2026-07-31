#include <imgui.h>
#include <trse/gui/Render.hpp>
#include <trse/saved/MissionObjectives.hpp>

namespace TRSE
{
int ScriptObjectiveType::Render(const char *label) { return GUI::Render(objectiveType, "objectiveType"); }
int MissionObjectiveData::Render(const char *label)
{
    if (ImGui::TreeNode(label))
    {
        GUI::Render(m_type, "m_type");
        GUI::Render(m_state, "m_state");
        GUI::Render(m_count, "m_count");
        GUI::Render(m_activatedCoordinateX, "m_activatedCoordinateX");
        GUI::Render(m_activatedCoordinateY, "m_activatedCoordinateY");
        GUI::Render(m_activatedUnit, "m_activatedUnit");
        GUI::Render(m_viewedMission, "m_viewedMission");
        GUI::Render(m_forceShowOnMap, "m_forceShowOnMap");
        ImGui::TreePop();
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}
int SavedMissionObjectives::Render(const char *label)
{
    if (ImGui::TreeNode(label))
    {
        GUI::Render(currentObjective, "currentObjective");
        for (int32_t i = 0; i < objectivesCount; ++i)
        {
            ImGui::PushID(i);
            GUI::Render(objectiveData[i], "objectiveData");
            ImGui::PopID();
        }
        ImGui::TreePop();
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}
}; // namespace TRSE