#include <nds.h>
#include <maxmod9.h>
#include <stdio.h>

#include "soundbank.h"
#include "soundbank_bin.h"

#include "MainBg.h"
#include "leftButtonOff.h"
#include "leftButtonOn.h"
#include "rightButtonOff.h"
#include "rightButtonOn.h"
#include "gong.h"
#include "duck.h"
#include "butthead.h"
#include "bluesbrothers.h"
#include "bttf.h"
#include "chewbacca.h"
#include "dsotm.h"
#include "eastwood.h"
#include "mario.h"

int SPRITECOUNT = 0;

typedef struct  
{
   int id;
   u16* gfx;
   SpriteSize size;
   SpriteColorFormat format;
   int rotationIndex;
   int paletteAlpha;
   int x;
   int y;
   mm_sound_effect sfx;
   char* desc;
} mySprite;

void initVideo() {
	// initialize VRAM banks
	vramSetBankA(VRAM_A_MAIN_BG_0x06000000);
	vramSetBankB(VRAM_B_MAIN_SPRITE_0x06400000);
	vramSetBankC(VRAM_C_SUB_BG_0x06200000);
	vramSetBankD(VRAM_D_SUB_SPRITE);
	vramSetBankE(VRAM_E_LCD);
	vramSetBankF(VRAM_F_LCD);
	vramSetBankG(VRAM_G_LCD);
	vramSetBankH(VRAM_H_LCD);
	vramSetBankI(VRAM_I_LCD);
	
	// set video modes
	videoSetMode(MODE_5_2D);
	videoSetModeSub(MODE_5_2D);
}

void initBackgrounds() {
	// bgInit(int layer, BgType type, BgSize size, int mapBase, int tileBase)	
	int bg2 = bgInit(2, BgType_Bmp16, BgSize_B16_256x256, 0,0);
	int bg2sub = bgInitSub(2, BgType_Bmp16, BgSize_B16_256x256, 2,0);
	decompress(MainBgBitmap, bgGetGfxPtr(bg2),  LZ77Vram);	
	decompress(MainBgBitmap, bgGetGfxPtr(bg2sub),  LZ77Vram);	
}

void initConsole(PrintConsole * console) {
	// consoleInit (PrintConsole * console, int layer, BgType type,
	// BgSize size, int mapBase, int tileBase, bool mainDisplay, bool loadGraphics)	
	consoleInit(console, 0, BgType_Text4bpp, BgSize_T_256x256, 2, 0, false, true);
	consoleSelect(console);
	printf("\x1b[30m");
}

