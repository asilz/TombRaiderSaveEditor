#include <imgui.h>
#include <trse/gui/Render.hpp>
#include <trse/saved/CustomizationData.hpp>

namespace TRSE
{
int SavedCustomizationData::Render(const char *label)
{
    if (ImGui::TreeNode(label))
    {
        GUI::Render(binaryStatesOwned, "binaryStatesOwned");
        GUI::Render(groupStatesOwned, "groupStatesOwned");
        GUI::Render(binaryCustomizationStates, "binaryCustomizationStates");
        GUI::Render(numGroupStates, "numGroupStates");
        GUI::Render(numSpawnerObjects, "numSpawnerObjects");
        // TODO: Render data

        ImGui::TreePop();
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}
}; // namespace TRSE