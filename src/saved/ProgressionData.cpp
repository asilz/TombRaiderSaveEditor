#include <imgui.h>
#include <trse/gui/Render.hpp>
#include <trse/saved/ProgressionData.hpp>

namespace TRSE
{
int SavedProgressionData::Render(const char *label)
{
    if (ImGui::TreeNode(label))
    {
        GUI::Render(progressionFlags, "progressionFlags");
        GUI::Render(numPersistenceHelpers, "numPersistenceHelpers");
        GUI::Render(numVolatilePersistenceHelpers, "numVolatilePersistenceHelpers");
        // TODO: GUI::Render(persistenceHelpers, "persistenceHelpers");
        ImGui::TreePop();
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}
}; // namespace TRSE