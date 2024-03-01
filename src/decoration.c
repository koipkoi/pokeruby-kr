#include "global.h"
#include "constants/decorations.h"
#include "main.h"
#include "constants/event_objects.h"
#include "overworld.h"
#include "sound.h"
#include "constants/songs.h"
#include "string_util.h"
#include "menu.h"
#include "menu_helpers.h"
#include "strings.h"
#include "script.h"
#include "palette.h"
#include "field_player_avatar.h"
#include "field_camera.h"
#include "field_fadetransition.h"
#include "fieldmap.h"
#include "metatile_behavior.h"
#include "event_data.h"
#include "field_weather.h"
#include "decoration.h"
#include "decoration_inventory.h"
#include "shop.h"
#include "ewram.h"

EWRAM_DATA u8 *gUnknown_020388D0 = NULL;
EWRAM_DATA u8 gUnknown_020388D4 = 0;
EWRAM_DATA u8 gUnknown_020388D5 = 0;
EWRAM_DATA u8 gUnknown_020388D6[16] = {0};
EWRAM_DATA u8 gUnknown_020388E6[12] = {0};
EWRAM_DATA u8 gUnknown_020388F2 = 0;
EWRAM_DATA u8 gUnknown_020388F3 = 0;
EWRAM_DATA u8 gUnknown_020388F4 = 0;
EWRAM_DATA u8 gUnknown_020388F5 = 0;
EWRAM_DATA u8 gUnknown_020388F6 = 0;
EWRAM_DATA u8 gUnknown_020388F7[8] = {0};
EWRAM_DATA struct UnkStruct_02038900 gUnknown_02038900 = {0};
EWRAM_DATA u16 gUnknown_020391A4 = 0;
EWRAM_DATA u16 gUnknown_020391A6 = 0;
EWRAM_DATA u8 gUnknown_020391A8 = 0;
EWRAM_DATA u8 gUnknown_020391A9 = 0;
EWRAM_DATA u8 gUnknown_020391AA = 0;
EWRAM_DATA struct OamData gUnknown_020391AC = {0};
EWRAM_DATA struct UnkStruct_020391B4 gUnknown_020391B4[16] = {0};
EWRAM_DATA u8 gUnknown_02039234 = 0;

const u8 DecorDesc_SMALL_DESK[] = _(
    "1인용 사이즈의\n"
    "작은 책상");

const u8 DecorDesc_POKEMON_DESK[] = _(
    "몬스터볼 형태의\n"
    "작은 책상");

const u8 DecorDesc_HEAVY_DESK[] = _(
    "철로 만들어진\n"
	"큰 책상\n"
    "위에 물건을 놓을 수 있다");

const u8 DecorDesc_RAGGED_DESK[] = _(
    "나무로 만들어진\n"
	"큰 책상\n"
    "위에 물건을 놓을 수 있다");

const u8 DecorDesc_COMFORT_DESK[] = _(
    "나뭇잎으로 만들어진\n"
    "큰 책상\n"
    "위에 물건을 놓을 수 있다");

const u8 DecorDesc_PRETTY_DESK[] = _(
    "유리로 만들어진\n"
    "거대한 책상\n"
    "많은 물건을 놓을 수 있다");

const u8 DecorDesc_BRICK_DESK[] = _(
    "벽돌로 만들어진\n"
    "거대한 책상\n"
    "많은 물건을 놓을 수 있다");

const u8 DecorDesc_CAMP_DESK[] = _(
    "통나무로 만들어진\n"
    "거대한 책상\n"
    "많은 물건을 놓을 수 있다");

const u8 DecorDesc_HARD_DESK[] = _(
    "돌로 만들어진\n"
    "거대한 책상\n"
    "많은 물건을 놓을 수 있다");

const u8 DecorDesc_SMALL_CHAIR[] = _(
    "혼자 앉는\n"
    "작은 의자");

const u8 DecorDesc_POKEMON_CHAIR[] = _(
    "몬스터볼\n"
    "형태의\n"
    "작은 의자");

const u8 DecorDesc_HEAVY_CHAIR[] = _(
    "철로 만들어진\n"
    "작은 의자");

const u8 DecorDesc_PRETTY_CHAIR[] = _(
    "유리로 만들어진\n"
    "작은 의자");

const u8 DecorDesc_COMFORT_CHAIR[] = _(
    "나뭇잎으로 만들어진\n"
    "작은 의자");

const u8 DecorDesc_RAGGED_CHAIR[] = _(
    "나무로 만들어진\n"
    "작은 의자");

const u8 DecorDesc_BRICK_CHAIR[] = _(
    "벽돌로 만들어진\n"
    "작은 의자");

const u8 DecorDesc_CAMP_CHAIR[] = _(
    "통나무로 만들어진\n"
    "작은 의자");

const u8 DecorDesc_HARD_CHAIR[] = _(
    "돌로 만들어진\n"
    "작은 의자");

const u8 DecorDesc_RED_PLANT[] = _(
    "새빨간 꽃이\n"
    "피어 있는 화분");

const u8 DecorDesc_TROPICAL_PLANT[] = _(
    "남국의 꽃이\n"
    "피어 있는 화분");

const u8 DecorDesc_PRETTY_FLOWERS[] = _(
    "귀여운 꽃이\n"
    "피어 있는 화분");

const u8 DecorDesc_COLORFUL_PLANT[] = _(
    "여러 가지 꽃이\n"
    "피어 있는\n"
    "큰 화분");

const u8 DecorDesc_BIG_PLANT[] = _(
    "우산 같은\n"
    "형태를 한\n"
    "큰 화분");

const u8 DecorDesc_GORGEOUS_PLANT[] = _(
    "훌륭한 나무가\n"
    "심어져 있는 화분");

const u8 DecorDesc_RED_BRICK[] = _(
    "빨간색 벽돌\n"
    "위에 물건을 놓을 수 있다");

const u8 DecorDesc_YELLOW_BRICK[] = _(
    "노란색 벽돌\n"
    "위에 물건을 놓을 수 있다");

const u8 DecorDesc_BLUE_BRICK[] = _(
    "파란색 벽돌\n"
    "위에 물건을 놓을 수 있다");

const u8 DecorDesc_RED_BALLOON[] = _(
    "물이 들어 있는\n"
    "빨간 풍선\n"
    "밟으면 터진다");

const u8 DecorDesc_BLUE_BALLOON[] = _(
    "물이 들어 있는\n"
    "파란 풍선\n"
    "밟으면 터진다");

const u8 DecorDesc_YELLOW_BALLOON[] = _(
    "물이 들어 있는\n"
    "노란 풍선\n"
    "밟으면 터진다");

const u8 DecorDesc_RED_TENT[] = _(
    "크고 빨간 텐트\n"
    "안에 들어갈 수 있다");

const u8 DecorDesc_BLUE_TENT[] = _(
    "크고 파란 텐트\n"
    "안에 들어갈 수 있다");

const u8 DecorDesc_SOLID_BOARD[] = _(
    "구멍 위에 놓으면\n"
    "다리처럼 건널 수 있다");

const u8 DecorDesc_SLIDE[] = _(
    "미끄럼대 위에서\n"
	"미끄러지며\n"
    "내려올 수 있다");

const u8 DecorDesc_FENCE_LENGTH[] = _(
    "작은 울타리\n"
    "지나갈 수 없다");

const u8 DecorDesc_FENCE_WIDTH[] = _(
    "작은 울타리\n"
    "지나갈 수 없다");

const u8 DecorDesc_TIRE[] = _(
    "낡고 큰 타이어\n"
    "위에 물건을 놓을 수 있다");

const u8 DecorDesc_STAND[] = _(
    "계단 위를 걸어\n"
    "미끄럼대에 올라간다");

const u8 DecorDesc_MUD_BALL[] = _(
    "둥근 진흙경단\n"
    "밟으면 부서진다");

const u8 DecorDesc_BREAKABLE_DOOR[] = _(
    "빠져나갈 수 있는\n"
    "이상한 도어");

const u8 DecorDesc_SAND_ORNAMENT[] = _(
    "만지면 무너지는\n"
    "모래 장식품");

const u8 DecorDesc_SILVER_SHIELD[] = _(
    "배틀타워에서\n"
    "50명 연승한\n"
    "기념의 상패");

const u8 DecorDesc_GOLD_SHIELD[] = _(
    "배틀타워에서\n"
    "100명 연승한\n"
    "기념의 상패");

const u8 DecorDesc_GLASS_ORNAMENT[] = _(
    "미술관에 있는\n"
    "유명한 조각을\n"
    "유리로 본떠 만든 것");

const u8 DecorDesc_TV[] = _(
    "회색빛의 작은\n"
    "장난감 TV");

const u8 DecorDesc_ROUND_TV[] = _(
    "도토링을 모델로 하여\n"
    "만들어진\n"
    "장난감 TV");

const u8 DecorDesc_CUTE_TV[] = _(
    "에나비를 모델로 하여\n"
    "만들어진\n"
    "장난감 TV");

const u8 DecorDesc_GLITTER_MAT[] = _(
    "밟으면 반짝이는\n"
    "이상한 매트");

const u8 DecorDesc_JUMP_MAT[] = _(
    "밟으면 점프하는\n"
    "짓궂은 매트");

const u8 DecorDesc_SPIN_MAT[] = _(
    "밟으면 빙글빙글 도는\n"
    "짖궂은 매트");

const u8 DecorDesc_C_LOW_NOTE_MAT[] = _(
    "밟으면 도에 해당하는\n"
    "소리가 나는 매트");

const u8 DecorDesc_D_NOTE_MAT[] = _(
    "밟으면 레에 해당하는\n"
    "소리가 나는 매트");

const u8 DecorDesc_E_NOTE_MAT[] = _(
    "밟으면 미에 해당하는\n"
    "소리가 나는 매트");

const u8 DecorDesc_F_NOTE_MAT[] = _(
    "밟으면 파에 해당하는\n"
    "소리가 나는 매트");

const u8 DecorDesc_G_NOTE_MAT[] = _(
    "밟으면 솔에 해당하는\n"
    "소리가 나는 매트");

const u8 DecorDesc_A_NOTE_MAT[] = _(
    "밟으면 라에 해당하는\n"
    "소리가 나는 매트");

const u8 DecorDesc_B_NOTE_MAT[] = _(
    "밟으면 시에 해당하는\n"
    "소리가 나는 매트");

const u8 DecorDesc_C_HIGH_NOTE_MAT[] = _(
    "밟으면 높은 도에 해당하는\n"
    "소리가 나는 매트");

const u8 DecorDesc_SURF_MAT[] = _(
    "파도타기의 표현으로\n"
    "만들어진 매트\n"
    "위에 물건을 놓을 수 있다");

const u8 DecorDesc_THUNDER_MAT[] = _(
    "번개의 표현으로\n"
    "만들어진 매트\n"
    "위에 물건을 놓을 수 있다");

const u8 DecorDesc_FIRE_BLAST_MAT[] = _(
    "불대문자의 표현으로\n"
    "만들어진 매트\n"
    "위에 물건을 놓을 수 있다");

const u8 DecorDesc_POWDER_SNOW_MAT[] = _(
    "눈싸라기의 표현으로\n"
    "만들어진 매트\n"
    "위에 물건을 놓을 수 있다");

const u8 DecorDesc_ATTRACT_MAT[] = _(
    "헤롱헤롱의 표현으로\n"
    "만들어진 매트\n"
    "위에 물건을 놓을 수 있다");

const u8 DecorDesc_FISSURE_MAT[] = _(
    "땅가르기의 표현으로\n"
    "만들어진 매트\n"
    "위에 물건을 놓을 수 있다");

const u8 DecorDesc_SPIKES_MAT[] = _(
    "압정뿌리기의 표현으로\n"
    "만들어진 매트\n"
    "위에 물건을 놓을 수 있다");

const u8 DecorDesc_BALL_POSTER[] = _(
    "몬스터볼이\n"
    "프린트되어 있는\n"
    "작은 포스터");

const u8 DecorDesc_GREEN_POSTER[] = _(
    "나무지기가\n"
    "프린트되어 있는\n"
    "작은 포스터");

const u8 DecorDesc_RED_POSTER[] = _(
    "아차모가\n"
    "프린트되어 있는\n"
    "작은 포스터");

const u8 DecorDesc_BLUE_POSTER[] = _(
    "물짱이가\n"
    "프린트되어 있는\n"
    "작은 포스터");

const u8 DecorDesc_CUTE_POSTER[] = _(
    "루리리가\n"
    "프린트되어 있는\n"
    "작은 포스터");

const u8 DecorDesc_PIKA_POSTER[] = _(
    "피카츄와 피츄가\n"
    "프린트되어 있는\n"
    "큰 포스터");

const u8 DecorDesc_LONG_POSTER[] = _(
    "세비퍼가\n"
    "프린트되어 있는\n"
    "큰 포스터");

const u8 DecorDesc_SEA_POSTER[] = _(
    "시라칸이\n"
    "프린트되어 있는\n"
    "큰 포스터");

const u8 DecorDesc_SKY_POSTER[] = _(
    "갈모매가\n"
    "프린트되어 있는\n"
    "큰 포스터");

const u8 DecorDesc_KISS_POSTER[] = _(
    "뽀뽀라가\n"
    "프린트되어 있는\n"
    "큰 포스터");

const u8 DecorDesc_PICHU_DOLL[] = _(
    "피츄의 봉제인형\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_PIKACHU_DOLL[] = _(
    "피카츄의 봉제인형\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_MARILL_DOLL[] = _(
    "마릴의 봉제인형\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_TOGEPI_DOLL[] = _(
    "토게피의 봉제인형\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_CYNDAQUIL_DOLL[] = _(
    "브케인의 봉제인형\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_CHIKORITA_DOLL[] = _(
    "치코리타의 봉제인형\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_TOTODILE_DOLL[] = _(
    "리아코의 봉제인형\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_JIGGLYPUFF_DOLL[] = _(
    "푸린의 봉제인형\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_MEOWTH_DOLL[] = _(
    "나옹의 봉제인형\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_CLEFAIRY_DOLL[] = _(
    "삐삐의 봉제인형\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_DITTO_DOLL[] = _(
    "메타몽의 봉제인형\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_SMOOCHUM_DOLL[] = _(
    "뽀뽀라의 봉제인형\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_TREECKO_DOLL[] = _(
    "나무지기의 봉제인형\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_TORCHIC_DOLL[] = _(
    "아차모의 봉제인형\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_MUDKIP_DOLL[] = _(
    "물짱이의 봉제인형\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_DUSKULL_DOLL[] = _(
    "해골몽의 봉제인형\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_WYNAUT_DOLL[] = _(
    "마자의 봉제인형\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_BALTOY_DOLL[] = _(
    "오뚝군의 봉제인형\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_KECLEON_DOLL[] = _(
    "켈리몬의 봉제인형\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_AZURILL_DOLL[] = _(
    "루리리의 봉제인형\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_SKITTY_DOLL[] = _(
    "에나비의 봉제인형\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_SWABLU_DOLL[] = _(
    "파비코의 봉제인형\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_GULPIN_DOLL[] = _(
    "꼴깍몬의 봉제인형\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_LOTAD_DOLL[] = _(
    "연꽃몬의 봉제인형\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_SEEDOT_DOLL[] = _(
    "도토링의 봉제인형\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_PIKA_CUSHION[] = _(
    "피카츄 쿠션\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_ROUND_CUSHION[] = _(
    "마릴리 쿠션\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_KISS_CUSHION[] = _(
    "뽀뽀라 쿠션\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_ZIGZAG_CUSHION[] = _(
    "지그제구리 쿠션\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_SPIN_CUSHION[] = _(
    "얼루기 쿠션\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_DIAMOND_CUSHION[] = _(
    "깜까미 쿠션\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_BALL_CUSHION[] = _(
    "볼 쿠션\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_GRASS_CUSHION[] = _(
    "풀마크 쿠션\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_FIRE_CUSHION[] = _(
    "불꽃마크 쿠션\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_WATER_CUSHION[] = _(
    "물마크 쿠션\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_SNORLAX_DOLL[] = _(
    "잠만보의 봉제인형\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_RHYDON_DOLL[] = _(
    "코뿌리의 봉제인형\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_LAPRAS_DOLL[] = _(
    "라프라스의 봉제인형\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_VENUSAUR_DOLL[] = _(
    "이상해꽃의 봉제인형\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_CHARIZARD_DOLL[] = _(
    "리자몽의 봉제인형\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_BLASTOISE_DOLL[] = _(
    "거북왕의 봉제인형\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_WAILMER_DOLL[] = _(
    "고래왕자의 봉제인형\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_REGIROCK_DOLL[] = _(
    "레지락의 봉제인형\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_REGICE_DOLL[] = _(
    "레지아이스의 봉제인형\n"
    "매트나 책상\n"
    "위에 놓는다");

const u8 DecorDesc_REGISTEEL_DOLL[] = _(
    "레지스틸의 봉제인형\n"
    "매트나 책상\n"
    "위에 놓는다");

const u16 DecorGfx_SMALL_DESK[] = {
    0x87
};

const u16 DecorGfx_POKEMON_DESK[] = {
    0x8F
};

const u16 DecorGfx_HEAVY_DESK[] = {
    0x90,
    0x91,
    0x92,
    0x98,
    0x99,
    0x9A
};

const u16 DecorGfx_RAGGED_DESK[] = {
    0x93,
    0x94,
    0x95,
    0x9B,
    0x9C,
    0x9D
};

const u16 DecorGfx_COMFORT_DESK[] = {
    0x96,
    0x97,
    0xA3,
    0x9E,
    0x9F,
    0xAB
};

const u16 DecorGfx_PRETTY_DESK[] = {
    0xBD,
    0xBE,
    0xBF,
    0xC5,
    0xC6,
    0xC7,
    0xCD,
    0xCE,
    0xCF
};

const u16 DecorGfx_BRICK_DESK[] = {
    0xA0,
    0xA1,
    0xA2,
    0xA8,
    0xA9,
    0xAA,
    0xB0,
    0xB1,
    0xB2
};

const u16 DecorGfx_CAMP_DESK[] = {
    0xA4,
    0xA5,
    0xA6,
    0xAC,
    0xAD,
    0xAE,
    0xB4,
    0xB5,
    0xB6
};

