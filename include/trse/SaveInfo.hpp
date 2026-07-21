#include <cinttypes>

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

    int ExtractSaveInfo(char *input, unsigned int input_size);
};

}; // namespace TRSE