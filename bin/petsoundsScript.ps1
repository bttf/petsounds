$gritPath = Split-Path -Parent $MyInvocation.MyCommand.Path
$outputFilePath = "$gritPath\petsoundsScript.txt"
$filelist = Get-ChildItem $gritPath -filter "*.png"
$id = 7
$outString = ""
$gritTemplate = "$gritPath\template.grit"

foreach ($file in $filelist) {
	$name = $file.name.Split('.')[0]
	$outString += '#include "' + $name + '.h"'
	$outString += "`n"
}
$outString += "`n`n" 
$outString | Out-File $outputFilePath
foreach ($file in $filelist) {
	$name = $file.name.Split('.')[0]
	$outString = "//$name`n"
	$outString += "mmLoadEffect(SFX_" + $name.ToUpper() + ");`n";
	$outString += "mm_sound_effect " + $name + "SFX = { { SFX_" + $name.ToUpper() +  " }, (int)(1.0f * (1<<10)), 0, 255, 128, };`n"
	$outString += "char " + $name + "Desc[] = 'INSERT DESC';`n"
	$outString += "mySprite $name = {" + $id + ", 0, SpriteSize_64x64, SpriteColorFormat_16Color, 0, "+$id+", defaultX, defaultY, "+$name+"SFX, "+$name+"Desc};`n"
	$outString += ""+$name+".gfx = oamAllocateGfx(&oamMain, SpriteSize_64x64, SpriteColorFormat_16Color);`n"
	$outString += "dmaCopy("+$name+"Pal, &SPRITE_PALETTE["+$name+".id * 16], "+$name+"PalLen);`n"
	$outString += "dmaCopy((u8*)"+$name+"Tiles, "+$name+".gfx, 2048);`n"
	$outString += "sprites["+$name+".id] = "+$name+";`n"
	$outString += "SPRITECOUNT++;`n"
	$outString | Out-File -append $outputFilePath
	Copy-Item $gritTemplate ($gritPath + $name + ".grit")
	$id++
}
