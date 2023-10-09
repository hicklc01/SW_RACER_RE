#ifndef SWRSPRITE_H
#define SWRSPRITE_H

#include "types.h"

#define swrSprite_SetPos_ADDR (0x00428660)

#define swrSprite_SetDim_ADDR (0x004286f0)

#define swrSprite_SetColor_ADDR (0x00428740)

#define swrSprite_SetFlag_ADDR (0x004287e0)

#define swrSprite_UpperPowerOfTwo_ADDR (0x00445c90)
#define swrSprite_LoadTexture_ADDR (0x00446ca0)
#define swrSprite_LoadTexture__ADDR (0x00446fb0)

void swrSprite_SetPos(short id, short x, short y);

void swrSprite_SetDim(short id, float width, float height);

void swrSprite_SetColor(short id, uint8_t r, uint8_t g, uint8_t b, uint8_t a);

void swrSprite_SetFlag(short id, unsigned int flag);

int swrSprite_UpperPowerOfTwo(int x);

swrSpriteTexture* swrSprite_LoadTexture(int index);
swrSpriteTexture* swrSprite_LoadTexture_(int index);

#endif // SWRSPRITE_H
