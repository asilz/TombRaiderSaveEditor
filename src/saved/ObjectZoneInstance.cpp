#include <imgui.h>
#include <trse/gui/Render.hpp>
#include <trse/saved/ObjectZoneInstance.hpp>

namespace TRSE
{
int SavedObjectZoneInstance::Render(const char *label)
{
    if (ImGui::TreeNode(label))
    {
        GUI::Render(objectZoneID, "objectZoneID");
        GUI::Render(birthUnitID, "birthUnitID");
        GUI::Render(bPurgeableSaveInfo, "bPurgeableSaveInfo");
        GUI::Render(position, "position");
        GUI::Render(reversedEulerRotation, "reversedEulerRotation");
        ImGui::TreePop();
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}
}; // namespace TRSE