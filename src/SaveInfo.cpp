#include <cinttypes>
#include <cstdio>
#include <imgui.h>
#include <trse/SaveInfo.hpp>
#include <trse/gui/Render.hpp>
#include <trse/saved/ActionGraph.hpp>
#include <trse/saved/BasicInstance.hpp>
#include <trse/saved/Campsites.hpp>
#include <trse/saved/ColdDarkness.hpp>
#include <trse/saved/CustomizationData.hpp>
#include <trse/saved/DeadDeadList.hpp>
#include <trse/saved/DeadDeadUnitList.hpp>
#include <trse/saved/GameStateTimer.hpp>
#include <trse/saved/Level.hpp>
#include <trse/saved/MapData.hpp>
#include <trse/saved/MissionObjectives.hpp>
#include <trse/saved/ObjectZoneInstance.hpp>
#include <trse/saved/ObjectZonePlacement.hpp>
#include <trse/saved/PlacementVarInstance.hpp>
#include <trse/saved/PlayerData.hpp>
#include <trse/saved/ProgressionData.hpp>
#include <trse/saved/RegionData.hpp>
#include <trse/saved/StreamLayerQueue.hpp>
#include <trse/saved/StreamLayers.hpp>
#include <trse/saved/UnitLightData.hpp>
#include <trse/saved/UnitLoadState.hpp>
#include <zlib.h>

