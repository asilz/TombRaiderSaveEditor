#pragma once

#include <cinttypes>

namespace TRSE
{

struct PlacementHashKey
{
    uint64_t m_keyValue;

    int Render(const char *label);
};

}; // namespace TRSE
