#include "global.h"
#include "menu.h"
#include "main.h"
#include "event_object_lock.h"
#include "script.h"
#include "constants/songs.h"
#include "sound.h"
#include "strings.h"
#include "text.h"
#include "text_window.h"
#include "string_util.h"

struct Menu
{
    u8 left;
    u8 top;
    s8 cursorPos;
    s8 minCursorPos;
    s8 maxCursorPos;
    u8 width;
    u8 height;
    u8 menu_field_7;
    u8 columnXCoords[8];
};

static void MultistepInitMenuWindowInternal(const struct WindowTemplate *, u16);
static void InitMenuWindowInternal(const struct WindowTemplate *, u16);
static bool8 IsGridCursorMovementClamped(void);
static u8 sub_8072484(u8, u8, u8, u8, u8, u8, u32);
static u8 sub_80724F4(u8, u8, u8, const struct MenuAction[], u8);
static void sub_8072620(u8, u8, u8, const struct MenuAction[], u8);

static struct Menu sMenu;

EWRAM_DATA struct Window gMenuWindow = {0};
EWRAM_DATA u8 gFiller_202E908[0x90] = {0};
EWRAM_DATA struct Window *gMenuWindowPtr = NULL;
EWRAM_DATA u8 gMenuMultistepInitState = 0;
EWRAM_DATA u16 gMenuTextTileOffset = 0;
EWRAM_DATA u16 gMenuTextWindowTileOffset = 0;
EWRAM_DATA u16 gMenuTextWindowContentTileOffset = 0;
EWRAM_DATA u16 gMenuMessageBoxContentTileOffset = 0;

const struct MenuAction gMenuYesNoItems[] =
{
    { OtherText_Yes, NULL },
    { OtherText_No, NULL },
};

void CloseMenu(void)
{
    PlaySE(SE_SELECT);
    Menu_EraseScreen();
    ScriptUnfreezeObjectEvents();
    ScriptContext2_Disable();
    Menu_DestroyCursor();
}

void AppendToList(u8 *list, u8 *pindex, u32 value)
{
    list[*pindex] = value;
    (*pindex)++;
}

void InitMenuWindow(const struct WindowTemplate *winTemplate)
{
    InitMenuWindowInternal(winTemplate, 1);
}

void MultistepInitMenuWindowBegin(const struct WindowTemplate *winTemplate)
{
    MultistepInitMenuWindowInternal(winTemplate, 1);
}

static void MultistepInitMenuWindowInternal(const struct WindowTemplate *winTemplate, u16 tileOffset)
{
    gMenuMultistepInitState = 0;
    gMenuTextTileOffset = tileOffset;
    gMenuWindowPtr = &gMenuWindow;
    Text_InitWindowWithTemplate(&gMenuWindow, winTemplate);
}

bool32 MultistepInitMenuWindowContinue(void)
{
    switch (gMenuMultistepInitState)
    {
    case 0:
        gMenuMultistepInitState++;
        return 0;
    case 1:
        gMenuTextWindowTileOffset = MultistepInitWindowTileData(gMenuWindowPtr, gMenuTextTileOffset);
        goto next;
    case 2:
        if (!MultistepLoadFont())
            goto fail;
        goto next;
    case 3:
        gMenuTextWindowContentTileOffset = TextWindow_SetBaseTileNum(gMenuTextWindowTileOffset);
    next:
        gMenuMultistepInitState++;
        return 0;
    case 4:
        TextWindow_LoadStdFrameGraphics(gMenuWindowPtr);
        gMenuMessageBoxContentTileOffset = TextWindow_SetDlgFrameBaseTileNum(gMenuTextWindowContentTileOffset);
        return 1;
    default:
    fail:
        return 0;
    }
}

static void InitMenuWindowInternal(const struct WindowTemplate *winTemplate, u16 tileOffset)
{
    gMenuWindowPtr = &gMenuWindow;
    Text_InitWindowWithTemplate(&gMenuWindow, winTemplate);
    gMenuTextTileOffset = tileOffset;
    gMenuTextWindowTileOffset = InitWindowTileData(gMenuWindowPtr, gMenuTextTileOffset);
    gMenuTextWindowContentTileOffset = TextWindow_SetBaseTileNum(gMenuTextWindowTileOffset);
    TextWindow_LoadStdFrameGraphics(gMenuWindowPtr);
    gMenuMessageBoxContentTileOffset = TextWindow_SetDlgFrameBaseTileNum(gMenuTextWindowContentTileOffset);
}

