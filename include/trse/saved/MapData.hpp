#pragma once

#include <trse/SaveInfo.hpp>

namespace TRSE
{

struct MapUnitData
{
    int unitID;
    bool showOnMap;
    int orderRevealed;
};

struct SavedMapData
{
    int64_t _padding_[2];
    uint32_t numMapUnits;
    struct MapUnitData mapUnits[0];

    static constexpr uint8_t SAVED_ID = SAVED_ID_MAP;
};

}; // namespace TRSE