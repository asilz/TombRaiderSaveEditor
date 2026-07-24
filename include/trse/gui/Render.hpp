#pragma once

#include <cstdint>
#include <trse/Errno.hpp>
#include <type_traits>

namespace TRSE
{

namespace GUI
{

template <class T> int Render(T &obj, const char *label) { return obj.Render(label); }

template <> int Render<int8_t>(int8_t &obj, const char *label);
template <> int Render<int16_t>(int16_t &obj, const char *label);
template <> int Render<int32_t>(int32_t &obj, const char *label);
template <> int Render<int64_t>(int64_t &obj, const char *label);
template <> int Render<uint8_t>(uint8_t &obj, const char *label);
template <> int Render<uint16_t>(uint16_t &obj, const char *label);
template <> int Render<uint32_t>(uint32_t &obj, const char *label);
template <> int Render<uint64_t>(uint64_t &obj, const char *label);
template <> int Render<float>(float &obj, const char *label);
template <> int Render<double>(double &obj, const char *label);

}; // namespace GUI

} // namespace TRSE
