#include "global.h"
#include "battle_anim_81258BC.h"
#include "battle.h"
#include "battle_controllers.h"
#include "battle_interface.h"
#include "battle_message.h"
#include "data2.h"
#include "link.h"
#include "main.h"
#include "palette.h"
#include "constants/songs.h"
#include "sound.h"
#include "text.h"
#include "util.h"
#include "ewram.h"

extern struct Window gWindowTemplate_Contest_MoveDescription;
extern u8 gDisplayedStringBattle[];
extern u8 gActionSelectionCursor[];

extern const u8 BattleText_PlayerMenu[];
extern u8 gActiveBattler;
extern const u8 BattleText_MenuOptionsSafari[];

extern void *gBattlerControllerFuncs[];
extern u8 gBattleBufferA[][0x200];
extern bool8 gDoingBattleAnim;
extern u8 gBattlerSpriteIds[];
extern struct SpriteTemplate gCreatingSpriteTemplate;
extern u16 gBattleTypeFlags;
extern u32 gBattleControllerExecFlags;
extern u16 gSpecialVar_ItemId;
extern MainCallback gPreBattleCallback1;
extern u8 gBankInMenu;
extern u8 gHealthboxSpriteIds[];
extern u16 gBattlerPartyIndexes[];
extern u16 gIntroSlideFlags;
extern u8 gBattleOutcome;

extern u8 GetBattlerSide(u8);
extern u8 GetBattlerAtPosition(u8);
extern u8 GetBattlerPosition(u8);
extern void LoadPlayerTrainerBankSprite();
extern u8 GetBattlerSubpriority();
extern void sub_80313A0(struct Sprite *);
extern void sub_810BADC(void);
extern void StartBattleIntroAnim();
extern void sub_804777C();
extern bool8 move_anim_start_t3();

#define SUB_812BB10_TILE_DATA_OFFSET 440

// this file's functions
void SafariHandleGetAttributes(void);
void SafariHandlecmd1(void);
void SafariHandleSetAttributes(void);
void SafariHandlecmd3(void);
void SafariHandleLoadPokeSprite(void);
void SafariHandleSendOutPoke(void);
void SafariHandleReturnPokeToBall(void);
void SafariHandleTrainerThrow(void);
void SafariHandleTrainerSlide(void);
void SafariHandleTrainerSlideBack(void);
void SafariHandlecmd10(void);
void SafariHandlecmd11(void);
void SafariHandlecmd12(void);
void SafariHandleBallThrow(void);
void SafariHandlePuase(void);
void SafariHandleMoveAnimation(void);
void SafariHandlePrintString(void);
void SafariHandlePrintStringPlayerOnly(void);
void SafariHandlecmd18(void);
void SafariHandlecmd19(void);
void SafariHandlecmd20(void);
void SafariHandleOpenBag(void);
void SafariHandlecmd22(void);
void SafariHandlecmd23(void);
void SafariHandleHealthBarUpdate(void);
void SafariHandleExpBarUpdate(void);
void SafariHandleStatusIconUpdate(void);
void SafariHandleStatusAnimation(void);
void SafariHandleStatusXor(void);
void SafariHandlecmd29(void);
void SafariHandleDMATransfer(void);
void SafariHandlecmd31(void);
void SafariHandlecmd32(void);
void SafariHandlecmd33(void);
void SafariHandlecmd34(void);
void SafariHandlecmd35(void);
void SafariHandlecmd36(void);
void SafariHandlecmd37(void);
void SafariHandlecmd38(void);
void SafariHandlecmd39(void);
void SafariHandlecmd40(void);
void SafariHandleHitAnimation(void);
void SafariHandlecmd42(void);
void SafariHandleEffectivenessSound(void);
void SafariHandlecmd44(void);
void SafariHandleFaintingCry(void);
void SafariHandleIntroSlide(void);
void SafariHandleTrainerBallThrow(void);
void SafariHandlecmd48(void);
void SafariHandlecmd49(void);
void SafariHandlecmd50(void);
void SafariHandleSpriteInvisibility(void);
void SafariHandleBattleAnimation(void);
void SafariHandleLinkStandbyMsg(void);
void SafariHandleResetActionMoveSelection(void);
void SafariHandlecmd55(void);
void SafariHandlecmd56(void);

