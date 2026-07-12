// The day/night system is a slightly-modified port from Diegoisawesome's CrystalDust project.
// The debug features are stripped out, along with some field effects that preserve original palette for emote bubbles.
// Trihard is also not currently taking advantage of the palette override system, which lets you
// do things like lit windows at night--the functionality is all there, though, and it's slightly modified from CrystalDust, in that
// you only specify the time of day enum, rather than an hour range.

#include "global.h"
#include "day_night.h"
#include "decompress.h"
#include "event_data.h"
#include "field_tasks.h"
#include "field_weather.h"
#include "overworld.h"
#include "palette.h"
#include "rtc.h"
#include "strings.h"
#include "string_util.h"
#include "constants/day_night.h"
#include "constants/rgb.h"

#define TINT_MORNING Q_8_8(0.8), Q_8_8(0.7), Q_8_8(0.9)
#define TINT_DAY Q_8_8(1.0), Q_8_8(1.0), Q_8_8(1.0)
#define TINT_NIGHT Q_8_8(0.6), Q_8_8(0.55), Q_8_8(1.0)

EWRAM_DATA u16 gPlttBufferPreDN[PLTT_BUFFER_SIZE] = {0};
static EWRAM_DATA s8 sOldHour = 0;
static EWRAM_DATA u8 sOldSeason = 0;
static EWRAM_DATA bool8 sRetintPhase = FALSE;
EWRAM_DATA struct PaletteOverride *gPaletteOverrides[4] = {NULL};

static const u16 sTimeOfDayTints[][3] = {
    {TINT_NIGHT},       // Midnight
    {TINT_NIGHT},       // 1 AM
    {TINT_NIGHT},       // 2 AM
    {TINT_NIGHT},       // 3 AM
    {Q_8_8(0.6), Q_8_8(0.6), Q_8_8(1.0)},     // 4 AM
    {TINT_MORNING},     // 5 AM
    {TINT_MORNING},     // 6 AM
    {TINT_MORNING},     // 7 AM
    {Q_8_8(0.9), Q_8_8(0.8), Q_8_8(1.0)},     // 8 AM
    {Q_8_8(1.0), Q_8_8(0.9), Q_8_8(1.0)},     // 9 AM
    {TINT_DAY},         // 10 AM
    {TINT_DAY},         // 11 AM
    {TINT_DAY},         // 12 PM
    {TINT_DAY},         // 1 PM
    {TINT_DAY},         // 2 PM
    {TINT_DAY},         // 3 PM
    {TINT_DAY},         // 4 PM
    {Q_8_8(1.0), Q_8_8(0.9), Q_8_8(0.8)},   // 5 PM
    {Q_8_8(0.9), Q_8_8(0.6), Q_8_8(0.67)},       // 6 PM
    {Q_8_8(0.7), Q_8_8(0.6), Q_8_8(0.9)},       // 7 PM
    {TINT_NIGHT},       // 8 PM
    {TINT_NIGHT},       // 9 PM
    {TINT_NIGHT},       // 10 PM
    {TINT_NIGHT},       // 11 PM
};

// Seasons. The intro asks which season you want and the Blue Nurse lets you change it,
// and until now VAR_CURRENT_SEASON had no reader anywhere -- the game said "You will play
// in Spring!" and looked identical all year. 2.X renders seasons in engine code we do not
// have, and the donor ships no seasonal art, so there is nothing to import.
//
// Instead, layer a season on the day/night tint that already exists: these are RGB scale
// factors multiplied into the hour's tone before the palette is recoloured. Outdoors only
// (ShouldTintOverworld), so interiors are untouched. Kept subtle -- this shades the world,
// it does not repaint it.
static const u16 sSeasonTints[NUM_SEASONS][3] = {
    [SEASON_SPRING] = {Q_8_8(1.00), Q_8_8(1.05), Q_8_8(0.97)},  // fresh, a little green
    [SEASON_SUMMER] = {Q_8_8(1.07), Q_8_8(1.03), Q_8_8(0.93)},  // bright and warm
    [SEASON_AUTUMN] = {Q_8_8(1.10), Q_8_8(0.93), Q_8_8(0.78)},  // amber
    [SEASON_WINTER] = {Q_8_8(0.88), Q_8_8(0.94), Q_8_8(1.12)},  // cold and blue
};

