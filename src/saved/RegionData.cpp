#include <imgui.h>
#include <trse/gui/Render.hpp>
#include <trse/saved/RegionData.hpp>

namespace TRSE
{
int HuntManagerInfo::Render(const char *label)
{
    if (ImGui::TreeNode(label))
    {
        GUI::Render(m_huntManagerPlacement, "m_huntManagerPlacement");

        // TODO: Render death times
        ImGui::TreePop();
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}

int RegionInfo::Render(const char *label)
{
    if (ImGui::TreeNode(label))
    {
        GUI::Render(m_regionID, "m_regionID");
        GUI::Render(m_fastTravelState, "m_fastTravelState");
        GUI::Render(m_timeOfDay, "m_timeOfDay");
        GUI::Render(m_regionState, "m_regionState");
        GUI::Render(m_regionStateIndex, "m_regionStateIndex");
        GUI::Render(m_salvageFromHunting, "m_salvageFromHunting");
        GUI::Render(m_salvageFromEnemies, "m_salvageFromEnemies");
        GUI::Render(m_xpFromHunting, "m_xpFromHunting");
        GUI::Render(m_xpFromPAC, "m_xpFromPAC");
        GUI::Render(m_relics, "m_relics");
        GUI::Render(m_documents, "m_documents");
        GUI::Render(m_tombsRaided, "m_tombsRaided");
        GUI::Render(m_murals, "m_murals");
        GUI::Render(m_survivalCaches, "m_survivalCaches");
        GUI::Render(m_explorerCorpses, "m_explorerCorpses");
        GUI::Render(m_documentChests, "m_documentChests");
        GUI::Render(m_strongboxes, "m_strongboxes");
        GUI::Render(m_cryptTreasures, "m_cryptTreasures");
        GUI::Render(m_ancientSeal, "m_ancientSeal");
        GUI::Render(m_codex, "m_codex");
        GUI::Render(m_monoliths, "m_monoliths");
        GUI::Render(m_missions, "m_missions");
        GUI::Render(m_regionLocalName, "m_regionLocalName");
        GUI::Render(m_brokenWeaponOpportunityTracking, "m_brokenWeaponOpportunityTracking");
        GUI::Render(m_brokenWeaponsClaimed, "m_brokenWeaponsClaimed");
        GUI::Render(m_brokenWeaponOpportunities, "m_brokenWeaponOpportunities");
        GUI::Render(m_brokenWeaponIndex, "m_brokenWeaponIndex");
        GUI::Render(m_brokenWeaponIndexLimit, "m_brokenWeaponIndexLimit");
        GUI::Render(m_hideOnMap, "m_hideOnMap");
        GUI::Render(m_allowStateDowngrades, "m_allowStateDowngrades");
        GUI::Render(m_onMapCoordinateX, "m_allowStateDowngrades");
        GUI::Render(m_onMapCoordinateY, "m_allowStateDowngrades");
        GUI::Render(m_onMapAreaWidth, "m_allowStateDowngrades");
        GUI::Render(m_onMapAreaHeight, "m_onMapAreaHeight");
        GUI::Render(m_isRetraversable, "m_isRetraversable");
        GUI::Render(m_countsTowardPercentComplete, "m_countsTowardPercentComplete");
        GUI::Render(m_activeMissionID, "m_activeMissionID");

        ImGui::TreePop();
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}

int SavedRegionData::Render(const char *label)
{
    if (ImGui::TreeNode(label))
    {
        for (size_t i = 0; i < IM_ARRAYSIZE(huntManagerInfo); ++i)
        {
            ImGui::PushID(i);
            GUI::Render(huntManagerInfo[i], "huntManagerInfo");
            ImGui::PopID();
        }
        for (uint32_t i = 0; i < numRegions; ++i)
        {
            ImGui::PushID(i);
            GUI::Render(regions[i], "regions");
            ImGui::PopID();
        }
        ImGui::TreePop();
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}
}; // namespace TRSE