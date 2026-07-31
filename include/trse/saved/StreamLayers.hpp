#pragma once

#include <trse/Hash.hpp>
#include <trse/SaveInfo.hpp>

namespace TRSE
{

struct StreamLayerStates // TODO: Figure out the contents
{
    uint8_t data[0x30];

    int Render(const char *label);
};

struct SavedStreamLayerData
{
    struct PlacementHashKey placementID;
    int numStreamLayers;
    struct StreamLayerStates active;
    struct StreamLayerStates loadRequested;

    int Render(const char *label);
};

struct SavedStreamLayers
{
    int64_t _padding_[2];
    struct StreamLayerStates globalChanged;
    struct StreamLayerStates globalLoaded;
    struct StreamLayerStates globalActive;
    int32_t numPlacements;
    struct SavedStreamLayerData streamLayerData[0];

    int Render(const char *label);

    static constexpr uint8_t SAVED_ID = SAVED_ID_STREAMLAYERDATA;
};
}; // namespace TRSE