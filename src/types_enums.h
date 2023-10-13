#ifndef TYPES_ENUMS_H
#define TYPES_ENUMS_H

typedef enum rdCameraProjectType
{
    rdCameraProjectType_Ortho = 0,
    rdCameraProjectType_Perspective = 1,
    rdCameraProjectType_PerspMVP = 2
} rdCameraProjectType;

typedef enum swrLoader_TYPE
{
    swrLoader_TYPE_MODEL_BLOCK = 0,
    swrLoader_TYPE_SPRITE_BLOCK = 1,
    swrLoader_TYPE_SPLINE_BLOCK = 2,
    swrLoader_TYPE_TEXTURE_BLOCK = 3
} swrLoader_TYPE;

typedef enum swrRace_STATE
{
    swrRace_STATE_LEGAL = 0,
    swrRace_STATE_SPLASH = 1,
    swrRace_STATE_ENTER_NAME = 2,
    swrRace_STATE_MAIN_MENU = 3,
    swrRace_STATE_JUNKYARD = 4,
    swrRace_STATE_POST_RACE_INFO = 5,
    swrRace_STATE_UNKNOWN = 6,
    swrRace_STATE_WATTO = 7,
    swrRace_STATE_LOOK_AT_VEHICLE = 8,
    swrRace_STATE_SELECT_VEHICLE = 9,
    swrRace_STATE_SELECT_PLANET = 12,
    swrRace_STATE_SELECT_TRACK = 13,
} swrRace_STATE; // from FUN_00454d40

typedef enum swrRace_TRACK
{
    swrRace_TRACK_BOONTA_TRAINING_COURSE = 0,
    swrRace_TRACK_BOONTA_CLASSIC = 1,
    swrRace_TRACK_BEEDOS_WILD_RIDE = 2,
    swrRace_TRACK_HOWLER_GORGE = 3,
    swrRace_TRACK_ANDOBI_MOUNTAIN_RUN = 4,
    swrRace_TRACK_ANDOBI_PRIME_CENTRUM = 5,
    swrRace_TRACK_AQUILARIS_CLASSIC = 6,
    swrRace_TRACK_SUNKEN_CITY = 7,
    swrRace_TRACK_BUMBYS_BREAKERS = 8,
    swrRace_TRACK_SCRAPPERS_RUN = 9,
    swrRace_TRACK_DETHROS_REVENGE = 10,
    swrRace_TRACK_ABYSS = 11,
    swrRace_TRACK_BAROO_COAST = 12,
    swrRace_TRACK_GRABVINE_GATEWAY = 13,
    swrRace_TRACK_FIRE_MOUNTAIN_RALLY = 14,
    swrRace_TRACK_INFERNO = 15,
    swrRace_TRACK_MON_GAZZA_SPEEDWAY = 16,
    swrRace_TRACK_SPICE_MINE_RUN = 17,
    swrRace_TRACK_ZUGGA_CHALLENGE = 18,
    swrRace_TRACK_VENGEANCE = 19,
    swrRace_TRACK_EXECUTIONER = 20,
    swrRace_TRACK_THE_GAUNTLET = 21,
    swrRace_TRACK_MALASTARE_100 = 22,
    swrRace_TRACK_DUG_DERBY = 23,
    swrRace_TRACK_SEBULBAS_LEGACY = 24
} swrRace_TRACK;

