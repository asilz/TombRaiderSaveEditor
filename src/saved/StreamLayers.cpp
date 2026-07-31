#include <imgui.h>
#include <trse/gui/Render.hpp>
#include <trse/saved/StreamLayers.hpp>

namespace TRSE
{
int StreamLayerStates::Render(const char *label)
{
    (void)label;
    return 0;
}
int SavedStreamLayerData::Render(const char *label)
{
    if (ImGui::TreeNode(label))
    {
        GUI::Render(placementID, "placementID");
        GUI::Render(numStreamLayers, "numStreamLayers");
        GUI::Render(active, "active");
        GUI::Render(loadRequested, "loadRequested");

        ImGui::TreePop();
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}

int SavedStreamLayers::Render(const char *label)
{
    if (ImGui::TreeNode(label))
    {
        GUI::Render(globalChanged, "globalChanged");
        GUI::Render(globalLoaded, "globalLoaded");
        GUI::Render(globalActive, "globalActive");
        for (int32_t i = 0; i < numPlacements; ++i)
        {
            ImGui::PushID(i);
            GUI::Render(streamLayerData[i], "streamLayerData");
            ImGui::PopID();
        }
        ImGui::TreePop();
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}
} // namespace TRSE