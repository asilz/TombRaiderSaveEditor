#pragma once

#include <trse/Hash.hpp>
#include <trse/SaveInfo.hpp>

namespace TRSE
{

struct StreamLayerStates // TODO: Figure out the contents
{
    uint8_t data[0x30];
};

struct SavedStreamLayerData
{
    struct PlacementHashKey placementID;
    int numStreamLayers;
    struct StreamLayerStates active;
    struct StreamLayerStates loadRequested;
};

struct SavedStreamLayers
{
    int64_t _padding_[2];
    struct StreamLayerStates globalChanged;
    struct StreamLayerStates globalLoaded;
    struct StreamLayerStates globalActive;
    int numPlacements;
    struct SavedStreamLayerData streamLayerData[0];

    static constexpr uint8_t SAVED_ID = SAVED_ID_STREAMLAYERDATA;
};
}; // namespace TRSE