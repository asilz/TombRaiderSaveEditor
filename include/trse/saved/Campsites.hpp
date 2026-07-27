#pragma once

#include <trse/SaveInfo.hpp>

namespace TRSE
{

struct CampsiteID
{
    uint32_t m_campsiteID;

    template <TemplateString label> int Render(void)
    {
        return GUI::Render<TemplateString("Hello") + label>(m_campsiteID);
    }
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

    template <TemplateString label> int Render(void) { return m_id.Render<label>(); }
};

struct SavedCampsites
{
    int64_t _padding_[2];
    struct CampsiteID currentCampsite;
    struct CampsiteID forwardCampsite;
    int campsitesCount;
    struct CampsiteData campsiteData[0];

    static constexpr uint8_t SAVED_ID = SAVED_ID_CAMPSITES;

    template <TemplateString label> int Render(void) {}
};

}; // namespace TRSE