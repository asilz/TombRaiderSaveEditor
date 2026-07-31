#include <imgui.h>
#include <trse/gui/Render.hpp>
#include <trse/saved/GameStateTimer.hpp>

namespace TRSE
{
int SavedGameStateTimer::Render(const char *label)
{
    if (ImGui::TreeNode(label))
    {
        GUI::Render(gameStateTimerStoredTime, "gameStateTimerStoredTime");
        GUI::Render(gameStateTimerRunning, "gameStateTimerRunning");
        ImGui::TreePop();
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}
}; // namespace TRSE