const u16 DecorGfx_HARD_DESK[] = {
    0xA7,
    0xBB,
    0xBC,
    0xAF,
    0xC3,
    0xC4,
    0xB7,
    0xCB,
    0xCC
};

const u16 DecorGfx_SMALL_CHAIR[] = {
    0xB8
};

const u16 DecorGfx_POKEMON_CHAIR[] = {
    0xB9
};

const u16 DecorGfx_HEAVY_CHAIR[] = {
    0xBA
};

const u16 DecorGfx_PRETTY_CHAIR[] = {
    0xC0
};

const u16 DecorGfx_COMFORT_CHAIR[] = {
    0xC1
};

const u16 DecorGfx_RAGGED_CHAIR[] = {
    0xC2
};

const u16 DecorGfx_BRICK_CHAIR[] = {
    0xC8
};

const u16 DecorGfx_CAMP_CHAIR[] = {
    0xC9
};

const u16 DecorGfx_HARD_CHAIR[] = {
    0xCA
};

const u16 DecorGfx_RED_PLANT[] = {
    0xD0,
    0xD8
};

const u16 DecorGfx_TROPICAL_PLANT[] = {
    0xD2,
    0xDA
};

const u16 DecorGfx_PRETTY_FLOWERS[] = {
    0xD4,
    0xDC
};

const u16 DecorGfx_COLORFUL_PLANT[] = {
    0xE0,
    0xE2,
    0xE8,
    0xE9
};

const u16 DecorGfx_BIG_PLANT[] = {
    0xE4,
    0xE6,
    0xEC,
    0xED
};

const u16 DecorGfx_GORGEOUS_PLANT[] = {
    0xF0,
    0xF2,
    0xF8,
    0xF9
};

const u16 DecorGfx_RED_BRICK[] = {
    0x25,
    0x2D
};

const u16 DecorGfx_YELLOW_BRICK[] = {
    0x26,
    0x2E
};

const u16 DecorGfx_BLUE_BRICK[] = {
    0x27,
    0x2F
};

const u16 DecorGfx_RED_BALLOON[] = {
    0x138
};

const u16 DecorGfx_BLUE_BALLOON[] = {
    0x13C
};

const u16 DecorGfx_YELLOW_BALLOON[] = {
    0x140
};

const u16 DecorGfx_RED_TENT[] = {
    0x30,
    0x31,
    0x32,
    0x38,
    0x39,
    0x3A,
    0x40,
    0x41,
    0x3B
};

const u16 DecorGfx_BLUE_TENT[] = {
    0x48,
    0x49,
    0x68,
    0x50,
    0x51,
    0x70,
    0x58,
    0x59,
    0x69
};

const u16 DecorGfx_SOLID_BOARD[] = {
    0x34,
    0x3C
};

const u16 DecorGfx_SLIDE[] = {
    0x35,
    0x36,
    0x3D,
    0x3E,
    0x63,
    0x64,
    0x6F,
    0x77
};

const u16 DecorGfx_FENCE_LENGTH[] = {
    0x33
};

const u16 DecorGfx_FENCE_WIDTH[] = {
    0x2C
};

const u16 DecorGfx_TIRE[] = {
    0x80,
    0x81,
    0x88,
    0x89
};

const u16 DecorGfx_STAND[] = {
    0x6A,
    0x6B,
    0x6C,
    0x6D,
    0x72,
    0x73,
    0x74,
    0x75
};

const u16 DecorGfx_MUD_BALL[] = {
    0x28
};

const u16 DecorGfx_BREAKABLE_DOOR[] = {
    0x37,
    0x3F
};

const u16 DecorGfx_SAND_ORNAMENT[] = {
    0x85,
    0x8D
};

const u16 DecorGfx_SILVER_SHIELD[] = {
    0xD6,
    0xDE
};

const u16 DecorGfx_GOLD_SHIELD[] = {
    0x12E,
    0x136
};

const u16 DecorGfx_GLASS_ORNAMENT[] = {
    0x82,
    0x8A
};

const u16 DecorGfx_TV[] = {
    0xF4
};

const u16 DecorGfx_ROUND_TV[] = {
    0xF5
};

const u16 DecorGfx_CUTE_TV[] = {
    0xF6
};

const u16 DecorGfx_GLITTER_MAT[] = {
    0x60
};

const u16 DecorGfx_JUMP_MAT[] = {
    0x61
};

const u16 DecorGfx_SPIN_MAT[] = {
    0x62
};

const u16 DecorGfx_C_LOW_NOTE_MAT[] = {
    0x78
};

const u16 DecorGfx_D_NOTE_MAT[] = {
    0x79
};

const u16 DecorGfx_E_NOTE_MAT[] = {
    0x7A
};

const u16 DecorGfx_F_NOTE_MAT[] = {
    0x7B
};

const u16 DecorGfx_G_NOTE_MAT[] = {
    0x7C
};

const u16 DecorGfx_A_NOTE_MAT[] = {
    0x7D
};

const u16 DecorGfx_B_NOTE_MAT[] = {
    0x7E
};

const u16 DecorGfx_C_HIGH_NOTE_MAT[] = {
    0xB3
};

const u16 DecorGfx_SURF_MAT[] = {
    0x42,
    0x43,
    0x44,
    0x4A,
    0x4B,
    0x4C,
    0x52,
    0x53,
    0x54
};

const u16 DecorGfx_THUNDER_MAT[] = {
    0x45,
    0x46,
    0x47,
    0x4D,
    0x4E,
    0x4F,
    0x55,
    0x56,
    0x57
};

const u16 DecorGfx_FIRE_BLAST_MAT[] = {
    0x5A,
    0x5B,
    0x5C,
    0x5D,
    0x5E,
    0x5F,
    0x65,
    0x66,
    0x67
};

const u16 DecorGfx_POWDER_SNOW_MAT[] = {
    0x100,
    0x101,
    0x102,
    0x108,
    0x109,
    0x10A,
    0x110,
    0x111,
    0x112
};

const u16 DecorGfx_ATTRACT_MAT[] = {
    0x103,
    0x104,
    0x105,
    0x10B,
    0x10C,
    0x10D,
    0x113,
    0x114,
    0x115
};

const u16 DecorGfx_FISSURE_MAT[] = {
    0x106,
    0x107,
    0x118,
    0x10E,
    0x10F,
    0x120,
    0x116,
    0x117,
    0x128
};

const u16 DecorGfx_SPIKES_MAT[] = {
    0x119,
    0x11A,
    0x11B,
    0x121,
    0x122,
    0x123,
    0x129,
    0x12A,
    0x12B
};

const u16 DecorGfx_BALL_POSTER[] = {
    0x130
};

const u16 DecorGfx_GREEN_POSTER[] = {
    0x131
};

const u16 DecorGfx_RED_POSTER[] = {
    0x132
};

const u16 DecorGfx_BLUE_POSTER[] = {
    0x133
};

const u16 DecorGfx_CUTE_POSTER[] = {
    0x134
};

const u16 DecorGfx_PIKA_POSTER[] = {
    0x11C,
    0x11D
};

const u16 DecorGfx_LONG_POSTER[] = {
    0x11E,
    0x11F
};

const u16 DecorGfx_SEA_POSTER[] = {
    0x124,
    0x125
};

const u16 DecorGfx_SKY_POSTER[] = {
    0x126,
    0x127
};

const u16 DecorGfx_KISS_POSTER[] = {
    0x12C,
    0x12D
};

const u16 DecorGfx_PICHU_DOLL[] = {
    OBJ_EVENT_GFX_PICHU_DOLL
};

const u16 DecorGfx_PIKACHU_DOLL[] = {
    OBJ_EVENT_GFX_PIKACHU_DOLL
};

const u16 DecorGfx_MARILL_DOLL[] = {
    OBJ_EVENT_GFX_MARILL_DOLL
};

const u16 DecorGfx_TOGEPI_DOLL[] = {
    OBJ_EVENT_GFX_TOGEPI_DOLL
};

const u16 DecorGfx_CYNDAQUIL_DOLL[] = {
    OBJ_EVENT_GFX_CYNDAQUIL_DOLL
};

const u16 DecorGfx_CHIKORITA_DOLL[] = {
    OBJ_EVENT_GFX_CHIKORITA_DOLL
};

const u16 DecorGfx_TOTODILE_DOLL[] = {
    OBJ_EVENT_GFX_TOTODILE_DOLL
};

const u16 DecorGfx_JIGGLYPUFF_DOLL[] = {
    OBJ_EVENT_GFX_JIGGLYPUFF_DOLL
};

const u16 DecorGfx_MEOWTH_DOLL[] = {
    OBJ_EVENT_GFX_MEOWTH_DOLL
};

const u16 DecorGfx_CLEFAIRY_DOLL[] = {
    OBJ_EVENT_GFX_CLEFAIRY_DOLL
};

const u16 DecorGfx_DITTO_DOLL[] = {
    OBJ_EVENT_GFX_DITTO_DOLL
};

const u16 DecorGfx_SMOOCHUM_DOLL[] = {
    OBJ_EVENT_GFX_SMOOCHUM_DOLL
};

const u16 DecorGfx_TREECKO_DOLL[] = {
    OBJ_EVENT_GFX_TREECKO_DOLL
};

const u16 DecorGfx_TORCHIC_DOLL[] = {
    OBJ_EVENT_GFX_TORCHIC_DOLL
};

const u16 DecorGfx_MUDKIP_DOLL[] = {
    OBJ_EVENT_GFX_MUDKIP_DOLL
};

const u16 DecorGfx_DUSKULL_DOLL[] = {
    OBJ_EVENT_GFX_DUSKULL_DOLL
};

const u16 DecorGfx_WYNAUT_DOLL[] = {
    OBJ_EVENT_GFX_WYNAUT_DOLL
};

const u16 DecorGfx_BALTOY_DOLL[] = {
    OBJ_EVENT_GFX_BALTOY_DOLL
};

const u16 DecorGfx_KECLEON_DOLL[] = {
    OBJ_EVENT_GFX_KECLEON_DOLL
};

const u16 DecorGfx_AZURILL_DOLL[] = {
    OBJ_EVENT_GFX_AZURILL_DOLL
};

const u16 DecorGfx_SKITTY_DOLL[] = {
    OBJ_EVENT_GFX_SKITTY_DOLL
};

const u16 DecorGfx_SWABLU_DOLL[] = {
    OBJ_EVENT_GFX_SWABLU_DOLL
};

const u16 DecorGfx_GULPIN_DOLL[] = {
    OBJ_EVENT_GFX_GULPIN_DOLL
};

const u16 DecorGfx_LOTAD_DOLL[] = {
    OBJ_EVENT_GFX_LOTAD_DOLL
};

const u16 DecorGfx_SEEDOT_DOLL[] = {
    OBJ_EVENT_GFX_SEEDOT_DOLL
};

const u16 DecorGfx_PIKA_CUSHION[] = {
    OBJ_EVENT_GFX_PIKA_CUSHION
};

const u16 DecorGfx_ROUND_CUSHION[] = {
    OBJ_EVENT_GFX_ROUND_CUSHION
};

const u16 DecorGfx_KISS_CUSHION[] = {
    OBJ_EVENT_GFX_KISS_CUSHION
};

const u16 DecorGfx_ZIGZAG_CUSHION[] = {
    OBJ_EVENT_GFX_ZIGZAG_CUSHION
};

const u16 DecorGfx_SPIN_CUSHION[] = {
    OBJ_EVENT_GFX_SPIN_CUSHION
};

const u16 DecorGfx_DIAMOND_CUSHION[] = {
    OBJ_EVENT_GFX_DIAMOND_CUSHION
};

const u16 DecorGfx_BALL_CUSHION[] = {
    OBJ_EVENT_GFX_BALL_CUSHION
};

const u16 DecorGfx_GRASS_CUSHION[] = {
    OBJ_EVENT_GFX_GRASS_CUSHION
};

const u16 DecorGfx_FIRE_CUSHION[] = {
    OBJ_EVENT_GFX_FIRE_CUSHION
};

const u16 DecorGfx_WATER_CUSHION[] = {
    OBJ_EVENT_GFX_WATER_CUSHION
};

const u16 DecorGfx_SNORLAX_DOLL[] = {
    OBJ_EVENT_GFX_BIG_SNORLAX_DOLL
};

const u16 DecorGfx_RHYDON_DOLL[] = {
    OBJ_EVENT_GFX_BIG_RHYDON_DOLL
};

const u16 DecorGfx_LAPRAS_DOLL[] = {
    OBJ_EVENT_GFX_BIG_LAPRAS_DOLL
};

const u16 DecorGfx_VENUSAUR_DOLL[] = {
    OBJ_EVENT_GFX_BIG_VENUSAUR_DOLL
};

const u16 DecorGfx_CHARIZARD_DOLL[] = {
    OBJ_EVENT_GFX_BIG_CHARIZARD_DOLL
};

const u16 DecorGfx_BLASTOISE_DOLL[] = {
    OBJ_EVENT_GFX_BIG_BLASTOISE_DOLL
};

const u16 DecorGfx_WAILMER_DOLL[] = {
    OBJ_EVENT_GFX_BIG_WAILMER_DOLL
};

const u16 DecorGfx_REGIROCK_DOLL[] = {
    OBJ_EVENT_GFX_BIG_REGIROCK_DOLL
};

const u16 DecorGfx_REGICE_DOLL[] = {
    OBJ_EVENT_GFX_BIG_REGICE_DOLL
};

const u16 DecorGfx_REGISTEEL_DOLL[] = {
    OBJ_EVENT_GFX_BIG_REGISTEEL_DOLL
};

