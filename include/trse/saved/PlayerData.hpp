#pragma once

#include <trse/SaveInfo.hpp>

namespace TRSE
{
struct PlayerDialogueData
{
    uint64_t m_dialoguePackageData[3][512];
    bool m_dialogueSequenceData[3][3072];

    int Render(const char *label);
};

struct DocumentToClueLinker
{
    uint32_t documentID;
    uint32_t clueID;

    int Render(const char *label);
};

struct CollectibleInfo
{
    bool isUnlocked : 1;
    bool isInfoFound : 1;

    int Render(const char *label);
};

typedef enum SessionType
{
    SessionType_SinglePlayer = 0,
    SessionType_Multiplayer = 1,
    SessionType_Automatic = 2
} SessionType;

struct PlayerCollectibleData
{
    struct CollectibleInfo m_foundCollectibles[512];
    struct DocumentToClueLinker m_foundClues[64];
    short m_scheduledLootIndices[64];
    enum SessionType m_sessionType;

    int Render(const char *label);
};

struct PlayerPersistentData
{
    struct NetPlayerInfo *m_pOwner;
    bool m_traits[1024];
    struct PlayerCollectibleData m_collectibles;
    struct PlayerDialogueData m_dialogueData;
    bool m_hasDoneStatusScreenTutorial : 1;
    bool m_bHasCharacterProfileChanged : 1;
    bool m_bHasBeenToCampsiteSkillsHunter : 1;
    bool m_bHasBeenToCampsiteSkillsRanger : 1;
    bool m_bHasBeenToCampsiteSkillsSurvivor : 1;
    bool m_bHasBennInSurvivorDifficulty : 1;
    uint8_t m_characterProfileIndex;
    uint16_t m_numStandardSideTombCompleted;
    uint16_t m_numPurchasedTraits;
    uint16_t m_numPurchasedTraitsForMetrics;
    uint32_t m_overallCheckpointVisits;
    uint16_t m_numPurchasedTraitsForMetricsByType[14];
    uint8_t m_numArrowsCraftedOfType[4];
    uint32_t m_weaponsViewed[32];
    uint32_t m_activeChallengesProgress[8];

    int Render(const char *label);
};

struct PlayerPersistentSaveData
{
    struct PlayerPersistentData playerData;

    int Render(const char *label);
};

struct SavedPlayerData
{
    int64_t _padding_[2];
    int32_t playerDataCount;
    struct PlayerPersistentSaveData playerData[0];

    int Render(const char *label);

    static constexpr uint8_t SAVED_ID = SAVED_ID_PLAYERDATA;
};

}; // namespace TRSE