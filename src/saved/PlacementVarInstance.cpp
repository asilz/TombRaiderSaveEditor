#include <imgui.h>
#include <trse/gui/Render.hpp>
#include <trse/saved/PlacementVarInstance.hpp>

namespace TRSE
{
int SavedPlacementVarInstance::Render(const char *label) { return GUI::Render(hashKey, "hashKey"); }
}; // namespace TRSE