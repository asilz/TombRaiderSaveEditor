#pragma once

#include <trse/Hash.hpp>
#include <trse/SaveInfo.hpp>

namespace TRSE
{

typedef enum StreamLayerAction
{
    NoAction = 0,
    Load = 1,
    Activate = 2,
    Deactivate = 3,
    Hide = 4,
    LoadAndHide = 5
} StreamLayerAction;

struct QueuedStreamLayerActions
{
    enum StreamLayerAction actions[384];
};

struct SavedStreamLayerQueueElem
{
    struct PlacementHashKey hashKey;
    struct QueuedStreamLayerActions actions;
};

struct SavedStreamLayerQueue
{
    int64_t _padding_[2];
    int count;
    struct SavedStreamLayerQueueElem queue[0];

    static constexpr uint8_t SAVED_ID = SAVED_ID_STREAMLAYERQUEUEDATA;
};
}; // namespace TRSE