u8 GetCurrentSeason(void)
{
    u16 season = VarGet(VAR_CURRENT_SEASON);

    if (season >= NUM_SEASONS)
        return SEASON_SPRING;

    return season;
}

// The hour's tone scaled by the season's. Both are Q8.8, so divide back down by 256.
static u16 GetDayNightTone(s8 hour, u8 channel)
{
    u32 tone = (u32)sTimeOfDayTints[hour][channel] * sSeasonTints[GetCurrentSeason()][channel];

    return tone >> 8;
}

const u8 *const gDayOfWeekTable[] =
{
    gText_Sunday,
    gText_Monday,
    gText_Tuesday,
    gText_Wednesday,
    gText_Thursday,
    gText_Friday,
    gText_Saturday
};

bool8 IsCurrentlyDay(void)
{
    if(!FlagGet(FLAG_IS_DAYNIGHT_INVERTED)){
		if (gLocalTime.hours >= 6 && gLocalTime.hours < 18)
			return TRUE;
		return FALSE;
	}
	else{
		if (gLocalTime.hours >= 6 && gLocalTime.hours < 18)
			return FALSE;
		return TRUE;
	}
}

bool8 IsCurrentlyDusk(void)
{
    if((!FlagGet(FLAG_IS_DAYNIGHT_INVERTED) && gLocalTime.hours == 17) ||
	    (FlagGet(FLAG_IS_DAYNIGHT_INVERTED) && gLocalTime.hours == 5))
		return TRUE;
	else
		return FALSE;
}

u8 GetCurrentTimeOfDay(void)
{
    return GetTimeOfDay(gLocalTime.hours);
}

u8 GetTimeOfDay(s8 hours)
{
    if(!FlagGet(FLAG_IS_DAYNIGHT_INVERTED)){
		if (hours < TIME_MORNING_HOUR)
			return TIME_NIGHT;
		else if (hours < TIME_DAY_HOUR)
			return TIME_MORNING;
		else if (hours < TIME_SUNSET_HOUR)
			return TIME_DAY;
		else if (hours < TIME_NIGHT_HOUR)
			return TIME_SUNSET;
		else
			return TIME_NIGHT;
	}
	else{
		if (hours < TIME_MORNING_HOUR)
			return TIME_DAY;
		else if (hours < TIME_DAY_HOUR)
			return TIME_SUNSET;
		else if (hours < TIME_SUNSET_HOUR)
			return TIME_NIGHT;
		else if (hours < TIME_NIGHT_HOUR)
			return TIME_MORNING;
		else
			return TIME_DAY;
	}
}

const u8 *GetDayOfWeekString(u8 dayOfWeek)
{
    return gDayOfWeekTable[dayOfWeek];
}

const u8 GetTimeOfDayString()
{
	return gLocalTime.hours;
}

u8 GetTimeOfDayHours()
{
	if(!FlagGet(FLAG_IS_DAYNIGHT_INVERTED)) // Normal Time
		return gLocalTime.hours;
	else if(gLocalTime.hours >= 12)			//Inverted Time
		return gLocalTime.hours - 12;
	else									//Inverted Time
		return gLocalTime.hours + 12;
}

void CopyDayOfWeekStringToVar1(void)
{
    if (gSpecialVar_0x8004 <= DAY_SATURDAY)
        StringCopy(gStringVar1, gDayOfWeekTable[gSpecialVar_0x8004]);
    else
        StringCopy(gStringVar1, gText_None);
}

void CopyCurrentDayOfWeekStringToVar1(void)
{
    RtcCalcLocalTime();
    if (gLocalTime.dayOfWeek <= DAY_SATURDAY)
        StringCopy(gStringVar1, gDayOfWeekTable[gLocalTime.dayOfWeek]);
    else
        StringCopy(gStringVar1, gText_None);
}

