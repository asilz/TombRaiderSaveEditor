#pragma once

#include <trse/Hash.hpp>
#include <trse/SaveInfo.hpp>

namespace TRSE
{

struct SavedActionGraph
{
    int64_t _padding_[2];
    struct PlacementHashKey hashKey;
    uint16_t msgQueueSize;
    uint16_t processQueueSize;
    uint16_t postProcessQueueSize;
    uint16_t nodeStreamSize;

    static constexpr uint8_t SAVED_ID = SAVED_ID_ACTIONGRAPH;

    int Render(const char *label);
};

}; // namespace TRSE