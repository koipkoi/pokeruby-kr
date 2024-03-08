#include "constants/species.h"
#include "constants/moves.h"
#include "constants/contest.h"

#define CONTEST_OPPONENT_JIMMY             0
#define CONTEST_OPPONENT_EDITH             1
#define CONTEST_OPPONENT_EVAN              2
#define CONTEST_OPPONENT_KELSEY            3
#define CONTEST_OPPONENT_MADISON           4
#define CONTEST_OPPONENT_RAYMOND           5
#define CONTEST_OPPONENT_GRANT             6
#define CONTEST_OPPONENT_PAIGE             7
#define CONTEST_OPPONENT_ALEC              8
#define CONTEST_OPPONENT_SYDNEY            9
#define CONTEST_OPPONENT_MORRIS           10
#define CONTEST_OPPONENT_MARIAH           11
#define CONTEST_OPPONENT_RUSSELL          12
#define CONTEST_OPPONENT_MELANIE          13
#define CONTEST_OPPONENT_CHANCE           14
#define CONTEST_OPPONENT_KARINA           15
#define CONTEST_OPPONENT_BOBBY            16
#define CONTEST_OPPONENT_CLAIRE           17
#define CONTEST_OPPONENT_WILLIE           18
#define CONTEST_OPPONENT_CASSIDY          19
#define CONTEST_OPPONENT_MORGAN           20
#define CONTEST_OPPONENT_SUMMER           21
#define CONTEST_OPPONENT_MILES            22
#define CONTEST_OPPONENT_AUDREY           23
#define CONTEST_OPPONENT_AVERY            24
#define CONTEST_OPPONENT_ARIANA           25
#define CONTEST_OPPONENT_ASHTON           26
#define CONTEST_OPPONENT_SANDRA           27
#define CONTEST_OPPONENT_CARSON           28
#define CONTEST_OPPONENT_KATRINA          29
#define CONTEST_OPPONENT_RONNIE           30
#define CONTEST_OPPONENT_CLAUDIA          31
#define CONTEST_OPPONENT_ELIAS            32
#define CONTEST_OPPONENT_JADE             33
#define CONTEST_OPPONENT_FRANCIS          34
#define CONTEST_OPPONENT_ALISHA           35
#define CONTEST_OPPONENT_SAUL             36
#define CONTEST_OPPONENT_FELICIA          37
#define CONTEST_OPPONENT_EMILIO           38
#define CONTEST_OPPONENT_KARLA            39
#define CONTEST_OPPONENT_DARRYL           40
#define CONTEST_OPPONENT_SELENA           41
#define CONTEST_OPPONENT_NOEL             42
#define CONTEST_OPPONENT_LACEY            43
#define CONTEST_OPPONENT_CORBIN           44
#define CONTEST_OPPONENT_JUSTINA          45
#define CONTEST_OPPONENT_RALPH            46
#define CONTEST_OPPONENT_ROSA             47
#define CONTEST_OPPONENT_KEATON           48
#define CONTEST_OPPONENT_MAYRA            49
#define CONTEST_OPPONENT_LAMAR            50
#define CONTEST_OPPONENT_AUBREY           51
#define CONTEST_OPPONENT_NIGEL            52
#define CONTEST_OPPONENT_CAMILLE          53
#define CONTEST_OPPONENT_DEON             54
#define CONTEST_OPPONENT_JANELLE          55
#define CONTEST_OPPONENT_HEATH            56
#define CONTEST_OPPONENT_SASHA            57
#define CONTEST_OPPONENT_FRANKIE          58
#define CONTEST_OPPONENT_HELEN            59

// All contest opponents have a common set of AI flags (which contains all of the actually
// useful AI scripts, as well as some dummys) and a random combination of 2-3 dummy flags.
// Seems that like the battle AI they had more plans for this than what ended up in the final game
#define CONTEST_AI_SET_1  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_20 | CONTEST_AI_DUMMY_21)
#define CONTEST_AI_SET_2  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_19 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_3  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_18 | CONTEST_AI_DUMMY_23)
#define CONTEST_AI_SET_4  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_17 | CONTEST_AI_DUMMY_23)
#define CONTEST_AI_SET_5  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_16 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_6  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_15 | CONTEST_AI_DUMMY_22)
#define CONTEST_AI_SET_7  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_14 | CONTEST_AI_DUMMY_23)
#define CONTEST_AI_SET_8  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_13 | CONTEST_AI_DUMMY_21)
#define CONTEST_AI_SET_9  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_12 | CONTEST_AI_DUMMY_24)
#define CONTEST_AI_SET_A  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_11 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_B  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_10 | CONTEST_AI_DUMMY_21)
#define CONTEST_AI_SET_C  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_9  | CONTEST_AI_DUMMY_21)
#define CONTEST_AI_SET_D  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_8  | CONTEST_AI_DUMMY_22 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_E  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_7  | CONTEST_AI_DUMMY_24)
#define CONTEST_AI_SET_F  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_6  | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_10 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_20 | CONTEST_AI_DUMMY_23)
#define CONTEST_AI_SET_11 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_18 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_12 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_17 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_13 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_16 | CONTEST_AI_DUMMY_22)
#define CONTEST_AI_SET_14 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_15 | CONTEST_AI_DUMMY_21)
#define CONTEST_AI_SET_15 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_14 | CONTEST_AI_DUMMY_22)
#define CONTEST_AI_SET_16 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_13 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_17 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_12 | CONTEST_AI_DUMMY_23 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_18 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_10 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_19 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_9  | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_1A (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_8  | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_1B (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_7  | CONTEST_AI_DUMMY_21)
#define CONTEST_AI_SET_1C (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_6  | CONTEST_AI_DUMMY_21)
#define CONTEST_AI_SET_1D (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_20 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_1E (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_15 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_1F (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_14 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_20 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_12 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_21 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_7  | CONTEST_AI_DUMMY_25)

