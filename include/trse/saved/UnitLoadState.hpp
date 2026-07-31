#pragma once

#include <trse/SaveInfo.hpp>

namespace TRSE
{
struct UnitLoadStateSaveData
{
    int32_t unitID;
    bool beingLoaded;
    char name[128];

    int Render(const char *label);
};

struct SavedUnitLoadState
{
    int64_t _padding_[2];
    int32_t mainFocusUnitID;
    int32_t unitDataCount;
    struct UnitLoadStateSaveData unitData[0];

    int Render(const char *label);

    static constexpr uint8_t SAVED_ID = SAVED_ID_UNITLOADSTATE;
};
}; // namespace TRSE