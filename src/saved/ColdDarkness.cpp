#include <imgui.h>
#include <trse/gui/Render.hpp>
#include <trse/saved/ColdDarkness.hpp>

namespace TRSE
{
int SavedColdDarknessData::Render(const char *label)
{
    if (ImGui::TreeNode(label))
    {
        ImGui::InputScalarN("m_numEnemyTypesKilled", ImGuiDataType_U32, m_numEnemyTypesKilled,
                            IM_ARRAYSIZE(m_numEnemyTypesKilled));
        GUI::Render(m_numSurvivorsRescued, "m_numSurvivorsRescued");
        GUI::Render(m_numWeaponsFound, "m_numWeaponsFound");
        GUI::Render(m_numTowerMistakes, "m_numTowerMistakes");
        GUI::Render(m_numShotsHit, "m_numShotsHit");
        GUI::Render(m_numShotsFired, "m_numShotsFired");
        GUI::Render(m_numPerfectTowerCompletions, "m_numPerfectTowerCompletions");
        GUI::Render(m_challengesStarted, "m_challengesStarted");
        GUI::Render(m_challengesFailed, "m_challengesFailed");
        GUI::Render(m_challengesCompleted, "m_challengesCompleted");
        ImGui::TreePop();
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}
}; // namespace TRSE