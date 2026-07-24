#pragma once

#include <trse/SaveInfo.hpp>

namespace TRSE
{
struct UnitLoadStateSaveData
{
    int unitID;
    bool beingLoaded;
    char name[128];
};

struct SavedUnitLoadState
{
    int64_t _padding_[2];
    int mainFocusUnitID;
    int unitDataCount;
    struct UnitLoadStateSaveData unitData[0];

    static constexpr uint8_t SAVED_ID = SAVED_ID_UNITLOADSTATE;
};
}; // namespace TRSE