void unref_sub_8071DA4(struct WindowTemplate *winTemplate, u16 tileOffset)
{
    gMenuWindowPtr = &gMenuWindow;
    Text_InitWindowWithTemplate(&gMenuWindow, winTemplate);
    gMenuTextWindowTileOffset = tileOffset;
    gMenuTextWindowContentTileOffset = TextWindow_SetBaseTileNum(gMenuTextWindowTileOffset);
    TextWindow_LoadStdFrameGraphics(gMenuWindowPtr);
    gMenuTextTileOffset = TextWindow_SetDlgFrameBaseTileNum(gMenuTextWindowContentTileOffset);
    gMenuMessageBoxContentTileOffset = InitWindowTileData(gMenuWindowPtr, gMenuTextTileOffset);
}

void Menu_LoadStdFrameGraphicsOverrideStyle(u8 frameType)
{
    TextWindow_LoadStdFrameGraphicsOverrideStyle(gMenuWindowPtr, frameType);
}

void Menu_LoadStdFrameGraphics(void)
{
    TextWindow_LoadStdFrameGraphics(gMenuWindowPtr);
}

void BasicInitMenuWindow(const struct WindowTemplate *winTemplate)
{
    Text_InitWindowWithTemplate(gMenuWindowPtr, winTemplate);
    gMenuWindowPtr->tileDataStartOffset = gMenuTextTileOffset;
}

// Prints 
void Menu_PrintText(const u8 *str, u8 left, u8 top)
{
    Text_InitWindowAndPrintText(gMenuWindowPtr, str, gMenuTextTileOffset, left, top);
}

void Menu_EraseWindowRect(u8 left, u8 top, u8 right, u8 bottom)
{
    Text_EraseWindowRect(gMenuWindowPtr, left, top, right, bottom);
}

void Menu_BlankWindowRect(u8 left, u8 top, u8 right, u8 bottom)
{
    Text_BlankWindowRect(gMenuWindowPtr, left, top, right, bottom);
}

void Menu_EraseScreen(void)
{
    Menu_EraseWindowRect(0, 0, 29, 19);
}

void Menu_DrawStdWindowFrame(u8 left, u8 top, u8 right, u8 bottom)
{
    TextWindow_DrawStdFrame(gMenuWindowPtr, left, top, right, bottom);
}

void sub_8071F40(const u8 *str)
{
    Menu_DrawStdWindowFrame(2, 14, 28, 19);
    Menu_PrintText(str, 3, 15);
}

void sub_8071F60(u8 a1, u8 a2, u8 a3)
{
    sub_8003490(gMenuWindowPtr, a1, gMenuTextTileOffset, a2, a3);
}

u16 unref_sub_8071F98(u8 x, u8 y)
{
    return Text_GetWindowTilemapEntry(gMenuWindowPtr, x, y);
}

void unref_sub_8071FBC(u16 a1, u8 a2, u8 a3, u8 a4, u8 a5)
{
    Text_FillWindowBorder(gMenuWindowPtr, a1, a2, a3, a4, a5);
}

void Menu_DisplayDialogueFrame(void)
{
    TextWindow_DisplayDialogueFrame(gMenuWindowPtr);
}

void MenuPrintMessage(const u8 *str, u8 left, u8 top)
{
    Contest_StartTextPrinter(gMenuWindowPtr, str, gMenuTextTileOffset, left, top);
}

void MenuPrintMessageDefaultCoords(const u8 *str)
{
    Contest_StartTextPrinter(gMenuWindowPtr, str, gMenuTextTileOffset, 4, 15);
}

void Menu_SetText(const u8 *str)
{
    Text_SetWindowText(gMenuWindowPtr, str);
}

u8 Menu_UpdateWindowText(void)
{
    return Text_UpdateWindow(gMenuWindowPtr);
}

u8 unref_sub_8072098(void)
{
    return Text_PrintWindowSimple(gMenuWindowPtr);
}

void Menu_ClearWindowText(void)
{
    Text_ClearWindow(gMenuWindowPtr);
}

