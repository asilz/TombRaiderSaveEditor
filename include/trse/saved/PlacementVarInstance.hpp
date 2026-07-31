#pragma once

#include <trse/Hash.hpp>
#include <trse/SaveInfo.hpp>

namespace TRSE
{

struct SavedPlacementVarInstance
{
    int64_t _padding_[2];
    struct PlacementHashKey hashKey;

    int Render(const char *label);

    static constexpr uint8_t SAVED_ID = SAVED_ID_PLACEMENTVAR_INSTANCE;
};

}; // namespace TRSE