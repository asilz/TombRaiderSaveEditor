#include <imgui.h>
#include <trse/gui/Render.hpp>
#include <trse/saved/BasicInstance.hpp>

namespace TRSE
{
int SavedBasicInstance::Render(const char *label)
{
    if (ImGui::TreeNode(label))
    {
        GUI::Render(extraDataSize, "extraDataSize");
        GUI::Render(componentDataSize, "componentDataSize");
        GUI::Render(hashKey, "hashKey");
        ImGui::TreePop();
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}
}; // namespace TRSE