u8 Menu_MoveCursor(s8 cursorDelta)
{
    s32 newPos = sMenu.cursorPos + cursorDelta;

    Menu_PrintText(gMenuCursorText_Space, sMenu.left + 1, 2 * sMenu.cursorPos + sMenu.top);

    if (newPos < sMenu.minCursorPos)
        sMenu.cursorPos = sMenu.maxCursorPos;
    else if (newPos > sMenu.maxCursorPos)
        sMenu.cursorPos = sMenu.minCursorPos;
    else
        sMenu.cursorPos += cursorDelta;

    Menu_PrintText(gMenuCursorText_Cursor, sMenu.left + 1, 2 * sMenu.cursorPos + sMenu.top);
    return sMenu.cursorPos;
}

u8 Menu_MoveCursorNoWrap(s8 cursorDelta)
{
    s32 newPos = sMenu.cursorPos + cursorDelta;

    Menu_PrintText(gMenuCursorText_Space, sMenu.left + 1, 2 * sMenu.cursorPos + sMenu.top);

    if (newPos < sMenu.minCursorPos)
        sMenu.cursorPos = sMenu.minCursorPos;
    else if (newPos > sMenu.maxCursorPos)
        sMenu.cursorPos = sMenu.maxCursorPos;
    else
        sMenu.cursorPos += cursorDelta;

    Menu_PrintText(gMenuCursorText_Cursor, sMenu.left + 1, 2 * sMenu.cursorPos + sMenu.top);
    return sMenu.cursorPos;
}

u8 Menu_GetCursorPos(void)
{
    return sMenu.cursorPos;
}

s8 Menu_ProcessInput(void)
{
    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        if (sMenu.menu_field_7)
            Menu_DestroyCursor();
        return sMenu.cursorPos;
    }

    if (gMain.newKeys & B_BUTTON)
    {
        if (sMenu.menu_field_7)
            Menu_DestroyCursor();
        return -1;
    }

    if (gMain.newKeys & DPAD_UP)
    {
        PlaySE(SE_SELECT);
        Menu_MoveCursor(-1);
        return -2;
    }
    else if (gMain.newKeys & DPAD_DOWN)
    {
        PlaySE(SE_SELECT);
        Menu_MoveCursor(1);
        return -2;
    }

    return -2;
}

s8 Menu_ProcessInputNoWrap(void)
{
    u8 cursorPos = sMenu.cursorPos;

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        if (sMenu.menu_field_7)
            Menu_DestroyCursor();
        return sMenu.cursorPos;
    }

    if (gMain.newKeys & B_BUTTON)
    {
        if (sMenu.menu_field_7)
            Menu_DestroyCursor();
        return -1;
    }

    if (gMain.newKeys & DPAD_UP)
    {
        if (cursorPos != Menu_MoveCursorNoWrap(-1))
            PlaySE(SE_SELECT);
        return -2;
    }
    else if (gMain.newKeys & DPAD_DOWN)
    {
        if (cursorPos != Menu_MoveCursorNoWrap(1))
            PlaySE(SE_SELECT);
        return -2;
    }

    Menu_MoveCursorNoWrap(0);
    return -2;
}

u8 Menu_MoveCursorItemPopupMenu(s8 delta)
{
    u8 menuHeight = (sMenu.maxCursorPos + 1) >> 1;
    s32 newPos = sMenu.cursorPos + delta;

    Menu_PrintText(
        gMenuCursorText_Space,
        6 * (sMenu.cursorPos / menuHeight) + sMenu.left + 1,
        2 * (sMenu.cursorPos % menuHeight) + sMenu.top
    );

    if (newPos < sMenu.minCursorPos)
        sMenu.cursorPos = sMenu.maxCursorPos;
    else if (newPos > sMenu.maxCursorPos)
        sMenu.cursorPos = sMenu.minCursorPos;
    else
        sMenu.cursorPos += delta;

    Menu_PrintText(
        gMenuCursorText_Cursor,
        6 * (sMenu.cursorPos / menuHeight) + sMenu.left + 1,
        2 * (sMenu.cursorPos % menuHeight) + sMenu.top
    );

    return sMenu.cursorPos;
}

