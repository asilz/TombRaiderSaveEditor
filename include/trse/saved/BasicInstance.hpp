#pragma once

#include <trse/Hash.hpp>
#include <trse/SaveInfo.hpp>

namespace TRSE
{
struct SavedBasicInstance
{
    int64_t _padding_[2];
    uint32_t extraDataSize;
    uint32_t componentDataSize;
    struct PlacementHashKey hashKey;

    static constexpr uint8_t SAVED_ID = SAVED_ID_BASIC_INSTANCE;
};
}; // namespace TRSE