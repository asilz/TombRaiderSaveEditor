#pragma once

#include <cinttypes>
#include <type_traits>

namespace TRSE
{

struct SystemTime
{
    uint64_t m_ordinal;
    uint16_t m_year;
    uint16_t m_milliseconds;
    uint8_t m_month;
    uint8_t m_dayOfWeek;
    uint8_t m_day;
    uint8_t m_hour;
    uint8_t m_minute;
    uint8_t m_second;

    int Render(const char *label);
};

struct SaveProgressData
{
    struct SystemTime m_saveTime;
    uint32_t m_playTime;
    uint32_t m_regionIndex;
    bool m_corrupted;
    int32_t m_globalProgressLevel;
    float m_percentComplete;
    float m_percentInstalled;
    uint8_t m_gameDifficulty;

    int Render(const char *label);
};

struct BlockInfo
{
    uint32_t size;
    uint32_t count;
};

struct SaveDataSizeInfo
{
    struct BlockInfo blockInfo[29];
    struct BlockInfo total;
};

struct RetroSave
{
    uint64_t data[0xF56];
};

struct SavedBasic;

typedef enum SavedIDEnums
{
    SAVED_ID_NONE = 0,
    SAVED_ID_DELETED = 1,
    SAVED_ID_LEVEL = 2,
    SAVED_ID_BASIC_INSTANCE = 3,
    SAVED_ID_OBJECTZONE_INSTANCE = 4,
    SAVED_ID_OBJECTZONE_PLACEMENT = 5,
    SAVED_ID_INSTANCE_SPLINE = 6,
    SAVED_ID_GAME_SPECIFIC = 7,
    SAVED_ID_STICKY_BOOLS = 8,
    SAVED_ID_STICKY_INTS = 9,
    SAVED_ID_STICKY_FLOATS = 10,
    SAVED_ID_STREAMLAYERDATA = 11,
    SAVED_ID_STREAMLAYERQUEUEDATA = 12,
    SAVED_ID_CUSTOMIZATIONDATA = 13,
    SAVED_ID_ACTIONGRAPH = 14,
    SAVED_ID_MISSIONOBJECTIVES = 15,
    SAVED_ID_REGIONDATA = 16,
    SAVED_ID_PLAYERDATA = 17,
    SAVED_ID_UNITLOADSTATE = 18,
    SAVED_ID_CAMPSITES = 19,
    SAVED_ID_MAP = 20,
    SAVED_ID_UNITLIGHTDATA = 21,
    SAVED_ID_DEADDEADLIST = 22,
    SAVED_ID_DEADDEADUNITLIST = 23,
    SAVED_ID_PLACEMENTVAR_INSTANCE = 24,
    SAVED_ID_ACTIVE_OBJECTIVES = 25,
    SAVED_ID_GAMESTATE_TIMER = 26,
    SAVED_ID_PROGRESSION_DATA = 27,
    SAVED_ID_COLD_DARKNESS = 28,
    SAVED_ID_MAX_IDS = 29
} SavedIDEnums;

struct SaveInfo
{
    struct SaveProgressData m_saveProgressData;
    struct RetroSave m_retroSave;
    uint32_t m_infoSize;
    uint8_t m_infoStart[4162828];
    struct SavedBasic *m_firstDeleteBlock;
    uint32_t m_magicNumber;
    struct SaveDataSizeInfo m_sizeInfo;
    uint32_t m_liveInstanceBlockMarker;

    int ExtractSaveInfo(const unsigned char *input, unsigned int input_size);

    int PackSaveInfo(unsigned char *output, unsigned int *output_size);

    int SetBackwardCompatible(void);

    template <typename T> T *GetBlock()
    {
        for (uint8_t *info = m_infoStart; info < m_infoStart + m_infoSize;
             info = info + (*(reinterpret_cast<uint32_t *>(info)) >> 6 & 0x3fffffc))
        {
            if (*info == T::SAVED_ID)
            {
                return reinterpret_cast<T *>(info);
            }
        }
        return nullptr;
    }

    int Render(const char *label);
};

}; // namespace TRSE