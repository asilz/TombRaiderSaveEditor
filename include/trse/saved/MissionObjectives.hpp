#pragma once

#include <trse/SaveInfo.hpp>

namespace TRSE
{

typedef enum ObjectiveStateType
{
    ObjectiveStateType_Inactive = 0,
    ObjectiveStateType_Active = 1,
    ObjectiveStateType_Pass = 2,
    ObjectiveStateType_Fail = 3,
    ObjectiveStateType_MAX = 4,
    ObjectiveStateType_None = 4294967295
} ObjectiveStateType;

struct ScriptObjectiveType
{
    uint32_t objectiveType;

    int Render(const char *label);
};

struct MissionObjectiveData
{
    struct ScriptObjectiveType m_type;
    enum ObjectiveStateType m_state;
    int m_count;
    float m_activatedCoordinateX;
    float m_activatedCoordinateY;
    int m_activatedUnit;
    bool m_viewedMission;
    bool m_forceShowOnMap;

    int Render(const char *label);
};

struct SavedMissionObjectives
{
    int64_t _padding_[2];
    int32_t objectivesCount;
    uint32_t currentObjective;
    struct MissionObjectiveData objectiveData[0];

    int Render(const char *label);

    static constexpr uint8_t SAVED_ID = SAVED_ID_MISSIONOBJECTIVES;
};

}; // namespace TRSE