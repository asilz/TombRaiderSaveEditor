#pragma once

#include <trse/SaveInfo.hpp>

namespace TRSE
{

struct DeadDeadUnitCount
{
    int unitID;
    int count;
};

struct SavedDeadDeadUnitList
{
    uint64_t _padding_[2];
    int deadDeadUnitCount;
    struct DeadDeadUnitCount deadDeadUnitCountList[0];

    static constexpr uint8_t SAVED_ID = SAVED_ID_DEADDEADUNITLIST;
};

}; // namespace TRSE