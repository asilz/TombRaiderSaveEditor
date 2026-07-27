#pragma once

#include <cstdint>
#include <trse/Errno.hpp>
#include <trse/TemplateString.hpp>
#include <type_traits>
#include <typeinfo>

namespace TRSE
{

namespace GUI
{

template <TemplateString name, class T> int Render(T &obj)
{
    if constexpr (std::is_class<T>())
    {
        return obj.Render();
    }
    else if constexpr (typeid(T) == typeid(int8_t))
    {
        if (ImGui::InputScalar(name.GetCStr(), ImGuiDataType_::ImGuiDataType_S8, &obj))
        {
            return TRSE_RET_IMGUI_EDIT;
        }
        return 0;
    }
    else if constexpr (typeid(T) == typeid(int16_t))
    {
        if (ImGui::InputScalar(name.GetCStr(), ImGuiDataType_::ImGuiDataType_S16, &obj))
        {
            return TRSE_RET_IMGUI_EDIT;
        }
        return 0;
    }
    else if constexpr (typeid(T) == typeid(int32_t))
    {
        if (ImGui::InputScalar(name.GetCStr(), ImGuiDataType_::ImGuiDataType_S32, &obj))
        {
            return TRSE_RET_IMGUI_EDIT;
        }
        return 0;
    }
    else if constexpr (typeid(T) == typeid(int64_t))
    {
        if (ImGui::InputScalar(name.GetCStr(), ImGuiDataType_::ImGuiDataType_S64, &obj))
        {
            return TRSE_RET_IMGUI_EDIT;
        }
        return 0;
    }
    else if constexpr (typeid(T) == typeid(uint8_t))
    {
        if (ImGui::InputScalar(name.GetCStr(), ImGuiDataType_::ImGuiDataType_U8, &obj))
        {
            return TRSE_RET_IMGUI_EDIT;
        }
        return 0;
    }
    else if constexpr (typeid(T) == typeid(uint16_t))
    {
        if (ImGui::InputScalar(name.GetCStr(), ImGuiDataType_::ImGuiDataType_U16, &obj))
        {
            return TRSE_RET_IMGUI_EDIT;
        }
        return 0;
    }
    else if constexpr (typeid(T) == typeid(uint32_t))
    {
        if (ImGui::InputScalar(name.GetCStr(), ImGuiDataType_::ImGuiDataType_U32, &obj))
        {
            return TRSE_RET_IMGUI_EDIT;
        }
        return 0;
    }
    else if constexpr (typeid(T) == typeid(uint64_t))
    {
        if (ImGui::InputScalar(name.GetCStr(), ImGuiDataType_::ImGuiDataType_U64, &obj))
        {
            return TRSE_RET_IMGUI_EDIT;
        }
        return 0;
    }
    else if constexpr (typeid(T) == typeid(float))
    {
        if (ImGui::InputFloat(name.GetCStr(), &obj, 0.01f, 1.0f, "%.3f"))
        {
            return TRSE_RET_IMGUI_EDIT;
        }
        return 0;
    }
    else if constexpr (typeid(T) == typeid(double))
    {
        if (ImGui::InputDouble(name.GetCStr(), &obj, 0.01f, 1.0f, "%.3f"))
        {
            return TRSE_RET_IMGUI_EDIT;
        }
        return 0;
    }
    else
    {
        static_assert(0);
    }
}

}; // namespace GUI

}; // namespace TRSE