// const data
typedef void (*BattleBufferCmd) (void);
const BattleBufferCmd gSafariBufferCommands[] =
{
    SafariHandleGetAttributes,
    SafariHandlecmd1,
    SafariHandleSetAttributes,
    SafariHandlecmd3,
    SafariHandleLoadPokeSprite,
    SafariHandleSendOutPoke,
    SafariHandleReturnPokeToBall,
    SafariHandleTrainerThrow,
    SafariHandleTrainerSlide,
    SafariHandleTrainerSlideBack,
    SafariHandlecmd10,
    SafariHandlecmd11,
    SafariHandlecmd12,
    SafariHandleBallThrow,
    SafariHandlePuase,
    SafariHandleMoveAnimation,
    SafariHandlePrintString,
    SafariHandlePrintStringPlayerOnly,
    SafariHandlecmd18,
    SafariHandlecmd19,
    SafariHandlecmd20,
    SafariHandleOpenBag,
    SafariHandlecmd22,
    SafariHandlecmd23,
    SafariHandleHealthBarUpdate,
    SafariHandleExpBarUpdate,
    SafariHandleStatusIconUpdate,
    SafariHandleStatusAnimation,
    SafariHandleStatusXor,
    SafariHandlecmd29,
    SafariHandleDMATransfer,
    SafariHandlecmd31,
    SafariHandlecmd32,
    SafariHandlecmd33,
    SafariHandlecmd34,
    SafariHandlecmd35,
    SafariHandlecmd36,
    SafariHandlecmd37,
    SafariHandlecmd38,
    SafariHandlecmd39,
    SafariHandlecmd40,
    SafariHandleHitAnimation,
    SafariHandlecmd42,
    SafariHandleEffectivenessSound,
    SafariHandlecmd44,
    SafariHandleFaintingCry,
    SafariHandleIntroSlide,
    SafariHandleTrainerBallThrow,
    SafariHandlecmd48,
    SafariHandlecmd49,
    SafariHandlecmd50,
    SafariHandleSpriteInvisibility,
    SafariHandleBattleAnimation,
    SafariHandleLinkStandbyMsg,
    SafariHandleResetActionMoveSelection,
    SafariHandlecmd55,
    SafariHandlecmd56,
};
// code

void SafariBufferExecCompleted(void);
void bx_wait_t6(void);
void sub_812B65C(void);
void SafariBufferRunCommand(void);
void sub_812B758(void);

void unref_sub_812B464(void)
{
}

void SetBankFuncToSafariBufferRunCommand(void)
{
    gBattlerControllerFuncs[gActiveBattler] = SafariBufferRunCommand;
}

void SafariBufferRunCommand(void)
{
    if (gBattleControllerExecFlags & gBitTable[gActiveBattler])
    {
        if (gBattleBufferA[gActiveBattler][0] < 0x39)
            gSafariBufferCommands[gBattleBufferA[gActiveBattler][0]]();
        else
            SafariBufferExecCompleted();
    }
}

const u8 sSafariMainMenuCursorCoords[][2] =
{
    {18, 15},
    {23, 15},
    {18, 17},
    {23, 17},
};

void BattleControllerSafari_DrawMainMenuCursor(u8 a, u8 selectedCursorTileNum)
{
    u8 x = sSafariMainMenuCursorCoords[a][0];
    u8 y = sSafariMainMenuCursorCoords[a][1];
    u16 *tilemapPtr = (u16 *)((u8 *)0x600C500 + (x * 2) + (y * 0x40));

    *tilemapPtr = 1 + selectedCursorTileNum;
    *(tilemapPtr + 0x20) = 2 + selectedCursorTileNum;
}