const struct Decoration gDecorations[] = {
    {DECOR_NONE,            _("작은 책상"),      	  DECORPERM_SOLID_FLOOR,  DECORSHAPE_1x1, DECORCAT_DESK,         0, DecorDesc_SMALL_DESK, DecorGfx_SMALL_DESK},
    {DECOR_SMALL_DESK,      _("작은 책상"),      	  DECORPERM_SOLID_FLOOR,  DECORSHAPE_1x1, DECORCAT_DESK,      3000, DecorDesc_SMALL_DESK, DecorGfx_SMALL_DESK},
    {DECOR_POKEMON_DESK,    _("포켓몬책상"),    	  DECORPERM_SOLID_FLOOR,  DECORSHAPE_1x1, DECORCAT_DESK,      3000, DecorDesc_POKEMON_DESK, DecorGfx_POKEMON_DESK},
    {DECOR_HEAVY_DESK,      _("묵직한 책상"),      	  DECORPERM_SOLID_FLOOR,  DECORSHAPE_3x2, DECORCAT_DESK,      6000, DecorDesc_HEAVY_DESK, DecorGfx_HEAVY_DESK},
    {DECOR_RAGGED_DESK,     _("울퉁불퉁책상"),     	  DECORPERM_SOLID_FLOOR,  DECORSHAPE_3x2, DECORCAT_DESK,      6000, DecorDesc_RAGGED_DESK, DecorGfx_RAGGED_DESK},
    {DECOR_COMFORT_DESK,    _("푹신푹신책상"),    	  DECORPERM_SOLID_FLOOR,  DECORSHAPE_3x2, DECORCAT_DESK,      6000, DecorDesc_COMFORT_DESK, DecorGfx_COMFORT_DESK},
    {DECOR_PRETTY_DESK,     _("고운 책상"),     	  DECORPERM_SOLID_FLOOR,  DECORSHAPE_3x3, DECORCAT_DESK,      9000, DecorDesc_PRETTY_DESK, DecorGfx_PRETTY_DESK},
    {DECOR_BRICK_DESK,      _("벽돌책상"),      	  DECORPERM_SOLID_FLOOR,  DECORSHAPE_3x3, DECORCAT_DESK,      9000, DecorDesc_BRICK_DESK, DecorGfx_BRICK_DESK},
    {DECOR_CAMP_DESK,       _("캠프책상"),       	  DECORPERM_SOLID_FLOOR,  DECORSHAPE_3x3, DECORCAT_DESK,      9000, DecorDesc_CAMP_DESK, DecorGfx_CAMP_DESK},
    {DECOR_HARD_DESK,       _("딱딱한 책상"),         DECORPERM_SOLID_FLOOR,  DECORSHAPE_3x3, DECORCAT_DESK,      9000, DecorDesc_HARD_DESK, DecorGfx_HARD_DESK},
    {DECOR_SMALL_CHAIR,     _("작은 의자"),     	  DECORPERM_PASS_FLOOR,   DECORSHAPE_1x1, DECORCAT_CHAIR,     2000, DecorDesc_SMALL_CHAIR, DecorGfx_SMALL_CHAIR},
    {DECOR_POKEMON_CHAIR,   _("포켓몬의자"),   		  DECORPERM_PASS_FLOOR,   DECORSHAPE_1x1, DECORCAT_CHAIR,     2000, DecorDesc_POKEMON_CHAIR, DecorGfx_POKEMON_CHAIR},
    {DECOR_HEAVY_CHAIR,     _("묵직한 의자"),     	  DECORPERM_PASS_FLOOR,   DECORSHAPE_1x1, DECORCAT_CHAIR,     2000, DecorDesc_HEAVY_CHAIR, DecorGfx_HEAVY_CHAIR},
    {DECOR_PRETTY_CHAIR,    _("고운 의자"),    	  DECORPERM_PASS_FLOOR,   DECORSHAPE_1x1, DECORCAT_CHAIR,     2000, DecorDesc_PRETTY_CHAIR, DecorGfx_PRETTY_CHAIR},
    {DECOR_COMFORT_CHAIR,   _("푹신푹신의자"),   	  DECORPERM_PASS_FLOOR,   DECORSHAPE_1x1, DECORCAT_CHAIR,     2000, DecorDesc_COMFORT_CHAIR, DecorGfx_COMFORT_CHAIR},
    {DECOR_RAGGED_CHAIR,    _("울퉁불퉁의자"),    	  DECORPERM_PASS_FLOOR,   DECORSHAPE_1x1, DECORCAT_CHAIR,     2000, DecorDesc_RAGGED_CHAIR, DecorGfx_RAGGED_CHAIR},
    {DECOR_BRICK_CHAIR,     _("벽돌의자"),     	  DECORPERM_PASS_FLOOR,   DECORSHAPE_1x1, DECORCAT_CHAIR,     2000, DecorDesc_BRICK_CHAIR, DecorGfx_BRICK_CHAIR},
    {DECOR_CAMP_CHAIR,      _("캠프의자"),      	  DECORPERM_PASS_FLOOR,   DECORSHAPE_1x1, DECORCAT_CHAIR,     2000, DecorDesc_CAMP_CHAIR, DecorGfx_CAMP_CHAIR},
    {DECOR_HARD_CHAIR,      _("딱딱한 의자"),      	  DECORPERM_PASS_FLOOR,   DECORSHAPE_1x1, DECORCAT_CHAIR,     2000, DecorDesc_HARD_CHAIR, DecorGfx_HARD_CHAIR},
    {DECOR_RED_PLANT,       _("새빨간 화분"),         DECORPERM_BEHIND_FLOOR, DECORSHAPE_1x2, DECORCAT_PLANT,     3000, DecorDesc_RED_PLANT, DecorGfx_RED_PLANT},
    {DECOR_TROPICAL_PLANT,  _("남국의 화분"),  		  DECORPERM_BEHIND_FLOOR, DECORSHAPE_1x2, DECORCAT_PLANT,     3000, DecorDesc_TROPICAL_PLANT, DecorGfx_TROPICAL_PLANT},
    {DECOR_PRETTY_FLOWERS,  _("귀여운 꽃"),  		  DECORPERM_BEHIND_FLOOR, DECORSHAPE_1x2, DECORCAT_PLANT,     3000, DecorDesc_PRETTY_FLOWERS, DecorGfx_PRETTY_FLOWERS},
    {DECOR_COLORFUL_PLANT,  _("컬러풀 화분"),  		  DECORPERM_BEHIND_FLOOR, DECORSHAPE_2x2, DECORCAT_PLANT,     5000, DecorDesc_COLORFUL_PLANT, DecorGfx_COLORFUL_PLANT},
    {DECOR_BIG_PLANT,       _("큰 화분"),       	  DECORPERM_BEHIND_FLOOR, DECORSHAPE_2x2, DECORCAT_PLANT,     5000, DecorDesc_BIG_PLANT, DecorGfx_BIG_PLANT},
    {DECOR_GORGEOUS_PLANT,  _("훌륭한 화분"),  		  DECORPERM_BEHIND_FLOOR, DECORSHAPE_2x2, DECORCAT_PLANT,     5000, DecorDesc_GORGEOUS_PLANT, DecorGfx_GORGEOUS_PLANT},
    {DECOR_RED_BRICK,       _("빨강벽돌"),       	  DECORPERM_SOLID_FLOOR,  DECORSHAPE_1x2, DECORCAT_ORNAMENT,   500, DecorDesc_RED_BRICK, DecorGfx_RED_BRICK},
    {DECOR_YELLOW_BRICK,    _("노랑벽돌"),    		  DECORPERM_SOLID_FLOOR,  DECORSHAPE_1x2, DECORCAT_ORNAMENT,   500, DecorDesc_YELLOW_BRICK, DecorGfx_YELLOW_BRICK},
    {DECOR_BLUE_BRICK,      _("파랑벽돌"),      	  DECORPERM_SOLID_FLOOR,  DECORSHAPE_1x2, DECORCAT_ORNAMENT,   500, DecorDesc_BLUE_BRICK, DecorGfx_BLUE_BRICK},
    {DECOR_RED_BALLOON,     _("빨강풍선"),     	  DECORPERM_PASS_FLOOR,   DECORSHAPE_1x1, DECORCAT_ORNAMENT,   500, DecorDesc_RED_BALLOON, DecorGfx_RED_BALLOON},
    {DECOR_BLUE_BALLOON,    _("파랑풍선"),    		  DECORPERM_PASS_FLOOR,   DECORSHAPE_1x1, DECORCAT_ORNAMENT,   500, DecorDesc_BLUE_BALLOON, DecorGfx_BLUE_BALLOON},
    {DECOR_YELLOW_BALLOON,  _("노랑풍선"),  		  DECORPERM_PASS_FLOOR,   DECORSHAPE_1x1, DECORCAT_ORNAMENT,   500, DecorDesc_YELLOW_BALLOON, DecorGfx_YELLOW_BALLOON},
    {DECOR_RED_TENT,        _("빨강텐트"),        	  DECORPERM_PASS_FLOOR,   DECORSHAPE_3x3, DECORCAT_ORNAMENT, 10000, DecorDesc_RED_TENT, DecorGfx_RED_TENT},
    {DECOR_BLUE_TENT,       _("파랑텐트"),       	  DECORPERM_PASS_FLOOR,   DECORSHAPE_3x3, DECORCAT_ORNAMENT, 10000, DecorDesc_BLUE_TENT, DecorGfx_BLUE_TENT},
    {DECOR_SOLID_BOARD,     _("단단한 판자"),     	  DECORPERM_PASS_FLOOR,   DECORSHAPE_1x2, DECORCAT_ORNAMENT,  3000, DecorDesc_SOLID_BOARD, DecorGfx_SOLID_BOARD},
    {DECOR_SLIDE,           _("미끄럼대"),           DECORPERM_PASS_FLOOR,   DECORSHAPE_2x4, DECORCAT_ORNAMENT,  8000, DecorDesc_SLIDE, DecorGfx_SLIDE},
    {DECOR_FENCE_LENGTH,    _("세로울타리"),    	  DECORPERM_SOLID_FLOOR,  DECORSHAPE_1x1, DECORCAT_ORNAMENT,   500, DecorDesc_FENCE_LENGTH, DecorGfx_FENCE_LENGTH},
    {DECOR_FENCE_WIDTH,     _("가로울타리"),     	  DECORPERM_SOLID_FLOOR,  DECORSHAPE_1x1, DECORCAT_ORNAMENT,   500, DecorDesc_FENCE_WIDTH, DecorGfx_FENCE_WIDTH},
    {DECOR_TIRE,            _("타이어"),            DECORPERM_SOLID_FLOOR,  DECORSHAPE_2x2, DECORCAT_ORNAMENT,   800, DecorDesc_TIRE, DecorGfx_TIRE},
    {DECOR_STAND,           _("큰 받침대"),          DECORPERM_PASS_FLOOR,   DECORSHAPE_4x2, DECORCAT_ORNAMENT,  7000, DecorDesc_STAND, DecorGfx_STAND},
    {DECOR_MUD_BALL,        _("진흙경단"),        	  DECORPERM_PASS_FLOOR,   DECORSHAPE_1x1, DECORCAT_ORNAMENT,   200, DecorDesc_MUD_BALL, DecorGfx_MUD_BALL},
    {DECOR_BREAKABLE_DOOR,  _("부서지는 도어"),  	  DECORPERM_PASS_FLOOR,   DECORSHAPE_1x2, DECORCAT_ORNAMENT,  3000, DecorDesc_BREAKABLE_DOOR, DecorGfx_BREAKABLE_DOOR},
    {DECOR_SAND_ORNAMENT,   _("모래장식품"),   		  DECORPERM_BEHIND_FLOOR, DECORSHAPE_1x2, DECORCAT_ORNAMENT,  3000, DecorDesc_SAND_ORNAMENT, DecorGfx_SAND_ORNAMENT},
    {DECOR_SILVER_SHIELD,   _("은상패"),   		  DECORPERM_BEHIND_FLOOR, DECORSHAPE_1x2, DECORCAT_ORNAMENT,     0, DecorDesc_SILVER_SHIELD, DecorGfx_SILVER_SHIELD},
    {DECOR_GOLD_SHIELD,     _("금상패"),     		  DECORPERM_BEHIND_FLOOR, DECORSHAPE_1x2, DECORCAT_ORNAMENT,     0, DecorDesc_GOLD_SHIELD, DecorGfx_GOLD_SHIELD},
    {DECOR_GLASS_ORNAMENT,  _("글라스오브제"),  		  DECORPERM_BEHIND_FLOOR, DECORSHAPE_1x2, DECORCAT_ORNAMENT,     0, DecorDesc_GLASS_ORNAMENT, DecorGfx_GLASS_ORNAMENT},
    {DECOR_TV,              _("TV"),              DECORPERM_SOLID_FLOOR,  DECORSHAPE_1x1, DECORCAT_ORNAMENT,  3000, DecorDesc_TV, DecorGfx_TV},
    {DECOR_ROUND_TV,        _("둥근 TV"),        	  DECORPERM_SOLID_FLOOR,  DECORSHAPE_1x1, DECORCAT_ORNAMENT,  4000, DecorDesc_ROUND_TV, DecorGfx_ROUND_TV},
    {DECOR_CUTE_TV,         _("귀여운 TV"),         DECORPERM_SOLID_FLOOR,  DECORSHAPE_1x1, DECORCAT_ORNAMENT,  4000, DecorDesc_CUTE_TV, DecorGfx_CUTE_TV},
    {DECOR_GLITTER_MAT,     _("반짝반짝매트"),   	  DECORPERM_PASS_FLOOR,   DECORSHAPE_1x1, DECORCAT_MAT,       2000, DecorDesc_GLITTER_MAT, DecorGfx_GLITTER_MAT},
    {DECOR_JUMP_MAT,        _("점프매트"),        	  DECORPERM_PASS_FLOOR,   DECORSHAPE_1x1, DECORCAT_MAT,       2000, DecorDesc_JUMP_MAT, DecorGfx_JUMP_MAT},
    {DECOR_SPIN_MAT,        _("뱅그르매트"),          DECORPERM_PASS_FLOOR,   DECORSHAPE_1x1, DECORCAT_MAT,       2000, DecorDesc_SPIN_MAT, DecorGfx_SPIN_MAT},
    {DECOR_C_LOW_NOTE_MAT,  _("음표매트CL"),  		  DECORPERM_PASS_FLOOR,   DECORSHAPE_1x1, DECORCAT_MAT,        500, DecorDesc_C_LOW_NOTE_MAT, DecorGfx_C_LOW_NOTE_MAT},
    {DECOR_D_NOTE_MAT,      _("음표매트D"),      	  DECORPERM_PASS_FLOOR,   DECORSHAPE_1x1, DECORCAT_MAT,        500, DecorDesc_D_NOTE_MAT, DecorGfx_D_NOTE_MAT},
    {DECOR_E_NOTE_MAT,      _("음표매트E"),      	  DECORPERM_PASS_FLOOR,   DECORSHAPE_1x1, DECORCAT_MAT,        500, DecorDesc_E_NOTE_MAT, DecorGfx_E_NOTE_MAT},
    {DECOR_F_NOTE_MAT,      _("음표매트F"),      	  DECORPERM_PASS_FLOOR,   DECORSHAPE_1x1, DECORCAT_MAT,        500, DecorDesc_F_NOTE_MAT, DecorGfx_F_NOTE_MAT},
    {DECOR_G_NOTE_MAT,      _("음표매트G"),      	  DECORPERM_PASS_FLOOR,   DECORSHAPE_1x1, DECORCAT_MAT,        500, DecorDesc_G_NOTE_MAT, DecorGfx_G_NOTE_MAT},
    {DECOR_A_NOTE_MAT,      _("음표매트A"),      	  DECORPERM_PASS_FLOOR,   DECORSHAPE_1x1, DECORCAT_MAT,        500, DecorDesc_A_NOTE_MAT, DecorGfx_A_NOTE_MAT},
    {DECOR_B_NOTE_MAT,      _("음표매트B"),      	  DECORPERM_PASS_FLOOR,   DECORSHAPE_1x1, DECORCAT_MAT,        500, DecorDesc_B_NOTE_MAT, DecorGfx_B_NOTE_MAT},
    {DECOR_C_HIGH_NOTE_MAT, _("음표매트CH"), 		  DECORPERM_PASS_FLOOR,   DECORSHAPE_1x1, DECORCAT_MAT,        500, DecorDesc_C_HIGH_NOTE_MAT, DecorGfx_C_HIGH_NOTE_MAT},
    {DECOR_SURF_MAT,        _("파도타기매트"),         DECORPERM_PASS_FLOOR,   DECORSHAPE_3x3, DECORCAT_MAT,       4000, DecorDesc_SURF_MAT, DecorGfx_SURF_MAT},
    {DECOR_THUNDER_MAT,     _("번개매트"),     	  DECORPERM_PASS_FLOOR,   DECORSHAPE_3x3, DECORCAT_MAT,       4000, DecorDesc_THUNDER_MAT, DecorGfx_THUNDER_MAT},
    {DECOR_FIRE_BLAST_MAT,  _("불대문자매트"),  		  DECORPERM_PASS_FLOOR,   DECORSHAPE_3x3, DECORCAT_MAT,       4000, DecorDesc_FIRE_BLAST_MAT, DecorGfx_FIRE_BLAST_MAT},
    {DECOR_POWDER_SNOW_MAT, _("눈싸라기매트"), 		  DECORPERM_PASS_FLOOR,   DECORSHAPE_3x3, DECORCAT_MAT,       4000, DecorDesc_POWDER_SNOW_MAT, DecorGfx_POWDER_SNOW_MAT},
    {DECOR_ATTRACT_MAT,     _("헤롱헤롱매트"),     	  DECORPERM_PASS_FLOOR,   DECORSHAPE_3x3, DECORCAT_MAT,       4000, DecorDesc_ATTRACT_MAT, DecorGfx_ATTRACT_MAT},
    {DECOR_FISSURE_MAT,     _("땅가르기매트"),     	  DECORPERM_PASS_FLOOR,   DECORSHAPE_3x3, DECORCAT_MAT,       4000, DecorDesc_FISSURE_MAT, DecorGfx_FISSURE_MAT},
    {DECOR_SPIKES_MAT,      _("압정뿌리기매트"),        DECORPERM_PASS_FLOOR,   DECORSHAPE_3x3, DECORCAT_MAT,       4000, DecorDesc_SPIKES_MAT, DecorGfx_SPIKES_MAT},
    {DECOR_BALL_POSTER,     _("볼포스터"),      	   DECORPERM_NA_WALL,     DECORSHAPE_1x1, DECORCAT_POSTER,    1000, DecorDesc_BALL_POSTER, DecorGfx_BALL_POSTER},
    {DECOR_GREEN_POSTER,    _("초록포스터"),     	   DECORPERM_NA_WALL,     DECORSHAPE_1x1, DECORCAT_POSTER,    1000, DecorDesc_GREEN_POSTER, DecorGfx_GREEN_POSTER},
    {DECOR_RED_POSTER,      _("빨강포스터"),           DECORPERM_NA_WALL,     DECORSHAPE_1x1, DECORCAT_POSTER,    1000, DecorDesc_RED_POSTER, DecorGfx_RED_POSTER},
    {DECOR_BLUE_POSTER,     _("옥색포스터"),           DECORPERM_NA_WALL,     DECORSHAPE_1x1, DECORCAT_POSTER,    1000, DecorDesc_BLUE_POSTER, DecorGfx_BLUE_POSTER},
    {DECOR_CUTE_POSTER,     _("귀여운 포스터"),     	   DECORPERM_NA_WALL,     DECORSHAPE_1x1, DECORCAT_POSTER,    1000, DecorDesc_CUTE_POSTER, DecorGfx_CUTE_POSTER},
    {DECOR_PIKA_POSTER,     _("번쩍번쩍포스터"),        DECORPERM_NA_WALL,     DECORSHAPE_2x1, DECORCAT_POSTER,    1500, DecorDesc_PIKA_POSTER, DecorGfx_PIKA_POSTER},
    {DECOR_LONG_POSTER,     _("긴 포스터"),      	   DECORPERM_NA_WALL,     DECORSHAPE_2x1, DECORCAT_POSTER,    1500, DecorDesc_LONG_POSTER, DecorGfx_LONG_POSTER},
    {DECOR_SEA_POSTER,      _("바다포스터"),       		DECORPERM_NA_WALL,     DECORSHAPE_2x1, DECORCAT_POSTER,    1500, DecorDesc_SEA_POSTER, DecorGfx_SEA_POSTER},
    {DECOR_SKY_POSTER,      _("하늘포스터"),       DECORPERM_NA_WALL,     DECORSHAPE_2x1, DECORCAT_POSTER,    1500, DecorDesc_SKY_POSTER, DecorGfx_SKY_POSTER},
    {DECOR_KISS_POSTER,     _("키스포스터"),      DECORPERM_NA_WALL,     DECORSHAPE_2x1, DECORCAT_POSTER,    1500, DecorDesc_KISS_POSTER, DecorGfx_KISS_POSTER},
    {DECOR_PICHU_DOLL,      _("피츄인형"),       DECORPERM_SOLID_MAT,   DECORSHAPE_1x1, DECORCAT_DOLL,      3000, DecorDesc_PICHU_DOLL, DecorGfx_PICHU_DOLL},
    {DECOR_PIKACHU_DOLL,    _("피카츄인형"),     DECORPERM_SOLID_MAT,   DECORSHAPE_1x1, DECORCAT_DOLL,      3000, DecorDesc_PIKACHU_DOLL, DecorGfx_PIKACHU_DOLL},
    {DECOR_MARILL_DOLL,     _("마릴인형"),       DECORPERM_SOLID_MAT,   DECORSHAPE_1x1, DECORCAT_DOLL,      3000, DecorDesc_MARILL_DOLL, DecorGfx_MARILL_DOLL},
    {DECOR_TOGEPI_DOLL,     _("토게피인형"),      DECORPERM_SOLID_MAT,   DECORSHAPE_1x1, DECORCAT_DOLL,      3000, DecorDesc_TOGEPI_DOLL, DecorGfx_TOGEPI_DOLL},
    {DECOR_CYNDAQUIL_DOLL,  _("브케인인형"),      DECORPERM_SOLID_MAT,   DECORSHAPE_1x1, DECORCAT_DOLL,      3000, DecorDesc_CYNDAQUIL_DOLL, DecorGfx_CYNDAQUIL_DOLL},
    {DECOR_CHIKORITA_DOLL,  _("치코리타인형"),     DECORPERM_SOLID_MAT,   DECORSHAPE_1x1, DECORCAT_DOLL,      3000, DecorDesc_CHIKORITA_DOLL, DecorGfx_CHIKORITA_DOLL},
    {DECOR_TOTODILE_DOLL,   _("리아코인형"),      DECORPERM_SOLID_MAT,   DECORSHAPE_1x1, DECORCAT_DOLL,      3000, DecorDesc_TOTODILE_DOLL, DecorGfx_TOTODILE_DOLL},
    {DECOR_JIGGLYPUFF_DOLL, _("푸린인형"),       DECORPERM_SOLID_MAT,   DECORSHAPE_1x1, DECORCAT_DOLL,      3000, DecorDesc_JIGGLYPUFF_DOLL, DecorGfx_JIGGLYPUFF_DOLL},
    {DECOR_MEOWTH_DOLL,     _("나옹인형"),       DECORPERM_SOLID_MAT,   DECORSHAPE_1x1, DECORCAT_DOLL,      3000, DecorDesc_MEOWTH_DOLL, DecorGfx_MEOWTH_DOLL},
    {DECOR_CLEFAIRY_DOLL,   _("삐삐인형"),       DECORPERM_SOLID_MAT,   DECORSHAPE_1x1, DECORCAT_DOLL,      3000, DecorDesc_CLEFAIRY_DOLL, DecorGfx_CLEFAIRY_DOLL},
    {DECOR_DITTO_DOLL,      _("메타몽인형"),      DECORPERM_SOLID_MAT,   DECORSHAPE_1x1, DECORCAT_DOLL,      3000, DecorDesc_DITTO_DOLL, DecorGfx_DITTO_DOLL},
    {DECOR_SMOOCHUM_DOLL,   _("뽀뽀라인형"),      DECORPERM_SOLID_MAT,   DECORSHAPE_1x1, DECORCAT_DOLL,      3000, DecorDesc_SMOOCHUM_DOLL, DecorGfx_SMOOCHUM_DOLL},
    {DECOR_TREECKO_DOLL,    _("나무지기인형"),     DECORPERM_SOLID_MAT,   DECORSHAPE_1x1, DECORCAT_DOLL,      3000, DecorDesc_TREECKO_DOLL, DecorGfx_TREECKO_DOLL},
    {DECOR_TORCHIC_DOLL,    _("아차모인형"),      DECORPERM_SOLID_MAT,   DECORSHAPE_1x1, DECORCAT_DOLL,      3000, DecorDesc_TORCHIC_DOLL, DecorGfx_TORCHIC_DOLL},
    {DECOR_MUDKIP_DOLL,     _("물짱이인형"),      DECORPERM_SOLID_MAT,   DECORSHAPE_1x1, DECORCAT_DOLL,      3000, DecorDesc_MUDKIP_DOLL, DecorGfx_MUDKIP_DOLL},
    {DECOR_DUSKULL_DOLL,    _("해골몽인형"),      DECORPERM_SOLID_MAT,   DECORSHAPE_1x1, DECORCAT_DOLL,      3000, DecorDesc_DUSKULL_DOLL, DecorGfx_DUSKULL_DOLL},
    {DECOR_WYNAUT_DOLL,     _("마자인형"),       DECORPERM_SOLID_MAT,   DECORSHAPE_1x1, DECORCAT_DOLL,      3000, DecorDesc_WYNAUT_DOLL, DecorGfx_WYNAUT_DOLL},
    {DECOR_BALTOY_DOLL,     _("오뚝군인형"),      DECORPERM_SOLID_MAT,   DECORSHAPE_1x1, DECORCAT_DOLL,      3000, DecorDesc_BALTOY_DOLL, DecorGfx_BALTOY_DOLL},
    {DECOR_KECLEON_DOLL,    _("켈리몬인형"),      DECORPERM_SOLID_MAT,   DECORSHAPE_1x1, DECORCAT_DOLL,      3000, DecorDesc_KECLEON_DOLL, DecorGfx_KECLEON_DOLL},
    {DECOR_AZURILL_DOLL,    _("루리리인형"),      DECORPERM_SOLID_MAT,   DECORSHAPE_1x1, DECORCAT_DOLL,      3000, DecorDesc_AZURILL_DOLL, DecorGfx_AZURILL_DOLL},
    {DECOR_SKITTY_DOLL,     _("에나비인형"),      DECORPERM_SOLID_MAT,   DECORSHAPE_1x1, DECORCAT_DOLL,      3000, DecorDesc_SKITTY_DOLL, DecorGfx_SKITTY_DOLL},
    {DECOR_SWABLU_DOLL,     _("파비코인형"),      DECORPERM_SOLID_MAT,   DECORSHAPE_1x1, DECORCAT_DOLL,      3000, DecorDesc_SWABLU_DOLL, DecorGfx_SWABLU_DOLL},
    {DECOR_GULPIN_DOLL,     _("꼴깍몬인형"),      DECORPERM_SOLID_MAT,   DECORSHAPE_1x1, DECORCAT_DOLL,      3000, DecorDesc_GULPIN_DOLL, DecorGfx_GULPIN_DOLL},
    {DECOR_LOTAD_DOLL,      _("연꽃몬인형"),       DECORPERM_SOLID_MAT,   DECORSHAPE_1x1, DECORCAT_DOLL,      3000, DecorDesc_LOTAD_DOLL, DecorGfx_LOTAD_DOLL},
    {DECOR_SEEDOT_DOLL,     _("도토링인형"),      DECORPERM_SOLID_MAT,   DECORSHAPE_1x1, DECORCAT_DOLL,      3000, DecorDesc_SEEDOT_DOLL, DecorGfx_SEEDOT_DOLL},
    {DECOR_PIKA_CUSHION,    _("번쩍쿠션"),     DECORPERM_SOLID_MAT,   DECORSHAPE_1x1, DECORCAT_CUSHION,   2000, DecorDesc_PIKA_CUSHION, DecorGfx_PIKA_CUSHION},
    {DECOR_ROUND_CUSHION,   _("둥근 쿠션"),    DECORPERM_SOLID_MAT,   DECORSHAPE_1x1, DECORCAT_CUSHION,   2000, DecorDesc_ROUND_CUSHION, DecorGfx_ROUND_CUSHION},
    {DECOR_KISS_CUSHION,    _("키스쿠션"),     DECORPERM_SOLID_MAT,   DECORSHAPE_1x1, DECORCAT_CUSHION,   2000, DecorDesc_KISS_CUSHION, DecorGfx_KISS_CUSHION},
    {DECOR_ZIGZAG_CUSHION,  _("지그재그쿠션"),   DECORPERM_SOLID_MAT,   DECORSHAPE_1x1, DECORCAT_CUSHION,   2000, DecorDesc_ZIGZAG_CUSHION, DecorGfx_ZIGZAG_CUSHION},
    {DECOR_SPIN_CUSHION,    _("빙그르쿠션"),     DECORPERM_SOLID_MAT,   DECORSHAPE_1x1, DECORCAT_CUSHION,   2000, DecorDesc_SPIN_CUSHION, DecorGfx_SPIN_CUSHION},
    {DECOR_DIAMOND_CUSHION, _("다이아쿠션"),  DECORPERM_SOLID_MAT,   DECORSHAPE_1x1, DECORCAT_CUSHION,   2000, DecorDesc_DIAMOND_CUSHION, DecorGfx_DIAMOND_CUSHION},
    {DECOR_BALL_CUSHION,    _("볼쿠션"),     DECORPERM_SOLID_MAT,   DECORSHAPE_1x1, DECORCAT_CUSHION,   2000, DecorDesc_BALL_CUSHION, DecorGfx_BALL_CUSHION},
    {DECOR_GRASS_CUSHION,   _("풀쿠션"),    DECORPERM_SOLID_MAT,   DECORSHAPE_1x1, DECORCAT_CUSHION,   2000, DecorDesc_GRASS_CUSHION, DecorGfx_GRASS_CUSHION},
    {DECOR_FIRE_CUSHION,    _("불꽃쿠션"),     DECORPERM_SOLID_MAT,   DECORSHAPE_1x1, DECORCAT_CUSHION,   2000, DecorDesc_FIRE_CUSHION, DecorGfx_FIRE_CUSHION},
    {DECOR_WATER_CUSHION,   _("물쿠션"),    DECORPERM_SOLID_MAT,   DECORSHAPE_1x1, DECORCAT_CUSHION,   2000, DecorDesc_WATER_CUSHION, DecorGfx_WATER_CUSHION},
    {DECOR_SNORLAX_DOLL,    _("잠만보인형"),     DECORPERM_SOLID_MAT,   DECORSHAPE_1x2, DECORCAT_DOLL,     10000, DecorDesc_SNORLAX_DOLL, DecorGfx_SNORLAX_DOLL},
    {DECOR_RHYDON_DOLL,     _("코뿌리인형"),      DECORPERM_SOLID_MAT,   DECORSHAPE_1x2, DECORCAT_DOLL,     10000, DecorDesc_RHYDON_DOLL, DecorGfx_RHYDON_DOLL},
    {DECOR_LAPRAS_DOLL,     _("라프라스인형"),      DECORPERM_SOLID_MAT,   DECORSHAPE_1x2, DECORCAT_DOLL,     10000, DecorDesc_LAPRAS_DOLL, DecorGfx_LAPRAS_DOLL},
    {DECOR_VENUSAUR_DOLL,   _("이상해꽃인형"),    DECORPERM_SOLID_MAT,   DECORSHAPE_1x2, DECORCAT_DOLL,     10000, DecorDesc_VENUSAUR_DOLL, DecorGfx_VENUSAUR_DOLL},
    {DECOR_CHARIZARD_DOLL,  _("리자몽인형"),   DECORPERM_SOLID_MAT,   DECORSHAPE_1x2, DECORCAT_DOLL,     10000, DecorDesc_CHARIZARD_DOLL, DecorGfx_CHARIZARD_DOLL},
    {DECOR_BLASTOISE_DOLL,  _("거북왕인형"),   DECORPERM_SOLID_MAT,   DECORSHAPE_1x2, DECORCAT_DOLL,     10000, DecorDesc_BLASTOISE_DOLL, DecorGfx_BLASTOISE_DOLL},
    {DECOR_WAILMER_DOLL,    _("고래왕자인형"),     DECORPERM_SOLID_MAT,   DECORSHAPE_1x2, DECORCAT_DOLL,     10000, DecorDesc_WAILMER_DOLL, DecorGfx_WAILMER_DOLL},
    {DECOR_REGIROCK_DOLL,   _("레지락인형"),    DECORPERM_SOLID_MAT,   DECORSHAPE_1x2, DECORCAT_DOLL,     10000, DecorDesc_REGIROCK_DOLL, DecorGfx_REGIROCK_DOLL},
    {DECOR_REGICE_DOLL,     _("레지아이스인형"),      DECORPERM_SOLID_MAT,   DECORSHAPE_1x2, DECORCAT_DOLL,     10000, DecorDesc_REGICE_DOLL, DecorGfx_REGICE_DOLL},
    {DECOR_REGISTEEL_DOLL,  _("레지스틸인형"),   DECORPERM_SOLID_MAT,   DECORSHAPE_1x2, DECORCAT_DOLL,     10000, DecorDesc_REGISTEEL_DOLL, DecorGfx_REGISTEEL_DOLL}
};

