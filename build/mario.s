
@{{BLOCK(mario)

@=======================================================================
@
@	mario, 64x64@4, 
@	+ palette 16 entries, not compressed
@	+ 64 tiles not compressed
@	Total size: 32 + 2048 = 2080
@
@	Time-stamp: 2013-02-05, 23:05:34
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.10
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global marioTiles		@ 2048 unsigned chars
marioTiles:
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0xDDD00000,0x333E0000,0x33111100,0xF3333110,0x66333310,0x556B3310,0x55555310,0x95965570
	.word 0x0000DDDD,0x000F1313,0x0E111333,0x911333FC,0x13333B62,0x133BB555,0x93B55555,0xE6557564
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0xF0000000,0xF0000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x95946544,0x49446544,0x496E964F,0x65594770,0x55E44770,0xE47E7E00,0x44119290,0x111B223E
	.word 0x4657456F,0x455449E4,0x4B946944,0xE7445569,0xE7E44555,0x047EE44E,0xE9911444,0x362B1111
	.word 0x0000000E,0x0000000E,0x0000000F,0x00000000,0x00000000,0x00000000,0x00000000,0x0000000D
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0xE0000000,0x39000000,0x19000000,0x79000000,0xD9000000,0x82000000,0x82000000,0x80000000
	.word 0x11162233,0x33162233,0x3319A211,0x336A8FFF,0x36AA8CCC,0x6A888FCC,0x2ACC82CC,0xAACC8222
	.word 0x36221111,0x36221333,0x162A1333,0xFF8A6133,0xCCCAA613,0xCC888A61,0xC22CC8A2,0x22ACC8AA
	.word 0x000000F3,0x00000D33,0x00000D11,0x00000D3F,0x00000D9C,0x0000082C,0x0000082C,0x00000082
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0xD0000000,0xBD000000,0x19000000,0x19000000
	.word 0x8888A228,0xAAA22220,0x2222A220,0x22222220,0x822222B1,0x06666971,0xF1117777,0xF1117777
	.word 0x22A888A8,0x2222AAAA,0x22A22222,0x22222222,0xB6222280,0x19666BD0,0x777111D0,0x777711D0
	.word 0x00000008,0x00000000,0x00000000,0x00000000,0x0000000B,0x00000F9B,0x00000D17,0x00000D17
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x19000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x0B1BBBBB,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0xBBBBB1D0,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000D1B,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.section .rodata
	.align	2
	.global marioPal		@ 32 unsigned chars
marioPal:
	.hword 0x7FFF,0x08F6,0x4965,0x10BD,0x367E,0x0423,0x1CCD,0x25DC
	.hword 0x62F1,0x2996,0x52AA,0x0CF2,0x7FFF,0x52B8,0x3DFB,0x5ADB

@}}BLOCK(mario)