void initSprites(mySprite * sprites) {
	int defaultX = (SCREEN_WIDTH/2) - 32;
	int defaultY = (SCREEN_HEIGHT/2) - 32;
	mmInitDefaultMem((mm_addr)soundbank_bin);
	
	oamInit(&oamMain, SpriteMapping_1D_64, false);
	mySprite leftButtonOff = {0, 0, SpriteSize_64x64, SpriteColorFormat_16Color, 0, 0, 0, defaultY};
	mySprite leftButtonOn = {1, 0, SpriteSize_64x64, SpriteColorFormat_16Color, 0, 1, 0, defaultY};
	mySprite rightButtonOff = {2, 0, SpriteSize_64x64, SpriteColorFormat_16Color, 0, 0, (256-64), defaultY};
	mySprite rightButtonOn = {3, 0, SpriteSize_64x64, SpriteColorFormat_16Color, 0, 1, (256-64), defaultY};
	leftButtonOff.gfx = oamAllocateGfx(&oamMain, SpriteSize_64x64, SpriteColorFormat_16Color);
	leftButtonOn.gfx = oamAllocateGfx(&oamMain, SpriteSize_64x64, SpriteColorFormat_16Color);
	rightButtonOff.gfx = oamAllocateGfx(&oamMain, SpriteSize_64x64, SpriteColorFormat_16Color);
	rightButtonOn.gfx = oamAllocateGfx(&oamMain, SpriteSize_64x64, SpriteColorFormat_16Color);
	dmaCopy(leftButtonOffPal, &SPRITE_PALETTE[leftButtonOff.id * 16], leftButtonOffPalLen);
	dmaCopy(leftButtonOnPal, &SPRITE_PALETTE[leftButtonOn.id * 16], leftButtonOnPalLen);
	dmaCopy((u8*)leftButtonOffTiles, leftButtonOff.gfx, 2048);
	dmaCopy((u8*)leftButtonOnTiles, leftButtonOn.gfx, 2048);
	dmaCopy((u8*)rightButtonOffTiles, rightButtonOff.gfx, 2048);
	dmaCopy((u8*)rightButtonOnTiles, rightButtonOn.gfx, 2048);
	sprites[leftButtonOff.id] = leftButtonOff;
	sprites[leftButtonOn.id] = leftButtonOn;
	sprites[rightButtonOff.id] = rightButtonOff;
	sprites[rightButtonOn.id] = rightButtonOn;
	SPRITECOUNT += 4;
	
	// mySprite {id, gfxPtr, SpriteSize, SpriteColorFormat, rotationIndex, paletteAlpha, x, y}
	//
	// gong
	mmLoadEffect(SFX_GONG);
	mm_sound_effect gongSFX = { {SFX_GONG}, (int)(1.0f * (1<<10)), 0, 255, 128, };
	char gongDesc[] = "An ancient gong from the hills of China.";
	mySprite gong = {4, 0, SpriteSize_64x64, SpriteColorFormat_16Color, 0, 4, defaultX, defaultY, gongSFX, gongDesc};
	gong.gfx = oamAllocateGfx(&oamMain, SpriteSize_64x64, SpriteColorFormat_16Color);
	dmaCopy(gongPal, &SPRITE_PALETTE[gong.id * 16], gongPalLen);
	dmaCopy((u8*)gongTiles, gong.gfx, 2048);
	sprites[gong.id] = gong;
	SPRITECOUNT++;
	
	// duck
	mmLoadEffect(SFX_DUCK);
	mm_sound_effect duckSFX = { { SFX_DUCK }, (int)(1.0f * (1<<10)), 0, 255, 128, };
	char duckDesc[] = "A mild-mannered duck.";
	mySprite duck = {5, 0, SpriteSize_64x64, SpriteColorFormat_16Color, 0, 5, defaultX, defaultY, duckSFX, duckDesc};
	duck.gfx = oamAllocateGfx(&oamMain, SpriteSize_64x64, SpriteColorFormat_16Color); 
	dmaCopy(duckPal, &SPRITE_PALETTE[duck.id * 16], buttheadPalLen);
	dmaCopy((u8*)duckTiles, duck.gfx, 2048);
	sprites[duck.id] = duck;
	SPRITECOUNT++;	// should be 6 now
	
	// butthead
	mmLoadEffect(SFX_BUTTHEAD);
	mm_sound_effect buttheadSFX = { { SFX_BUTTHEAD }, (int)(1.0f * (1<<10)), 0, 255, 128, };
	char buttheadDesc[] = "Butt-head.";
	mySprite butthead = {6, 0, SpriteSize_64x64, SpriteColorFormat_16Color, 0, 6, defaultX, defaultY, buttheadSFX, buttheadDesc};
	butthead.gfx = oamAllocateGfx(&oamMain, SpriteSize_64x64, SpriteColorFormat_16Color); 
	dmaCopy(buttheadPal, &SPRITE_PALETTE[butthead.id * 16], buttheadPalLen);
	dmaCopy((u8*)buttheadTiles, butthead.gfx, 2048);
	sprites[butthead.id] = butthead;
	SPRITECOUNT++;
	
	//bluesbrothers
	mmLoadEffect(SFX_BLUESBROTHERS);
	mm_sound_effect bluesbrothersSFX = { { SFX_BLUESBROTHERS }, (int)(1.0f * (1<<10)), 0, 255, 128, };
	char bluesbrothersDesc[] = "Jake and Elwood.";
	mySprite bluesbrothers = {7, 0, SpriteSize_64x64, SpriteColorFormat_16Color, 0, 7, defaultX, defaultY, bluesbrothersSFX, bluesbrothersDesc};
	bluesbrothers.gfx = oamAllocateGfx(&oamMain, SpriteSize_64x64, SpriteColorFormat_16Color);
	dmaCopy(bluesbrothersPal, &SPRITE_PALETTE[bluesbrothers.id * 16], bluesbrothersPalLen);
	dmaCopy((u8*)bluesbrothersTiles, bluesbrothers.gfx, 2048);
	sprites[bluesbrothers.id] = bluesbrothers;
	SPRITECOUNT++;

	//bttf
	mmLoadEffect(SFX_BTTF);
	mm_sound_effect bttfSFX = { { SFX_BTTF }, (int)(1.0f * (1<<10)), 0, 255, 128, };
	char bttfDesc[] = "88 mph.";
	mySprite bttf = {8, 0, SpriteSize_64x64, SpriteColorFormat_16Color, 0, 8, defaultX, defaultY, bttfSFX, bttfDesc};
	bttf.gfx = oamAllocateGfx(&oamMain, SpriteSize_64x64, SpriteColorFormat_16Color);
	dmaCopy(bttfPal, &SPRITE_PALETTE[bttf.id * 16], bttfPalLen);
	dmaCopy((u8*)bttfTiles, bttf.gfx, 2048);
	sprites[bttf.id] = bttf;
	SPRITECOUNT++;

	//chewbacca
	mmLoadEffect(SFX_CHEWBACCA);
	mm_sound_effect chewbaccaSFX = { { SFX_CHEWBACCA }, (int)(1.0f * (1<<10)), 0, 255, 128, };
	char chewbaccaDesc[] = "Chewie.";
	mySprite chewbacca = {9, 0, SpriteSize_64x64, SpriteColorFormat_16Color, 0, 9, defaultX, defaultY, chewbaccaSFX, chewbaccaDesc};
	chewbacca.gfx = oamAllocateGfx(&oamMain, SpriteSize_64x64, SpriteColorFormat_16Color);
	dmaCopy(chewbaccaPal, &SPRITE_PALETTE[chewbacca.id * 16], chewbaccaPalLen);
	dmaCopy((u8*)chewbaccaTiles, chewbacca.gfx, 2048);
	sprites[chewbacca.id] = chewbacca;
	SPRITECOUNT++;

	//dsotm
	mmLoadEffect(SFX_DSOTM);
	mm_sound_effect dsotmSFX = { { SFX_DSOTM }, (int)(1.0f * (1<<10)), 0, 255, 128, };
	char dsotmDesc[] = "1973.";
	mySprite dsotm = {10, 0, SpriteSize_64x64, SpriteColorFormat_16Color, 0, 10, defaultX, defaultY, dsotmSFX, dsotmDesc};
	dsotm.gfx = oamAllocateGfx(&oamMain, SpriteSize_64x64, SpriteColorFormat_16Color);
	dmaCopy(dsotmPal, &SPRITE_PALETTE[dsotm.id * 16], dsotmPalLen);
	dmaCopy((u8*)dsotmTiles, dsotm.gfx, 2048);
	sprites[dsotm.id] = dsotm;
	SPRITECOUNT++;

	//eastwood
	mmLoadEffect(SFX_EASTWOOD);
	mm_sound_effect eastwoodSFX = { { SFX_EASTWOOD }, (int)(1.0f * (1<<10)), 0, 255, 128, };
	char eastwoodDesc[] = "-_-";
	mySprite eastwood = {11, 0, SpriteSize_64x64, SpriteColorFormat_16Color, 0, 11, defaultX, defaultY, eastwoodSFX, eastwoodDesc};
	eastwood.gfx = oamAllocateGfx(&oamMain, SpriteSize_64x64, SpriteColorFormat_16Color);
	dmaCopy(eastwoodPal, &SPRITE_PALETTE[eastwood.id * 16], eastwoodPalLen);
	dmaCopy((u8*)eastwoodTiles, eastwood.gfx, 2048);
	sprites[eastwood.id] = eastwood;
	SPRITECOUNT++;

	//mario
	mmLoadEffect(SFX_MARIO);
	mm_sound_effect marioSFX = { { SFX_MARIO }, (int)(1.0f * (1<<10)), 0, 255, 128, };
	char marioDesc[] = "An Italian Plumber.";
	mySprite mario = {12, 0, SpriteSize_64x64, SpriteColorFormat_16Color, 0, 12, defaultX, defaultY, marioSFX, marioDesc};
	mario.gfx = oamAllocateGfx(&oamMain, SpriteSize_64x64, SpriteColorFormat_16Color);
	dmaCopy(marioPal, &SPRITE_PALETTE[mario.id * 16], marioPalLen);
	dmaCopy((u8*)marioTiles, mario.gfx, 2048);
	sprites[mario.id] = mario;
	SPRITECOUNT++;
}

