#include <imgui.h>
#include <trse/gui/Render.hpp>
#include <trse/saved/DeadDeadUnitList.hpp>

namespace TRSE
{

int SavedDeadDeadUnitList::Render(const char *label)
{
    if (ImGui::TreeNode(label))
    {
        for (int32_t i = 0; i < deadDeadUnitCount; ++i)
        {
            ImGui::PushID(i);
            GUI::Render(deadDeadUnitCountList[i], "deadDeadUnitCountList");
            ImGui::PopID();
        }
        ImGui::TreePop();
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}

int DeadDeadUnitCount::Render(const char *label)
{
    if (ImGui::TreeNode(label))
    {
        GUI::Render(unitID, "unitID");
        GUI::Render(count, "count");
        ImGui::TreePop();
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}

}; // namespace TRSE