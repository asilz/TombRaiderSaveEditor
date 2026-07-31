#pragma once

#include <trse/SaveInfo.hpp>

namespace TRSE
{

typedef enum UnitLightSaveDataTypes
{
    LIGHTSAVETYPE_UnitLightGroup = 1,
    LIGHTSAVETYPE_GlobalLightGroup = 2
} UnitLightSaveDataTypes;

struct UnitLightSaveData
{
    enum UnitLightSaveDataTypes lightDataType;
    uint16_t admdOrGroupIndex;
    bool isEnabled;
    float intensity;
    float rangeScale;

    int Render(const char *label);
};

struct SavedUnitLightData
{
    int64_t _padding_[2];
    int32_t unitID;
    int32_t lightDataCount;
    struct UnitLightSaveData lightData[0];

    int Render(const char *label);

    static constexpr uint8_t SAVED_ID = SAVED_ID_UNITLIGHTDATA;
};

}; // namespace TRSE