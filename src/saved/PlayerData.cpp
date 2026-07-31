#include <imgui.h>
#include <trse/gui/Render.hpp>
#include <trse/saved/PlayerData.hpp>

namespace TRSE
{
int PlayerDialogueData::Render(const char *label)
{
    if (ImGui::TreeNode(label))
    {
        for (size_t i = 0; i < IM_ARRAYSIZE(m_dialoguePackageData); ++i)
        {
            ImGui::PushID(i);
            ImGui::InputScalarN("m_dialoguePackageData", ImGuiDataType_U64, m_dialoguePackageData[i],
                                IM_ARRAYSIZE(m_dialoguePackageData[i]));
            ImGui::PopID();
        }
        for (size_t i = 0; i < IM_ARRAYSIZE(m_dialogueSequenceData); ++i)
        {
            ImGui::PushID(i);
            ImGui::InputScalarN("m_dialogueSequenceData", ImGuiDataType_U8, m_dialogueSequenceData[i],
                                IM_ARRAYSIZE(m_dialogueSequenceData[i])); // TODO: This is a bool, fix the rendering
            ImGui::PopID();
        }
        ImGui::TreePop();
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}
int DocumentToClueLinker::Render(const char *label)
{
    if (ImGui::TreeNode(label))
    {
        GUI::Render(documentID, "documentID");
        GUI::Render(clueID, "clueID");
        ImGui::TreePop();
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}

int CollectibleInfo::Render(const char *label)
{
    if (ImGui::TreeNode(label))
    {
        bool tmp = isUnlocked;
        GUI::Render(tmp, "isUnlocked");
        isUnlocked = tmp;

        tmp = isInfoFound;
        GUI::Render(tmp, "isInfoFound");
        isInfoFound = tmp;

        ImGui::TreePop();
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}

int PlayerCollectibleData::Render(const char *label)
{
    if (ImGui::TreeNode(label))
    {
        for (size_t i = 0; i < IM_ARRAYSIZE(m_foundCollectibles); ++i)
        {
            ImGui::PushID(i);
            GUI::Render(m_foundCollectibles[i], "m_foundCollectibles");
            ImGui::PopID();
        }
        for (size_t i = 0; i < IM_ARRAYSIZE(m_foundClues); ++i)
        {
            ImGui::PushID(i);
            GUI::Render(m_foundClues[i], "m_foundCollectibles");
            ImGui::PopID();
        }
        for (size_t i = 0; i < IM_ARRAYSIZE(m_scheduledLootIndices); ++i)
        {
            ImGui::PushID(i);
            GUI::Render(m_scheduledLootIndices[i], "m_scheduledLootIndices");
            ImGui::PopID();
        }
        GUI::Render(m_sessionType, "m_sessionType");
        ImGui::TreePop();
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}

int PlayerPersistentData::Render(const char *label)
{
    if (ImGui::TreeNode(label))
    {
        GUI::Render(m_collectibles, "m_collectibles");
        GUI::Render(m_dialogueData, "m_dialogueData");

        bool tmp = m_hasDoneStatusScreenTutorial;
        GUI::Render(tmp, "m_hasDoneStatusScreenTutorial");
        m_hasDoneStatusScreenTutorial = tmp;

        tmp = m_bHasCharacterProfileChanged;
        GUI::Render(tmp, "m_bHasCharacterProfileChanged");
        m_bHasCharacterProfileChanged = tmp;

        tmp = m_bHasBeenToCampsiteSkillsHunter;
        GUI::Render(tmp, "m_bHasBeenToCampsiteSkillsHunter");
        m_bHasBeenToCampsiteSkillsHunter = tmp;

        tmp = m_bHasBeenToCampsiteSkillsRanger;
        GUI::Render(tmp, "m_bHasBeenToCampsiteSkillsRanger");
        m_bHasBeenToCampsiteSkillsRanger = tmp;

        tmp = m_bHasBeenToCampsiteSkillsSurvivor;
        GUI::Render(tmp, "m_bHasBeenToCampsiteSkillsSurvivor");
        m_bHasBeenToCampsiteSkillsSurvivor = tmp;

        tmp = m_bHasBennInSurvivorDifficulty;
        GUI::Render(tmp, "m_bHasBennInSurvivorDifficulty");
        m_bHasBennInSurvivorDifficulty = tmp;

        GUI::Render(m_characterProfileIndex, "m_characterProfileIndex");
        GUI::Render(m_numStandardSideTombCompleted, "m_numStandardSideTombCompleted");
        GUI::Render(m_numPurchasedTraits, "m_numPurchasedTraits");
        GUI::Render(m_numPurchasedTraitsForMetrics, "m_numPurchasedTraitsForMetrics");
        GUI::Render(m_overallCheckpointVisits, "m_overallCheckpointVisits;");
        GUI::Render(m_numPurchasedTraitsForMetrics, "m_numPurchasedTraitsForMetrics");

        ImGui::InputScalarN("m_numPurchasedTraitsForMetricsByType", ImGuiDataType_U16,
                            m_numPurchasedTraitsForMetricsByType, IM_ARRAYSIZE(m_numPurchasedTraitsForMetricsByType));
        ImGui::InputScalarN("m_numArrowsCraftedOfType", ImGuiDataType_U16, m_numArrowsCraftedOfType,
                            IM_ARRAYSIZE(m_numArrowsCraftedOfType));
        ImGui::InputScalarN("m_weaponsViewed", ImGuiDataType_U16, m_weaponsViewed, IM_ARRAYSIZE(m_weaponsViewed));
        ImGui::InputScalarN("m_activeChallengesProgress", ImGuiDataType_U16, m_activeChallengesProgress,
                            IM_ARRAYSIZE(m_activeChallengesProgress));

        ImGui::TreePop();
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}

int PlayerPersistentSaveData::Render(const char *label)
{
    (void)label;
    return GUI::Render(playerData, "playerData");
}

int SavedPlayerData::Render(const char *label)
{
    if (ImGui::TreeNode(label))
    {
        for (int32_t i = 0; i < playerDataCount; ++i)
        {
            ImGui::PushID(i);
            GUI::Render(playerData[i], "playerData");
            ImGui::PopID();
        }
        ImGui::TreePop();
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}
}; // namespace TRSE