static void LoadPaletteOverrides(void)
{
    u8 i, j;
    const u16* src;
    u16* dest;
    u8 curTimeOfDay = GetCurrentTimeOfDay();

    for (i = 0; i < ARRAY_COUNT(gPaletteOverrides); i++)
    {
        const struct PaletteOverride *curr = gPaletteOverrides[i];
        if (curr != NULL)
        {
            while (curr->slot != PALOVER_LIST_TERM && curr->palette != NULL)
            {
                if (curr->timeOfDay == curTimeOfDay)
                {
                    for (j = 0, src = curr->palette, dest = gPlttBufferUnfaded + (curr->slot * 16); j < 16; j++, src++, dest++)
                    {
                        if (*src != RGB_BLACK)
                            *dest = *src;
                    }
                }
                curr++;
            }
        }
    }
}

bool8 ShouldTintOverworld(void)
{
    if (IsMapTypeOutdoors(gMapHeader.mapType))
        return TRUE;

    // more conditions?
    return FALSE;
}

void TintPaletteForDayNight(u16 offset, u16 size)//check
{
    
	if (ShouldTintOverworld())
    {
        s8 hour;
        RtcCalcLocalTimeFast();
        hour = GetTimeOfDayHours();
        TintPalette_CustomToneWithCopy(gPlttBufferPreDN + offset, gPlttBufferUnfaded + offset, size / 2, GetDayNightTone(hour, 0), GetDayNightTone(hour, 1), GetDayNightTone(hour, 2), FALSE);
    }
    else
    {
        CpuCopy16(gPlttBufferPreDN + offset, gPlttBufferUnfaded + offset, size);
    }
    LoadPaletteOverrides();
}

static void TintPlayerPaletteForDayNight(u16 offset, u16 size)//check
{
    
	//ShouldTintOverworld()
    s8 hour;
    RtcCalcLocalTimeFast();
    hour = GetTimeOfDayHours();
    SetCharacterPalette(gPlttBufferPreDN + offset, gPlttBufferUnfaded + offset, size / 2, GetDayNightTone(hour, 0), GetDayNightTone(hour, 1), GetDayNightTone(hour, 2), FALSE);
    
    LoadPaletteOverrides();
}

static void TintOpponentPaletteForDayNight(u16 offset, u16 size)
{
    s8 hour;
    RtcCalcLocalTimeFast();
    hour = GetTimeOfDayHours();
    SetPasswordTrainerPalette(gPlttBufferPreDN + offset, gPlttBufferUnfaded + offset);
    LoadPaletteOverrides();
}

static void ChangePlayerTrainerPalette(u16 offset, u16 size)//check
{
    
	//ShouldTintOverworld()
    s8 hour;
    RtcCalcLocalTimeFast();
    hour = GetTimeOfDayHours();
    SetCharacterTrainerPalette(gPlttBufferPreDN + offset, gPlttBufferUnfaded + offset, size / 2);
    
    LoadPaletteOverrides();
}

void LoadCompressedPaletteDayNight(const void *src, u16 offset, u16 size)
{
    LZDecompressWram(src, gPaletteDecompressionBuffer);
    CpuCopy16(gPaletteDecompressionBuffer, gPlttBufferPreDN + offset, size);
    TintPaletteForDayNight(offset, size);
    CpuCopy16(gPlttBufferUnfaded + offset, gPlttBufferFaded + offset, size);
}

void LoadPaletteDayNight(const void *src, u16 offset, u16 size)
{
    CpuCopy16(src, gPlttBufferPreDN + offset, size);
    TintPaletteForDayNight(offset, size);
    CpuCopy16(gPlttBufferUnfaded + offset, gPlttBufferFaded + offset, size);
}

void LoadPlayerPaletteDayNight(const void *src, u16 offset, u16 size)
{
    CpuCopy16(src, gPlttBufferPreDN + offset, size);
    TintPlayerPaletteForDayNight(offset, size);
    CpuCopy16(gPlttBufferUnfaded + offset, gPlttBufferFaded + offset, size);
}

