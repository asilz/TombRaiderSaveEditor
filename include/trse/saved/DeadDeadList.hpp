#pragma once

#include <trse/SaveInfo.hpp>

namespace TRSE
{

struct SavedDeadDeadList
{
    int64_t _padding_[2];
    int deadDeadCount;
    uint64_t deadDeadList[0];

    static constexpr uint8_t SAVED_ID = SAVED_ID_DEADDEADLIST;
};

}; // namespace TRSE