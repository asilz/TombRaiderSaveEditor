#pragma once

#include <trse/SaveInfo.hpp>

namespace TRSE
{

struct DeadDeadUnitCount
{
    int unitID;
    int count;

    int Render(const char *label);
};

struct SavedDeadDeadUnitList
{
    uint64_t _padding_[2];
    int32_t deadDeadUnitCount;
    struct DeadDeadUnitCount deadDeadUnitCountList[0];

    int Render(const char *label);

    static constexpr uint8_t SAVED_ID = SAVED_ID_DEADDEADUNITLIST;
};

}; // namespace TRSE