void BattleControllerSafari_EraseMainMenuCursor(u8 a)
{
    u8 x = sSafariMainMenuCursorCoords[a][0];
    u8 y = sSafariMainMenuCursorCoords[a][1];
    u16 *tilemapPtr = (u16 *)((u8 *)0x600C500 + (x * 2) + (y * 0x40));

    *tilemapPtr = 32;
    *(tilemapPtr + 0x20) = 32;
}

void bx_battle_menu_t6_2(void)
{
    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);

        // Useless switch statement.
        switch (gActionSelectionCursor[gActiveBattler])
        {
        case 0:
            BtlController_EmitTwoReturnValues(1, 5, 0);
            break;
        case 1:
            BtlController_EmitTwoReturnValues(1, 6, 0);
            break;
        case 2:
            BtlController_EmitTwoReturnValues(1, 7, 0);
            break;
        case 3:
            BtlController_EmitTwoReturnValues(1, 8, 0);
            break;
        }
        SafariBufferExecCompleted();
    }
    else if (gMain.newKeys & DPAD_LEFT)
    {
        if (gActionSelectionCursor[gActiveBattler] & 1)
        {
            PlaySE(SE_SELECT);
            BattleControllerSafari_EraseMainMenuCursor(gActionSelectionCursor[gActiveBattler]);
            gActionSelectionCursor[gActiveBattler] ^= 1;
            BattleControllerSafari_DrawMainMenuCursor(gActionSelectionCursor[gActiveBattler], 0);
        }
    }
    else if (gMain.newKeys & DPAD_RIGHT)
    {
        if (!(gActionSelectionCursor[gActiveBattler] & 1))
        {
            PlaySE(SE_SELECT);
            BattleControllerSafari_EraseMainMenuCursor(gActionSelectionCursor[gActiveBattler]);
            gActionSelectionCursor[gActiveBattler] ^= 1;
            BattleControllerSafari_DrawMainMenuCursor(gActionSelectionCursor[gActiveBattler], 0);
        }
    }
    else if (gMain.newKeys & DPAD_UP)
    {
        if (gActionSelectionCursor[gActiveBattler] & 2)
        {
            PlaySE(SE_SELECT);
            BattleControllerSafari_EraseMainMenuCursor(gActionSelectionCursor[gActiveBattler]);
            gActionSelectionCursor[gActiveBattler] ^= 2;
            BattleControllerSafari_DrawMainMenuCursor(gActionSelectionCursor[gActiveBattler], 0);
        }
    }
    else if (gMain.newKeys & DPAD_DOWN)
    {
        if (!(gActionSelectionCursor[gActiveBattler] & 2))
        {
            PlaySE(SE_SELECT);
            BattleControllerSafari_EraseMainMenuCursor(gActionSelectionCursor[gActiveBattler]);
            gActionSelectionCursor[gActiveBattler] ^= 2;
            BattleControllerSafari_DrawMainMenuCursor(gActionSelectionCursor[gActiveBattler], 0);
        }
    }
#if DEBUG
    else if (gMain.newKeys & R_BUTTON)
    {
        if (!ewram17810[gActiveBattler].unk0_5)
            move_anim_start_t3(gActiveBattler, gActiveBattler, gActiveBattler, 4, 0);
    }
    else if (gMain.newKeys & START_BUTTON)
    {
        sub_804454C();
    }
#endif
}

void sub_812B65C(void)
{
    if (gSprites[gBattlerSpriteIds[gActiveBattler]].callback == SpriteCallbackDummy)
        SafariBufferExecCompleted();
}

void sub_812B694(void)
{
    if (gWindowTemplate_Contest_MoveDescription.state == 0)
        SafariBufferExecCompleted();
}