int within(touchPosition * touch, mySprite sprite) {
	if (touch->px >= sprite.x && touch->px <= sprite.x+64 &&
		touch->py >= sprite.y && touch->py <= sprite.y+64) {
			return 1;
		}
	return 0;
}

int main() {
	touchPosition touch;
	PrintConsole mainScreen;
	mySprite sprites[128];
	
	lcdMainOnBottom();
	initVideo();
	initBackgrounds();
	initConsole(&mainScreen);
	initSprites(sprites);
	
	//leftButtonOff
	oamSet(&oamMain, sprites[0].id, sprites[0].x, sprites[0].y, 0, 0, SpriteSize_64x64,
		SpriteColorFormat_16Color, sprites[0].gfx, -1, false, false, false, false, false);
	//rightButtonOff
	oamSet(&oamMain, sprites[2].id, sprites[2].x, sprites[2].y, 0, 0, SpriteSize_64x64,
		SpriteColorFormat_16Color, sprites[2].gfx, -1, false, false, false, false, false);
	
	int keys = keysDown();
	int currentSprite = 4;
	int moveLeft = 0;
	int moveRight = 0;
	int MOVE_SPEED = 21;
	while (true) {
		//consoleClear();
		scanKeys();
		touchRead(&touch);
		keys = keysHeld();
		
		if (keys) {
			if (keys & KEY_TOUCH) {
				touchRead(&touch);
				if (within(&touch, sprites[0])) {
					// leftButton clicked
					// leftButtonOn
					oamClearSprite(&oamMain, 0);
					oamSet(&oamMain, sprites[1].id, sprites[1].x, sprites[1].y, 0, 1, SpriteSize_64x64,
						SpriteColorFormat_16Color, sprites[1].gfx, -1, false, false, false, false, false);
					swiWaitForVBlank();
					oamUpdate(&oamMain);
					moveLeft = 1;
				}
				else if (within(&touch, sprites[2])) {
					// rightButton clicked
					// rightButtonOn
					oamClearSprite(&oamMain, 2);
					oamSet(&oamMain, sprites[3].id, sprites[3].x, sprites[3].y, 0, 1, SpriteSize_64x64,
						SpriteColorFormat_16Color, sprites[3].gfx, -1, false, false, false, false, false);
					swiWaitForVBlank();
					oamUpdate(&oamMain);
					moveRight = 1;
				}
				else if(within(&touch, sprites[currentSprite])) {
					mmEffectEx(&sprites[currentSprite].sfx);
				}
			}
		}
		else {
			//leftButtonOff
			oamClearSprite(&oamMain, 1);
			oamSet(&oamMain, sprites[0].id, sprites[0].x, sprites[0].y, 0, 0, SpriteSize_64x64,
				SpriteColorFormat_16Color, sprites[0].gfx, -1, false, false, false, false, false);
			//rightButtonOff
			oamClearSprite(&oamMain, 3);
			oamSet(&oamMain, sprites[2].id, sprites[2].x, sprites[2].y, 0, 0, SpriteSize_64x64,
				SpriteColorFormat_16Color, sprites[2].gfx, -1, false, false, false, false, false);
				
			if (moveLeft) {
				if ((currentSprite - 1) >= 4) {
					// move current sprite to the right and new one in from left
					int x1 = sprites[currentSprite].x;
					int x2 = -64;
					
					while (x1 < 280 || x2 < 96) {
						oamSet(&oamMain, sprites[currentSprite].id, x1, 
							sprites[currentSprite].y, 0, sprites[currentSprite].paletteAlpha, 
							SpriteSize_64x64, SpriteColorFormat_16Color, sprites[currentSprite].gfx, 
							-1, false, false, false, false, false);
						oamSet(&oamMain, sprites[currentSprite-1].id, x2, sprites[currentSprite-1].y,
							0, sprites[currentSprite-1].paletteAlpha, SpriteSize_64x64,
							SpriteColorFormat_16Color, sprites[currentSprite-1].gfx, -1, false, false,
							false, false, false);
						swiWaitForVBlank();
						oamUpdate(&oamMain);
						x1 += MOVE_SPEED;
						x2 += MOVE_SPEED;
					}
					currentSprite--;
				}
				moveLeft = 0;
			}
			else if (moveRight) {
				if ((currentSprite + 1) - SPRITECOUNT < 0) {
					// move current sprite to the left and new one from right
					int x1 = sprites[currentSprite].x;
					int x2 = 256;
					
					while (x1 > -80 || x2 > 96) {
						oamSet(&oamMain, sprites[currentSprite].id, x1, 
							sprites[currentSprite].y, 0, sprites[currentSprite].paletteAlpha, 
							SpriteSize_64x64, SpriteColorFormat_16Color, sprites[currentSprite].gfx, 
							-1, false, false, false, false, false);
						oamSet(&oamMain, sprites[currentSprite+1].id, x2, sprites[currentSprite+1].y,
							0, sprites[currentSprite+1].paletteAlpha, SpriteSize_64x64,
							SpriteColorFormat_16Color, sprites[currentSprite+1].gfx, -1, false, false,
							false, false, false);
						swiWaitForVBlank();
						oamUpdate(&oamMain);
						x1 -= MOVE_SPEED;
						x2 -= MOVE_SPEED;
					}
					currentSprite++;
				}
				moveRight = 0;
			}
		}
		
		//oamSet(oam, id, x, y, priority, palette_alpha, size, colorformat, gfxOffset, affineIndex,
		//sizedouble, hide, hflip, vflip, mosaic);
		//
		//gong
		consoleClear();
		printf("\x1b[3;3H%s", sprites[currentSprite].desc);
		oamSet(&oamMain, sprites[currentSprite].id, sprites[currentSprite].x, sprites[currentSprite].y, 0, sprites[currentSprite].paletteAlpha, SpriteSize_64x64, SpriteColorFormat_16Color,
			sprites[currentSprite].gfx, -1, false, false, false, false, false);
			
		swiWaitForVBlank();
		oamUpdate(&oamMain);	
	}
}