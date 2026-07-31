#pragma once

#include <trse/SaveInfo.hpp>

namespace TRSE
{

struct MapUnitData
{
    int unitID;
    bool showOnMap;
    int orderRevealed;

    int Render(const char *label);
};

struct SavedMapData
{
    int64_t _padding_[2];
    uint32_t numMapUnits;
    struct MapUnitData mapUnits[0];

    int Render(const char *label);

    static constexpr uint8_t SAVED_ID = SAVED_ID_MAP;
};

}; // namespace TRSE