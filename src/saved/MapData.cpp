#include <imgui.h>
#include <trse/gui/Render.hpp>
#include <trse/saved/MapData.hpp>

namespace TRSE
{
int MapUnitData::Render(const char *label)
{
    if (ImGui::TreeNode(label))
    {
        GUI::Render(unitID, "unitID");
        GUI::Render(showOnMap, "showOnMap");
        GUI::Render(orderRevealed, "orderRevealed");
        ImGui::TreePop();
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}
int SavedMapData::Render(const char *label)
{
    if (ImGui::TreeNode(label))
    {
        for (uint32_t i = 0; i < numMapUnits; ++i)
        {
            ImGui::PushID(i);
            GUI::Render(mapUnits[i], label);
            ImGui::PopID();
        }
        ImGui::TreePop();
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}
}; // namespace TRSE