static u8 Menu_MoveCursorGridLayout(s8 delta)
{
    // Don't move cursor if it is clamped
    if (sMenu.cursorPos + delta <= sMenu.maxCursorPos)
    {
        if (IsGridCursorMovementClamped() == TRUE)
            return sMenu.cursorPos;
    }
    else
    {
        return sMenu.cursorPos;
    }

    if ((sMenu.maxCursorPos + 1) / sMenu.width == 0)
    {
        Menu_PrintText(
            gMenuCursorText_Space,
            sMenu.left + 1 + sMenu.columnXCoords[sMenu.cursorPos % sMenu.width],
            2 * ((sMenu.cursorPos / sMenu.width) % sMenu.height) + sMenu.top
        );
    }
    else
    {
        Menu_PrintText(
            gMenuCursorText_Space,
            sMenu.left + 1 + sMenu.columnXCoords[sMenu.cursorPos % sMenu.width],
            2 * (sMenu.cursorPos / sMenu.width) + sMenu.top
        );
    }

    sMenu.cursorPos += delta;

    if ((sMenu.maxCursorPos + 1) / sMenu.width == 0)
    {
        Menu_PrintText(
            gMenuCursorText_Cursor,
            sMenu.left + 1 + sMenu.columnXCoords[sMenu.cursorPos % sMenu.width],
            2 * ((sMenu.cursorPos / sMenu.width) % sMenu.height) + sMenu.top
        );
    }
    else
    {
        Menu_PrintText(
            gMenuCursorText_Cursor,
            sMenu.left + 1 + sMenu.columnXCoords[sMenu.cursorPos % sMenu.width],
            2 * (sMenu.cursorPos / sMenu.width) + sMenu.top
        );
    }

    return sMenu.cursorPos;
}

// Returns TRUE if the cursor is on an edge and cannot move in the pressed direction
static bool8 IsGridCursorMovementClamped(void)
{
    if (gMain.newKeys & DPAD_UP)
    {
        // is cursor on first row?
        if (sMenu.cursorPos < sMenu.width)
            return TRUE;
    }
    if (gMain.newKeys & DPAD_DOWN)
    {
        // is cursor on last row?
        if (sMenu.cursorPos >= sMenu.maxCursorPos + 1 - sMenu.width)
            return TRUE;
    }
    if (gMain.newKeys & DPAD_LEFT)
    {
        // is cursor on first column?
        if ((sMenu.cursorPos - sMenu.cursorPos % sMenu.width) % sMenu.width == 1 // always false
         || sMenu.cursorPos == 0  // redundant
         || sMenu.cursorPos % sMenu.width == 0)
            return TRUE;
    }
    if (gMain.newKeys & DPAD_RIGHT)
    {
        // is cursor on last column?
        if (sMenu.cursorPos % sMenu.width == sMenu.width - 1)
            return TRUE;
    }

    return FALSE;
}

static u8 sub_8072484(u8 a1, u8 a2, u8 menuItemCount, u8 a4, u8 width, u8 a6, u32 a7)
{
    u8 v7;

    sMenu.width = width;
    sMenu.height = menuItemCount / width;
    InitMenu(0, a1, a2, menuItemCount, a4);
    v7 = 0;
    if (a7)
        v7 = -1;
    sMenu.menu_field_7 = v7;
    return a4;
}

static u8 sub_80724F4(u8 left, u8 top, u8 menuItemCount, const struct MenuAction menuItems[], u8 columnCount)
{
    u8 i;
    u8 maxWidth;
    s32 height;

    for (i = 0; i < 7; i++)
        sMenu.columnXCoords[i] = 0;

    maxWidth = 0;
    for (i = 0; i < menuItemCount; i++)
    {
        u8 width = (GetStringWidthInMenuWindow(menuItems[i].text) + 7) / 8 + 1;

        if (width > maxWidth)
            maxWidth = width;
    }

    for (i = 1; i <= columnCount; i++)
        sMenu.columnXCoords[i] = maxWidth;

    for (i = 1; i <= columnCount; i++)
        sMenu.columnXCoords[i] += 1 + sMenu.columnXCoords[i - 1];

    sMenu.columnXCoords[columnCount]--;

    if (!((menuItemCount / 2) < columnCount || (menuItemCount % 2 != 0))
     || columnCount == 1
     || columnCount == menuItemCount)
    {
        height = 2 * (menuItemCount / columnCount) + 1;
    }
    else
    {
        height = 2 * ((menuItemCount / columnCount) + 1) + 1;
    }

    {
        u8 right;
        u8 bottom;
        u32 totalWidth;
        s32 val;

        val = (s8)top + height;
        val = val << 24;
        bottom = val >> 24;

        totalWidth = (sMenu.columnXCoords[columnCount] + 1);
        right = left + totalWidth;

        Menu_DrawStdWindowFrame(left, top, right, bottom);
    }

    return maxWidth;
}

