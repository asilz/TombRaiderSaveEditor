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

    int Render(const char *label);
};

struct SavedStreamLayerQueueElem
{
    struct PlacementHashKey hashKey;
    struct QueuedStreamLayerActions actions;

    int Render(const char *label);
};

struct SavedStreamLayerQueue
{
    int64_t _padding_[2];
    int32_t count;
    struct SavedStreamLayerQueueElem queue[0];

    int Render(const char *label);

    static constexpr uint8_t SAVED_ID = SAVED_ID_STREAMLAYERQUEUEDATA;
};
}; // namespace TRSE