#include <imgui.h>
#include <trse/gui/Render.hpp>

namespace TRSE
{

namespace GUI
{
template <> int Render<int8_t>(int8_t &obj, const char *label)
{
    if (ImGui::InputScalar(label, ImGuiDataType_::ImGuiDataType_S8, &obj))
    {
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}

template <> int Render<int16_t>(int16_t &obj, const char *label)
{
    if (ImGui::InputScalar(label, ImGuiDataType_::ImGuiDataType_S16, &obj))
    {
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}

template <> int Render<int32_t>(int32_t &obj, const char *label)
{
    if (ImGui::InputScalar(label, ImGuiDataType_::ImGuiDataType_S32, &obj))
    {
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}

template <> int Render<int64_t>(int64_t &obj, const char *label)
{
    if (ImGui::InputScalar(label, ImGuiDataType_::ImGuiDataType_S64, &obj))
    {
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}

template <> int Render<uint8_t>(uint8_t &obj, const char *label)
{
    if (ImGui::InputScalar(label, ImGuiDataType_::ImGuiDataType_U8, &obj))
    {
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}

template <> int Render<uint16_t>(uint16_t &obj, const char *label)
{
    if (ImGui::InputScalar(label, ImGuiDataType_::ImGuiDataType_U16, &obj))
    {
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}

template <> int Render<uint32_t>(uint32_t &obj, const char *label)
{
    if (ImGui::InputScalar(label, ImGuiDataType_::ImGuiDataType_U32, &obj))
    {
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}

template <> int Render<uint64_t>(uint64_t &obj, const char *label)
{
    if (ImGui::InputScalar(label, ImGuiDataType_::ImGuiDataType_S64, &obj))
    {
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}

template <> int Render<float>(float &obj, const char *label)
{
    if (ImGui::InputFloat(label, &obj, 0.01f, 1.0f, "%.3f"))
    {
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}

template <> int Render<double>(double &obj, const char *label)
{
    if (ImGui::InputDouble(label, &obj, 0.01f, 1.0f, "%.3f"))
    {
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}

}; // namespace GUI
}; // namespace TRSE