void LoadOpponentPaletteDayNight(const void *src, u16 offset, u16 size)
{
    CpuCopy16(src, gPlttBufferPreDN + offset, size);
    TintOpponentPaletteForDayNight(offset, size);
    CpuCopy16(gPlttBufferUnfaded + offset, gPlttBufferFaded + offset, size);
}

void LoadPlayerTrainerPalette(const void *src, u16 offset, u16 size)
{
    CpuCopy16(src, gPlttBufferPreDN + offset, size);
    ChangePlayerTrainerPalette(offset, size);
    CpuCopy16(gPlttBufferUnfaded + offset, gPlttBufferFaded + offset, size);
}

void CheckClockForImmediateTimeEvents(void)
{
    if (ShouldTintOverworld() && !sRetintPhase)
        RtcCalcLocalTimeFast();
}

void ProcessImmediateTimeEvents(void)
{
    s8 hour;
    u8 season;

    if (ShouldTintOverworld())
    {
        if (!sRetintPhase)
        {
            hour = GetTimeOfDayHours();
            season = GetCurrentSeason();
            // Also retint when the SEASON changes, not just the hour -- otherwise picking a
            // new season at the Pokemon Center would not repaint until the clock ticked over.
            if (hour != sOldHour || season != sOldSeason)
            {
                sOldHour = hour;
                sOldSeason = season;
                sRetintPhase = 1;
				//SetCharacterPaletteDayNight     (gPlttBufferPreDN, gPlttBufferUnfaded, BG_PLTT_SIZE / 2, GetDayNightTone(hour, 0), GetDayNightTone(hour, 1), GetDayNightTone(hour, 2), TRUE);
                TintPalette_CustomToneWithCopy(gPlttBufferPreDN, gPlttBufferUnfaded, BG_PLTT_SIZE / 2, GetDayNightTone(hour, 0), GetDayNightTone(hour, 1), GetDayNightTone(hour, 2), TRUE);
			}
        }
        else
        {
            sRetintPhase = 0;
			SetCharacterPaletteDayNight     (gPlttBufferPreDN + (BG_PLTT_SIZE / 2), gPlttBufferUnfaded + (BG_PLTT_SIZE / 2), OBJ_PLTT_SIZE / 2, GetDayNightTone(sOldHour, 0), GetDayNightTone(sOldHour, 1), GetDayNightTone(sOldHour, 2), TRUE);
			//TintPalette_CustomToneWithCopy(gPlttBufferPreDN + (BG_PLTT_SIZE / 2), gPlttBufferUnfaded + (BG_PLTT_SIZE / 2), OBJ_PLTT_SIZE / 2, GetDayNightTone(sOldHour, 0), GetDayNightTone(sOldHour, 1), GetDayNightTone(sOldHour, 2), TRUE);
            LoadPaletteOverrides();
            if (gWeatherPtr->palProcessingState != WEATHER_PAL_STATE_SCREEN_FADING_IN &&
                gWeatherPtr->palProcessingState != WEATHER_PAL_STATE_SCREEN_FADING_OUT)
                CpuCopy16(gPlttBufferUnfaded, gPlttBufferFaded, PLTT_SIZE);
				
			
            ChooseAmbientCrySpecies();  // so a time-of-day appropriate mon is chosen
            ForceTimeBasedEvents();     // for misc events that should run on time of day boundaries
        }
    }
}

void DoLoadSpritePaletteDayNight(const u16 *src, u16 paletteOffset)
{
    LoadPaletteDayNight(src, paletteOffset + 0x100, 32);
}

void DoLoadPlayerSpritePaletteDayNight(const u16 *src, u16 paletteOffset)//player
{
    LoadPlayerPaletteDayNight(src, paletteOffset + 0x100, 32);
}

void DoLoadOpponentSpritePaletteDayNight(const u16 *src, u16 paletteOffset)//Opponent Trainer
{
    LoadOpponentPaletteDayNight(src, paletteOffset + 0x100, 32);
}