const u8 *const gUnknown_083EC5E4[] = {
    SecretBaseText_Desk,
    SecretBaseText_Chair,
    SecretBaseText_Plant,
    SecretBaseText_Ornament,
    SecretBaseText_Mat,
    SecretBaseText_Poster,
    SecretBaseText_Doll,
    SecretBaseText_Cushion
};

const struct MenuAction2 gUnknown_083EC604[] = {
    {SecretBaseText_Decorate, sub_80FF160},
    {SecretBaseText_PutAway, sub_8100A0C},
    {SecretBaseText_Toss, sub_8101700},
    {gOtherText_Exit, gpu_pal_decompress_alloc_tag_and_upload}
};

const u8 *const gUnknown_083EC624[] = {
    SecretBaseText_PutOutDecor,
    SecretBaseText_StoreChosenDecor,
    SecretBaseText_ThrowAwayDecor,
    gMenuText_GoBackToPrev
};

const struct YesNoFuncTable gUnknown_083EC634[] = {
    {sub_80FF5BC, sub_80FF058},
    {sub_81017A0, sub_80FF058},
    {sub_81017A0, sub_80FF058},
    {sub_8109D04, sub_80FF058}
};

// text

extern u8 SecretBase_EventScript_PCCancel[];

void sub_80FE1DC(void)
{
    sub_80FE2B4();
    Menu_DrawStdWindowFrame(0, 0, 10, 9);
    Menu_PrintItems(2, 1, 4, (const struct MenuAction *)gUnknown_083EC604);
    InitMenu(0, 1, 1, 4, gUnknown_020388D4);
}

void sub_80FE220(void)
{
    gUnknown_020388D4 = 0;
    ScriptContext2_Enable();
    sub_80FE1DC();
    sub_80FE394();
}

void DecorationPC(u8 taskId)
{
    sub_80FE220();
    gTasks[taskId].func = Task_DecorationPCProcessMenuInput;
}

void Task_SecretBasePC_Decoration(u8 taskId)
{
    DecorationPC(taskId);
    sDecorationContext.items = gSaveBlock1.secretBases[0].decorations;
    sDecorationContext.pos = gSaveBlock1.secretBases[0].decorationPos;
    sDecorationContext.size = sizeof gSaveBlock1.secretBases[0].decorations;
    sDecorationContext.isPlayerRoom = 0;
}

void DoPlayerPCDecoration(u8 taskId)
{
    DecorationPC(taskId);
    sDecorationContext.items = gSaveBlock1.playerRoomDecor;
    sDecorationContext.pos = gSaveBlock1.playerRoomDecorPos;
    sDecorationContext.size = sizeof gSaveBlock1.playerRoomDecor;
    sDecorationContext.isPlayerRoom = 1;
}

void sub_80FE2B4(void)
{
    u16 palettes[3] = {RGB(24, 24, 24),
                       RGB(28, 28, 28),
                       RGB(31, 31, 31)};
    LoadPalette(&palettes[2], 0xdf, 2);
    LoadPalette(&palettes[1], 0xd1, 2);
    LoadPalette(&palettes[0], 0xd8, 2);
}

void Task_DecorationPCProcessMenuInput(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        if (gMain.newKeys & DPAD_UP)
        {
            PlaySE(SE_SELECT);
            gUnknown_020388D4 = Menu_MoveCursor(-1);
            sub_80FE394();
        }
        if (gMain.newKeys & DPAD_DOWN)
        {
            PlaySE(SE_SELECT);
            gUnknown_020388D4 = Menu_MoveCursor(1);
            sub_80FE394();
        }
        if (gMain.newKeys & A_BUTTON)
        {
            PlaySE(SE_SELECT);
            gUnknown_083EC604[gUnknown_020388D4].func(taskId);
        } else if (gMain.newKeys & B_BUTTON)
        {
            PlaySE(SE_SELECT);
            gpu_pal_decompress_alloc_tag_and_upload(taskId);
        }
    }
}

void sub_80FE394(void)
{
    Menu_BlankWindowRect(4, 15, 25, 18);
    Menu_PrintText(gUnknown_083EC624[gUnknown_020388D4], 4, 15);
}

void gpu_pal_decompress_alloc_tag_and_upload(u8 taskId)
{
    Menu_DestroyCursor();
    Menu_EraseWindowRect(0, 0, 10, 9);
    Menu_BlankWindowRect(4, 15, 25, 18);
    FreeSpritePaletteByTag(6);
    if (sDecorationContext.isPlayerRoom == 0)
    {
        ScriptContext1_SetupScript(SecretBase_EventScript_PCCancel);
        DestroyTask(taskId);
    } else
    {
        ReshowPlayerPC(taskId);
    }
}

void sub_80FE418(u8 taskId)
{
    sub_80FE5AC(taskId);
}

void sub_80FE428(u8 taskId)
{
    InitMenu(0, 1, 1, 4, gUnknown_020388D4);
    sub_80FE394();
    gTasks[taskId].func = Task_DecorationPCProcessMenuInput;
}

void sub_80FE470(u8 decoCat, u8 left, u8 top, u8 palIdx) // PrintDecorationCategorySelectionMenuString
{
    u8 *strptr;
    u8 v0;
    v0 = Menu_GetTextWindowPaletteNum();
    // PALETTE {palIdx}
    strptr = gStringVar4;
    strptr[0] = EXT_CTRL_CODE_BEGIN;
    strptr[1] = 5;
    strptr[2] = palIdx;
    strptr += 3;
    strptr = StringCopy(strptr, gUnknown_083EC5E4[decoCat]);
    strptr = AlignInt1InMenuWindow(strptr, GetNumDecorationsInInventoryCategory(decoCat), 0x56, 1);
    *strptr++ = 0xba;
    strptr = AlignInt1InMenuWindow(strptr, gDecorationInventories[decoCat].size, 0x68, 1);
    strptr[0] = EXT_CTRL_CODE_BEGIN;
    strptr[1] = 5;
    strptr[2] = v0;
    strptr[3] = EOS;
    Menu_PrintText(gStringVar4, left, top);
}

void sub_80FE528(u8 taskId) // PrintDecorationCategorySelectionMenuStrings
{
    u8 decoCat;
    Menu_DrawStdWindowFrame(0, 0, 14, 19);
    for (decoCat=0; decoCat<8; decoCat++)
    {
        if (sDecorationContext.isPlayerRoom == 1 && gTasks[taskId].data[11] == 0 && decoCat != DECORCAT_DOLL && decoCat != DECORCAT_CUSHION)
        {
            sub_80FE470(decoCat, 2, 2 * decoCat + 1, 13); // Selectable
        } else
        {
            sub_80FE470(decoCat, 2, 2 * decoCat + 1, 255); // Unselectable
        }
    }
    Menu_PrintText(gOtherText_Exit, 2, 17);
}

void sub_80FE5AC(u8 taskId)
{
    Menu_DestroyCursor();
    Menu_EraseWindowRect(0, 0, 29, 19);
    sub_80FE528(taskId);
    InitMenu(0, 1, 1, 9, gUnknown_020388F6);
    gTasks[taskId].func = sub_80FE604;
}