void sub_812B6AC(void)
{
    if (!gPaletteFade.active)
    {
        gMain.inBattle = FALSE;
        gMain.callback1 = gPreBattleCallback1;
        SetMainCallback2(gMain.savedCallback);
    }
}

void bx_wait_t6(void)
{
    if (!gDoingBattleAnim || !ewram17810[gActiveBattler].unk0_6)
        SafariBufferExecCompleted();
}

void sub_812B724(void)
{
    if (!gPaletteFade.active)
    {
        gBattlerControllerFuncs[gActiveBattler] = sub_812B758;
        sub_810BADC();
    }
}

void sub_812B758(void)
{
    if (gMain.callback2 == BattleMainCB2 && !gPaletteFade.active)
    {
        BtlController_EmitOneReturnValue(1, gSpecialVar_ItemId);
        SafariBufferExecCompleted();
    }
}

void sub_812B794(void)
{
    if (!ewram17810[gActiveBattler].unk0_5)
        SafariBufferExecCompleted();
}

void SafariBufferExecCompleted(void)
{
    gBattlerControllerFuncs[gActiveBattler] = SafariBufferRunCommand;
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        u8 playerId = GetMultiplayerId();

        PrepareBufferDataTransferLink(2, 4, &playerId);
        gBattleBufferA[gActiveBattler][0] = 0x38;
    }
    else
    {
        gBattleControllerExecFlags &= ~gBitTable[gActiveBattler];
    }
}

void unref_sub_812B838(void)
{
    if (!ewram17810[gActiveBattler].unk0_4)
        SafariBufferExecCompleted();
}

void SafariHandleGetAttributes(void)
{
    SafariBufferExecCompleted();
}

void SafariHandlecmd1(void)
{
    SafariBufferExecCompleted();
}

void SafariHandleSetAttributes(void)
{
    SafariBufferExecCompleted();
}

void SafariHandlecmd3(void)
{
    SafariBufferExecCompleted();
}

void SafariHandleLoadPokeSprite(void)
{
    SafariBufferExecCompleted();
}

void SafariHandleSendOutPoke(void)
{
    SafariBufferExecCompleted();
}

void SafariHandleReturnPokeToBall(void)
{
    SafariBufferExecCompleted();
}

void SafariHandleTrainerThrow(void)
{
    LoadPlayerTrainerBankSprite(gSaveBlock2.playerGender, gActiveBattler);
    GetMonSpriteTemplate_803C5A0(gSaveBlock2.playerGender, GetBattlerPosition(gActiveBattler));
    gBattlerSpriteIds[gActiveBattler] = CreateSprite(
      &gCreatingSpriteTemplate,
      80,
      (8 - gTrainerBackPicCoords[gSaveBlock2.playerGender].coords) * 4 + 80,
      30);
    gSprites[gBattlerSpriteIds[gActiveBattler]].oam.paletteNum = gActiveBattler;
    gSprites[gBattlerSpriteIds[gActiveBattler]].x2 = 240;
    gSprites[gBattlerSpriteIds[gActiveBattler]].data[0] = -2;
    gSprites[gBattlerSpriteIds[gActiveBattler]].callback = sub_80313A0;
    gBattlerControllerFuncs[gActiveBattler] = sub_812B65C;
}

void SafariHandleTrainerSlide(void)
{
    SafariBufferExecCompleted();
}

void SafariHandleTrainerSlideBack(void)
{
    SafariBufferExecCompleted();
}

void SafariHandlecmd10(void)
{
    SafariBufferExecCompleted();
}

void SafariHandlecmd11(void)
{
    SafariBufferExecCompleted();
}

void SafariHandlecmd12(void)
{
    ewram17840.unk8 = 4;
    gDoingBattleAnim = 1;
    move_anim_start_t4(gActiveBattler, gActiveBattler, GetBattlerAtPosition(1), 4);
    gBattlerControllerFuncs[gActiveBattler] = bx_wait_t6;
}

