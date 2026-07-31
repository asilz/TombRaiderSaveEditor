#include <imgui.h>
#include <trse/gui/Render.hpp>
#include <trse/saved/DeadDeadList.hpp>

namespace TRSE
{
int SavedDeadDeadList::Render(const char *label)
{
    if (ImGui::TreeNode(label))
    {
        if (deadDeadCount > 0)
        {
            ImGui::InputScalarN("deadDeadList", ImGuiDataType_U64, deadDeadList, deadDeadCount);
        }
        ImGui::TreePop();
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}
}; // namespace TRSE