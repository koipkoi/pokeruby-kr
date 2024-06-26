#include "global.h"
#include "ewram.h"
#include "random.h"
#include "task.h"
#include "contest.h"
#include "text.h"
#include "string_util.h"
#include "link.h"

static void SendBlockToAllOpponents(const void *data, u16 size)
{
    memcpy(gDecompressionBuffer, data, size);
    SendBlock(bitmask_all_link_players_but_self(), gDecompressionBuffer, size);
}

static bool8 HasPlayerReceivedBlock(u8 who)
{
    u8 flag = 1 << who;
    if (!(GetBlockReceivedStatus() & flag))
        return FALSE;
    ResetBlockReceivedFlag(flag);
    return TRUE;
}

static bool8 HaveAllPlayersReceivedBlock(void)
{
    int i;

    for (i = 0; i < MAX_LINK_PLAYERS; i++)
    {
        if (!((GetBlockReceivedStatus() >> i) & 1))
            return FALSE;
    }
    ResetBlockReceivedFlags();
    return TRUE;
}

void Task_LinkContest_Init(u8 taskId)
{
    u8 i;

    for (i = 0; i < 4; i++)
        gBlockRecvBuffer[i][0] = 0xff;
}

u8 GetStringLanguage(const u8 *string)
{
    u8 language = GAME_LANGUAGE;
    if (string[0] == EXT_CTRL_CODE_BEGIN && string[1] == 0x15)
        return language;
    if (StringLength(string) < OT_NAME_LENGTH - 1)
    {
        while (*string != EOS)
        {
            if (((*string >= CHAR_A && *string <= CHAR_z) ||
                    (*string >= CHAR_0 + 0 && *string <= CHAR_0 + 9) ||
                    *string == CHAR_SPACE ||
                    *string == CHAR_PERIOD ||
                    *string == CHAR_COMMA ||
                    *string == CHAR_EXCL_MARK ||
                    *string == CHAR_QUESTION_MARK ||
                    *string == CHAR_MALE ||
                    *string == CHAR_FEMALE ||
                    *string == CHAR_SLASH ||
                    *string == CHAR_HYPHEN ||
                    *string == CHAR_ELLIPSIS ||
                    *string == CHAR_DBL_QUOT_LEFT ||
                    *string == CHAR_DBL_QUOT_RIGHT ||
                    *string == CHAR_SGL_QUOT_LEFT ||
                    *string == CHAR_DBL_QUOT_LEFT)) // Most likely a typo, CHAR_SGL_QUOT_RIGHT should be here instead.
            {
                string++;
            }
            else
            {
                language = LANGUAGE_JAPANESE;
                break;
            }
        }
    }
    return language;
}

void sub_80C8734(u8 taskId)
{
    int i;
    u8 *name;

    switch (gTasks[taskId].data[0]) {
        default:
            gTasks[taskId].data[0] = 0;
            SwitchTaskToFollowupFunc(taskId);
            break;
        case 0:
            if (GetMultiplayerId() == 0) {
                if (IsLinkTaskFinished()) {
                    memcpy(gBlockSendBuffer, gContestMons + gContestPlayerMonIndex, sizeof(struct ContestPokemon));
                    sub_8007E9C(2);
                    gTasks[taskId].data[0]++;
                }
            }
            else
            {
                memcpy(gBlockSendBuffer, gContestMons + gContestPlayerMonIndex, sizeof(struct ContestPokemon));
                gTasks[taskId].data[0]++;
            }
            break;
        case 1:
            if (HaveAllPlayersReceivedBlock())
            {
                for (i = 0; i < MAX_LINK_PLAYERS; i++)
                {
                    memcpy(gContestMons + i, gBlockRecvBuffer[i], sizeof(struct ContestPokemon));
                    name = gContestMons[i].nickname;
                    if (gLinkPlayers[i].language == LANGUAGE_JAPANESE)
                    {
                        ConvertInternationalString(name, GetStringLanguage(name));
                    }
                    else if (name[10] == EXT_CTRL_CODE_BEGIN)
                    {
                        ConvertInternationalString(name, LANGUAGE_JAPANESE);
                    } else
                    {
                        name[5] = name[10];
                        name[10] = EOS;
                    }
                    name = gContestMons[i].trainerName;
                    if (gLinkPlayers[i].language == LANGUAGE_JAPANESE)
                    {
                        name[7] = EOS;
                        name[6] = name[4];
                        name[5] = name[3];
                        name[4] = name[2];
                        name[3] = name[1];
                        name[2] = name[0];
                        name[1] = 0x15;
                        name[0] = EXT_CTRL_CODE_BEGIN;
                    }
                    else
                    {
                        name[5] = name[7];
                        name[7] = EOS;
                    }
                }
                gTasks[taskId].data[0]++;
            }
            break;
    }
}