void SafariHandleBallThrow(void)
{
    u8 var = gBattleBufferA[gActiveBattler][1];

    ewram17840.unk8 = var;
    gDoingBattleAnim = 1;
    move_anim_start_t4(gActiveBattler, gActiveBattler, GetBattlerAtPosition(1), 4);
    gBattlerControllerFuncs[gActiveBattler] = bx_wait_t6;
}

// TODO: spell Pause correctly
void SafariHandlePuase(void)
{
    SafariBufferExecCompleted();
}

void SafariHandleMoveAnimation(void)
{
    SafariBufferExecCompleted();
}

void SafariHandlePrintString(void)
{
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    BufferStringBattle(*(u16 *)&gBattleBufferA[gActiveBattler][2]);
    Contest_StartTextPrinter(&gWindowTemplate_Contest_MoveDescription, gDisplayedStringBattle, 144, 2, 15);
    gBattlerControllerFuncs[gActiveBattler] = sub_812B694;
}

void SafariHandlePrintStringPlayerOnly(void)
{
    if (GetBattlerSide(gActiveBattler) == 0)
        SafariHandlePrintString();
    else
        SafariBufferExecCompleted();
}

void SafariHandlecmd18(void)
{
    int i;

    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 160;
    gWindowTemplate_Contest_MoveDescription.paletteNum = 0;
    Text_FillWindowRectDefPalette(&gWindowTemplate_Contest_MoveDescription, 10, 2, 15, 27, 18);
    Text_FillWindowRectDefPalette(&gWindowTemplate_Contest_MoveDescription, 10, 2, 35, 16, 36);
    gBattlerControllerFuncs[gActiveBattler] = bx_battle_menu_t6_2;

    Text_InitWindow(&gWindowTemplate_Contest_MoveDescription, BattleText_MenuOptionsSafari, 400, 19, 35);
    Text_PrintWindow8002F44(&gWindowTemplate_Contest_MoveDescription);

    for (i = 0; i < 4; i++)
        BattleControllerSafari_EraseMainMenuCursor(i);

    BattleControllerSafari_DrawMainMenuCursor(gActionSelectionCursor[gActiveBattler], 0);
    BattleStringExpandPlaceholdersToDisplayedString(BattleText_PlayerMenu);

    Text_InitWindow(&gWindowTemplate_Contest_MoveDescription, gDisplayedStringBattle, SUB_812BB10_TILE_DATA_OFFSET, 2, 35);
    Text_PrintWindow8002F44(&gWindowTemplate_Contest_MoveDescription);
}

void SafariHandlecmd19(void)
{
    SafariBufferExecCompleted();
}

void SafariHandlecmd20(void)
{
    SafariBufferExecCompleted();
}

void SafariHandleOpenBag(void)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB(0, 0, 0));
    gBattlerControllerFuncs[gActiveBattler] = sub_812B724;
    gBankInMenu = gActiveBattler;
}

void SafariHandlecmd22(void)
{
    SafariBufferExecCompleted();
}

void SafariHandlecmd23(void)
{
    SafariBufferExecCompleted();
}

void SafariHandleHealthBarUpdate(void)
{
    SafariBufferExecCompleted();
}

void SafariHandleExpBarUpdate(void)
{
    SafariBufferExecCompleted();
}

void SafariHandleStatusIconUpdate(void)
{
    sub_8045A5C(gHealthboxSpriteIds[gActiveBattler], &gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], 11);
    SafariBufferExecCompleted();
}

void SafariHandleStatusAnimation(void)
{
    SafariBufferExecCompleted();
}

void SafariHandleStatusXor(void)
{
    SafariBufferExecCompleted();
}

void SafariHandlecmd29(void)
{
    SafariBufferExecCompleted();
}

void SafariHandleDMATransfer(void)
{
    SafariBufferExecCompleted();
}

void SafariHandlecmd31(void)
{
    SafariBufferExecCompleted();
}