void sub_80FE604(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        if (gMain.newAndRepeatedKeys & DPAD_UP)
        {
            PlaySE(SE_SELECT);
            Menu_MoveCursor(-1);
        } else if (gMain.newAndRepeatedKeys & DPAD_DOWN)
        {
            PlaySE(SE_SELECT);
            Menu_MoveCursor(1);
        } else if (gMain.newKeys & A_BUTTON)
        {
            PlaySE(SE_SELECT);
            gUnknown_020388F6 = Menu_GetCursorPos();
            if (gUnknown_020388F6 != 8)
            {
                gUnknown_020388D5 = GetNumDecorationsInInventoryCategory(gUnknown_020388F6);
                if (gUnknown_020388D5)
                {
                    SortDecorationInventory(gUnknown_020388F6);
                    gUnknown_020388D0 = gDecorationInventories[gUnknown_020388F6].items;
                    sub_80FEF50(taskId);
                    ClearVerticalScrollIndicatorPalettes();
                    sub_80F9480(gUnknown_020388F7, 8);
                    LoadScrollIndicatorPalette();
                    gTasks[taskId].func = sub_80FE868;
                } else
                {
                    Menu_DestroyCursor();
                    Menu_EraseWindowRect(0, 0, 14, 19);
                    DisplayItemMessageOnField(taskId, gSecretBaseText_NoDecors, sub_80FE418, 0);
                }
            } else
            {
                sub_80FE728(taskId);
            }
        } else if (gMain.newKeys & B_BUTTON)
        {
            PlaySE(SE_SELECT);
            sub_80FE728(taskId);
        }
    }
}

void sub_80FE728(u8 taskId)
{
    if (gTasks[taskId].data[11] != 3)
    {
        sub_80FE758(taskId);
    } else
    {
        sub_8109DAC(taskId);
    }
}

void sub_80FE758(u8 taskId)
{
    Menu_DestroyCursor();
    Menu_EraseWindowRect(0, 0, 14, 19);
    if (gTasks[taskId].data[11] != 2)
    {
        sub_80FE1DC();
        Menu_DisplayDialogueFrame();
        sub_80FE394();
        gTasks[taskId].func = Task_DecorationPCProcessMenuInput;
    } else
    {
        Shop_RunExitSellMenuTask(taskId);
    }
}

void sub_80FE7A8(u8 taskId)
{
    gTasks[taskId].data[11] = 3;
    gUnknown_020388F6 = 0;
    sub_80FE5AC(taskId);
}

void sub_80FE7D4(u8 *dest, u8 decClass)
{
    StringCopy(dest, gUnknown_083EC5E4[decClass]);
}

void sub_80FE7EC(u8 taskId)
{
    Menu_DestroyCursor();
    Menu_EraseWindowRect(0, 0, 29, 19);

    sub_80FEC94(taskId);
    sub_80FECB8(gUnknown_020388F6);

    Menu_DrawStdWindowFrame(15, 12, 29, 19);

    sub_80FECE0(gUnknown_020388F2 + gUnknown_020388F4);
    InitMenu(0, 1, 2, gUnknown_020388F3 + 1, gUnknown_020388F2);
}

void sub_80FE868(u8 taskId)
{
    sub_80FE7EC(taskId);
    gTasks[taskId].func = sub_80FE948;
}

void sub_80FE894(u8 taskId /*r8*/, s8 cursorVector /*r5*/, s8 bgVector /*r7*/)
{
    int v0 /*r10*/;
    u8 v1;
    v0 = gUnknown_020388F2 + gUnknown_020388F4 == gUnknown_020388D5;
    PlaySE(SE_SELECT);
    if (cursorVector != 0)
    {
        gUnknown_020388F2 = Menu_MoveCursor(cursorVector);
    }
    if (bgVector != 0)
    {
        v1 = gUnknown_020388F4;
        gUnknown_020388F4 = v1 + bgVector;
        sub_80FEABC(taskId, 1);
    }
    if (gUnknown_020388F2 + gUnknown_020388F4 != gUnknown_020388D5)
    {
        if (v0)
        {
            Menu_DrawStdWindowFrame(15, 12, 29, 19);
        }
        sub_80FECE0(gUnknown_020388F2 + gUnknown_020388F4);
    } else
    {
        Menu_EraseWindowRect(15, 12, 29, 19);
    }
}

void sub_80FE948(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        if ((gMain.newAndRepeatedKeys & DPAD_ANY) == DPAD_UP)
        {
            if (gUnknown_020388F2 != 0)
            {
                sub_80FE894(taskId, -1, 0);
            } else if (gUnknown_020388F4 != 0)
            {
                sub_80FE894(taskId, 0, -1);
            }
        }
        if ((gMain.newAndRepeatedKeys & DPAD_ANY) == DPAD_DOWN)
        {
            if (gUnknown_020388F2 != gUnknown_020388F3)
            {
                sub_80FE894(taskId, 1, 0);
            } else if (gUnknown_020388F4 + gUnknown_020388F2 != gUnknown_020388D5)
            {
                sub_80FE894(taskId, 0, 1);
            }
        }
        if (gMain.newKeys & A_BUTTON)
        {
            Menu_DestroyCursor();
            PlaySE(SE_SELECT);
            gUnknown_020388F5 = gUnknown_020388F2 + gUnknown_020388F4;
            if (gUnknown_020388F5 == gUnknown_020388D5)
            {
                gUnknown_083EC634[gTasks[taskId].data[11]].noFunc(taskId);
            } else
            {
                gUnknown_083EC634[gTasks[taskId].data[11]].yesFunc(taskId);
            }
        } else if (gMain.newKeys & B_BUTTON)
        {
            Menu_DestroyCursor();
            PlaySE(SE_SELECT);
            gUnknown_083EC634[gTasks[taskId].data[11]].noFunc(taskId);
        }
    }
}

const u8 gUnknown_083EC65A[] = _("{PALETTE 13}{STR_VAR_1}");

void sub_80FEABC(u8 taskId, u8 dummy1)
{
    u16 i;
    u16 j;
    u8 ni;
    if (gUnknown_020388F4 != 0 || (DestroyVerticalScrollIndicator(TOP_ARROW), gUnknown_020388F4 != 0))
    {
        CreateVerticalScrollIndicators(TOP_ARROW, 0x3c, 0x08);
    }
    if (gUnknown_020388F4 + 7 == gUnknown_020388D5)
    {
        DestroyVerticalScrollIndicator(BOTTOM_ARROW);
    }
    if (gUnknown_020388F4 + 7 < gUnknown_020388D5)
    {
        CreateVerticalScrollIndicators(BOTTOM_ARROW, 0x3c, 0x98);
    }
    for (i=gUnknown_020388F4; i<gUnknown_020388F4+8; i++)
    {
        ni = 2 * (i - gUnknown_020388F4) + 2;
        if (gUnknown_020388F7[i - gUnknown_020388F4])
        {
            sub_80F94F8(&gUnknown_020388F7[i - gUnknown_020388F4]);
        }
        if (i == gUnknown_020388D5)
        {
            Menu_PrintTextPixelCoordsAndGetLines(gOtherText_Exit, 16, 8 * ni, 0x68, 1);
            break;
        }
        if (gUnknown_020388D0[i])
        {
            if (sDecorationContext.isPlayerRoom == 1 && gUnknown_020388F6 != DECORCAT_DOLL && gUnknown_020388F6 != DECORCAT_CUSHION && gTasks[taskId].data[11] == 0)
            {
                StringCopy(gStringVar1, gDecorations[gUnknown_020388D0[i]].name);
                Menu_PrintTextPixelCoordsAndGetLines(gUnknown_083EC65A, 16, 8 * ni, 0x68, 1);
            } else
            {
                Menu_PrintTextPixelCoordsAndGetLines(gDecorations[gUnknown_020388D0[i]].name, 16, 8 * ni, 0x68, 1);
            }
            for (j=0; j<16; j++)
            {
                if (gUnknown_020388D6[j] - 1 == i)
                {
                    sub_80F94A4(4, &gUnknown_020388F7[i - gUnknown_020388F4], 0x6c, (i - gUnknown_020388F4) * 16 + 24);
                    break;
                }
            }
            for (j=0; j<12; j++)
            {
                if (gUnknown_020388E6[j] - 1 == i)
                {
                    sub_80F94A4(5, &gUnknown_020388F7[i - gUnknown_020388F4], 0x6c, (i - gUnknown_020388F4) * 16 + 24);
                    break;
                }
            }
        }
    }
}

void sub_80FEC94(u8 taskId)
{
    Menu_DrawStdWindowFrame(0, 0, 14, 19);
    sub_80FEABC(taskId, 0);
}

void sub_80FECB8(u8 decoCat)
{
    Menu_DrawStdWindowFrame(15, 0, 29, 3);
    sub_80FE470(decoCat, 16, 1, 0xff);
}

void sub_80FECE0(u8 decoCat)
{
    sub_8072AB0(gDecorations[gUnknown_020388D0[decoCat]].description, 128, 104, 104, 48, 1);
}

void sub_80FED1C(void)
{
    Menu_EraseWindowRect(15, 0, 29, 3);
    Menu_EraseWindowRect(15, 12, 29, 19);
}

void sub_80FED3C(u8 taskId)
{
    LoadScrollIndicatorPalette();
    gTasks[taskId].func = sub_80FE868;
}

bool8 sub_80FED64(u8 a0)
{
    u8 i;
    for (i=0; i<16; i++)
    {
        if (gUnknown_020388D6[i] == a0)
        {
            return TRUE;
        }
    }
    return FALSE;
}

void sub_80FED90(u8 taskId)
{
    u16 i;
    u16 j;
    u16 k;
    u16 cnt;
    cnt = 0;
    for (i=0; i<16; i++)
    {
        gUnknown_020388D6[i] = 0;
        if (i < 12)
        {
            gUnknown_020388E6[i] = 0;
        }
    }
    for (i=0; i<16; i++)
    {
        if (gSaveBlock1.secretBases[0].decorations[i] != 0)
        {
            for (j=0; j<gDecorationInventories[gUnknown_020388F6].size; j++)
            {
                if (gUnknown_020388D0[j] == gSaveBlock1.secretBases[0].decorations[i])
                {
                    for (k=0; k<cnt && gUnknown_020388D6[k]!=j+1; k++);
                    if (k == cnt)
                    {
                        gUnknown_020388D6[cnt] = j+1;
                        cnt++;
                        break;
                    }
                }
            }
        }
    }
    cnt = 0;
    for (i=0; i<12; i++)
    {
        if (gSaveBlock1.playerRoomDecor[i] != 0)
        {
            for (j=0; j<gDecorationInventories[gUnknown_020388F6].size; j++)
            {
                if (gUnknown_020388D0[j] == gSaveBlock1.playerRoomDecor[i] && !sub_80FED64(j + 1))
                {
                    for (k=0; k<cnt && gUnknown_020388E6[k]!=j+1; k++);
                    if (k == cnt)
                    {
                        gUnknown_020388E6[cnt] = j+1;
                        cnt++;
                        break;
                    }
                }
            }
        }
    }
}

void sub_80FEF28(void)
{
    if (gUnknown_020388D5 <= 7)
    {
        gUnknown_020388F3 = gUnknown_020388D5;
    } else
    {
        gUnknown_020388F3 = 7;
    }
}

void sub_80FEF50(u8 taskId)
{
    sub_80FED90(taskId);
    sub_80FEF28();
    gUnknown_020388F2 = 0;
    gUnknown_020388F4 = 0;
}

void sub_80FEF74(void)
{
    sub_80F9520(gUnknown_020388F7, 8);
    DestroyVerticalScrollIndicator(TOP_ARROW);
    DestroyVerticalScrollIndicator(BOTTOM_ARROW);
    Menu_DestroyCursor();
    Menu_EraseWindowRect(0, 0, 14, 19);
}

bool8 sub_80FEFA4(void)
{
    u16 i;
    int v0;
    for (i=0; i<16; i++)
    {
        v0 = gUnknown_020388F4 + gUnknown_020388F2 + 1;
        if (gUnknown_020388D6[i] == v0 || (i < 12 && gUnknown_020388E6[i] == v0))
        {
            return FALSE;
        }
    }
    return TRUE;
}

void sub_80FEFF4(u8 taskId)
{
    if (gMain.newKeys & A_BUTTON || gMain.newKeys & B_BUTTON)
    {
        LoadScrollIndicatorPalette();
        gTasks[taskId].func = sub_80FE868;
    }
}

void sub_80FF034(u8 taskId)
{
    Menu_DestroyCursor();
    Menu_EraseWindowRect(0, 0, 14, 19);
    sub_80FE5AC(taskId);
}

void sub_80FF058(u8 taskId)
{
    sub_80F9520(gUnknown_020388F7, 8);
    DestroyVerticalScrollIndicator(TOP_ARROW);
    DestroyVerticalScrollIndicator(BOTTOM_ARROW);
    BuyMenuFreeMemory();
    gTasks[taskId].func = sub_80FF034;
}

void sub_80FF098(u8 taskId)
{
    gUnknown_020388D5--;
    if (gUnknown_020388F4 + 7 > gUnknown_020388D5 && gUnknown_020388F4 != 0)
    {
        gUnknown_020388F4--;
    }
    SortDecorationInventory(gUnknown_020388F6);
    sub_80FED90(taskId);
    sub_80FEF28();
}

void sub_80FF0E0(u8 taskId)
{
    gTasks[taskId].data[3] = gSaveBlock1.pos.x;
    gTasks[taskId].data[4] = gSaveBlock1.pos.y;
    PlayerGetDestCoords(&gTasks[taskId].data[0], &gTasks[taskId].data[1]);
}

void sub_80FF114(u8 taskId)
{
    DrawWholeMapView();
    Overworld_SetWarpDestination(gSaveBlock1.location.mapGroup, gSaveBlock1.location.mapNum, -1, gTasks[taskId].data[3], gTasks[taskId].data[4]);
    WarpIntoMap();
}
void sub_80FF160(u8 taskId)
{
    if (!GetNumDecorationsInInventory())
    {
        DisplayItemMessageOnField(taskId, gSecretBaseText_NoDecors, sub_80FE428, 0);
    } else
    {
        gTasks[taskId].data[11] = 0;
        gUnknown_020388F6 = 0;
        sub_80FE5AC(taskId);
    }
}

u16 sub_80FF1B0(u8 decoId, u8 a1)
{
    u16 retval;
    retval = 0xffff;

    switch (decoId)
    {
        case DECOR_STAND:
            retval = gUnknown_083EC97C[a1] << 12;
            return retval;
        case DECOR_SLIDE:
            retval = gUnknown_083EC984[a1] << 12;
            return retval;
        default:
            return retval;
    }
}

void sub_80FF1EC(u16 mapX, u16 mapY, u8 decWidth, u8 decHeight, u16 decIdx)
{
    u16 i;
    u16 j;
    u16 behavior;
    u16 collision;
    u16 v0;
    u16 v1;
    s16 x;
    s16 decBottom;

    for (i=0; i<decHeight; i++)
    {
        decBottom = mapY - decHeight + 1 + i;
        for (j=0; j<decWidth; j++)
        {
            x = mapX + j;
            behavior = GetBehaviorByMetatileId(0x200 + gDecorations[decIdx].tiles[i * decWidth + j]);
            if (MetatileBehavior_IsSecretBaseImpassable(behavior) == TRUE || (gDecorations[decIdx].permission != DECORPERM_PASS_FLOOR && (behavior >> 12) != 0))
                collision = 0xc00; // impassable collision
            else
                collision = 0x000; // passable collision

            if (gDecorations[decIdx].permission != DECORPERM_NA_WALL && MetatileBehavior_IsSecretBaseNorthWall(MapGridGetMetatileBehaviorAt(x, decBottom)) == 1)
                v0 = 1;
            else
                v0 = 0;

            v1 = sub_80FF1B0(gDecorations[decIdx].id, i * decWidth + j);
            if (v1 != 0xffff)
            {
                MapGridSetMetatileEntryAt(x, decBottom, (gDecorations[decIdx].tiles[i * decWidth + j] + (0x200 | v0)) | collision | v1);
            } else
            {
                MapGridSetMetatileIdAt(x, decBottom, (gDecorations[decIdx].tiles[i * decWidth + j] + (0x200 | v0)) | collision);
            }
        }
    }
}

void sub_80FF394(u16 mapX, u16 mapY, u16 decIdx)
{
    switch (gDecorations[decIdx].shape)
    {
        case DECORSHAPE_1x1:
            sub_80FF1EC(mapX, mapY, 1, 1, decIdx);
            break;
        case DECORSHAPE_2x1:
            sub_80FF1EC(mapX, mapY, 2, 1, decIdx);
            break;
        case DECORSHAPE_3x1: // unused
            sub_80FF1EC(mapX, mapY, 3, 1, decIdx);
            break;
        case DECORSHAPE_4x2:
            sub_80FF1EC(mapX, mapY, 4, 2, decIdx);
            break;
        case DECORSHAPE_2x2:
            sub_80FF1EC(mapX, mapY, 2, 2, decIdx);
            break;
        case DECORSHAPE_1x2:
            sub_80FF1EC(mapX, mapY, 1, 2, decIdx);
            break;
        case DECORSHAPE_1x3: // unused
            sub_80FF1EC(mapX, mapY, 1, 3, decIdx);
            break;
        case DECORSHAPE_2x4:
            sub_80FF1EC(mapX, mapY, 2, 4, decIdx);
            break;
        case DECORSHAPE_3x3:
            sub_80FF1EC(mapX, mapY, 3, 3, decIdx);
            break;
        case DECORSHAPE_3x2:
            sub_80FF1EC(mapX, mapY, 3, 2, decIdx);
            break;
    }
}

void sub_80FF474(void)
{
    u8 i;
    u8 j;
    for (i=0; i<14; i++)
    {
        if (FlagGet(i + FLAG_DECORATION_2) == 1)
        {
            FlagClear(i + FLAG_DECORATION_2);
            for (j=0; j<gMapHeader.events->objectEventCount; j++)
            {
                if (gMapHeader.events->objectEvents[j].flagId == i + FLAG_DECORATION_2)
                {
                    break;
                }
            }
            VarSet(0x3f20 + gMapHeader.events->objectEvents[j].graphicsId, gUnknown_02038900.decoration->tiles[0]);
            gSpecialVar_0x8005 = gMapHeader.events->objectEvents[j].localId;
            gSpecialVar_0x8006 = gUnknown_020391A4;
            gSpecialVar_0x8007 = gUnknown_020391A6;
            show_sprite(gSpecialVar_0x8005, gSaveBlock1.location.mapNum, gSaveBlock1.location.mapGroup);
            sub_805C0F8(gSpecialVar_0x8005, gSaveBlock1.location.mapNum, gSaveBlock1.location.mapGroup, gSpecialVar_0x8006, gSpecialVar_0x8007);
            TryOverrideTemplateCoordsForObjectEvent(gSpecialVar_0x8005, gSaveBlock1.location.mapNum, gSaveBlock1.location.mapGroup);
            break;
        }
    }
}