void Task_LinkContest_CommunicateRng(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
        default:
            gTasks[taskId].data[0] = 0;
            SwitchTaskToFollowupFunc(taskId);
            break;
        case 0:
            if (GetMultiplayerId() == 0)
            {
                if (IsLinkTaskFinished())
                {
                    SendBlockToAllOpponents(&gRngValue, sizeof(u32));
                    gTasks[taskId].data[0]++;
                }
            }
            else
            {
                gTasks[taskId].data[0]++;
            }
            break;
        case 1:
            if (HasPlayerReceivedBlock(0))
            {
                memcpy(&gRngValue, gBlockRecvBuffer[0], sizeof(u32));
                memcpy(&gContestRngValue, gBlockRecvBuffer[0], sizeof(u32));
                gTasks[taskId].data[0]++;
            }
            break;
    }
}

void Task_LinkContest_CommunicateCategory(u8 taskId)
{
    int i;

    switch (gTasks[taskId].data[0])
    {
        default:
            gTasks[taskId].data[0] = 0;
            SwitchTaskToFollowupFunc(taskId);
            break;
        case 0:
            gBlockSendBuffer[0] = gTasks[taskId].data[9];
            if (GetMultiplayerId() == 0)
            {
                if (IsLinkTaskFinished())
                {
                    sub_8007E9C(2);
                    gTasks[taskId].data[0]++;
                }
            }
            else
            {
                gTasks[taskId].data[0]++;
            }
            break;
        case 1:
            if (HaveAllPlayersReceivedBlock())
            {
                for (i = 0; i < MAX_LINK_PLAYERS; i++)
                {
                    gTasks[taskId].data[i + 1] = gBlockRecvBuffer[i][0];
                }
                gTasks[taskId].data[0]++;
            }
            break;
    }
}

void Task_LinkContest_CommunicateMonIdxs(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
        default:
            gTasks[taskId].data[0] = 0;
            SwitchTaskToFollowupFunc(taskId);
            break;
        case 0:
            if (IsLinkTaskFinished())
            {
                SendBlockToAllOpponents(&gContestPlayerMonIndex, sizeof(u8));
                gTasks[taskId].data[0]++;
            }
            break;
        case 1:
            if (HaveAllPlayersReceivedBlock())
            {
                gTasks[taskId].data[0]++;
            }
            break;
    }
}

void sub_80C8A38(u8 taskId)
{
    int i;

    switch (gTasks[taskId].data[0])
    {
        default:
            gTasks[taskId].data[0] = 0;
            SwitchTaskToFollowupFunc(taskId);
            break;
        case 0:
            if (IsLinkTaskFinished())
            {
                SendBlockToAllOpponents(&sContestantStatus[gContestPlayerMonIndex].currMove, sizeof(u16));
                gTasks[taskId].data[0]++;
            }
            break;
        case 1:
            if (HaveAllPlayersReceivedBlock())
            {
                for (i = 0; i < MAX_LINK_PLAYERS; i++)
                {
                    *&sContestantStatus[i].currMove = gBlockRecvBuffer[i][0];
                }
                gTasks[taskId].data[0]++;
            }
            break;
    }
}

void Task_LinkContest_CommunicateFinalStandings(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
        case 0:
            if (IsLinkTaskFinished())
            {
                SendBlockToAllOpponents(gContestMonTotalPoints, sizeof gContestMonTotalPoints);
                gTasks[taskId].data[0]++;
            }
            break;
        case 1:
            if (HaveAllPlayersReceivedBlock())
            {
                memcpy(gContestMonTotalPoints, gBlockRecvBuffer[gContestLinkLeaderIndex], sizeof gContestMonTotalPoints);
                gTasks[taskId].data[0]++;
            }
            break;
        case 2:
        case 5:
        case 8:
        case 11:
            if (gTasks[taskId].data[1]++ > 10)
            {
                gTasks[taskId].data[1] = 0;
                gTasks[taskId].data[0]++;
            }
            break;
        case 3:
            if (IsLinkTaskFinished())
            {
                SendBlockToAllOpponents(
                    gContestMonAppealPointTotals, sizeof gContestMonAppealPointTotals);
                gTasks[taskId].data[0]++;
            }
            break;
        case 4:
            if (HaveAllPlayersReceivedBlock())
            {
                memcpy(gContestMonAppealPointTotals, gBlockRecvBuffer[gContestLinkLeaderIndex], sizeof gContestMonAppealPointTotals);
                gTasks[taskId].data[0]++;
            }
            break;
        case 6:
            if (IsLinkTaskFinished())
            {
                SendBlockToAllOpponents(gContestMonRound2Points, sizeof gContestMonRound2Points);
                gTasks[taskId].data[0]++;
            }
            break;
        case 7:
            if (HaveAllPlayersReceivedBlock())
            {
                memcpy(gContestMonRound2Points, gBlockRecvBuffer[gContestLinkLeaderIndex], sizeof gContestMonRound2Points);
                gTasks[taskId].data[0]++;
            }
            break;
        case 9:
            if (IsLinkTaskFinished())
            {
                SendBlockToAllOpponents(gContestFinalStandings, sizeof gContestFinalStandings);
                gTasks[taskId].data[0]++;
            }
            break;
        case 10:
            if (HaveAllPlayersReceivedBlock())
            {
                memcpy(gContestFinalStandings, gBlockRecvBuffer[gContestLinkLeaderIndex], sizeof gContestFinalStandings);
                gTasks[taskId].data[0]++;
            }
            break;
        default:
            gTasks[taskId].data[0] = 0;
            SwitchTaskToFollowupFunc(taskId);
            break;
    }
}

