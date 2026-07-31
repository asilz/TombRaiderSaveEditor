#include <imgui.h>
#include <trse/gui/Render.hpp>
#include <trse/saved/UnitLightData.hpp>

namespace TRSE
{
int UnitLightSaveData::Render(const char *label)
{
    if (ImGui::TreeNode(label))
    {
        GUI::Render(lightDataType, "lightDataType");
        GUI::Render(admdOrGroupIndex, "admdOrGroupIndex");
        GUI::Render(isEnabled, "isEnabled");
        GUI::Render(intensity, "intensity");
        GUI::Render(rangeScale, "rangeScale");

        ImGui::TreePop();
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}

int SavedUnitLightData::Render(const char *label)
{
    if (ImGui::TreeNode(label))
    {
        GUI::Render(unitID, "unitID");
        for (int32_t i = 0; i < lightDataCount; ++i)
        {
            ImGui::PushID(i);
            GUI::Render(lightData[i], "lightData");
            ImGui::PopID();
        }
        ImGui::TreePop();
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}
}; // namespace TRSE