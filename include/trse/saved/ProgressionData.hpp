#pragma once

#include <trse/Hash.hpp>
#include <trse/SaveInfo.hpp>

namespace TRSE
{

struct SavedProgressionData
{
    int64_t _padding_[2];
    int progressionFlags;
    uint8_t numPersistenceHelpers;
    uint8_t numVolatilePersistenceHelpers;
    struct PlacementHashKey persistenceHelpers[0];

    static constexpr uint8_t SAVED_ID = SAVED_ID_PROGRESSION_DATA;
};

}; // namespace TRSE