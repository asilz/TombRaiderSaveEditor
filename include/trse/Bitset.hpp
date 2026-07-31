#pragma once

#include <cstddef>

namespace TRSE
{

template <size_t N> class Bitset
{
    unsigned int m_value[(N + sizeof(unsigned int) * 8 - 1) / (sizeof(unsigned int) * 8)];

  public:
    int Render(const char *label)
    {
        (void)label;
        return 0;
    } // TODO: Render bitsets
};

}; // namespace TRSE