typedef enum swrSprite_NAME
{
    swrSprite_NAME_ALDARBEEDO = 0,
    swrSprite_NAME_BENQUADRINAROS = 1,
    swrSprite_NAME_2 = 2,
    swrSprite_NAME_3 = 3,
    swrSprite_NAME_BULSEYENAVIOR = 4,
    swrSprite_NAME_5 = 5,
    swrSprite_NAME_6 = 6,
    swrSprite_NAME_7 = 7,
    swrSprite_NAME_8 = 8,
    swrSprite_NAME_9 = 9,
    swrSprite_NAME_10 = 10,
    swrSprite_NAME_MARSGUO = 11,
    swrSprite_NAME_12 = 12,
    swrSprite_NAME_13 = 13,
    swrSprite_NAME_14 = 14,
    swrSprite_NAME_RATTSTYREL = 15,
    swrSprite_NAME_16 = 16,
    swrSprite_NAME_17 = 17,
    swrSprite_NAME_18 = 18,
    swrSprite_NAME_STARTINGGRIDONE = 19,
    swrSprite_NAME_STARTINGGRIDTWO = 20,
    swrSprite_NAME_STARTINGGRIDTHREE = 21,
    swrSprite_NAME_N64CONTROLLER = 22,
    swrSprite_NAME_CURSOR = 23,
    swrSprite_NAME_NOISE = 24,
    swrSprite_NAME_25 = 25,
    swrSprite_NAME_26 = 26,
    swrSprite_NAME_SPLASHSCREEN = 27,
    swrSprite_NAME_28 = 28,
    swrSprite_NAME_29 = 29,
    swrSprite_NAME_30 = 30,
    swrSprite_NAME_31 = 31,
    swrSprite_NAME_32 = 32,
    swrSprite_NAME_33 = 33,
    swrSprite_NAME_34 = 34,
    swrSprite_NAME_35 = 35,
    swrSprite_NAME_ANAKINSKYWALKER = 36,
    swrSprite_NAME_GASGANO = 37,
    swrSprite_NAME_SEBULBA = 38,
    swrSprite_NAME_39 = 39,
    swrSprite_NAME_40 = 40,
    swrSprite_NAME_41 = 41,
    swrSprite_NAME_42 = 42,
    swrSprite_NAME_43 = 43,
    swrSprite_NAME_RACERFLAG_44 = 44,
    swrSprite_NAME_RACERFLAG_45 = 45,
    swrSprite_NAME_RACERFLAG_46 = 46,
    swrSprite_NAME_RACERFLAG_47 = 47,
    swrSprite_NAME_RACERFLAG_48 = 48,
    swrSprite_NAME_RACERFLAG_49 = 49,
    swrSprite_NAME_RACERFLAG_50 = 50,
    swrSprite_NAME_RACERFLAG_51 = 51,
    swrSprite_NAME_RACERFLAG_52 = 52,
    swrSprite_NAME_RACERFLAG_53 = 53,
    swrSprite_NAME_RACERFLAG_54 = 54,
    swrSprite_NAME_RACERFLAG_55 = 55,
    swrSprite_NAME_RACERFLAG_56 = 56,
    swrSprite_NAME_RACERFLAG_57 = 57,
    swrSprite_NAME_RACERFLAG_58 = 58,
    swrSprite_NAME_RACERFLAG_59 = 59,
    swrSprite_NAME_RACERFLAG_60 = 60,
    swrSprite_NAME_RACERFLAG_61 = 61,
    swrSprite_NAME_RACERFLAG_62 = 62,
    swrSprite_NAME_RACERFLAG_63 = 63,
    swrSprite_NAME_RACERFLAG_64 = 64,
    swrSprite_NAME_RACERFLAG_65 = 65,
    swrSprite_NAME_RACERFLAG_66 = 66,
    swrSprite_NAME_RACERFLAG_67 = 67,
    swrSprite_NAME_RACERFLAG_68 = 68,
    swrSprite_NAME_RACERFLAG_69 = 69,
    swrSprite_NAME_RACERFLAG_70 = 70,
    swrSprite_NAME_RACERFLAG_71 = 71,
    swrSprite_NAME_72 = 72,
    swrSprite_NAME_73 = 73,
    swrSprite_NAME_74 = 74,
    swrSprite_NAME_75 = 75,
    swrSprite_NAME_76 = 76,
    swrSprite_NAME_77 = 77,
    swrSprite_NAME_78 = 78,
    swrSprite_NAME_79 = 79,
    swrSprite_NAME_80 = 80,
    swrSprite_NAME_81 = 81,
    swrSprite_NAME_82 = 82,
    swrSprite_NAME_83 = 83,
    swrSprite_NAME_84 = 84,
    swrSprite_NAME_85 = 85,
    swrSprite_NAME_86 = 86,
    swrSprite_NAME_N64 = 87,
    swrSprite_NAME_88 = 88,
    swrSprite_NAME_89 = 89,
    swrSprite_NAME_90 = 90,
    swrSprite_NAME_91 = 91,
    swrSprite_NAME_FLAGFIRSTPLACE = 92,
    swrSprite_NAME_FLAGSECONDPLACE = 93,
    swrSprite_NAME_FLAGTHIRDPLACE = 94,
    swrSprite_NAME_95 = 95,
    swrSprite_NAME_96 = 96,
    swrSprite_NAME_97 = 97,
    swrSprite_NAME_98 = 98,
    swrSprite_NAME_SPEEDOMETERRAMP = 99,
    swrSprite_NAME_100 = 100,
    swrSprite_NAME_101 = 101,
    swrSprite_NAME_102 = 102,
    swrSprite_NAME_103 = 103,
    swrSprite_NAME_SPEEDOMETER = 104,
    swrSprite_NAME_105 = 105,
    swrSprite_NAME_106 = 106,
    swrSprite_NAME_107 = 107,
    swrSprite_NAME_108 = 108,
    swrSprite_NAME_109 = 109,
    swrSprite_NAME_110 = 110,
    swrSprite_NAME_111 = 111,
    swrSprite_NAME_112 = 112,
    swrSprite_NAME_113 = 113,
    swrSprite_NAME_114 = 114,
    swrSprite_NAME_115 = 115,
    swrSprite_NAME_116 = 116,
    swrSprite_NAME_117 = 117,
    swrSprite_NAME_118 = 118,
    swrSprite_NAME_119 = 119,
    swrSprite_NAME_120 = 120,
    swrSprite_NAME_121 = 121,
    swrSprite_NAME_122 = 122,
    swrSprite_NAME_123 = 123,
    swrSprite_NAME_124 = 124,
    swrSprite_NAME_125 = 125,
    swrSprite_NAME_126 = 126,
    swrSprite_NAME_127 = 127,
    swrSprite_NAME_128 = 128,
    swrSprite_NAME_129 = 129,
    swrSprite_NAME_RACEARTWORK_130 = 130,
    swrSprite_NAME_RACEARTWORK_131 = 131,
    swrSprite_NAME_RACEARTWORK_132 = 132,
    swrSprite_NAME_RACEARTWORK_133 = 133,
    swrSprite_NAME_RACEARTWORK_134 = 134,
    swrSprite_NAME_RACEARTWORK_135 = 135,
    swrSprite_NAME_RACEARTWORK_136 = 136,
    swrSprite_NAME_RACEARTWORK_137 = 137,
    swrSprite_NAME_138 = 138,
    swrSprite_NAME_139 = 139,
    swrSprite_NAME_140 = 140,
    swrSprite_NAME_141 = 141,
    swrSprite_NAME_142 = 142,
    swrSprite_NAME_143 = 143,
    swrSprite_NAME_144 = 144,
    swrSprite_NAME_145 = 145,
    swrSprite_NAME_146 = 146,
    swrSprite_NAME_147 = 147,
    swrSprite_NAME_148 = 148,
    swrSprite_NAME_149 = 149,
    swrSprite_NAME_150 = 150,
    swrSprite_NAME_151 = 151,
    swrSprite_NAME_152 = 152,
    swrSprite_NAME_153 = 153,
    swrSprite_NAME_154 = 154,
    swrSprite_NAME_155 = 155,
    swrSprite_NAME_156 = 156,
    swrSprite_NAME_157 = 157,
    swrSprite_NAME_158 = 158,
    swrSprite_NAME_159 = 159,
    swrSprite_NAME_SPLASHSCREENWIDE = 160,
    swrSprite_NAME_EPISODE1 = 161,
    swrSprite_NAME_RACER = 162,
    swrSprite_NAME_STARWARS = 163,
    swrSprite_NAME_STAR = 164,
    swrSprite_NAME_WARS = 165,
    swrSprite_NAME_SPEEDOMETERRAMPBORDER = 166,
    swrSprite_NAME_LUCASARTS = 167,
    swrSprite_NAME_LUCASARTSGLOW = 168,
    swrSprite_NAME_169 = 169,
    swrSprite_NAME_THETEAM = 170,
    swrSprite_NAME_171 = 171,
    swrSprite_NAME_172 = 172,
    swrSprite_NAME_173 = 173,
    swrSprite_NAME_174 = 174,
    swrSprite_NAME_175 = 175,
    swrSprite_NAME_EXPANSIONPACK = 176,
    swrSprite_NAME_177 = 177
} swrSprite_NAME;

#endif // TYPES_ENUMS_H
