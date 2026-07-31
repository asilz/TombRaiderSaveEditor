#include <trse/Hash.hpp>
#include <trse/gui/Render.hpp>

namespace TRSE
{
int PlacementHashKey::Render(const char *label) { return GUI::Render(m_keyValue, label); }
}; // namespace TRSE