void SafariHandlecmd32(void)
{
    SafariBufferExecCompleted();
}

void SafariHandlecmd33(void)
{
    SafariBufferExecCompleted();
}

void SafariHandlecmd34(void)
{
    SafariBufferExecCompleted();
}

void SafariHandlecmd35(void)
{
    SafariBufferExecCompleted();
}

void SafariHandlecmd36(void)
{
    SafariBufferExecCompleted();
}

void SafariHandlecmd37(void)
{
    SafariBufferExecCompleted();
}

void SafariHandlecmd38(void)
{
    SafariBufferExecCompleted();
}

void SafariHandlecmd39(void)
{
    SafariBufferExecCompleted();
}

void SafariHandlecmd40(void)
{
    SafariBufferExecCompleted();
}

void SafariHandleHitAnimation(void)
{
    SafariBufferExecCompleted();
}

void SafariHandlecmd42(void)
{
    SafariBufferExecCompleted();
}

void SafariHandleEffectivenessSound(void)
{
    s8 pan;

    if (GetBattlerSide(gActiveBattler) == 0)
        pan = -64;
    else
        pan = 63;
    PlaySE12WithPanning(gBattleBufferA[gActiveBattler][1] | (gBattleBufferA[gActiveBattler][2] << 8), pan);
    SafariBufferExecCompleted();
}

void SafariHandlecmd44(void)
{
    PlayFanfare(gBattleBufferA[gActiveBattler][1] | (gBattleBufferA[gActiveBattler][2] << 8));
    SafariBufferExecCompleted();
}

void SafariHandleFaintingCry(void)
{
    u16 species = GetMonData(&gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], MON_DATA_SPECIES);

    PlayCry1(species, 25);
    SafariBufferExecCompleted();
}

void SafariHandleIntroSlide(void)
{
    StartBattleIntroAnim(gBattleBufferA[gActiveBattler][1]);
    gIntroSlideFlags |= 1;
    SafariBufferExecCompleted();
}

void SafariHandleTrainerBallThrow(void)
{
    sub_8045A5C(gHealthboxSpriteIds[gActiveBattler], &gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], 10);
    sub_804777C(gActiveBattler);
    sub_8043DFC(gHealthboxSpriteIds[gActiveBattler]);
    SafariBufferExecCompleted();
}

void SafariHandlecmd48(void)
{
    SafariBufferExecCompleted();
}

void SafariHandlecmd49(void)
{
    SafariBufferExecCompleted();
}

void SafariHandlecmd50(void)
{
    SafariBufferExecCompleted();
}

void SafariHandleSpriteInvisibility(void)
{
    SafariBufferExecCompleted();
}

void SafariHandleBattleAnimation(void)
{
    u8 r3 = gBattleBufferA[gActiveBattler][1];
    u16 r4 = gBattleBufferA[gActiveBattler][2] | (gBattleBufferA[gActiveBattler][3] << 8);

    if (move_anim_start_t3(gActiveBattler, gActiveBattler, gActiveBattler, r3, r4) != 0)
        SafariBufferExecCompleted();
    else
        gBattlerControllerFuncs[gActiveBattler] = sub_812B794;
}

void SafariHandleLinkStandbyMsg(void)
{
    SafariBufferExecCompleted();
}

void SafariHandleResetActionMoveSelection(void)
{
    SafariBufferExecCompleted();
}

void SafariHandlecmd55(void)
{
    gBattleOutcome = gBattleBufferA[gActiveBattler][1];
    FadeOutMapMusic(5);
    BeginFastPaletteFade(3);
    SafariBufferExecCompleted();
    if ((gBattleTypeFlags & BATTLE_TYPE_LINK) && !(gBattleTypeFlags & BATTLE_TYPE_WILD))
        gBattlerControllerFuncs[gActiveBattler] = sub_812B6AC;
}

void SafariHandlecmd56(void)
{
}
