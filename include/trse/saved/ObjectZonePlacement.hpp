#pragma once

#include <trse/Linalg.hpp>
#include <trse/SaveInfo.hpp>

namespace TRSE
{

struct SavedObjectZonePlacement
{
    int64_t _padding_[4];
    uint32_t bPurgeableSaveInfo : 1;
    uint32_t bHasPosition : 1;
    uint32_t bHasRotation : 1;
    uint32_t bDeadDead : 1;
    uint32_t objectID : 16;
    uint32_t pad : 12;
    struct Vector3f data[0];

    static constexpr uint8_t SAVED_ID = SAVED_ID_OBJECTZONE_PLACEMENT;
};

}; // namespace TRSE