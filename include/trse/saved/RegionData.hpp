#pragma once

#include <trse/Hash.hpp>
#include <trse/SaveInfo.hpp>

namespace TRSE
{

struct HuntManagerInfo
{
    struct PlacementHashKey m_huntManagerPlacement;
    float m_deathTimes[25][6];
};

struct ScriptObjectiveType
{
    uint32_t objectiveType;
};

typedef enum FastTravelState
{
    k_fastTravelStateLost = 0,
    k_fastTravelStateCharted = 1
} FastTravelState;

typedef enum TimeOfDayEnum
{
    k_timeOfDayNight = 0,
    k_timeOfDayDawn = 1,
    k_timeOfDayDay = 2,
    k_timeOfDayDusk = 3,
    k_timeOfDayNumTimes = 4
} TimeOfDayEnum;

typedef enum RegionStateEnum
{
    k_regionStateNeverBeenHere = 0,
    k_regionStateFirstTraversal = 1,
    k_regionStateFirstTraversal_HubArrival = 2,
    k_regionStateFirstTraversal_SignificantEvent = 3,
    k_regionStateSecondTraversal = 4,
    k_regionStateThirdTraversal = 5,
    k_regionStatePostStory = 6,
    k_regionStatePostGame = 7
} RegionStateEnum;

struct RegionInfo
{
    uint32_t m_regionID;
    enum FastTravelState m_fastTravelState;
    enum TimeOfDayEnum m_timeOfDay;
    enum RegionStateEnum m_regionState;
    uint32_t m_regionStateIndex;
    uint32_t m_salvageFromHunting;
    uint32_t m_salvageFromEnemies;
    uint32_t m_xpFromHunting;
    uint32_t m_xpFromPAC;
    uint32_t m_relics;
    uint32_t m_documents;
    uint32_t m_tombsRaided;
    uint32_t m_murals;
    uint32_t m_survivalCaches;
    uint32_t m_explorerCorpses;
    uint32_t m_documentChests;
    uint32_t m_strongboxes;
    uint32_t m_cryptTreasures;
    uint32_t m_ancientSeal;
    uint32_t m_codex;
    uint32_t m_monoliths;
    uint32_t m_missions;
    uint32_t m_regionLocalName;
    uint32_t m_brokenWeaponOpportunityTracking;
    uint32_t m_brokenWeaponsClaimed;
    uint32_t m_brokenWeaponOpportunities;
    int32_t m_brokenWeaponIndex;
    int32_t m_brokenWeaponIndexLimit;
    bool m_hideOnMap;
    bool m_allowStateDowngrades;
    float m_onMapCoordinateX;
    float m_onMapCoordinateY;
    float m_onMapAreaWidth;
    float m_onMapAreaHeight;
    bool m_isRetraversable;
    bool m_countsTowardPercentComplete;
    struct ScriptObjectiveType m_activeMissionID;
};

struct SavedRegionData
{
    int64_t _padding_[2];
    struct HuntManagerInfo huntManagerInfo[35];
    uint32_t numRegions;
    struct RegionInfo regions[0];

    static constexpr uint8_t SAVED_ID = SAVED_ID_REGIONDATA;
};

}; // namespace TRSE