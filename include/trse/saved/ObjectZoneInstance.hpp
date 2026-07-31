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
    Vector3f position;
    Vector3f reversedEulerRotation;

    int Render(const char *label);

    static constexpr uint8_t SAVED_ID = SAVED_ID_OBJECTZONE_INSTANCE;
};

}; // namespace TRSE