static void sub_8072620(u8 left, u8 top, u8 menuItemCount, const struct MenuAction menuItems[], u8 columnCount)
{
    u8 i;
    u8 maxWidth;

    for (i = 0; i < 7; i++)
        sMenu.columnXCoords[i] = 0;

    maxWidth = 0;
    for (i = 0; i < menuItemCount; i++)
    {
        u8 width = (GetStringWidthInMenuWindow(menuItems[i].text) + 7) / 8 + 1;

        if (width > maxWidth)
            maxWidth = width;
    }

    for (i = 1; i <= columnCount; i++)
        sMenu.columnXCoords[i] = maxWidth;

    for (i = 1; i <= columnCount; i++)
        sMenu.columnXCoords[i] += 1 + sMenu.columnXCoords[i - 1];

    sMenu.columnXCoords[columnCount]--;

    for (i = 0; i < columnCount; i++)
    {
        u8 row = 0;
        u8 j;
        for (j = 0; i + j < menuItemCount; j += columnCount, row++)
            Menu_PrintText(menuItems[i + j].text, left + sMenu.columnXCoords[i % columnCount] + 1, top + 2 * row);
    }
}

void sub_807274C(u8 left, u8 top, u8 menuItemCount, u8 a4, const struct MenuAction menuItems[], u8 columnCount, u32 a7)
{
    u8 maxWidth = sub_80724F4(left, top, menuItemCount, menuItems, columnCount);

    sub_8072484(left + 1, top + 1, menuItemCount, a4, columnCount, maxWidth, a7);
    sub_8072620(left + 1, top + 1, menuItemCount, menuItems, columnCount);
}

s8 Menu_ProcessInputGridLayout(void)
{
    if (gMain.newKeys & A_BUTTON)
    {
        if (sMenu.menu_field_7)
            Menu_DestroyCursor();
        PlaySE(SE_SELECT);
        return Menu_GetCursorPos();
    }

    if (gMain.newKeys & B_BUTTON)
    {
        if (sMenu.menu_field_7)
            Menu_DestroyCursor();
        return -1;
    }

    if (gMain.newKeys & DPAD_UP)
    {
        PlaySE(SE_SELECT);
        // Move up one whole row
        Menu_MoveCursorGridLayout(-sMenu.width);
        return -2;
    }
    else if (gMain.newKeys & DPAD_DOWN)
    {
        PlaySE(SE_SELECT);
        // Move down one whole column
        Menu_MoveCursorGridLayout(sMenu.width);
        return -2;
    }
    else if (gMain.newKeys & DPAD_LEFT)
    {
        PlaySE(SE_SELECT);
        Menu_MoveCursorGridLayout(-1);
        return -2;
    }
    else if (gMain.newKeys & DPAD_RIGHT)
    {
        PlaySE(SE_SELECT);
        Menu_MoveCursorGridLayout(1);
        return -2;
    }

    return -2;
}

u8 Menu_GetColumnXCoord(u8 column)
{
    return sMenu.columnXCoords[column];
}

void Menu_PrintItems(u8 left, u8 top, u8 menuItemCount, const void * menuItems)
{
    u8 i;

    for (i = 0; i < menuItemCount; i++)
        Menu_PrintText(((const struct MenuAction *)menuItems)[i].text, left, top + 2 * i);
}

void Menu_PrintItemsReordered(u8 left, u8 top, u8 menuItemCount, const void * menuItems, const u8 *order)
{
    u8 i;

    for (i = 0; i < menuItemCount; i++)
        Menu_PrintText(((const struct MenuAction *)menuItems)[order[i]].text, left, top + 2 * i);
}

void InitYesNoMenu(u8 left, u8 top, u8 a3)
{
    Menu_PrintItems(left + 2, top + 1, 2, gMenuYesNoItems);
    InitMenu(0, left + 1, top + 1, 2, 0);
}

void DisplayYesNoMenu(u8 left, u8 top, u32 a3)
{
    Menu_DrawStdWindowFrame(left, top, left + 6, top + 5);
    InitYesNoMenu(left, top, 5);
    sMenu.menu_field_7 = a3 ? -1 : 0;
}

s8 Menu_ProcessInputNoWrap_(void)
{
    return Menu_ProcessInputNoWrap();
}