#define CONTEST_OPPONENT_NICKNAME_JIMMY          "포챠"
#define CONTEST_OPPONENT_OTNAME_JIMMY            "건강"
#define CONTEST_OPPONENT_NICKNAME_EDITH          "지그제군"
#define CONTEST_OPPONENT_OTNAME_EDITH            "미아"
#define CONTEST_OPPONENT_NICKNAME_EVAN           "독쿤"
#define CONTEST_OPPONENT_OTNAME_EVAN             "주로"
#define CONTEST_OPPONENT_NICKNAME_KELSEY         "도돌이"
#define CONTEST_OPPONENT_OTNAME_KELSEY           "나주"
#define CONTEST_OPPONENT_NICKNAME_MADISON        "로테일"
#define CONTEST_OPPONENT_OTNAME_MADISON          "혜화"
#define CONTEST_OPPONENT_NICKNAME_RAYMOND        "토중"
#define CONTEST_OPPONENT_OTNAME_RAYMOND          "렌"
#define CONTEST_OPPONENT_NICKNAME_GRANT          "코코"
#define CONTEST_OPPONENT_OTNAME_GRANT            "승인"
#define CONTEST_OPPONENT_NICKNAME_PAIGE          "모매매"
#define CONTEST_OPPONENT_OTNAME_PAIGE            "유이카"
#define CONTEST_OPPONENT_NICKNAME_ALEC           "게을이"
#define CONTEST_OPPONENT_OTNAME_ALEC             "인목"
#define CONTEST_OPPONENT_NICKNAME_SYDNEY         "곤뇽"
#define CONTEST_OPPONENT_OTNAME_SYDNEY           "청이"
#define CONTEST_OPPONENT_NICKNAME_MORRIS         "풍풍"
#define CONTEST_OPPONENT_OTNAME_MORRIS           "명웅"
#define CONTEST_OPPONENT_NICKNAME_MARIAH         "보리"
#define CONTEST_OPPONENT_OTNAME_MARIAH           "청엽"
#define CONTEST_OPPONENT_NICKNAME_RUSSELL        "주뱃이"
#define CONTEST_OPPONENT_OTNAME_RUSSELL          "용수"
#define CONTEST_OPPONENT_NICKNAME_MELANIE        "꼴깍군"
#define CONTEST_OPPONENT_OTNAME_MELANIE          "유우나"
#define CONTEST_OPPONENT_NICKNAME_CHANCE         "라이건"
#define CONTEST_OPPONENT_OTNAME_CHANCE           "신광"
#define CONTEST_OPPONENT_NICKNAME_KARINA         "라비빈"
#define CONTEST_OPPONENT_OTNAME_KARINA           "모모"
#define CONTEST_OPPONENT_NICKNAME_BOBBY          "두둥"
#define CONTEST_OPPONENT_OTNAME_BOBBY            "진팔"
#define CONTEST_OPPONENT_NICKNAME_CLAIRE         "클래러"
#define CONTEST_OPPONENT_OTNAME_CLAIRE           "수정"
#define CONTEST_OPPONENT_NICKNAME_WILLIE         "선선이"
#define CONTEST_OPPONENT_OTNAME_WILLIE           "귀남"
#define CONTEST_OPPONENT_NICKNAME_CASSIDY        "두지군"
#define CONTEST_OPPONENT_OTNAME_CASSIDY          "연두"
#define CONTEST_OPPONENT_NICKNAME_MORGAN         "오뚝"
#define CONTEST_OPPONENT_OTNAME_MORGAN           "완역"
#define CONTEST_OPPONENT_NICKNAME_SUMMER         "둔둔타"
#define CONTEST_OPPONENT_OTNAME_SUMMER           "마오"
#define CONTEST_OPPONENT_NICKNAME_MILES          "얼룩스"
#define CONTEST_OPPONENT_OTNAME_MILES            "정인"
#define CONTEST_OPPONENT_NICKNAME_AUDREY         "코콕"
#define CONTEST_OPPONENT_OTNAME_AUDREY           "조화"
#define CONTEST_OPPONENT_NICKNAME_AVERY          "쭉가"
#define CONTEST_OPPONENT_OTNAME_AVERY            "신행"
#define CONTEST_OPPONENT_NICKNAME_ARIANA         "카멜리"
#define CONTEST_OPPONENT_OTNAME_ARIANA           "교화"
#define CONTEST_OPPONENT_NICKNAME_ASHTON         "콘붕어"
#define CONTEST_OPPONENT_OTNAME_ASHTON           "도현"
#define CONTEST_OPPONENT_NICKNAME_SANDRA         "미끌이"
#define CONTEST_OPPONENT_OTNAME_SANDRA           "사효"
#define CONTEST_OPPONENT_NICKNAME_CARSON         "장조"
#define CONTEST_OPPONENT_OTNAME_CARSON           "순태"
#define CONTEST_OPPONENT_NICKNAME_KATRINA        "연꽃이"
#define CONTEST_OPPONENT_OTNAME_KATRINA          "무혜"
#define CONTEST_OPPONENT_NICKNAME_RONNIE         "도라"
#define CONTEST_OPPONENT_OTNAME_RONNIE           "공효"
#define CONTEST_OPPONENT_NICKNAME_CLAUDIA        "탱이"
#define CONTEST_OPPONENT_OTNAME_CLAUDIA          "자희"
#define CONTEST_OPPONENT_NICKNAME_ELIAS          "아이아이"
#define CONTEST_OPPONENT_OTNAME_ELIAS            "기태"
#define CONTEST_OPPONENT_NICKNAME_JADE           "제비돌이"
#define CONTEST_OPPONENT_OTNAME_JADE             "초미"
#define CONTEST_OPPONENT_NICKNAME_FRANCIS        "그라둥이"
#define CONTEST_OPPONENT_OTNAME_FRANCIS          "할트"
#define CONTEST_OPPONENT_NICKNAME_ALISHA         "뷰티플"
#define CONTEST_OPPONENT_OTNAME_ALISHA           "릴리카"
#define CONTEST_OPPONENT_NICKNAME_SAUL           "콘콘군"
#define CONTEST_OPPONENT_OTNAME_SAUL             "기영"
#define CONTEST_OPPONENT_NICKNAME_FELICIA        "폭발타"
#define CONTEST_OPPONENT_OTNAME_FELICIA          "초선"
#define CONTEST_OPPONENT_NICKNAME_EMILIO         "알통이"
#define CONTEST_OPPONENT_OTNAME_EMILIO           "키요할"
#define CONTEST_OPPONENT_NICKNAME_KARLA          "토스"
#define CONTEST_OPPONENT_OTNAME_KARLA            "시연"
#define CONTEST_OPPONENT_NICKNAME_DARRYL         "스네이키"
#define CONTEST_OPPONENT_OTNAME_DARRYL           "길성"
#define CONTEST_OPPONENT_NICKNAME_SELENA         "그래왕자"
#define CONTEST_OPPONENT_OTNAME_SELENA           "마사"
#define CONTEST_OPPONENT_NICKNAME_NOEL           "킹"
#define CONTEST_OPPONENT_OTNAME_NOEL             "리키"
#define CONTEST_OPPONENT_NICKNAME_LACEY          "초승이"
#define CONTEST_OPPONENT_OTNAME_LACEY            "연화"
#define CONTEST_OPPONENT_NICKNAME_CORBIN         "펠리퍼"
#define CONTEST_OPPONENT_OTNAME_CORBIN           "계남"
#define CONTEST_OPPONENT_NICKNAME_JUSTINA        "갸랑이"
#define CONTEST_OPPONENT_OTNAME_JUSTINA          "용희"
#define CONTEST_OPPONENT_NICKNAME_RALPH          "공길이"
#define CONTEST_OPPONENT_OTNAME_RALPH            "달홍"
#define CONTEST_OPPONENT_NICKNAME_ROSA           "냥이"
#define CONTEST_OPPONENT_OTNAME_ROSA             "아키나"
#define CONTEST_OPPONENT_NICKNAME_KEATON         "게킹"
#define CONTEST_OPPONENT_OTNAME_KEATON           "용식"
#define CONTEST_OPPONENT_NICKNAME_MAYRA          "파비리"
#define CONTEST_OPPONENT_OTNAME_MAYRA            "진준"
#define CONTEST_OPPONENT_NICKNAME_LAMAR          "킬킬"
#define CONTEST_OPPONENT_OTNAME_LAMAR            "등호"
#define CONTEST_OPPONENT_NICKNAME_AUBREY         "큰꽃돌이"
#define CONTEST_OPPONENT_OTNAME_AUBREY           "은희"
#define CONTEST_OPPONENT_NICKNAME_NIGEL          "스컬몽"
#define CONTEST_OPPONENT_OTNAME_NIGEL            "일남"
#define CONTEST_OPPONENT_NICKNAME_CAMILLE        "네이"
#define CONTEST_OPPONENT_OTNAME_CAMILLE          "밀레이"
#define CONTEST_OPPONENT_NICKNAME_DEON           "샤크니"
#define CONTEST_OPPONENT_OTNAME_DEON             "카다몬"
#define CONTEST_OPPONENT_NICKNAME_JANELLE        "사랑동동"
#define CONTEST_OPPONENT_OTNAME_JANELLE          "무민"
#define CONTEST_OPPONENT_NICKNAME_HEATH          "헤라돌이"
#define CONTEST_OPPONENT_OTNAME_HEATH            "가람"
#define CONTEST_OPPONENT_NICKNAME_SASHA          "붐붐"
#define CONTEST_OPPONENT_OTNAME_SASHA            "주하"
#define CONTEST_OPPONENT_NICKNAME_FRANKIE        "피돌이"
#define CONTEST_OPPONENT_OTNAME_FRANKIE          "진택"
#define CONTEST_OPPONENT_NICKNAME_HELEN          "틀려용"
#define CONTEST_OPPONENT_OTNAME_HELEN            "미쿨"