namespace TRSE
{

static constexpr unsigned int SAVE_INFO_SIZE = 0x400000;

int SaveInfo::ExtractSaveInfo(const unsigned char *input, unsigned int input_size)
{
    printf("Zlib version: %s\n", ZLIB_VERSION);

    z_stream infstream;
    infstream.zalloc = Z_NULL;
    infstream.zfree = Z_NULL;
    infstream.opaque = Z_NULL;
    infstream.avail_in = input_size;      // size of input
    infstream.next_in = input;            // input char array
    infstream.avail_out = SAVE_INFO_SIZE; // size of output
    infstream.next_out =
        reinterpret_cast<Bytef *>(this); // This is undefined behaviour, but I think this is what the game does

    int ret = inflateInit2(&infstream, 0xf); // 0xf because this is what rise does
    if (ret)
    {
        return ret;
    }

    ret = inflate(&infstream, Z_FINISH); // defined to 4 in Rise. Probably Z_FINISH
    if (ret != Z_STREAM_END)
    {
        return ret;
    }

    return 0;
}

int SaveInfo::PackSaveInfo(unsigned char *output, unsigned int *output_size)
{
    z_stream infstream;
    infstream.zalloc = Z_NULL;
    infstream.zfree = Z_NULL;
    infstream.opaque = Z_NULL;
    infstream.avail_in = SAVE_INFO_SIZE;
    infstream.next_in = reinterpret_cast<Bytef *>(this);
    infstream.avail_out = *output_size;
    infstream.next_out = output;

    int err = deflateInit(&infstream, Z_DEFAULT_COMPRESSION);
    if (err)
    {
        return err;
    }

    err = deflate(&infstream, Z_FINISH);

    deflateEnd(&infstream);
    *output_size = infstream.total_out;
    if (err != Z_STREAM_END)
    {
        return -5;
    }

    return 0;
}

int SaveInfo::SetBackwardCompatible(void)
{
    m_infoSize = m_infoSize & 0xffffff;
    return 0;
}

int SystemTime::Render(const char *label)
{
    if (ImGui::TreeNode(label))
    {
        GUI::Render(m_ordinal, "m_ordinal");
        GUI::Render(m_year, "m_year");
        GUI::Render(m_milliseconds, "m_milliseconds");
        GUI::Render(m_month, "m_month");
        GUI::Render(m_dayOfWeek, "m_dayOfWeek");
        GUI::Render(m_day, "m_day");
        GUI::Render(m_hour, "m_hour");
        GUI::Render(m_minute, "m_minute");
        GUI::Render(m_second, "m_second");

        ImGui::TreePop();
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}

int SaveProgressData::Render(const char *label)
{
    if (ImGui::TreeNode(label))
    {
        GUI::Render(m_saveTime, "m_saveTime");
        GUI::Render(m_playTime, "m_playTime");
        GUI::Render(m_regionIndex, "m_regionIndex");
        GUI::Render(m_corrupted, "m_corrupted");
        GUI::Render(m_globalProgressLevel, "m_globalProgressLevel");
        GUI::Render(m_percentComplete, "m_percentComplete");
        GUI::Render(m_percentInstalled, "m_percentInstalled");
        GUI::Render(m_gameDifficulty, "m_gameDifficulty");

        ImGui::TreePop();
        return TRSE_RET_IMGUI_EDIT;
    }
    return 0;
}

int SaveInfo::Render(const char *label)
{
    ImGui::Text(label);
    int i = 0;
    int ret = 0;

    GUI::Render(m_saveProgressData, "m_saveProgressData");

    // TODO: Figure out why newer binary seems to use 24 bits of info size for the actual size
    for (uint8_t *info = m_infoStart; info < m_infoStart + (m_infoSize & 0xffffff);
         info = info + (*(reinterpret_cast<uint32_t *>(info)) >> 6 & 0x3fffffc))
    {

        ImGui::PushID(i++);
        switch (*info)
        {
        case SavedActionGraph::SAVED_ID:
            ret = reinterpret_cast<SavedActionGraph *>(info)->Render("SavedActionGraph");
            break;
        case SavedBasicInstance::SAVED_ID:
            ret = reinterpret_cast<SavedBasicInstance *>(info)->Render("SavedBasicInstance");
            break;
        case SavedCampsites::SAVED_ID:
            ret = reinterpret_cast<SavedCampsites *>(info)->Render("SavedCampsites");
            break;
        case SavedColdDarknessData::SAVED_ID:
            ret = reinterpret_cast<SavedColdDarknessData *>(info)->Render("SavedColdDarknessData");
            break;
        case SavedCustomizationData::SAVED_ID:
            ret = reinterpret_cast<SavedCustomizationData *>(info)->Render("SavedCustomizationData");
            break;
        case SavedDeadDeadList::SAVED_ID:
            ret = reinterpret_cast<SavedDeadDeadList *>(info)->Render("SavedDeadDeadList");
            break;
        case SavedDeadDeadUnitList::SAVED_ID:
            ret = reinterpret_cast<SavedDeadDeadUnitList *>(info)->Render("SavedDeadDeadUnitList");
            break;
        case SavedGameStateTimer::SAVED_ID:
            ret = reinterpret_cast<SavedGameStateTimer *>(info)->Render("SavedGameStateTimer");
            break;
        case SavedLevel::SAVED_ID:
            ret = reinterpret_cast<SavedLevel *>(info)->Render("SavedLevel");
            break;
        case SavedMapData::SAVED_ID:
            ret = reinterpret_cast<SavedMapData *>(info)->Render("SavedMapData");
            break;
        case SavedMissionObjectives::SAVED_ID:
            ret = reinterpret_cast<SavedMissionObjectives *>(info)->Render("SavedMissionObjectives");
            break;
        case SavedObjectZoneInstance::SAVED_ID:
            ret = reinterpret_cast<SavedObjectZoneInstance *>(info)->Render("SavedObjectZoneInstance");
            break;
        case SavedObjectZonePlacement::SAVED_ID:
            ret = reinterpret_cast<SavedObjectZonePlacement *>(info)->Render("SavedObjectZonePlacement");
            break;
        case SavedPlacementVarInstance::SAVED_ID:
            ret = reinterpret_cast<SavedPlacementVarInstance *>(info)->Render("SavedPlacementVarInstance");
            break;
        case SavedPlayerData::SAVED_ID:
            ret = reinterpret_cast<SavedPlayerData *>(info)->Render("SavedPlayerData");
            break;
        case SavedProgressionData::SAVED_ID:
            ret = reinterpret_cast<SavedProgressionData *>(info)->Render("SavedProgressionData");
            break;
        case SavedRegionData::SAVED_ID:
            ret = reinterpret_cast<SavedRegionData *>(info)->Render("SavedRegionData");
            break;
        case SavedStreamLayerQueue::SAVED_ID:
            ret = reinterpret_cast<SavedStreamLayerQueue *>(info)->Render("SavedStreamLayerQueue");
            break;
        case SavedStreamLayers::SAVED_ID:
            ret = reinterpret_cast<SavedStreamLayers *>(info)->Render("SavedStreamLayers");
            break;
        case SavedUnitLightData::SAVED_ID:
            ret = reinterpret_cast<SavedUnitLightData *>(info)->Render("SavedUnitLightData");
            break;
        case SavedUnitLoadState::SAVED_ID:
            ret = reinterpret_cast<SavedUnitLoadState *>(info)->Render("SavedUnitLoadState");
            break;

        default:
            ret = 0;
            break;
        }
        ImGui::PopID();
    }

    return ret;
}
}; // namespace TRSE