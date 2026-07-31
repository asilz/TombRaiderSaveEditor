#pragma once

#include <trse/Bitset.hpp>
#include <trse/SaveInfo.hpp>

namespace TRSE
{

struct SavedColdDarknessData
{
    int64_t _padding_[2];
    uint32_t m_numEnemyTypesKilled[8];
    uint32_t m_numSurvivorsRescued;
    uint32_t m_numWeaponsFound;
    uint32_t m_numTowerMistakes;
    uint32_t m_numShotsHit;
    uint32_t m_numShotsFired;
    uint32_t m_numPerfectTowerCompletions;
    Bitset<5> m_challengesStarted;
    Bitset<5> m_challengesFailed;
    Bitset<5> m_challengesCompleted;

    int Render(const char *label);

    static constexpr uint8_t SAVED_ID = SAVED_ID_COLD_DARKNESS;
};

}; // namespace TRSE