bool8 sub_80FF58C/*IsThereRoomForMoreDecorations*/(void)
{
    u16 i;
    for (i=0; i<sDecorationContext.size; i++)
    {
        if (sDecorationContext.items[i] == 0)
        {
            return TRUE;
        }
    }
    return FALSE;
}

void sub_80FF5BC(u8 taskId)
{
    if (sDecorationContext.isPlayerRoom == 1 && gUnknown_020388F6 != DECORCAT_DOLL && gUnknown_020388F6 != DECORCAT_CUSHION)
    {
        sub_80FEF74();
        sub_80FED1C();
        DisplayItemMessageOnField(taskId, gSecretBaseText_DecorCantPlace, sub_80FEFF4, 0);
    } else if (sub_80FEFA4() == TRUE)
    {
        if (sub_80FF58C() == TRUE)
        {
            FadeScreen(1, 0);
            gTasks[taskId].data[2] = 0;
            gTasks[taskId].func = sub_80FF6AC;
        } else
        {
            sub_80FEF74();
            sub_80FED1C();
            ConvertIntToDecimalStringN(gStringVar1, sDecorationContext.size, STR_CONV_MODE_RIGHT_ALIGN, 2);
            if (!sDecorationContext.isPlayerRoom)
            {
                StringExpandPlaceholders(gStringVar4, gSecretBaseText_NoMoreDecor);
            } else
            {
                StringExpandPlaceholders(gStringVar4, gSecretBaseText_NoMoreDecor2);
            }
            DisplayItemMessageOnField(taskId, gStringVar4, sub_80FEFF4, 0);
        }
    } else
    {
        sub_80FEF74();
        sub_80FED1C();
        DisplayItemMessageOnField(taskId, gSecretBaseText_InUseAlready, sub_80FEFF4, 0);
    }
}

void sub_80FF6AC(u8 taskId)
{
    switch (gTasks[taskId].data[2])
    {
        case 0:
            if (!gPaletteFade.active)
            {
                sub_80FF0E0(taskId);
                DestroyVerticalScrollIndicator(TOP_ARROW);
                DestroyVerticalScrollIndicator(BOTTOM_ARROW);
                sub_80F9520(gUnknown_020388F7, 8);
                BuyMenuFreeMemory();
                gTasks[taskId].data[2] = 1;
            }
            break;
        case 1:
            gPaletteFade.bufferTransferDisabled = 1;
            AddDecorationIconObjectFromObjectEvent(&gUnknown_02038900, gUnknown_020388D0[gUnknown_020388F5]);
            sub_80FF960(taskId);
            SetUpPlacingDecorationPlayerAvatar(taskId, &gUnknown_02038900);
            pal_fill_black();
            gPaletteFade.bufferTransferDisabled = 0;
            gTasks[taskId].data[2] = 2;
            break;
        case 2:
            if (IsWeatherNotFadingIn() == TRUE)
            {
                gTasks[taskId].data[12] = 0;
                sub_810065C(taskId);
            }
            break;
    }
}

void AddDecorationIconObjectFromObjectEvent(struct UnkStruct_02038900 * unk_02038900, u8 decoIdx)
{
    sub_80FEF74();
    sub_80FED1C();
    sub_81006D0(unk_02038900);
    unk_02038900->decoration = &gDecorations[decoIdx];
    if (gDecorations[decoIdx].permission != DECORPERM_SOLID_MAT)
    {
        sub_81008BC(unk_02038900);
        sub_8100930(unk_02038900->decoration->shape);
        sub_8100874(unk_02038900);
        sub_810070C(unk_02038900->palette, ((u16 *)gMapHeader.mapLayout->secondaryTileset->metatiles + 8 * unk_02038900->decoration->tiles[0])[7] >> 12);
        LoadSpritePalette(&gUnknown_083EC954);
        gUnknown_020391A8 = gSprites[gFieldCamera.trackedSpriteId].data[0];
        gFieldCamera.trackedSpriteId = CreateSprite(&gSpriteTemplate_83EC93C, gUnknown_083EC900[unk_02038900->decoration->shape].x,  gUnknown_083EC900[unk_02038900->decoration->shape].y, 0);
    } else
    {
        gUnknown_020391A8 = gSprites[gFieldCamera.trackedSpriteId].data[0];
        gFieldCamera.trackedSpriteId = AddPseudoObjectEvent(unk_02038900->decoration->tiles[0], sub_81009A8, gUnknown_083EC900[unk_02038900->decoration->shape].x,  gUnknown_083EC900[unk_02038900->decoration->shape].y, 1);
        gSprites[gFieldCamera.trackedSpriteId].oam.priority = 1;
    }
}

void SetUpPlacingDecorationPlayerAvatar(u8 taskId, struct UnkStruct_02038900 *unk_02038900)
{
    u8 v0;
    v0 = 16 * (u8)gTasks[taskId].data[5] + gUnknown_083EC900[unk_02038900->decoration->shape].x - 8 * ((u8)gTasks[taskId].data[5] - 1);
    if (unk_02038900->decoration->shape == DECORSHAPE_3x1 || unk_02038900->decoration->shape == DECORSHAPE_3x3 || unk_02038900->decoration->shape == DECORSHAPE_3x2)
    {
        v0 -= 8;
    }
    if (gSaveBlock2.playerGender == MALE)
    {
        gUnknown_020391A9 = AddPseudoObjectEvent(0xc1, SpriteCallbackDummy, v0, 0x48, 0);
    } else
    {
        gUnknown_020391A9 = AddPseudoObjectEvent(0xc2, SpriteCallbackDummy, v0, 0x48, 0);
    }
    gSprites[gUnknown_020391A9].oam.priority = 1;
    DestroySprite(&gSprites[gUnknown_020391A8]);
    gUnknown_020391A8 = gFieldCamera.trackedSpriteId;
}

void sub_80FF960(u8 taskId)
{
    switch (gDecorations[gUnknown_020388D0[gUnknown_020388F5]].shape)
    {
        case DECORSHAPE_1x1:
            gTasks[taskId].data[5] = 1;
            gTasks[taskId].data[6] = 1;
            break;
        case DECORSHAPE_2x1:
            gTasks[taskId].data[5] = 2;
            gTasks[taskId].data[6] = 1;
            break;
        case DECORSHAPE_3x1:
            gTasks[taskId].data[5] = 3;
            gTasks[taskId].data[6] = 1;
            break;
        case DECORSHAPE_4x2:
            gTasks[taskId].data[5] = 4;
            gTasks[taskId].data[6] = 2;
            break;
        case DECORSHAPE_2x2:
            gTasks[taskId].data[5] = 2;
            gTasks[taskId].data[6] = 2;
            break;
        case DECORSHAPE_1x2:
            gTasks[taskId].data[5] = 1;
            gTasks[taskId].data[6] = 2;
            break;
        case DECORSHAPE_1x3:
            gTasks[taskId].data[5] = 1;
            gTasks[taskId].data[6] = 3;
            gTasks[taskId].data[1]++;
            break;
        case DECORSHAPE_2x4:
            gTasks[taskId].data[5] = 2;
            gTasks[taskId].data[6] = 4;
            break;
        case DECORSHAPE_3x3:
            gTasks[taskId].data[5] = 3;
            gTasks[taskId].data[6] = 3;
            break;
        case DECORSHAPE_3x2:
            gTasks[taskId].data[5] = 3;
            gTasks[taskId].data[6] = 2;
            break;
    }
}

void sub_80FFAB0(u8 taskId)
{
    gTasks[taskId].data[10] = 0;
    gSprites[gUnknown_020391A8].data[7] = 1;
    gSprites[gUnknown_020391A9].data[7] = 1;
    sub_810045C();
    sub_8100038(taskId);
}

void sub_80FFB08(u8 taskId)
{
    gTasks[taskId].data[10] = 0;
    gSprites[gUnknown_020391A8].data[7] = 1;
    gSprites[gUnknown_020391A9].data[7] = 1;
    sub_810045C();
    DisplayItemMessageOnField(taskId, gSecretBaseText_CancelDecorating, sub_8100248, 0);
}

bool8 sub_80FFB6C(u8 metatileBehavior, u16 layerType)
{
    if (MetatileBehavior_IsBlockDecoration(metatileBehavior) != TRUE || layerType != 0)
    {
        return FALSE;
    }
    return TRUE;
}

bool8 sub_80FFB94(u8 taskId, s16 x, s16 y, u16 decoId)
{
    if (x == gTasks[taskId].data[3] + 7 && y == gTasks[taskId].data[4] + 7 && decoId != 0)
    {
        return FALSE;
    }
    return TRUE;
}

bool8 sub_80FFBDC(u16 metatileBehavior, const struct Decoration *decoration)
{
    if (MetatileBehavior_IsBlockDecoration(metatileBehavior) != TRUE)
    {
        if (decoration->id == DECOR_SOLID_BOARD && MetatileBehavior_IsSecretBaseHole(metatileBehavior) == TRUE)
        {
            return TRUE;
        }
        if (MetatileBehavior_IsNormal(metatileBehavior))
        {
            return TRUE;
        }
    }
    return FALSE;
}

bool8 sub_80FFC24(u8 taskId, const struct Decoration *decoration)
{
    u8 i;
    u8 j;
    u8 behaviorAt;
    u16 layerType;
    u8 mapY;
    u8 mapX;
    s16 curY;
    s16 curX;
    mapY = gTasks[taskId].data[6];
    mapX = gTasks[taskId].data[5];
    switch (decoration->permission)
    {
        case DECORPERM_SOLID_FLOOR:
        case DECORPERM_PASS_FLOOR:
            for (i=0; i<mapY; i++)
            {
                curY = gTasks[taskId].data[1] - i;
                for (j=0; j<mapX; j++)
                {
                    curX = gTasks[taskId].data[0] + j;
                    behaviorAt = MapGridGetMetatileBehaviorAt(curX, curY);
                    layerType = GetBehaviorByMetatileId(0x200 + decoration->tiles[(mapY - 1 - i) * mapX + j]) & 0xf000;
                    if (!sub_80FFBDC(behaviorAt, decoration))
                    {
                        return FALSE;
                    }
                    if (!sub_80FFB94(taskId, curX, curY, layerType))
                    {
                        return FALSE;
                    }
                    behaviorAt = GetObjectEventIdByXYZ(curX, curY, 0);
                    if (behaviorAt != 0 && behaviorAt != 16)
                    {
                        return FALSE;
                    }
                }
            }
            break;
        case DECORPERM_BEHIND_FLOOR:
            for (i=0; i<mapY-1; i++)
            {
                curY = gTasks[taskId].data[1] - i;
                for (j=0; j<mapX; j++)
                {
                    curX = gTasks[taskId].data[0] + j;
                    behaviorAt = MapGridGetMetatileBehaviorAt(curX, curY);
                    layerType = GetBehaviorByMetatileId(0x200 + decoration->tiles[(mapY - 1 - i) * mapX + j]) & 0xf000;
                    if (!MetatileBehavior_IsNormal(behaviorAt) && !sub_80FFB6C(behaviorAt, layerType))
                    {
                        return FALSE;
                    }
                    if (!sub_80FFB94(taskId, curX, curY, layerType))
                    {
                        return FALSE;
                    }
                    if (GetObjectEventIdByXYZ(curX, curY, 0) != 16)
                    {
                        return FALSE;
                    }
                }
            }
            curY = gTasks[taskId].data[1] - mapY + 1;
            for (j=0; j<mapX; j++)
            {
                curX = gTasks[taskId].data[0] + j;
                behaviorAt = MapGridGetMetatileBehaviorAt(curX, curY);
                layerType = GetBehaviorByMetatileId(0x200 + decoration->tiles[j]) & 0xf000;
                if (!MetatileBehavior_IsNormal(behaviorAt) && !MetatileBehavior_IsSecretBaseNorthWall(behaviorAt))
                {
                    return FALSE;
                }
                if (!sub_80FFB94(taskId, curX, curY, layerType))
                {
                    return FALSE;
                }
                behaviorAt = GetObjectEventIdByXYZ(curX, curY, 0);
                if (behaviorAt != 0 && behaviorAt != 16)
                {
                    return FALSE;
                }
            }
            break;
        case DECORPERM_NA_WALL:
            for (i=0; i<mapY; i++)
            {
                curY = gTasks[taskId].data[1] - i;
                for (j=0; j<mapX; j++)
                {
                    curX = gTasks[taskId].data[0] + j;
                    if (!MetatileBehavior_IsSecretBaseNorthWall(MapGridGetMetatileBehaviorAt(curX, curY)))
                    {
                        return FALSE;
                    }
                    if (MapGridGetMetatileIdAt(curX, curY + 1) == 0x28c)
                    {
                        return FALSE;
                    }
                }
            }
            break;
        case DECORPERM_SOLID_MAT:
            curY = gTasks[taskId].data[1];
            for (j=0; j<mapX; j++)
            {
                curX = gTasks[taskId].data[0] + j;
                behaviorAt = MapGridGetMetatileBehaviorAt(curX, curY);
                if (decoration->shape == DECORSHAPE_1x2)
                {
                    if (!MetatileBehavior_IsLargeMatCenter(behaviorAt))
                    {
                        return FALSE;
                    }
                }
                else if (!MetatileBehavior_IsSecretBaseLargeMatEdge(behaviorAt))
                {
                    if (!MetatileBehavior_IsLargeMatCenter(behaviorAt))
                    {
                        return FALSE;
                    }
                }
                if (GetObjectEventIdByXYZ(curX, curY, 0) != 16)
                {
                    return FALSE;
                }
            }
            break;
    }
    return TRUE;
}

void sub_8100038(u8 taskId)
{
    if (sub_80FFC24(taskId, &gDecorations[gUnknown_020388D0[gUnknown_020388F5]]) == 1)
    {
        DisplayItemMessageOnField(taskId, gSecretBaseText_PlaceItHere, sub_81000A0, 0);
    } else
    {
        PlaySE(SE_FAILURE);
        DisplayItemMessageOnField(taskId, gSecretBaseText_CantBePlacedHere, sub_81006A8, 0);
    }
}

void sub_81000A0(u8 taskId)
{
    DisplayYesNoMenu(20, 8, 1);
    DoYesNoFuncWithChoice(taskId, &gUnknown_083EC95C);
}

void sub_81000C4(u8 taskId)
{
    Menu_EraseWindowRect(0, 0, 29, 19);
    sub_8100174(taskId);
    if (gDecorations[gUnknown_020388D0[gUnknown_020388F5]].permission != DECORPERM_SOLID_MAT)
    {
        sub_80FF394(gTasks[taskId].data[0], gTasks[taskId].data[1], gUnknown_020388D0[gUnknown_020388F5]);
    } else
    {
        gUnknown_020391A4 = gTasks[taskId].data[0] - 7;
        gUnknown_020391A6 = gTasks[taskId].data[1] - 7;
        ScriptContext1_SetupScript(gUnknown_081A2F7B);
    }
    gSprites[gUnknown_020391A8].y += 2;
    sub_810028C(taskId);
}

void sub_8100174(u8 taskId)
{
    u16 i;
    for (i=0; i<sDecorationContext.size; i++)
    {
        if (sDecorationContext.items[i] == 0)
        {
            sDecorationContext.items[i] = gUnknown_020388D0[gUnknown_020388F5];
            sDecorationContext.pos[i] = ((gTasks[taskId].data[0] - 7) << 4) + (gTasks[taskId].data[1] - 7);
            break;
        }
    }
    if (!sDecorationContext.isPlayerRoom)
    {
        for (i=0; i<16; i++)
        {
            if (gUnknown_020388D6[i] == 0)
            {
                gUnknown_020388D6[i] = gUnknown_020388F5 + 1;
                break;
            }
        }
    } else
    {
        for (i=0; i<12; i++)
        {
            if (gUnknown_020388E6[i] == 0)
            {
                gUnknown_020388E6[i] = gUnknown_020388F5 + 1;
                break;
            }
        }
    }
}

void sub_8100248(u8 taskId)
{
    DisplayYesNoMenu(20, 8, 1);
    DoYesNoFuncWithChoice(taskId, &gUnknown_083EC964);
}

void sub_810026C(u8 taskId)
{
    Menu_EraseWindowRect(0, 0, 29, 19);
    sub_810028C(taskId);
}

void sub_810028C(u8 taskId)
{
    FadeScreen(1, 0);
    gTasks[taskId].data[2] = 0;
    gTasks[taskId].func = c1_overworld_prev_quest;
}

void c1_overworld_prev_quest(u8 taskId)
{
    switch (gTasks[taskId].data[2])
    {
        case 0:
            ScriptContext2_Enable();
            if (!gPaletteFade.active)
            {
                sub_80FF114(taskId);
                gTasks[taskId].data[2] = 1;
            }
            break;
        case 1:
            sub_81016F4();
            FreeSpritePaletteByTag(0xbb8);
            gFieldCallback = &sub_8100364;
            SetMainCallback2(CB2_ReturnToField);
            DestroyTask(taskId);
            break;
    }
}

void sub_8100334(u8 taskId)
{
    if (IsWeatherNotFadingIn() == TRUE)
    {
        gTasks[taskId].func = sub_80FE948;
    }
}

void sub_8100364(void)
{
    ScriptContext2_Enable();
    LoadScrollIndicatorPalette();
    pal_fill_black();
    sub_80FE7EC(CreateTask(sub_8100334, 8));
}

bool8 sub_810038C(u8 taskId)
{
    s16 *data;
    data = gTasks[taskId].data;
    if (gUnknown_020391AA == DIR_SOUTH && data[1] - data[6] - 6 < 0)
    {
        data[1]++;
        return FALSE;
    } else if (gUnknown_020391AA == DIR_NORTH && data[1] - 7 >= gMapHeader.mapLayout->height)
    {
        data[1]--;
        return FALSE;
    } else if (gUnknown_020391AA == DIR_WEST && data[0] - 7 < 0)
    {
        data[0]++;
        return FALSE;
    } else if (gUnknown_020391AA == DIR_EAST && data[0] + data[5] - 8 >= gMapHeader.mapLayout->width)
    {
        data[0]--;
        return FALSE;
    }
    return TRUE;
}