void Task_LinkContest_CommunicateAppealsState(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
        case 0:
            if (IsLinkTaskFinished())
            {
                SendBlockToAllOpponents(sContestantStatus, 4 * sizeof(struct ContestantStatus));
                gTasks[taskId].data[0]++;
            }
            break;
        case 1:
            if (HaveAllPlayersReceivedBlock())
            {
                memcpy(sContestantStatus, gBlockRecvBuffer[gContestLinkLeaderIndex], 4 * sizeof(struct ContestantStatus));
                gTasks[taskId].data[0]++;
            }
            break;
        case 2:
        case 5:
        case 8:
        case 11:
            if (gTasks[taskId].data[1]++ > 10)
            {
                gTasks[taskId].data[1] = 0;
                gTasks[taskId].data[0]++;
            }
            break;
        case 3:
            if (IsLinkTaskFinished())
            {
                SendBlockToAllOpponents(&eContestAppealResults, sizeof eContestAppealResults);
                gTasks[taskId].data[0]++;
            }
            break;
        case 4:
            if (HaveAllPlayersReceivedBlock())
            {
                memcpy(&eContestAppealResults, gBlockRecvBuffer[gContestLinkLeaderIndex], sizeof eContestAppealResults);
                gTasks[taskId].data[0]++;
            }
            break;
        case 6:
            if (IsLinkTaskFinished())
            {
                SendBlockToAllOpponents(&eContestExcitement, sizeof eContestExcitement);
                gTasks[taskId].data[0]++;
            }
            break;
        case 7:
            if (HaveAllPlayersReceivedBlock())
            {
                memcpy(&eContestExcitement, gBlockRecvBuffer[gContestLinkLeaderIndex], sizeof eContestExcitement);
                gTasks[taskId].data[0]++;
            }
            break;
        case 9:
            if (IsLinkTaskFinished())
            {
                SendBlockToAllOpponents(gContestantTurnOrder, sizeof gContestantTurnOrder);
                gTasks[taskId].data[0]++;
            }
            break;
        case 10:
            if (HaveAllPlayersReceivedBlock())
            {
                memcpy(gContestantTurnOrder, gBlockRecvBuffer[gContestLinkLeaderIndex], sizeof gContestantTurnOrder);
                gTasks[taskId].data[0]++;
            }
            break;
        default:
            gTasks[taskId].data[0] = 0;
            SwitchTaskToFollowupFunc(taskId);
            break;
    }
}

void Task_LinkContest_CommunicateLeaderIds(u8 taskId)
{
    int i;

    switch (gTasks[taskId].data[0])
    {
        default:
            gTasks[taskId].data[0] = 0;
            SwitchTaskToFollowupFunc(taskId);
            break;
        case 0:
            gBlockSendBuffer[0] = 0x64;
            if (GetMultiplayerId() == 0)
            {
                if (IsLinkTaskFinished())
                {
                    sub_8007E9C(2);
                    gTasks[taskId].data[0]++;
                }
            }
            else
            {
                gTasks[taskId].data[0]++;
            }
            break;
        case 1:
            if (HaveAllPlayersReceivedBlock())
            {
                for (i = 0; i < MAX_LINK_PLAYERS; i++)
                {
                    gTasks[taskId].data[5 + i] = gBlockRecvBuffer[i][0];
                }
                gTasks[taskId].data[0]++;
            }
            break;
    }
}

void Task_LinkContest_CommunicateRound1Points(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
        default:
            gTasks[taskId].data[0] = 0;
            SwitchTaskToFollowupFunc(taskId);
            break;
        case 0:
            if (IsLinkTaskFinished())
            {
                SendBlockToAllOpponents(gContestMonRound1Points, sizeof gContestMonRound1Points);
                gTasks[taskId].data[0]++;
            }
            break;
        case 1:
            if (HaveAllPlayersReceivedBlock())
            {
                memcpy(gContestMonRound1Points, gBlockRecvBuffer[gContestLinkLeaderIndex], sizeof gContestMonRound1Points);
                gTasks[taskId].data[0]++;
            }
            break;
    }
}

void Task_LinkContest_CommunicateTurnOrder(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
        default:
            gTasks[taskId].data[0] = 0;
            SwitchTaskToFollowupFunc(taskId);
            break;
        case 0:
            if (IsLinkTaskFinished())
            {
                SendBlockToAllOpponents(gContestantTurnOrder, sizeof gContestantTurnOrder);
                gTasks[taskId].data[0]++;
            }
            break;
        case 1:
            if (HaveAllPlayersReceivedBlock())
            {
                memcpy(gContestantTurnOrder, gBlockRecvBuffer[gContestLinkLeaderIndex], sizeof gContestantTurnOrder);
                gTasks[taskId].data[0]++;
            }
            break;
    }
}