const struct ContestPokemon gContestOpponents[] = {
    [CONTEST_OPPONENT_JIMMY] = {
        .species = SPECIES_POOCHYENA,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_JIMMY),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_JIMMY),
        .trainerGfxId = OBJ_EVENT_GFX_BOY_1,
        .flags = CONTEST_AI_SET_1,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves = { MOVE_ROAR, MOVE_BITE, MOVE_TAKE_DOWN, MOVE_HOWL },
        .cool = 10,
        .beauty = 4,
        .cute = 10,
        .smart = 3,
        .tough = 4,
        .sheen = 50,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_EDITH] = {
        .species = SPECIES_ZIGZAGOON,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_EDITH),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_EDITH),
        .trainerGfxId = OBJ_EVENT_GFX_GIRL_1,
        .flags = CONTEST_AI_SET_2,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves = { MOVE_REST, MOVE_TAIL_WHIP, MOVE_TACKLE, MOVE_COVET },
        .cool = 10,
        .beauty = 10,
        .cute = 6,
        .smart = 1,
        .tough = 2,
        .sheen = 60,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_EVAN] = {
        .species = SPECIES_DUSTOX,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_EVAN),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_EVAN),
        .trainerGfxId = OBJ_EVENT_GFX_LITTLE_BOY_2,
        .flags = CONTEST_AI_SET_3,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves = { MOVE_SILVER_WIND, MOVE_MOONLIGHT, MOVE_LIGHT_SCREEN, MOVE_GUST },
        .cool = 2,
        .beauty = 10,
        .cute = 10,
        .smart = 12,
        .tough = 4,
        .sheen = 70,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_KELSEY] = {
        .species = SPECIES_SEEDOT,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_KELSEY),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_KELSEY),
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_1,
        .flags = CONTEST_AI_SET_4,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves = { MOVE_BIDE, MOVE_SYNTHESIS, MOVE_BULLET_SEED, MOVE_GROWTH },
        .cool = 3,
        .beauty = 3,
        .cute = 5,
        .smart = 2,
        .tough = 7,
        .sheen = 80,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_MADISON] = {
        .species = SPECIES_TAILLOW,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_MADISON),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_MADISON),
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_2,
        .flags = CONTEST_AI_SET_5,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves = { MOVE_WING_ATTACK, MOVE_AGILITY, MOVE_AERIAL_ACE, MOVE_GROWL },
        .cool = 1,
        .beauty = 3,
        .cute = 3,
        .smart = 5,
        .tough = 4,
        .sheen = 90,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_RAYMOND] = {
        .species = SPECIES_NINCADA,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_RAYMOND),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_RAYMOND),
        .trainerGfxId = OBJ_EVENT_GFX_BLACK_BELT,
        .flags = CONTEST_AI_SET_6,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves = { MOVE_LEECH_LIFE, MOVE_FALSE_SWIPE, MOVE_FURY_SWIPES, MOVE_MIND_READER },
        .cool = 5,
        .beauty = 2,
        .cute = 10,
        .smart = 7,
        .tough = 8,
        .sheen = 100,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_GRANT] = {
        .species = SPECIES_SHROOMISH,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_GRANT),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_GRANT),
        .trainerGfxId = OBJ_EVENT_GFX_YOUNGSTER,
        .flags = CONTEST_AI_SET_7,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves = { MOVE_STUN_SPORE, MOVE_LEECH_SEED, MOVE_MEGA_DRAIN, MOVE_ATTRACT },
        .cool = 3,
        .beauty = 3,
        .cute = 10,
        .smart = 2,
        .tough = 2,
        .sheen = 50,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_PAIGE] = {
        .species = SPECIES_WINGULL,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_PAIGE),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_PAIGE),
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_5,
        .flags = CONTEST_AI_SET_8,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves = { MOVE_MIST, MOVE_WATER_GUN, MOVE_GROWL, MOVE_PURSUIT },
        .cool = 3,
        .beauty = 5,
        .cute = 1,
        .smart = 10,
        .tough = 10,
        .sheen = 60,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_ALEC] = {
        .species = SPECIES_SLAKOTH,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_ALEC),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_ALEC),
        .trainerGfxId = OBJ_EVENT_GFX_CAMPER,
        .flags = CONTEST_AI_SET_9,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves = { MOVE_STRENGTH, MOVE_COUNTER, MOVE_YAWN, MOVE_ENCORE },
        .cool = 10,
        .beauty = 4,
        .cute = 4,
        .smart = 5,
        .tough = 18,
        .sheen = 70,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_SYDNEY] = {
        .species = SPECIES_WHISMUR,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_SYDNEY),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_SYDNEY),
        .trainerGfxId = OBJ_EVENT_GFX_LASS,
        .flags = CONTEST_AI_SET_A,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves = { MOVE_ASTONISH, MOVE_SCREECH, MOVE_UPROAR, MOVE_HYPER_VOICE },
        .cool = 2,
        .beauty = 2,
        .cute = 7,
        .smart = 2,
        .tough = 7,
        .sheen = 80,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_MORRIS] = {
        .species = SPECIES_MAKUHITA,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_MORRIS),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_MORRIS),
        .trainerGfxId = OBJ_EVENT_GFX_SCHOOL_KID_M,
        .flags = CONTEST_AI_SET_B,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves = { MOVE_SEISMIC_TOSS, MOVE_VITAL_THROW, MOVE_TACKLE, MOVE_REVERSAL },
        .cool = 9,
        .beauty = 1,
        .cute = 1,
        .smart = 8,
        .tough = 1,
        .sheen = 90,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_MARIAH] = {
        .species = SPECIES_ARON,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_MARIAH),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_MARIAH),
        .trainerGfxId = OBJ_EVENT_GFX_GIRL_2,
        .flags = CONTEST_AI_SET_C,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves = { MOVE_METAL_CLAW, MOVE_IRON_DEFENSE, MOVE_HEADBUTT, MOVE_TAKE_DOWN },
        .cool = 5,
        .beauty = 10,
        .cute = 2,
        .smart = 10,
        .tough = 2,
        .sheen = 100,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_RUSSELL] = {
        .species = SPECIES_ZUBAT,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_RUSSELL),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_RUSSELL),
        .trainerGfxId = OBJ_EVENT_GFX_MAN_4,
        .flags = CONTEST_AI_SET_D,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves = { MOVE_HAZE, MOVE_MEAN_LOOK, MOVE_CONFUSE_RAY, MOVE_LEECH_LIFE },
        .cool = 4,
        .beauty = 2,
        .cute = 2,
        .smart = 2,
        .tough = 10,
        .sheen = 50,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_MELANIE] = {
        .species = SPECIES_GULPIN,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_MELANIE),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_MELANIE),
        .trainerGfxId = OBJ_EVENT_GFX_LITTLE_GIRL_1,
        .flags = CONTEST_AI_SET_E,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves = { MOVE_SLUDGE, MOVE_AMNESIA, MOVE_TOXIC, MOVE_YAWN },
        .cool = 1,
        .beauty = 10,
        .cute = 1,
        .smart = 10,
        .tough = 5,
        .sheen = 60,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_CHANCE] = {
        .species = SPECIES_ELECTRIKE,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_CHANCE),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_CHANCE),
        .trainerGfxId = OBJ_EVENT_GFX_BOY_4,
        .flags = CONTEST_AI_SET_F,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves = { MOVE_SPARK, MOVE_THUNDER_WAVE, MOVE_THUNDER, MOVE_ROAR },
        .cool = 20,
        .beauty = 10,
        .cute = 1,
        .smart = 1,
        .tough = 1,
        .sheen = 70,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_KARINA] = {
        .species = SPECIES_ROSELIA,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_KARINA),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_KARINA),
        .trainerGfxId = OBJ_EVENT_GFX_PICNICKER,
        .flags = CONTEST_AI_SET_10,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves = { MOVE_PETAL_DANCE, MOVE_MAGICAL_LEAF, MOVE_GRASS_WHISTLE, MOVE_INGRAIN },
        .cool = 50,
        .beauty = 15,
        .cute = 75,
        .smart = 10,
        .tough = 20,
        .sheen = 100,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_BOBBY] = {
        .species = SPECIES_DODUO,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_BOBBY),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_BOBBY),
        .trainerGfxId = OBJ_EVENT_GFX_RUNNING_TRIATHLETE_M,
        .flags = CONTEST_AI_SET_2,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves = { MOVE_PECK, MOVE_FURY_ATTACK, MOVE_RETURN, MOVE_GROWL },
        .cool = 15,
        .beauty = 21,
        .cute = 15,
        .smart = 85,
        .tough = 35,
        .sheen = 110,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_CLAIRE] = {
        .species = SPECIES_TRAPINCH,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_CLAIRE),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_CLAIRE),
        .trainerGfxId = OBJ_EVENT_GFX_GIRL_1,
        .flags = CONTEST_AI_SET_11,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves = { MOVE_BITE, MOVE_SAND_ATTACK, MOVE_DIG, MOVE_FAINT_ATTACK },
        .cool = 75,
        .beauty = 25,
        .cute = 25,
        .smart = 10,
        .tough = 25,
        .sheen = 120,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_WILLIE] = {
        .species = SPECIES_CACNEA,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_WILLIE),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_WILLIE),
        .trainerGfxId = OBJ_EVENT_GFX_LITTLE_BOY_2,
        .flags = CONTEST_AI_SET_12,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves = { MOVE_SPIKES, MOVE_LEER, MOVE_POISON_STING, MOVE_SAND_ATTACK },
        .cool = 10,
        .beauty = 30,
        .cute = 25,
        .smart = 65,
        .tough = 25,
        .sheen = 130,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_CASSIDY] = {
        .species = SPECIES_SANDSHREW,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_CASSIDY),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_CASSIDY),
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_2,
        .flags = CONTEST_AI_SET_13,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves = { MOVE_SLASH, MOVE_DEFENSE_CURL, MOVE_SWIFT, MOVE_FURY_SWIPES },
        .cool = 30,
        .beauty = 90,
        .cute = 30,
        .smart = 10,
        .tough = 100,
        .sheen = 140,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_MORGAN] = {
        .species = SPECIES_BALTOY,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_MORGAN),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_MORGAN),
        .trainerGfxId = OBJ_EVENT_GFX_BLACK_BELT,
        .flags = CONTEST_AI_SET_14,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves = { MOVE_SELF_DESTRUCT, MOVE_ROCK_TOMB, MOVE_PSYBEAM, MOVE_CONFUSION },
        .cool = 50,
        .beauty = 40,
        .cute = 10,
        .smart = 35,
        .tough = 35,
        .sheen = 150,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_SUMMER] = {
        .species = SPECIES_NUMEL,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_SUMMER),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_SUMMER),
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_5,
        .flags = CONTEST_AI_SET_15,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves = { MOVE_MAGNITUDE, MOVE_EARTHQUAKE, MOVE_SUNNY_DAY, MOVE_FLAMETHROWER },
        .cool = 40,
        .beauty = 5,
        .cute = 40,
        .smart = 40,
        .tough = 40,
        .sheen = 100,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_MILES] = {
        .species = SPECIES_SPINDA,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_MILES),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_MILES),
        .trainerGfxId = OBJ_EVENT_GFX_CAMPER,
        .flags = CONTEST_AI_SET_16,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves = { MOVE_TEETER_DANCE, MOVE_PSYCH_UP, MOVE_HYPNOSIS, MOVE_UPROAR },
        .cool = 25,
        .beauty = 75,
        .cute = 25,
        .smart = 10,
        .tough = 25,
        .sheen = 110,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_AUDREY] = {
        .species = SPECIES_SWABLU,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_AUDREY),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_AUDREY),
        .trainerGfxId = OBJ_EVENT_GFX_LASS,
        .flags = CONTEST_AI_SET_17,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves = { MOVE_MIRROR_MOVE, MOVE_PERISH_SONG, MOVE_SAFEGUARD, MOVE_MIST },
        .cool = 30,
        .beauty = 30,
        .cute = 40,
        .smart = 30,
        .tough = 25,
        .sheen = 120,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_AVERY] = {
        .species = SPECIES_LINOONE,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_AVERY),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_AVERY),
        .trainerGfxId = OBJ_EVENT_GFX_SCHOOL_KID_M,
        .flags = CONTEST_AI_SET_A,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves = { MOVE_GROWL, MOVE_COVET, MOVE_SAND_ATTACK, MOVE_REST },
        .cool = 40,
        .beauty = 40,
        .cute = 30,
        .smart = 10,
        .tough = 30,
        .sheen = 130,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_ARIANA] = {
        .species = SPECIES_KECLEON,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_ARIANA),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_ARIANA),
        .trainerGfxId = OBJ_EVENT_GFX_GIRL_2,
        .flags = CONTEST_AI_SET_18,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves = { MOVE_THIEF, MOVE_SCREECH, MOVE_ANCIENT_POWER, MOVE_BIND },
        .cool = 10,
        .beauty = 10,
        .cute = 40,
        .smart = 75,
        .tough = 35,
        .sheen = 140,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_ASHTON] = {
        .species = SPECIES_GOLDEEN,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_ASHTON),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_ASHTON),
        .trainerGfxId = OBJ_EVENT_GFX_MAN_4,
        .flags = CONTEST_AI_SET_19,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves = { MOVE_HORN_ATTACK, MOVE_FURY_ATTACK, MOVE_HORN_DRILL, MOVE_TAIL_WHIP },
        .cool = 70,
        .beauty = 30,
        .cute = 5,
        .smart = 30,
        .tough = 25,
        .sheen = 150,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_SANDRA] = {
        .species = SPECIES_BARBOACH,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_SANDRA),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_SANDRA),
        .trainerGfxId = OBJ_EVENT_GFX_LITTLE_GIRL_1,
        .flags = CONTEST_AI_SET_1A,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves = { MOVE_MUD_SPORT, MOVE_WATER_SPORT, MOVE_EARTHQUAKE, MOVE_FUTURE_SIGHT },
        .cool = 45,
        .beauty = 45,
        .cute = 60,
        .smart = 25,
        .tough = 15,
        .sheen = 100,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_CARSON] = {
        .species = SPECIES_SKARMORY,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_CARSON),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_CARSON),
        .trainerGfxId = OBJ_EVENT_GFX_YOUNGSTER,
        .flags = CONTEST_AI_SET_1B,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves = { MOVE_SWIFT, MOVE_DOUBLE_TEAM, MOVE_AGILITY, MOVE_CUT },
        .cool = 40,
        .beauty = 30,
        .cute = 25,
        .smart = 60,
        .tough = 20,
        .sheen = 110,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_KATRINA] = {
        .species = SPECIES_LOTAD,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_KATRINA),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_KATRINA),
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_1,
        .flags = CONTEST_AI_SET_1C,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves = { MOVE_ASTONISH, MOVE_GROWL, MOVE_RAIN_DANCE, MOVE_WATER_PULSE },
        .cool = 15,
        .beauty = 15,
        .cute = 30,
        .smart = 15,
        .tough = 75,
        .sheen = 120,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_RONNIE] = {
        .species = SPECIES_LAIRON,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_RONNIE),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_RONNIE),
        .trainerGfxId = OBJ_EVENT_GFX_HIKER,
        .flags = CONTEST_AI_SET_1D,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves = { MOVE_METAL_SOUND, MOVE_METAL_CLAW, MOVE_HARDEN, MOVE_TAKE_DOWN },
        .cool = 30,
        .beauty = 50,
        .cute = 35,
        .smart = 100,
        .tough = 90,
        .sheen = 200,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_CLAUDIA] = {
        .species = SPECIES_NUZLEAF,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_CLAUDIA),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_CLAUDIA),
        .trainerGfxId = OBJ_EVENT_GFX_GIRL_1,
        .flags = CONTEST_AI_SET_2,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves = { MOVE_GROWTH, MOVE_RAZOR_WIND, MOVE_EXPLOSION, MOVE_EXTRASENSORY },
        .cool = 75,
        .beauty = 75,
        .cute = 65,
        .smart = 35,
        .tough = 70,
        .sheen = 210,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_ELIAS] = {
        .species = SPECIES_NINJASK,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_ELIAS),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_ELIAS),
        .trainerGfxId = OBJ_EVENT_GFX_LITTLE_BOY_2,
        .flags = CONTEST_AI_SET_11,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves = { MOVE_SCREECH, MOVE_FURY_SWIPES, MOVE_SAND_ATTACK, MOVE_BATON_PASS },
        .cool = 30,
        .beauty = 50,
        .cute = 95,
        .smart = 70,
        .tough = 70,
        .sheen = 220,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_JADE] = {
        .species = SPECIES_SWELLOW,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_JADE),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_JADE),
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_2,
        .flags = CONTEST_AI_SET_12,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves = { MOVE_AGILITY, MOVE_AERIAL_ACE, MOVE_WING_ATTACK, MOVE_FLY },
        .cool = 65,
        .beauty = 85,
        .cute = 35,
        .smart = 75,
        .tough = 40,
        .sheen = 230,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_FRANCIS] = {
        .species = SPECIES_MIGHTYENA,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_FRANCIS),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_FRANCIS),
        .trainerGfxId = OBJ_EVENT_GFX_BLACK_BELT,
        .flags = CONTEST_AI_SET_5,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves = { MOVE_TAUNT, MOVE_THIEF, MOVE_ODOR_SLEUTH, MOVE_TAKE_DOWN },
        .cool = 40,
        .beauty = 80,
        .cute = 35,
        .smart = 70,
        .tough = 70,
        .sheen = 240,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_ALISHA] = {
        .species = SPECIES_BEAUTIFLY,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_ALISHA),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_ALISHA),
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_5,
        .flags = CONTEST_AI_SET_1E,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves = { MOVE_MORNING_SUN, MOVE_SILVER_WIND, MOVE_STUN_SPORE, MOVE_SECRET_POWER },
        .cool = 40,
        .beauty = 70,
        .cute = 25,
        .smart = 80,
        .tough = 100,
        .sheen = 250,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_SAUL] = {
        .species = SPECIES_SEAKING,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_SAUL),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_SAUL),
        .trainerGfxId = OBJ_EVENT_GFX_CAMPER,
        .flags = CONTEST_AI_SET_1F,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves = { MOVE_FLAIL, MOVE_SUPERSONIC, MOVE_HORN_ATTACK, MOVE_FURY_ATTACK },
        .cool = 80,
        .beauty = 60,
        .cute = 30,
        .smart = 70,
        .tough = 90,
        .sheen = 200,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_FELICIA] = {
        .species = SPECIES_CAMERUPT,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_FELICIA),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_FELICIA),
        .trainerGfxId = OBJ_EVENT_GFX_LASS,
        .flags = CONTEST_AI_SET_16,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves = { MOVE_EARTHQUAKE, MOVE_FISSURE, MOVE_OVERHEAT, MOVE_HYPER_BEAM },
        .cool = 100,
        .beauty = 80,
        .cute = 20,
        .smart = 50,
        .tough = 65,
        .sheen = 210,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_EMILIO] = {
        .species = SPECIES_MACHOP,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_EMILIO),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_EMILIO),
        .trainerGfxId = OBJ_EVENT_GFX_SCHOOL_KID_M,
        .flags = CONTEST_AI_SET_20,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves = { MOVE_SEISMIC_TOSS, MOVE_FOCUS_ENERGY, MOVE_KARATE_CHOP, MOVE_SCARY_FACE },
        .cool = 70,
        .beauty = 85,
        .cute = 25,
        .smart = 60,
        .tough = 50,
        .sheen = 220,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_KARLA] = {
        .species = SPECIES_LOMBRE,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_KARLA),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_KARLA),
        .trainerGfxId = OBJ_EVENT_GFX_GIRL_2,
        .flags = CONTEST_AI_SET_A,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves = { MOVE_ATTRACT, MOVE_FLASH, MOVE_UPROAR, MOVE_GROWL },
        .cool = 40,
        .beauty = 60,
        .cute = 90,
        .smart = 45,
        .tough = 70,
        .sheen = 230,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_DARRYL] = {
        .species = SPECIES_SEVIPER,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_DARRYL),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_DARRYL),
        .trainerGfxId = OBJ_EVENT_GFX_MAN_4,
        .flags = CONTEST_AI_SET_18,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves = { MOVE_POISON_FANG, MOVE_GLARE, MOVE_WRAP, MOVE_SCREECH },
        .cool = 35,
        .beauty = 50,
        .cute = 90,
        .smart = 40,
        .tough = 100,
        .sheen = 240,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_SELENA] = {
        .species = SPECIES_WAILMER,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_SELENA),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_SELENA),
        .trainerGfxId = OBJ_EVENT_GFX_OLD_WOMAN_1,
        .flags = CONTEST_AI_SET_19,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves = { MOVE_WATER_PULSE, MOVE_REST, MOVE_WATER_SPOUT, MOVE_SPLASH },
        .cool = 30,
        .beauty = 100,
        .cute = 100,
        .smart = 50,
        .tough = 30,
        .sheen = 250,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_NOEL] = {
        .species = SPECIES_MAGIKARP,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_NOEL),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_NOEL),
        .trainerGfxId = OBJ_EVENT_GFX_YOUNGSTER,
        .flags = CONTEST_AI_SET_1A,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves = { MOVE_TACKLE, MOVE_SPLASH, MOVE_FLAIL, MOVE_TACKLE },
        .cool = 30,
        .beauty = 30,
        .cute = 160,
        .smart = 50,
        .tough = 160,
        .sheen = 255,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_LACEY] = {
        .species = SPECIES_LUNATONE,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_LACEY),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_LACEY),
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_1,
        .flags = CONTEST_AI_SET_21,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves = { MOVE_EXPLOSION, MOVE_FUTURE_SIGHT, MOVE_PSYCHIC, MOVE_CONFUSION },
        .cool = 50,
        .beauty = 70,
        .cute = 60,
        .smart = 70,
        .tough = 50,
        .sheen = 210,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_CORBIN] = {
        .species = SPECIES_PELIPPER,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_CORBIN),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_CORBIN),
        .trainerGfxId = OBJ_EVENT_GFX_MANIAC,
        .flags = CONTEST_AI_SET_F,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves = { MOVE_MIST, MOVE_HAIL, MOVE_HYPER_BEAM, MOVE_WING_ATTACK },
        .cool = 95,
        .beauty = 80,
        .cute = 85,
        .smart = 35,
        .tough = 35,
        .sheen = 220,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_JUSTINA] = {
        .species = SPECIES_GYARADOS,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_JUSTINA),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_JUSTINA),
        .trainerGfxId = OBJ_EVENT_GFX_PICNICKER,
        .flags = CONTEST_AI_SET_1D,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves = { MOVE_HYPER_BEAM, MOVE_HYDRO_PUMP, MOVE_RAIN_DANCE, MOVE_BITE },
        .cool = 160,
        .beauty = 200,
        .cute = 20,
        .smart = 40,
        .tough = 160,
        .sheen = 255,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_RALPH] = {
        .species = SPECIES_LOUDRED,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_RALPH),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_RALPH),
        .trainerGfxId = OBJ_EVENT_GFX_OLD_MAN_1,
        .flags = CONTEST_AI_SET_2,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves = { MOVE_HYPER_VOICE, MOVE_STOMP, MOVE_ROAR, MOVE_HOWL },
        .cool = 170,
        .beauty = 50,
        .cute = 55,
        .smart = 150,
        .tough = 160,
        .sheen = 255,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_ROSA] = {
        .species = SPECIES_DELCATTY,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_ROSA),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_ROSA),
        .trainerGfxId = OBJ_EVENT_GFX_GIRL_1,
        .flags = CONTEST_AI_SET_11,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves = { MOVE_ATTRACT, MOVE_ASSIST, MOVE_FAINT_ATTACK, MOVE_TAIL_WHIP },
        .cool = 40,
        .beauty = 200,
        .cute = 150,
        .smart = 185,
        .tough = 60,
        .sheen = 255,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_KEATON] = {
        .species = SPECIES_SLAKING,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_KEATON),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_KEATON),
        .trainerGfxId = OBJ_EVENT_GFX_LITTLE_BOY_2,
        .flags = CONTEST_AI_SET_12,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves = { MOVE_COVET, MOVE_COUNTER, MOVE_ENCORE, MOVE_SLACK_OFF },
        .cool = 85,
        .beauty = 85,
        .cute = 170,
        .smart = 110,
        .tough = 150,
        .sheen = 255,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_MAYRA] = {
        .species = SPECIES_ALTARIA,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_MAYRA),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_MAYRA),
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_2,
        .flags = CONTEST_AI_SET_5,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves = { MOVE_DRAGON_DANCE, MOVE_HYPER_BEAM, MOVE_PERISH_SONG, MOVE_SAFEGUARD },
        .cool = 170,
        .beauty = 150,
        .cute = 30,
        .smart = 30,
        .tough = 90,
        .sheen = 255,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_LAMAR] = {
        .species = SPECIES_KIRLIA,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_LAMAR),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_LAMAR),
        .trainerGfxId = OBJ_EVENT_GFX_BOY_4,
        .flags = CONTEST_AI_SET_1E,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves = { MOVE_SHOCK_WAVE, MOVE_SHADOW_BALL, MOVE_SKILL_SWAP, MOVE_RETURN },
        .cool = 230,
        .beauty = 60,
        .cute = 60,
        .smart = 230,
        .tough = 80,
        .sheen = 255,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_AUBREY] = {
        .species = SPECIES_VILEPLUME,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_AUBREY),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_AUBREY),
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_5,
        .flags = CONTEST_AI_SET_1F,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves = { MOVE_PETAL_DANCE, MOVE_SWEET_SCENT, MOVE_STUN_SPORE, MOVE_FLASH },
        .cool = 35,
        .beauty = 200,
        .cute = 150,
        .smart = 130,
        .tough = 40,
        .sheen = 255,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_NIGEL] = {
        .species = SPECIES_DUSKULL,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_NIGEL),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_NIGEL),
        .trainerGfxId = OBJ_EVENT_GFX_CAMPER,
        .flags = CONTEST_AI_SET_16,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves = { MOVE_DISABLE, MOVE_FUTURE_SIGHT, MOVE_NIGHT_SHADE, MOVE_PURSUIT },
        .cool = 25,
        .beauty = 35,
        .cute = 230,
        .smart = 150,
        .tough = 160,
        .sheen = 255,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_CAMILLE] = {
        .species = SPECIES_XATU,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_CAMILLE),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_CAMILLE),
        .trainerGfxId = OBJ_EVENT_GFX_LASS,
        .flags = CONTEST_AI_SET_20,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves = { MOVE_NIGHT_SHADE, MOVE_FUTURE_SIGHT, MOVE_CONFUSE_RAY, MOVE_PSYCHIC },
        .cool = 35,
        .beauty = 35,
        .cute = 150,
        .smart = 130,
        .tough = 170,
        .sheen = 255,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_DEON] = {
        .species = SPECIES_SHARPEDO,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_DEON),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_DEON),
        .trainerGfxId = OBJ_EVENT_GFX_SCHOOL_KID_M,
        .flags = CONTEST_AI_SET_A,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves = { MOVE_AGILITY, MOVE_SWAGGER, MOVE_TAUNT, MOVE_TAKE_DOWN },
        .cool = 140,
        .beauty = 70,
        .cute = 140,
        .smart = 75,
        .tough = 100,
        .sheen = 255,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_JANELLE] = {
        .species = SPECIES_LUVDISC,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_JANELLE),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_JANELLE),
        .trainerGfxId = OBJ_EVENT_GFX_GIRL_2,
        .flags = CONTEST_AI_SET_18,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves = { MOVE_SWEET_KISS, MOVE_ATTRACT, MOVE_TAKE_DOWN, MOVE_CHARM },
        .cool = 50,
        .beauty = 100,
        .cute = 220,
        .smart = 40,
        .tough = 190,
        .sheen = 255,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_HEATH] = {
        .species = SPECIES_HERACROSS,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_HEATH),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_HEATH),
        .trainerGfxId = OBJ_EVENT_GFX_MAN_4,
        .flags = CONTEST_AI_SET_19,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves = { MOVE_STRENGTH, MOVE_ENDURE, MOVE_REVERSAL, MOVE_ROCK_TOMB },
        .cool = 170,
        .beauty = 70,
        .cute = 110,
        .smart = 240,
        .tough = 140,
        .sheen = 255,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_SASHA] = {
        .species = SPECIES_ELECTRODE,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_SASHA),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_SASHA),
        .trainerGfxId = OBJ_EVENT_GFX_LITTLE_GIRL_1,
        .flags = CONTEST_AI_SET_1A,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves = { MOVE_EXPLOSION, MOVE_LIGHT_SCREEN, MOVE_SWIFT, MOVE_FLASH },
        .cool = 200,
        .beauty = 200,
        .cute = 30,
        .smart = 35,
        .tough = 50,
        .sheen = 255,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_FRANKIE] = {
        .species = SPECIES_PICHU,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_FRANKIE),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_FRANKIE),
        .trainerGfxId = OBJ_EVENT_GFX_YOUNGSTER,
        .flags = CONTEST_AI_SET_21,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves = { MOVE_SWEET_KISS, MOVE_ATTRACT, MOVE_REST, MOVE_TAIL_WHIP },
        .cool = 25,
        .beauty = 150,
        .cute = 180,
        .smart = 115,
        .tough = 120,
        .sheen = 255,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_HELEN] = {
        .species = SPECIES_WOBBUFFET,
        .nickname = _(CONTEST_OPPONENT_NICKNAME_HELEN),
        .trainerName = _(CONTEST_OPPONENT_OTNAME_HELEN),
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_1,
        .flags = CONTEST_AI_SET_F,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves = { MOVE_COUNTER, MOVE_MIRROR_COAT, MOVE_SAFEGUARD, MOVE_DESTINY_BOND },
        .cool = 60,
        .beauty = 230,
        .cute = 50,
        .smart = 220,
        .tough = 210,
        .sheen = 255,
        .personality = 0,
        .otId = 0xFFFF
    },
};
