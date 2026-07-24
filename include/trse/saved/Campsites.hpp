#pragma once

#include <trse/SaveInfo.hpp>

namespace TRSE
{

struct CampsiteID
{
    uint32_t m_campsiteID;

    int Render(const char *label);
};

typedef enum CampsiteState
{
    CampsiteState_NotFound = 0,
    CampsiteState_Found_Unlit = 1,
    CampsiteState_Discovered = 2,
    CampsiteState_Tomb_Raided = 3
} CampsiteState;

struct CampsiteData
{
    struct CampsiteID m_id;
    enum CampsiteState m_state;
    int m_progressionIndex;
    bool m_visited;
    bool m_viewedInCampsite;

    int Render(const char *label);
};

struct SavedCampsites
{
    int64_t _padding_[2];
    struct CampsiteID currentCampsite;
    struct CampsiteID forwardCampsite;
    int campsitesCount;
    struct CampsiteData campsiteData[0];

    static constexpr uint8_t SAVED_ID = SAVED_ID_CAMPSITES;

    int Render(const char *label);
};

}; // namespace TRSE