bool8 sub_8100430(void)
{
    if ((gMain.heldKeys & DPAD_ANY) != DPAD_UP && (gMain.heldKeys & DPAD_ANY) != DPAD_DOWN && (gMain.heldKeys & DPAD_ANY) != DPAD_LEFT && (gMain.heldKeys & DPAD_ANY) != DPAD_RIGHT)
    {
        return FALSE;
    }
    return TRUE;
}

void sub_810045C(void)
{
    gUnknown_020391AA = 0;
    gSprites[gUnknown_020391A8].data[2] = 0;
    gSprites[gUnknown_020391A8].data[3] = 0;
}

void sub_8100494(u8 taskId)
{
    if (!gSprites[gUnknown_020391A8].data[4])
    {
        if (gTasks[taskId].data[10] == 1)
        {
            gUnknown_083EC96C[gTasks[taskId].data[12]].yesFunc(taskId);
            return;
        } else if (gTasks[taskId].data[10] == 2)
        {
            gUnknown_083EC96C[gTasks[taskId].data[12]].noFunc(taskId);
            return;
        }
        if ((gMain.heldKeys & DPAD_ANY) == DPAD_UP)
        {
            gUnknown_020391AA = DIR_SOUTH;
            gSprites[gUnknown_020391A8].data[2] =  0;
            gSprites[gUnknown_020391A8].data[3] = -2;
            gTasks[taskId].data[1]--;
        }
        if ((gMain.heldKeys & DPAD_ANY) == DPAD_DOWN)
        {
            gUnknown_020391AA = DIR_NORTH;
            gSprites[gUnknown_020391A8].data[2] =  0;
            gSprites[gUnknown_020391A8].data[3] =  2;
            gTasks[taskId].data[1]++;
        }
        if ((gMain.heldKeys & DPAD_ANY) == DPAD_LEFT)
        {
            gUnknown_020391AA = DIR_WEST;
            gSprites[gUnknown_020391A8].data[2] = -2;
            gSprites[gUnknown_020391A8].data[3] =  0;
            gTasks[taskId].data[0]--;
        }
        if ((gMain.heldKeys & DPAD_ANY) == DPAD_RIGHT)
        {
            gUnknown_020391AA = DIR_EAST;
            gSprites[gUnknown_020391A8].data[2] =  2;
            gSprites[gUnknown_020391A8].data[3] =  0;
            gTasks[taskId].data[0]++;
        }
        if (!sub_8100430() || !sub_810038C(taskId))
        {
            sub_810045C();
        }
    }
    if (gUnknown_020391AA)
    {
        gSprites[gUnknown_020391A8].data[4]++;
        gSprites[gUnknown_020391A8].data[4] &= 7;
    }
    if (!gTasks[taskId].data[10])
    {
        if (gMain.newKeys & A_BUTTON)
        {
            gTasks[taskId].data[10] = A_BUTTON;
        }
        if (gMain.newKeys & B_BUTTON)
        {
            gTasks[taskId].data[10] = B_BUTTON;
        }
    }
}

void sub_810065C(u8 taskId)
{
    Menu_EraseWindowRect(0, 0, 29, 19);
    gSprites[gUnknown_020391A8].data[7] = 0;
    gTasks[taskId].data[10] = 0;
    gTasks[taskId].func = sub_8100494;
}

void sub_81006A8(u8 taskId)
{
    if ((gMain.newKeys & A_BUTTON) || (gMain.newKeys & B_BUTTON))
    {
        sub_810065C(taskId);
    }
}

void sub_81006D0(struct UnkStruct_02038900 *unk_02038900)
{
    u16 i;
    for (i=0; i<0x800; i++)
    {
        unk_02038900->image[i] = 0;
    }
    for (i=0; i<0x40; i++)
    {
        unk_02038900->tiles[i] = 0;
    }
}

void sub_810070C(u16 *a0, u16 a1)
{
    u16 i;
    for (i=0; i<16; i++)
    {
        a0[i] = ((u16 *)gMapHeader.mapLayout->primaryTileset->palettes)[16 * a1 + i];
    }
}

void sub_8100740(u8 *dest, u16 flags)
{
    u8 buffer[32];
    u16 mode;
    u16 i;
    mode = flags >> 10;
    if (flags != 0)
    {
        flags &= 0x3ff;
    }
    for (i=0; i<32; i++)
    {
        buffer[i] = ((u8 *)gMapHeader.mapLayout->primaryTileset->tiles)[flags * 32 + i];
    }
    switch (mode)
    {
        case 0:
            for (i=0; i<32; i++)
            {
                dest[i] = buffer[i];
            }
            break;
        case 1:
            for (i=0; i<8; i++)
            {
                dest[4*i] = (buffer[4*(i+1) - 1] >> 4) + ((buffer[4*(i+1) - 1] & 0xf) << 4);
                dest[4*i + 1] = (buffer[4*(i+1) - 2] >> 4) + ((buffer[4*(i+1) - 2] & 0xf) << 4);
                dest[4*i + 2] = (buffer[4*(i+1) - 3] >> 4) + ((buffer[4*(i+1) - 3] & 0xf) << 4);
                dest[4*i + 3] = (buffer[4*(i+1) - 4] >> 4) + ((buffer[4*(i+1) - 4] & 0xf) << 4);
            }
            break;
        case 2:
            for (i=0; i<8; i++)
            {
                dest[4*i] = buffer[4*(7-i)];
                dest[4*i + 1] = buffer[4*(7-i) + 1];
                dest[4*i + 2] = buffer[4*(7-i) + 2];
                dest[4*i + 3] = buffer[4*(7-i) + 3];
            }
            break;
        case 3:
            for (i=0; i<32; i++)
            {
                dest[i] = (buffer[31-i] >> 4) + ((buffer[31-i] & 0xf) << 4);
            }
            break;
    }
}

void sub_8100874(struct UnkStruct_02038900 *unk_02038900)
{
    u16 i;
    for (i=0; i<0x40; i++)
        sub_8100740(&unk_02038900->image[i * 32], unk_02038900->tiles[i]);
}

u16 sub_810089C(u16 a0)
{
    return ((u16 *)gMapHeader.mapLayout->secondaryTileset->metatiles)[a0] & 0xfff;
}

