#pragma once

#include <trse/Bitset.hpp>
#include <trse/SaveInfo.hpp>

namespace TRSE
{

struct SavedCustomizationData
{
    int64_t _padding_[2];
    Bitset<256> binaryStatesOwned;
    Bitset<256> groupStatesOwned;
    Bitset<256> binaryCustomizationStates;
    uint16_t numGroupStates;
    uint32_t numSpawnerObjects;
    uint8_t data[0];

    int Render(const char *label);

    static constexpr uint8_t SAVED_ID = SAVED_ID_CUSTOMIZATIONDATA;
};

}; // namespace TRSE