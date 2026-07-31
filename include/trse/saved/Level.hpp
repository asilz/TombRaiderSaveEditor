#pragma once

#include <trse/SaveInfo.hpp>

namespace TRSE
{
struct SavedLevel
{
    int64_t _padding_[2];
    float waterZ;
    int8_t levelCount;
    int32_t extraData[0];

    int Render(const char *label);

    static constexpr uint8_t SAVED_ID = SAVED_ID_LEVEL;
};
}; // namespace TRSE