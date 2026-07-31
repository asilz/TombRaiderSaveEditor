#include <imgui.h>
#include <trse/gui/Render.hpp>
#include <trse/saved/StreamLayerQueue.hpp>

namespace TRSE
{
int QueuedStreamLayerActions::Render(const char *label)
{
    if (ImGui::TreeNode(label))
    {
        for (size_t i = 0; i < IM_ARRAYSIZE(actions); ++i)
        {
            ImGui::PushID(i);
            GUI::Render(actions[i], "actions");
            ImGui::PopID();
        }
        ImGui::TreePop();
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}

int SavedStreamLayerQueueElem::Render(const char *label)
{
    if (ImGui::TreeNode(label))
    {
        GUI::Render(hashKey, "hashKey");
        GUI::Render(actions, "actions");
        ImGui::TreePop();
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}

int SavedStreamLayerQueue::Render(const char *label)
{
    if (ImGui::TreeNode(label))
    {
        for (int32_t i = 0; i < count; ++i)
        {
            ImGui::PushID(i);
            GUI::Render(queue[i], "queue");
            ImGui::PopID();
        }

        ImGui::TreePop();
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}
}; // namespace TRSE