const u8 Unknown_3EC660[] = {0, 1, 2, 3};
const u8 Unknown_3EC664[] = {0, 1, 2, 3, 4, 5, 8, 9, 10, 11, 12, 13};
const u8 Unknown_3EC670[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
const u8 Unknown_3EC680[] = {0, 1, 4, 5, 8, 9, 12, 13, 16, 17, 20, 21};
const u8 Unknown_3EC68C[] = {0, 1, 2, 3, 4, 5, 6, 7};
const u8 Unknown_3EC694[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};
const u8 Unknown_3EC6B4[] = {0, 1, 2, 3, 4, 5, 8, 9, 10, 11, 12, 13, 16, 17, 18, 19, 20, 21, 24, 25, 26, 27, 28, 29, 32, 33, 34, 35, 36, 37, 40, 41, 42, 43, 44, 45};
const u8 Unknown_3EC6D8[] = {0, 1, 2, 3, 4, 5, 8, 9, 10, 11, 12, 13, 16, 17, 18, 19, 20, 21, 24, 25, 26, 27, 28, 29};

const u8 Unknown_3EC6F0[] = {0, 0, 0, 0};
const u8 Unknown_3EC6F4[] = {0, 0, 1, 1, 0, 0, 1, 1};
const u8 Unknown_3EC6FC[] = {0, 0, 1, 1, 2, 2, 0, 0, 1, 1, 2, 2};
const u8 Unknown_3EC708[] = {0, 0, 1, 1, 2, 2, 3, 3, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 4, 4, 5, 5, 6, 6, 7, 7};
const u8 Unknown_3EC728[] = {0, 0, 1, 1, 0, 0, 1, 1, 2, 2, 3, 3, 2, 2, 3, 3};
const u8 Unknown_3EC738[] = {0, 0, 0, 0, 1, 1, 1, 1};
const u8 Unknown_3EC740[] = {0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2};
const u8 Unknown_3EC74C[] = {0, 0, 1, 1, 0, 0, 1, 1, 2, 2, 3, 3, 2, 2, 3, 3, 4, 4, 5, 5, 4, 4, 5, 5, 6, 6, 7, 7, 6, 6, 7, 7};
const u8 Unknown_3EC76C[] = {0, 0, 1, 1, 2, 2, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 6, 6, 7, 7, 8, 8};
const u8 Unknown_3EC790[] = {0, 0, 1, 1, 2, 2, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 3, 3, 4, 4, 5, 5};

const u8 Unknown_3EC7A8[] = {4, 5, 6, 7};
const u8 Unknown_3EC7AC[] = {4, 5, 4, 5, 6, 7, 6, 7};
const u8 Unknown_3EC7B4[] = {4, 5, 4, 5, 4, 5, 6, 7, 6, 7, 6, 7};
const u8 Unknown_3EC7C0[] = {4, 5, 4, 5, 4, 5, 4, 5, 6, 7, 6, 7, 6, 7, 6, 7, 4, 5, 4, 5, 4, 5, 4, 5, 6, 7, 6, 7, 6, 7, 6, 7};
const u8 Unknown_3EC7E0[] = {4, 5, 4, 5, 6, 7, 6, 7, 4, 5, 4, 5, 6, 7, 6, 7};
const u8 Unknown_3EC7F0[] = {4, 5, 6, 7, 4, 5, 6, 7};
const u8 Unknown_3EC7F8[] = {4, 5, 6, 7, 4, 5, 6, 7, 4, 5, 6, 7};
const u8 Unknown_3EC804[] = {4, 5, 4, 5, 6, 7, 6, 7, 4, 5, 4, 5, 6, 7, 6, 7, 4, 5, 4, 5, 6, 7, 6, 7, 4, 5, 4, 5, 6, 7, 6, 7};
const u8 Unknown_3EC824[] = {4, 5, 4, 5, 4, 5, 6, 7, 6, 7, 6, 7, 4, 5, 4, 5, 4, 5, 6, 7, 6, 7, 6, 7, 4, 5, 4, 5, 4, 5, 6, 7, 6, 7, 6, 7};
const u8 Unknown_3EC848[] = {4, 5, 4, 5, 4, 5, 6, 7, 6, 7, 6, 7, 4, 5, 4, 5, 4, 5, 6, 7, 6, 7, 6, 7};

const struct UnkStruct_803EC860 gUnknown_083EC860[] = {
    {Unknown_3EC660, Unknown_3EC6F0, Unknown_3EC7A8, 0x4},
    {Unknown_3EC68C, Unknown_3EC6F4, Unknown_3EC7AC, 0x8},
    {Unknown_3EC664, Unknown_3EC6FC, Unknown_3EC7B4, 0xc},
    {Unknown_3EC694, Unknown_3EC708, Unknown_3EC7C0, 0x20},
    {Unknown_3EC670, Unknown_3EC728, Unknown_3EC7E0, 0x10},
    {Unknown_3EC68C, Unknown_3EC738, Unknown_3EC7F0, 0x8},
    {Unknown_3EC680, Unknown_3EC740, Unknown_3EC7F8, 0xc},
    {Unknown_3EC694, Unknown_3EC74C, Unknown_3EC804, 0x20},
    {Unknown_3EC6B4, Unknown_3EC76C, Unknown_3EC824, 0x24},
    {Unknown_3EC6D8, Unknown_3EC790, Unknown_3EC848, 0x18}
};

const struct UnkStruct_083EC900 gUnknown_083EC900[] = {
    {0, 1, 0x78, 0x4e},
    {1, 2, 0x80, 0x4e},
    {1, 3, 0x90, 0x56},
    {1, 3, 0x90, 0x46},
    {0, 2, 0x80, 0x46},
    {2, 2, 0x78, 0x46},
    {2, 3, 0x80, 0x56},
    {2, 3, 0x80, 0x36},
    {0, 3, 0x90, 0x46},
    {1, 3, 0x90, 0x46}
};

const union AnimCmd gSpriteAnim_83EC928[] = {
    ANIMCMD_FRAME(.imageValue = 0, .duration = 0),
    ANIMCMD_END
};

const union AnimCmd *const gSpriteAnimTable_83EC930[] = {
    gSpriteAnim_83EC928
};

const struct SpriteFrameImage gSpriteImageTable_83EC934[] = {
    {.data = gUnknown_02038900.image, .size = sizeof(gUnknown_02038900.image)}
};

const struct SpriteTemplate gSpriteTemplate_83EC93C = {
    .tileTag = 0xffff,
    .paletteTag = 3000,
    .oam = &gUnknown_020391AC,
    .anims = gSpriteAnimTable_83EC930,
    .images = gSpriteImageTable_83EC934,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81009A8
};

const struct SpritePalette gUnknown_083EC954 = {.data = (u16 *)&gUnknown_02038900.palette, .tag = 3000};

const struct YesNoFuncTable gUnknown_083EC95C = {.yesFunc = sub_81000C4, .noFunc = sub_810065C};
const struct YesNoFuncTable gUnknown_083EC964 = {.yesFunc = sub_810026C, .noFunc = sub_810065C};
const struct YesNoFuncTable gUnknown_083EC96C[] = {
    {.yesFunc = sub_80FFAB0, .noFunc = sub_80FFB08},
    {.yesFunc = sub_8100F88, .noFunc = sub_8100FB4}
};

const u8 gUnknown_083EC97C[] = {4, 4, 4, 4, 0, 3, 3, 0};
const u8 gUnknown_083EC984[] = {4, 4, 4, 4, 0, 4, 3, 0};

const u16 gUnknown_083EC98C[] = INCBIN_U16("graphics/unknown/83EC98C.gbapal");
const u16 Unknown_3EC9AC[] = INCBIN_U16("graphics/unknown/83EC9AC.gbapal");
const struct YesNoFuncTable gUnknown_083EC9CC = {.yesFunc = sub_810153C, .noFunc = sub_8100EEC};
const struct YesNoFuncTable gUnknown_083EC9D4 = {.yesFunc = sub_8101590, .noFunc = sub_8100EEC};
const u32 gSpriteImage_83EC9DC[] = INCBIN_U32("graphics/unknown_sprites/83EC9DC.4bpp");
const struct SpritePalette gUnknown_083ECA5C = {.data = gUnknown_083EC98C, .tag = 8};
const struct SpritePalette gUnknown_083ECA64 = {.data = Unknown_3EC9AC, .tag = 8};
const struct OamData gOamData_83ECA6C = {
    .size = 1, .priority = 1
};

const union AnimCmd gSpriteAnim_83ECA74[] = {
    ANIMCMD_FRAME(.imageValue = 0, .duration = 0),
    ANIMCMD_END
};

const union AnimCmd *const gSpriteAnimTable_83ECA7C[] = {
    gSpriteAnim_83ECA74
};

const struct SpriteFrameImage gSpriteImageTable_83ECA80[] = {
    obj_frame_tiles(gSpriteImage_83EC9DC)
};

const struct SpriteTemplate gSpriteTemplate_83ECA88 = {
    .tileTag = 0xffff,
    .paletteTag = 8,
    .oam = &gOamData_83ECA6C,
    .anims = gSpriteAnimTable_83ECA7C,
    .images = gSpriteImageTable_83ECA80,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8101698
};

const struct YesNoFuncTable gUnknown_083ECAA0 = {.yesFunc = sub_8101848, .noFunc = sub_80FED3C};

void sub_81008BC(struct UnkStruct_02038900 *unk_02038900)
{
    u8 i;
    u8 shape;
    shape = unk_02038900->decoration->shape;
    for (i=0; i<gUnknown_083EC860[shape].size; i++)
    {
        unk_02038900->tiles[gUnknown_083EC860[shape].tiles[i]] = sub_810089C(unk_02038900->decoration->tiles[gUnknown_083EC860[shape].y[i]] * 8 + gUnknown_083EC860[shape].x[i]);
    }
}

void sub_8100930(u8 decoShape)
{
    gUnknown_020391AC.y = 0;
    gUnknown_020391AC.affineMode = 0;
    gUnknown_020391AC.objMode = 0;
    gUnknown_020391AC.mosaic = 0;
    gUnknown_020391AC.bpp = 0;
    gUnknown_020391AC.shape = gUnknown_083EC900[decoShape].shape;
    gUnknown_020391AC.x = 0;
    gUnknown_020391AC.matrixNum = 0;
    gUnknown_020391AC.size = gUnknown_083EC900[decoShape].size;
    gUnknown_020391AC.tileNum = 0;
    gUnknown_020391AC.priority = 1;
    gUnknown_020391AC.paletteNum = 0;
}

void sub_81009A8(struct Sprite *sprite)
{
    sprite->data[2] = 0;
    sprite->data[3] = 0;
    sprite->data[4] = 0;
    sprite->data[5] = 0;
    sprite->data[6] = 0;
    sprite->data[7] = 0;
    sprite->callback = sub_81009C0;
}

void sub_81009C0(struct Sprite *sprite)
{
    if (sprite->data[7] == 0)
    {
        if (sprite->data[6] < 15)
        {
            sprite->invisible = FALSE;
        } else
        {
            sprite->invisible = TRUE;
        }
        sprite->data[6] = (sprite->data[6] + 1) & 0x1f;
    } else
    {
        sprite->invisible = FALSE;
    }
}

void sub_8100A0C(u8 taskId)
{
    if (sub_8100D38(taskId) == 1)
    {
        FadeScreen(1, 0);
        gTasks[taskId].data[2] = 0;
        gTasks[taskId].func = sub_8100E70;
    } else
    {
        DisplayItemMessageOnField(taskId, gSecretBaseText_NoDecorInUse, sub_80FE428, 0);
    }
}

void sub_8100A60(u8 a0)
{
    sDecorationContext.items[a0] = 0;
    sDecorationContext.pos[a0] = 0;
}

void sub_8100A7C(void)
{
    u16 i;
    gSpecialVar_0x8005 = 0;
    gSpecialVar_Result = 0;
    if (gSpecialVar_0x8004 == gUnknown_02039234)
    {
        gSpecialVar_Result = 1;
    } else if (gDecorations[sDecorationContext.items[gUnknown_020391B4[gSpecialVar_0x8004].decorId]].permission == DECORPERM_SOLID_MAT)
    {
        gSpecialVar_0x8005 = gUnknown_020391B4[gSpecialVar_0x8004].flagId;
        sub_8100A60(gUnknown_020391B4[gSpecialVar_0x8004].decorId);
        for (i=0; i<gMapHeader.events->objectEventCount; i++)
        {
            if (gMapHeader.events->objectEvents[i].flagId == gSpecialVar_0x8005)
            {
                gSpecialVar_0x8006 = gMapHeader.events->objectEvents[i].localId;
                break;
            }
        }
    }
}

void sub_8100B20(void)
{
    u8 i;
    for (i=0; i<gMapHeader.events->objectEventCount; i++)
    {
        if (gMapHeader.events->objectEvents[i].flagId == gSpecialVar_0x8004)
        {
            gSpecialVar_0x8005 = gMapHeader.events->objectEvents[i].localId;
            break;
        }
    }
}

void sub_8100B6C(void)
{
    u8 i;
    u8 j;
    u8 k;
    u8 x;
    u8 y;
    u8 permission;
    for (i=0; i<gUnknown_02039234; i++)
    {
        permission = gDecorations[sDecorationContext.items[gUnknown_020391B4[i].decorId]].permission;
        x = sDecorationContext.pos[gUnknown_020391B4[i].decorId] >> 4;
        y = sDecorationContext.pos[gUnknown_020391B4[i].decorId] & 0xf;
        if (permission != DECORPERM_SOLID_MAT)
        {
            if (sDecorationContext.items[gUnknown_020391B4[i].decorId] == DECOR_SAND_ORNAMENT && MapGridGetMetatileIdAt(x + 7, y + 7) == 0x28c)
            {
                gUnknown_020391B4[i].height++;
            }
            for (j=0; j<gUnknown_020391B4[i].height; j++)
            {
                for (k=0; k<gUnknown_020391B4[i].width; k++)
                {
                    MapGridSetMetatileEntryAt(x + 7 + k, y + 7 - j, ((u16 *)gMapHeader.mapLayout->map)[(x + k) + gMapHeader.mapLayout->width * (y - j)] | 0x3000);
                }
            }
            sub_8100A60(gUnknown_020391B4[i].decorId);
        }
    }
}

void sub_8100C88(u8 taskId)
{
    switch (gTasks[taskId].data[2])
    {
        case 0:
            sub_8100B6C();
            gTasks[taskId].data[2] = 1;
            break;
        case 1:
            if (!gPaletteFade.active)
            {
                DrawWholeMapView();
                ScriptContext1_SetupScript(gUnknown_081A2F8A);
                Menu_EraseWindowRect(0, 0, 29, 19);
                gTasks[taskId].data[2] = 2;
            }
            break;
        case 2:
            ScriptContext2_Enable();
            sub_80FED90(taskId);
            pal_fill_black();
            gTasks[taskId].data[2] = 3;
            break;
        case 3:
            if (IsWeatherNotFadingIn() == TRUE)
            {
                gTasks[taskId].data[13] = -1;
                DisplayItemMessageOnField(taskId, gSecretBaseText_DecorReturned, sub_81010F0, 0);
            }
            break;
    }
}

bool8 sub_8100D38(u8 taskId)
{
    u16 i;
    for (i=0; i<sDecorationContext.size; i++)
    {
        if (sDecorationContext.items[i] != 0)
        {
            gTasks[taskId].data[13] = i;
            return TRUE;
        }
    }
    return FALSE;
}

void SetUpPuttingAwayDecorationPlayerAvatar(void)
{
    GetPlayerFacingDirection();
    Menu_EraseWindowRect(0, 0, 29, 19);
    gUnknown_020391A8 = gSprites[gFieldCamera.trackedSpriteId].data[0];
    sub_81016C8();
    gFieldCamera.trackedSpriteId = CreateSprite(&gSpriteTemplate_83ECA88, 0x78, 0x50, 0);
    if (gSaveBlock2.playerGender == MALE)
    {
        gUnknown_020391A9 = AddPseudoObjectEvent(0xc1, SpriteCallbackDummy, 0x88, 0x48, 0);
    } else
    {
        gUnknown_020391A9 = AddPseudoObjectEvent(0xc2, SpriteCallbackDummy, 0x88, 0x48, 0);
    }
    gSprites[gUnknown_020391A9].oam.priority = 1;
    DestroySprite(&gSprites[gUnknown_020391A8]);
    gUnknown_020391A8 = gFieldCamera.trackedSpriteId;
    gSprites[gUnknown_020391A8].oam.priority = 1;
}

void sub_8100E70(u8 taskId)
{
    s16 *data;
    data = gTasks[taskId].data;
    switch (data[2])
    {
        case 0:
            if (!gPaletteFade.active)
            {
                sub_80FF0E0(taskId);
                data[2] = 1;
                data[6] = 1;
                data[5] = 1;
                Menu_DestroyCursor();
            }
            break;
        case 1:
            SetUpPuttingAwayDecorationPlayerAvatar();
            pal_fill_black();
            data[2] = 2;
            break;
        case 2:
            if (IsWeatherNotFadingIn() == TRUE)
            {
                data[12] = 1;
                sub_8100EEC(taskId);
            }
            break;
    }
}

void sub_8100EEC(u8 taskId)
{
    Menu_EraseWindowRect(0, 0, 29, 19);
    gSprites[gUnknown_020391A8].data[7] = 0;
    gSprites[gUnknown_020391A8].invisible = FALSE;
    gSprites[gUnknown_020391A8].callback = sub_8101698;
    gSprites[gUnknown_020391A9].x = 0x88;
    gSprites[gUnknown_020391A9].y = 0x48;
    gTasks[taskId].data[10] = 0;
    gTasks[taskId].func = sub_8100494;
}

void sub_8100F88(u8 taskId)
{
    gTasks[taskId].data[10] = 0;
    sub_810045C();
    sub_8101024(taskId);
}

void sub_8100FB4(u8 taskId)
{
    gTasks[taskId].data[10] = 0;
    sub_810045C();
    gSprites[gUnknown_020391A8].invisible = FALSE;
    gSprites[gUnknown_020391A8].callback = SpriteCallbackDummy;
    DisplayItemMessageOnField(taskId, gSecretBaseText_StopPuttingAwayDecor, sub_810156C, 0);
}

void sub_8101024(u8 taskId)
{
    u8 metatileBehavior;
    s16 *data;
    sub_8101460(taskId);
    if (gUnknown_02039234 != 0)
    {
        DisplayItemMessageOnField(taskId, gSecretBaseText_ReturnDecor, sub_8101518, 0);
    } else
    {
        data = gTasks[taskId].data;
        metatileBehavior = MapGridGetMetatileBehaviorAt(data[0], data[1]);
        if (MetatileBehavior_IsSecretBasePC(metatileBehavior) == TRUE
         || MetatileBehavior_IsPlayerRoomPCOn(metatileBehavior) == TRUE)
        {
            gSprites[gUnknown_020391A8].invisible = FALSE;
            gSprites[gUnknown_020391A8].callback = SpriteCallbackDummy;
            DisplayItemMessageOnField(taskId, gSecretBaseText_StopPuttingAwayDecor, sub_810156C, 0);
        } else
        {
            DisplayItemMessageOnField(taskId, gSecretBaseText_NoDecor, sub_81010F0, 0);
        }
    }
}

void sub_81010F0(u8 taskId)
{
    if ((gMain.newKeys & A_BUTTON) || (gMain.newKeys & B_BUTTON))
    {
        sub_8100EEC(taskId);
    }
}

void sub_8101118(u8 decorIdx, struct UnkStruct_020391B4 *unk_020391B4)
{
    if (gDecorations[decorIdx].shape == DECORSHAPE_1x1)
    {
        unk_020391B4->width = 1;
        unk_020391B4->height = 1;
    } else if (gDecorations[decorIdx].shape == DECORSHAPE_2x1)
    {
        unk_020391B4->width = 2;
        unk_020391B4->height = 1;
    } else if (gDecorations[decorIdx].shape == DECORSHAPE_3x1)
    {
        unk_020391B4->width = 3;
        unk_020391B4->height = 1;
    } else if (gDecorations[decorIdx].shape == DECORSHAPE_4x2)
    {
        unk_020391B4->width = 4;
        unk_020391B4->height = 2;
    } else if (gDecorations[decorIdx].shape == DECORSHAPE_2x2)
    {
        unk_020391B4->width = 2;
        unk_020391B4->height = 2;
    } else if (gDecorations[decorIdx].shape == DECORSHAPE_1x2)
    {
        unk_020391B4->width = 1;
        unk_020391B4->height = 2;
    } else if (gDecorations[decorIdx].shape == DECORSHAPE_1x3)
    {
        unk_020391B4->width = 1;
        unk_020391B4->height = 3;
    } else if (gDecorations[decorIdx].shape == DECORSHAPE_2x4)
    {
        unk_020391B4->width = 2;
        unk_020391B4->height = 4;
    } else if (gDecorations[decorIdx].shape == DECORSHAPE_3x3)
    {
        unk_020391B4->width = 3;
        unk_020391B4->height = 3;
    } else if (gDecorations[decorIdx].shape == DECORSHAPE_3x2)
    {
        unk_020391B4->width = 3;
        unk_020391B4->height = 2;
    }
}

void sub_8101198(u8 x, u8 y)
{
    gSprites[gUnknown_020391A8].invisible = TRUE;
    gSprites[gUnknown_020391A8].callback = SpriteCallbackDummy;
    gSprites[gUnknown_020391A9].x = 0x88 + x * 16;
    gSprites[gUnknown_020391A9].y = 0x48 + y * 16;
}

bool8 sub_8101200(u8 taskId, u8 decorIdx, struct UnkStruct_020391B4 *unk_020391B4)
{
    u8 x;
    u8 y;
    u8 xOff;
    u8 yOff;
    x = gTasks[taskId].data[0] - 7;
    y = gTasks[taskId].data[1] - 7;
    xOff = sDecorationContext.pos[decorIdx] >> 4;
    yOff = sDecorationContext.pos[decorIdx] & 0xf;
    if (sDecorationContext.items[decorIdx] == DECOR_SAND_ORNAMENT && MapGridGetMetatileIdAt(xOff + 7, yOff + 7) == 0x28c)
    {
        unk_020391B4->height--;
    }
    if (x >= xOff && x < xOff + unk_020391B4->width && y > yOff - unk_020391B4->height && y <= yOff)
    {
        sub_8101198(unk_020391B4->width - (x - xOff + 1), yOff - y);
        return TRUE;
    }
    return FALSE;
}

void sub_81012A0(void)
{
    u8 xOff;
    u8 yOff;
    u16 i;
    xOff = sDecorationContext.pos[gUnknown_020391B4[gUnknown_02039234].decorId] >> 4;
    yOff = sDecorationContext.pos[gUnknown_020391B4[gUnknown_02039234].decorId] & 0xf;
    for (i=0; i<0x40; i++)
    {
        if (gSaveBlock1.objectEventTemplates[i].x == xOff && gSaveBlock1.objectEventTemplates[i].y == yOff && !FlagGet(gSaveBlock1.objectEventTemplates[i].flagId))
        {
            gUnknown_020391B4[gUnknown_02039234].flagId = gSaveBlock1.objectEventTemplates[i].flagId;
            break;
        }
    }
}

bool8 sub_8101340(u8 taskId)
{
    u16 i;
    for (i=0; i<sDecorationContext.size; i++)
    {
        if (sDecorationContext.items[i] != 0)
        {
            if (gDecorations[sDecorationContext.items[i]].permission == DECORPERM_SOLID_MAT)
            {
                sub_8101118(sDecorationContext.items[i], gUnknown_020391B4);
                if (sub_8101200(taskId, i, gUnknown_020391B4) == TRUE)
                {
                    gUnknown_020391B4->decorId = i;
                    sub_81012A0();
                    gUnknown_02039234 = 1;
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

void sub_81013B8(u8 a0, u8 a1, u8 a2, u8 a3)
{
    u8 i;
    u8 xOff;
    u8 yOff;
    u8 decorIdx;
    for (i=0; i<sDecorationContext.size; i++)
    {
        decorIdx = sDecorationContext.items[i];
        xOff = sDecorationContext.pos[i] >> 4;
        yOff = sDecorationContext.pos[i] & 0xf;
        if (decorIdx != 0 && gDecorations[decorIdx].permission == DECORPERM_SOLID_MAT && a0 <= xOff && a1 <= yOff && a2 >= xOff && a3 >= yOff)
        {
            gUnknown_020391B4[gUnknown_02039234].decorId = i;
            sub_81012A0();
            gUnknown_02039234++;
        }
    }
}

void sub_8101460(u8 taskId)
{
    u8 i;
    u8 xOff;
    u8 yOff;
    u8 var1;
    u32 var2;

    gUnknown_02039234 = 0;
    if (sub_8101340(taskId) != TRUE)
    {
        for (i = 0; i < sDecorationContext.size; i++)
        {
            var1 = sDecorationContext.items[i];
            if (var1 != 0)
            {
                sub_8101118(var1, gUnknown_020391B4);
                if (sub_8101200(taskId, i, gUnknown_020391B4) == TRUE)
                {
                    gUnknown_020391B4[0].decorId = i;
                    gUnknown_02039234++;
                    break;
                }
            }
        }
        if (gUnknown_02039234 != 0)
        {
            xOff = sDecorationContext.pos[gUnknown_020391B4[0].decorId] >> 4;
            yOff = sDecorationContext.pos[gUnknown_020391B4[0].decorId] & 0xf;
            var1 = yOff - gUnknown_020391B4[0].height + 1;
            var2 = gUnknown_020391B4[0].width + xOff - 1;

            sub_81013B8(xOff, var1, var2, yOff);
        }
    }
}

void sub_8101518(u8 taskId)
{
    DisplayYesNoMenu(20, 8, 1);
    DoYesNoFuncWithChoice(taskId, &gUnknown_083EC9CC);
}

void sub_810153C(u8 taskId)
{
    FadeScreen(1, 0);
    gTasks[taskId].data[2] = 0;
    gTasks[taskId].func = sub_8100C88;
}

void sub_810156C(u8 taskId)
{
    DisplayYesNoMenu(20, 8, 1);
    DoYesNoFuncWithChoice(taskId, &gUnknown_083EC9D4);
}

void sub_8101590(u8 taskId)
{
    Menu_EraseWindowRect(0, 0, 29, 19);
    sub_81015B0(taskId);
}

void sub_81015B0(u8 taskId)
{
    FadeScreen(1, 0);
    gTasks[taskId].data[2] = 0;
    gTasks[taskId].func = sub_81015E0;
}

void sub_81015E0(u8 taskId)
{
    switch (gTasks[taskId].data[2])
    {
        case 0:
            if (!gPaletteFade.active)
            {
                sub_80FF114(taskId);
                gTasks[taskId].data[2] = 1;
            }
            break;
        case 1:
            sub_81016F4();
            gFieldCallback = sub_8101678;
            SetMainCallback2(CB2_ReturnToField);
            DestroyTask(taskId);
            break;
    }
}

void sub_8101648(u8 taskId)
{
    if (IsWeatherNotFadingIn() == TRUE)
    {
        gTasks[taskId].func = Task_DecorationPCProcessMenuInput;
    }
}

void sub_8101678(void)
{
    pal_fill_black();
    Menu_DisplayDialogueFrame();
    sub_80FE220();
    CreateTask(sub_8101648, 8);
}

void sub_8101698(struct Sprite *sprite)
{
    sprite->data[0] = (sprite->data[0] + 1) & 0x1f;
    if (sprite->data[0] >= 16)
    {
        sprite->invisible = TRUE;
    } else
    {
        sprite->invisible = FALSE;
    }
}

void sub_81016C8(void)
{
    if (gSaveBlock2.playerGender == MALE)
    {
        LoadSpritePalette(&gUnknown_083ECA5C);
    } else
    {
        LoadSpritePalette(&gUnknown_083ECA64);
    }
}

void sub_81016F4(void)
{
    FreeSpritePaletteByTag(8);
}

void sub_8101700(u8 taskId)
{
    if (!GetNumDecorationsInInventory())
    {
        DisplayItemMessageOnField(taskId, gSecretBaseText_NoDecors, sub_80FE428, 0);
    } else
    {
        gTasks[taskId].data[11] = 1;
        gUnknown_020388F6 = 0;
        sub_80FE5AC(taskId);
    }
}

void sub_8101750(u8 taskId)
{
    if (!GetNumDecorationsInInventory())
    {
        DisplayItemMessageOnField(taskId, gSecretBaseText_NoDecors, sub_80FE428, 0);
    } else
    {
        gTasks[taskId].data[11] = 2;
        gUnknown_020388F6 = 0;
        sub_80FE5AC(taskId);
    }
}

void sub_81017A0(u8 taskId)
{
    sub_80FEF74();
    sub_80FED1C();
    if (sub_80FEFA4() == TRUE)
    {
        StringCopy(gStringVar1, gDecorations[gUnknown_020388D0[gUnknown_020388F5]].name);
        StringExpandPlaceholders(gStringVar4, gSecretBaseText_WillBeDiscarded);
        DisplayItemMessageOnField(taskId, gStringVar4, sub_8101824, 0);
    } else
    {
        DisplayItemMessageOnField(taskId, gSecretBaseText_DecorInUse, sub_80FEFF4, 0);
    }
}

void sub_8101824(u8 taskId)
{
    DisplayYesNoMenu(20, 8, 1);
    DoYesNoFuncWithChoice(taskId, &gUnknown_083ECAA0);
}

void sub_8101848(u8 taskId)
{
    Menu_EraseWindowRect(20, 8, 26, 14);
    sub_8109A30(gUnknown_020388D0[gUnknown_020388F5]);
    gUnknown_020388D0[gUnknown_020388F5] = DECOR_NONE;
    sub_80FF098(taskId);
    DisplayItemMessageOnField(taskId, gSecretBaseText_DecorThrownAway, sub_80FEFF4, 0);
}
