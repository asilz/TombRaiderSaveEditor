#include <imgui.h>
#include <trse/gui/Render.hpp>
#include <trse/saved/ActionGraph.hpp>

namespace TRSE
{

int SavedActionGraph::Render(const char *label)
{
    if (ImGui::TreeNode(label))
    {
        GUI::Render(hashKey, "hashKey");
        GUI::Render(msgQueueSize, "msgQueueSize");
        GUI::Render(processQueueSize, "processQueueSize");
        GUI::Render(postProcessQueueSize, "postProcessQueueSize");
        GUI::Render(nodeStreamSize, "nodeStreamSize");
        ImGui::TreePop();
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}

}; // namespace TRSE