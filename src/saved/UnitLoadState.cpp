#include <imgui.h>
#include <trse/gui/Render.hpp>
#include <trse/saved/UnitLoadState.hpp>

namespace TRSE
{
int UnitLoadStateSaveData::Render(const char *label)
{
    if (ImGui::TreeNode(label))
    {
        GUI::Render(unitID, "unitID");
        GUI::Render(beingLoaded, "beingLoaded");
        ImGui::InputText("name", name, sizeof(name));

        ImGui::TreePop();
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}

int SavedUnitLoadState::Render(const char *label)
{
    if (ImGui::TreeNode(label))
    {
        GUI::Render(mainFocusUnitID, "mainFocusUnitID");
        for (int32_t i = 0; i < unitDataCount; ++i)
        {
            ImGui::PushID(i);
            GUI::Render(unitData[i], label);
            ImGui::PopID();
        }
        ImGui::TreePop();
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}
}; // namespace TRSE