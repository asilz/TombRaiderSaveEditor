#include <imgui.h>
#include <trse/gui/Render.hpp>
#include <trse/saved/Level.hpp>

namespace TRSE
{
int SavedLevel::Render(const char *label)
{
    if (ImGui::TreeNode(label))
    {
        GUI::Render(waterZ, "waterZ");
        if (levelCount > 0)
        {
            ImGui::InputScalarN("extraData", ImGuiDataType_S32, extraData, levelCount);
        }
        ImGui::TreePop();
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}
}; // namespace TRSE