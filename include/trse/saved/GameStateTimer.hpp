#pragma once

#include <trse/SaveInfo.hpp>

namespace TRSE
{
struct SavedGameStateTimer
{
    int64_t _padding_[2];
    uint64_t gameStateTimerStoredTime;
    bool gameStateTimerRunning;

    static constexpr uint8_t SAVED_ID = SAVED_ID_GAMESTATE_TIMER;
};
}; // namespace TRSE