#include <imgui.h>
#include <trse/Linalg.hpp>
#include <trse/gui/Render.hpp>

namespace TRSE
{
int Vector3f::Render(const char *label)
{
    if (ImGui::TreeNode(label))
    {
        GUI::Render(x, "x");
        GUI::Render(y, "y");
        GUI::Render(z, "z");

        ImGui::TreePop();
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}
}; // namespace TRSE