u8 Menu_PrintTextPixelCoords(const u8 *text, u8 left, u16 top, u8 a4)
{
    return Text_InitWindow8004D04(gMenuWindowPtr, text, gMenuTextTileOffset, left, top, a4);
}

u8 Menu_PrintTextPixelCoordsAndGetLines(const u8 *text, u8 left, u16 top, u8 width, u32 a5)
{
    return sub_8004FD0(gMenuWindowPtr, NULL, text, gMenuTextTileOffset, left, top, width, a5);
}

u8 Menu_BufferedPrintTextPixelCoordsAndGetLines(u8 *dest, u8 *src, u8 left, u16 top, u8 width, u32 a6)
{
    return sub_8004FD0(gMenuWindowPtr, dest, src, gMenuTextTileOffset, left, top, width, a6);
}

int sub_8072AB0(const u8 *str, u8 left, u16 top, u8 width, u8 height, u32 a6)
{
    u8 newlineCount = sub_8004FD0(gMenuWindowPtr, NULL, str, gMenuTextTileOffset, left, top, width, a6);

    left /= 8;
    top /= 8;
    width = (width + 7) / 8;
    height = (height + 7) / 8;

    if (newlineCount < height)
        Menu_BlankWindowRect(left, top + 2 * newlineCount, left + width - 1, height + top - 1);
}

void MenuPrint_RightAligned(const u8 *str, u8 right, u8 top)
{
    Text_InitWindow_RightAligned(gMenuWindowPtr, str, gMenuTextTileOffset, right, top);
}

void MenuPrint_AlignedToRightOfReferenceString(const u8 *src, u8 left, u8 top, const u8 *widthRefStr)
{
    u8 buffer[64];
    u8 width = GetStringWidth(gMenuWindowPtr, widthRefStr);
    AlignString(gMenuWindowPtr, buffer, src, width, 1);
    Text_InitWindowAndPrintText(gMenuWindowPtr, buffer, gMenuTextTileOffset, left, top);
}

void MenuPrint_Centered(const u8 *text, u8 left, u8 top, u16 width)
{
    Text_InitWindow_Centered(gMenuWindowPtr, text, gMenuTextTileOffset, left, top, width);
}

u8 *AlignInt1InMenuWindow(u8 *dest, s32 value, u8 alignAmount, u8 alignType)
{
    return AlignInt1(gMenuWindowPtr, dest, value, alignAmount, alignType);
}

u8 *AlignInt2InMenuWindow(u8 *dest, s32 value, u8 alignAmount, u8 alignType)
{
    return AlignInt2(gMenuWindowPtr, dest, value, alignAmount, alignType);
}

u8 *AlignStringInMenuWindow(u8 *dest, const u8 *src, u8 alignAmount, u8 alignType)
{
    return AlignString(gMenuWindowPtr, dest, src, alignAmount, alignType);
}

u8 GetStringWidthInMenuWindow(const u8 *str)
{
    return GetStringWidth(gMenuWindowPtr, str);
}

u8 Menu_GetTextWindowPaletteNum(void)
{
    return Text_GetWindowPaletteNum(gMenuWindowPtr);
}

void Menu_GetTextColors(u8 *a1, u8 *a2, u8 *a3)
{
    Text_GetTextColors(gMenuWindowPtr, a1, a2, a3);
}

u32 Menu_UpdateWindowTextOverrideLineLength(u8 lineLength)
{
    return Text_UpdateWindowOverrideLineLength(gMenuWindowPtr, lineLength);
}

struct Window *unref_sub_8072D0C(void)
{
    return gMenuWindowPtr;
}

u8 InitMenu(u8 cursorSubpriority, u8 left, u8 top, u8 numChoices, u8 cursorPos)
{
    s32 pos;

    sMenu.left = left - 1;
    sMenu.top = top;
    sMenu.minCursorPos = 0;
    sMenu.maxCursorPos = numChoices - 1;
    sMenu.menu_field_7 = 0;

    pos = cursorPos;

    if (pos < 0 || pos > sMenu.maxCursorPos)
        pos = 0;

    sMenu.cursorPos = pos;
    Menu_MoveCursor(0);

    return pos;
}

void unref_sub_8072DC0()
{
    // No-op
}

void sub_8072DCC(u8 unused)
{
    // No-op
}

void sub_8072DDC(u8 a1)
{
    sub_8072DCC(8 * a1);
}

void Menu_DestroyCursor(void)
{
    // No-op
}
