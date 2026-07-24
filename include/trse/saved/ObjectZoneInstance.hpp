#pragma once

#include <trse/Linalg.hpp>
#include <trse/SaveInfo.hpp>

namespace TRSE
{

struct SavedObjectZoneInstance
{
    int64_t _padding_[4];
    uint32_t objectZoneID;
    int birthUnitID;
    bool bPurgeableSaveInfo;
    struct Vector3f position;
    struct Vector3f reversedEulerRotation;

    static constexpr uint8_t SAVED_ID = SAVED_ID_OBJECTZONE_INSTANCE;
};

}; // namespace TRSE