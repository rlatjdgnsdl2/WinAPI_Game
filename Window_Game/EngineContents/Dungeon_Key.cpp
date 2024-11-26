#include "PreCompile.h"
#include "Dungeon_BSP.h"


void ADungeon_BSP::InitKeySet()
{
	TileIndexForKey.insert({ "000011011",0 });
	TileIndexForKey.insert({ "100011011",0 });
	TileIndexForKey.insert({ "001011011",0 });
	TileIndexForKey.insert({ "000011111",0 });
	TileIndexForKey.insert({ "101011011",0 });
	TileIndexForKey.insert({ "100011111",0 });
	TileIndexForKey.insert({ "001011111",0 });
	TileIndexForKey.insert({ "101011111",0 });

	TileIndexForKey.insert({ "000111111",1 });
	TileIndexForKey.insert({ "001111111",1 });
	TileIndexForKey.insert({ "100111111",1 });
	TileIndexForKey.insert({ "101111111",1 });

	TileIndexForKey.insert({ "000110110",2 });
	TileIndexForKey.insert({ "100110110",2 });
	TileIndexForKey.insert({ "001110110",2 });
	TileIndexForKey.insert({ "000110111",2 });
	TileIndexForKey.insert({ "101110110",2 });
	TileIndexForKey.insert({ "100110111",2 });
	TileIndexForKey.insert({ "001110111",2 });
	TileIndexForKey.insert({ "101110111",2 });

	TileIndexForKey.insert({ "011011011",3 });
	TileIndexForKey.insert({ "011011111",3 });
	TileIndexForKey.insert({ "111011011",3 });
	TileIndexForKey.insert({ "111011111",3 });

	TileIndexForKey.insert({ "111111111",4 });

	TileIndexForKey.insert({ "110110110",5 });
	TileIndexForKey.insert({ "111110110",5 });
	TileIndexForKey.insert({ "111110111",5 });
	TileIndexForKey.insert({ "110110111",5 });

	TileIndexForKey.insert({ "011011000",6 });
	TileIndexForKey.insert({ "111011000",6 });
	TileIndexForKey.insert({ "011011100",6 });
	TileIndexForKey.insert({ "011011001",6 });
	TileIndexForKey.insert({ "111011100",6 });
	TileIndexForKey.insert({ "111011001",6 });
	TileIndexForKey.insert({ "011011101",6 });
	TileIndexForKey.insert({ "111011101",6 });

	TileIndexForKey.insert({ "111111000",7 });
	TileIndexForKey.insert({ "111111100",7 });
	TileIndexForKey.insert({ "111111101",7 });
	TileIndexForKey.insert({ "111111001",7 });

	TileIndexForKey.insert({ "110110000",8 });
	TileIndexForKey.insert({ "110110100",8 });
	TileIndexForKey.insert({ "111110000",8 });
	TileIndexForKey.insert({ "110110001",8 });
	TileIndexForKey.insert({ "111110100",8 });
	TileIndexForKey.insert({ "111110001",8 });
	TileIndexForKey.insert({ "110110101",8 });
	TileIndexForKey.insert({ "111110101",8 });

	TileIndexForKey.insert({ "000011010",9 });
	TileIndexForKey.insert({ "100011010",9 });
	TileIndexForKey.insert({ "001011010",9 });
	TileIndexForKey.insert({ "000011110",9 });
	TileIndexForKey.insert({ "101011010",9 });
	TileIndexForKey.insert({ "100011110",9 });
	TileIndexForKey.insert({ "001011110",9 });
	TileIndexForKey.insert({ "101011110",9 });

	TileIndexForKey.insert({ "000111000",10 });
	TileIndexForKey.insert({ "100111000",10 });
	TileIndexForKey.insert({ "001111000",10 });
	TileIndexForKey.insert({ "000111100",10 });
	TileIndexForKey.insert({ "000111001",10 });
	TileIndexForKey.insert({ "101111000",10 });
	TileIndexForKey.insert({ "100111100",10 });
	TileIndexForKey.insert({ "100111001",10 });
	TileIndexForKey.insert({ "001111100",10 });
	TileIndexForKey.insert({ "001111001",10 });
	TileIndexForKey.insert({ "000111101",10 });
	TileIndexForKey.insert({ "101111100",10 });
	TileIndexForKey.insert({ "101111001",10 });
	TileIndexForKey.insert({ "100111101",10 });
	TileIndexForKey.insert({ "001111101",10 });
	TileIndexForKey.insert({ "101111101",10 });


	TileIndexForKey.insert({ "000110010",11 });
	TileIndexForKey.insert({ "100110010",11 });
	TileIndexForKey.insert({ "001110010",11 });
	TileIndexForKey.insert({ "000110011",11 });
	TileIndexForKey.insert({ "101110010",11 });
	TileIndexForKey.insert({ "100110011",11 });
	TileIndexForKey.insert({ "001110011",11 });
	TileIndexForKey.insert({ "101110011",11 });

	TileIndexForKey.insert({ "010010010",12 });
	TileIndexForKey.insert({ "110010010",12 });
	TileIndexForKey.insert({ "011010010",12 });
	TileIndexForKey.insert({ "010010110",12 });
	TileIndexForKey.insert({ "010010011",12 });
	TileIndexForKey.insert({ "111010010",12 });
	TileIndexForKey.insert({ "110010110",12 });
	TileIndexForKey.insert({ "110010011",12 });
	TileIndexForKey.insert({ "011010110",12 });
	TileIndexForKey.insert({ "011010011",12 });
	TileIndexForKey.insert({ "010010111",12 });
	TileIndexForKey.insert({ "111010110",12 });
	TileIndexForKey.insert({ "110010111",12 });
	TileIndexForKey.insert({ "111010011",12 });
	TileIndexForKey.insert({ "011010111",12 });
	TileIndexForKey.insert({ "111010111",12 });



	TileIndexForKey.insert({ "000010000",13 });
	TileIndexForKey.insert({ "100010000",13 });
	TileIndexForKey.insert({ "001010000",13 });
	TileIndexForKey.insert({ "000010100",13 });
	TileIndexForKey.insert({ "000010001",13 });
	TileIndexForKey.insert({ "101010000",13 });
	TileIndexForKey.insert({ "100010100",13 });
	TileIndexForKey.insert({ "100010001",13 });
	TileIndexForKey.insert({ "001010100",13 });
	TileIndexForKey.insert({ "001010001",13 });
	TileIndexForKey.insert({ "000010101",13 });
	TileIndexForKey.insert({ "101010100",13 });
	TileIndexForKey.insert({ "101010001",13 });
	TileIndexForKey.insert({ "001010101",13 });
	TileIndexForKey.insert({ "101010101",13 });
	TileIndexForKey.insert({ "100010101",13 });

	TileIndexForKey.insert({ "010011000",14 });
	TileIndexForKey.insert({ "110011000",14 });
	TileIndexForKey.insert({ "010011100",14 });
	TileIndexForKey.insert({ "010011001",14 });
	TileIndexForKey.insert({ "110011100",14 });
	TileIndexForKey.insert({ "110011001",14 });
	TileIndexForKey.insert({ "010011101",14 });
	TileIndexForKey.insert({ "110011101",14 });

	TileIndexForKey.insert({ "010110000",15 });
	TileIndexForKey.insert({ "011110000",15 });
	TileIndexForKey.insert({ "010110100",15 });
	TileIndexForKey.insert({ "010110001",15 });
	TileIndexForKey.insert({ "011110100",15 });
	TileIndexForKey.insert({ "011110001",15 });
	TileIndexForKey.insert({ "010110101",15 });
	TileIndexForKey.insert({ "011110101",15 });

	TileIndexForKey.insert({ "000010010",16 });
	TileIndexForKey.insert({ "100010010",16 });
	TileIndexForKey.insert({ "001010010",16 });
	TileIndexForKey.insert({ "000010110",16 });
	TileIndexForKey.insert({ "000010011",16 });
	TileIndexForKey.insert({ "101010010",16 });
	TileIndexForKey.insert({ "100010110",16 });
	TileIndexForKey.insert({ "100010011",16 });
	TileIndexForKey.insert({ "001010110",16 });
	TileIndexForKey.insert({ "001010011",16 });
	TileIndexForKey.insert({ "000010111",16 });
	TileIndexForKey.insert({ "101010110",16 });
	TileIndexForKey.insert({ "101010011",16 });
	TileIndexForKey.insert({ "100010111",16 });
	TileIndexForKey.insert({ "001010111",16 });
	TileIndexForKey.insert({ "101010111",16 });

	TileIndexForKey.insert({ "000011000",17 });
	TileIndexForKey.insert({ "100011000",17 });
	TileIndexForKey.insert({ "001011000",17 });
	TileIndexForKey.insert({ "000011100",17 });
	TileIndexForKey.insert({ "000011001",17 });
	TileIndexForKey.insert({ "101011000",17 });
	TileIndexForKey.insert({ "100011100",17 });
	TileIndexForKey.insert({ "100011001",17 });
	TileIndexForKey.insert({ "001011100",17 });
	TileIndexForKey.insert({ "001011001",17 });
	TileIndexForKey.insert({ "000011101",17 });
	TileIndexForKey.insert({ "101011100",17 });
	TileIndexForKey.insert({ "100011101",17 });
	TileIndexForKey.insert({ "101011001",17 });
	TileIndexForKey.insert({ "001011101",17 });
	TileIndexForKey.insert({ "101011101",17 });

	TileIndexForKey.insert({ "010111010",18 });

	TileIndexForKey.insert({ "100110000",19 });
	TileIndexForKey.insert({ "001110000",19 });
	TileIndexForKey.insert({ "000110100",19 });
	TileIndexForKey.insert({ "000110001",19 });
	TileIndexForKey.insert({ "101110000",19 });
	TileIndexForKey.insert({ "100110100",19 });
	TileIndexForKey.insert({ "100110001",19 });
	TileIndexForKey.insert({ "001110100",19 });
	TileIndexForKey.insert({ "001110001",19 });
	TileIndexForKey.insert({ "000110101",19 });
	TileIndexForKey.insert({ "101110100",19 });
	TileIndexForKey.insert({ "101110001",19 });
	TileIndexForKey.insert({ "100110101",19 });
	TileIndexForKey.insert({ "001110101",19 });
	TileIndexForKey.insert({ "101110101",19 });
	TileIndexForKey.insert({ "000110000",19 });

	TileIndexForKey.insert({ "110010000",20 });
	TileIndexForKey.insert({ "011010000",20 });
	TileIndexForKey.insert({ "010010100",20 });
	TileIndexForKey.insert({ "010010001",20 });
	TileIndexForKey.insert({ "111010000",20 });
	TileIndexForKey.insert({ "110010100",20 });
	TileIndexForKey.insert({ "110010001",20 });
	TileIndexForKey.insert({ "011010100",20 });
	TileIndexForKey.insert({ "011010001",20 });
	TileIndexForKey.insert({ "010010101",20 });
	TileIndexForKey.insert({ "111010100",20 });
	TileIndexForKey.insert({ "111010001",20 });
	TileIndexForKey.insert({ "011010101",20 });
	TileIndexForKey.insert({ "111010101",20 });
	TileIndexForKey.insert({ "110010101",20 });
	TileIndexForKey.insert({ "010010000",20 });

	TileIndexForKey.insert({ "000111010",21 });
	TileIndexForKey.insert({ "100111010",21 });
	TileIndexForKey.insert({ "001111010",21 });
	TileIndexForKey.insert({ "101111010",21 });

	TileIndexForKey.insert({ "110011010",22 });
	TileIndexForKey.insert({ "010011110",22 });
	TileIndexForKey.insert({ "110011110",22 });
	TileIndexForKey.insert({ "010011010",22 });

	TileIndexForKey.insert({ "011110010",23 });
	TileIndexForKey.insert({ "010110011",23 });
	TileIndexForKey.insert({ "011110011",23 });
	TileIndexForKey.insert({ "010110010",23 });

	TileIndexForKey.insert({ "010111000",24 });
	TileIndexForKey.insert({ "010111100",24 });
	TileIndexForKey.insert({ "010111001",24 });
	TileIndexForKey.insert({ "010111101",24 });

	TileIndexForKey.insert({ "111111010",25 });
	TileIndexForKey.insert({ "110111110",26 });
	TileIndexForKey.insert({ "011111011",27 });
	TileIndexForKey.insert({ "010111111",28 });

	TileIndexForKey.insert({ "111111110",29 });
	TileIndexForKey.insert({ "111111011",30 });
	TileIndexForKey.insert({ "110111111",31 });
	TileIndexForKey.insert({ "011111111",32 });

	TileIndexForKey.insert({ "011011010",33 });
	TileIndexForKey.insert({ "111011010",33 });
	TileIndexForKey.insert({ "011011110",33 });
	TileIndexForKey.insert({ "111011110",33 });

	TileIndexForKey.insert({ "110110010",34 });
	TileIndexForKey.insert({ "111110010",34 });
	TileIndexForKey.insert({ "110110011",34 });
	TileIndexForKey.insert({ "111110011",34 });

	TileIndexForKey.insert({ "110011011",35 });
	TileIndexForKey.insert({ "010011111",35 });
	TileIndexForKey.insert({ "110011111",35 });
	TileIndexForKey.insert({ "010011011",35 });

	TileIndexForKey.insert({ "011110110",36 });
	TileIndexForKey.insert({ "010110111",36 });
	TileIndexForKey.insert({ "011110111",36 });
	TileIndexForKey.insert({ "010110110",36 });

	TileIndexForKey.insert({ "100111110",37 });
	TileIndexForKey.insert({ "001111110",37 });
	TileIndexForKey.insert({ "101111110",37 });
	TileIndexForKey.insert({ "000111110",37 });

	TileIndexForKey.insert({ "100111011",38 });
	TileIndexForKey.insert({ "001111011",38 });
	TileIndexForKey.insert({ "101111011",38 });
	TileIndexForKey.insert({ "000111011",38 });

	TileIndexForKey.insert({ "110111100",39 });
	TileIndexForKey.insert({ "110111001",39 });
	TileIndexForKey.insert({ "110111101",39 });
	TileIndexForKey.insert({ "110111000",39 });

	TileIndexForKey.insert({ "011111100",40 });
	TileIndexForKey.insert({ "011111001",40 });
	TileIndexForKey.insert({ "011111101",40 });
	TileIndexForKey.insert({ "011111000",40 });

	TileIndexForKey.insert({ "010111011",41 });
	TileIndexForKey.insert({ "010111110",42 });
	TileIndexForKey.insert({ "011111010",43 });
	TileIndexForKey.insert({ "110111010",44 });
	TileIndexForKey.insert({ "011111110",45 });
	TileIndexForKey.insert({ "110111011",46 });







	MiniMapSpriteName.insert({ "000011011","LeftTop.png"});
	MiniMapSpriteName.insert({ "100011011","LeftTop.png" });
	MiniMapSpriteName.insert({ "001011011","LeftTop.png" });
	MiniMapSpriteName.insert({ "000011111","LeftTop.png" });
	MiniMapSpriteName.insert({ "101011011","LeftTop.png" });
	MiniMapSpriteName.insert({ "100011111","LeftTop.png" });
	MiniMapSpriteName.insert({ "001011111","LeftTop.png" });
	MiniMapSpriteName.insert({ "101011111","LeftTop.png" });
	
	MiniMapSpriteName.insert({ "000111111","Top.png"});
	MiniMapSpriteName.insert({ "001111111","Top.png" });
	MiniMapSpriteName.insert({ "100111111","Top.png" });
	MiniMapSpriteName.insert({ "101111111","Top.png" });
	
	MiniMapSpriteName.insert({ "000110110","RightTop.png" });
	MiniMapSpriteName.insert({ "100110110","RightTop.png" });
	MiniMapSpriteName.insert({ "001110110","RightTop.png" });
	MiniMapSpriteName.insert({ "000110111","RightTop.png" });
	MiniMapSpriteName.insert({ "101110110","RightTop.png" });
	MiniMapSpriteName.insert({ "100110111","RightTop.png" });
	MiniMapSpriteName.insert({ "001110111","RightTop.png" });
	MiniMapSpriteName.insert({ "101110111","RightTop.png" });
	
	MiniMapSpriteName.insert({ "011011011","Left.png" });
	MiniMapSpriteName.insert({ "011011111","Left.png" });
	MiniMapSpriteName.insert({ "111011011","Left.png" });
	MiniMapSpriteName.insert({ "111011111","Left.png" });
	
	MiniMapSpriteName.insert({ "111111111","Void.png"});
	
	MiniMapSpriteName.insert({ "110110110","Right.png"});
	MiniMapSpriteName.insert({ "111110110","Right.png"});
	MiniMapSpriteName.insert({ "111110111","Right.png"});
	MiniMapSpriteName.insert({ "110110111","Right.png"});
	
	MiniMapSpriteName.insert({ "011011000","LeftBottom.png" });
	MiniMapSpriteName.insert({ "111011000","LeftBottom.png" });
	MiniMapSpriteName.insert({ "011011100","LeftBottom.png" });
	MiniMapSpriteName.insert({ "011011001","LeftBottom.png" });
	MiniMapSpriteName.insert({ "111011100","LeftBottom.png" });
	MiniMapSpriteName.insert({ "111011001","LeftBottom.png" });
	MiniMapSpriteName.insert({ "011011101","LeftBottom.png" });
	MiniMapSpriteName.insert({ "111011101","LeftBottom.png" });
	
	MiniMapSpriteName.insert({ "111111000","Bottom.png" });
	MiniMapSpriteName.insert({ "111111100","Bottom.png" });
	MiniMapSpriteName.insert({ "111111101","Bottom.png" });
	MiniMapSpriteName.insert({ "111111001","Bottom.png" });
	
	MiniMapSpriteName.insert({ "110110000","RightBottom.png" });
	MiniMapSpriteName.insert({ "110110100","RightBottom.png" });
	MiniMapSpriteName.insert({ "111110000","RightBottom.png" });
	MiniMapSpriteName.insert({ "110110001","RightBottom.png" });
	MiniMapSpriteName.insert({ "111110100","RightBottom.png" });
	MiniMapSpriteName.insert({ "111110001","RightBottom.png" });
	MiniMapSpriteName.insert({ "110110101","RightBottom.png" });
	MiniMapSpriteName.insert({ "111110101","RightBottom.png" });
	
	MiniMapSpriteName.insert({ "000011010","LeftTop.png" });
	MiniMapSpriteName.insert({ "100011010","LeftTop.png" });
	MiniMapSpriteName.insert({ "001011010","LeftTop.png" });
	MiniMapSpriteName.insert({ "000011110","LeftTop.png" });
	MiniMapSpriteName.insert({ "101011010","LeftTop.png" });
	MiniMapSpriteName.insert({ "100011110","LeftTop.png" });
	MiniMapSpriteName.insert({ "001011110","LeftTop.png" });
	MiniMapSpriteName.insert({ "101011110","LeftTop.png" });

	MiniMapSpriteName.insert({ "000111000","Horizontal.png" });
	MiniMapSpriteName.insert({ "100111000","Horizontal.png" });
	MiniMapSpriteName.insert({ "001111000","Horizontal.png" });
	MiniMapSpriteName.insert({ "000111100","Horizontal.png" });
	MiniMapSpriteName.insert({ "000111001","Horizontal.png" });
	MiniMapSpriteName.insert({ "101111000","Horizontal.png" });
	MiniMapSpriteName.insert({ "100111100","Horizontal.png" });
	MiniMapSpriteName.insert({ "100111001","Horizontal.png" });
	MiniMapSpriteName.insert({ "001111100","Horizontal.png" });
	MiniMapSpriteName.insert({ "001111001","Horizontal.png" });
	MiniMapSpriteName.insert({ "000111101","Horizontal.png" });
	MiniMapSpriteName.insert({ "101111100","Horizontal.png" });
	MiniMapSpriteName.insert({ "101111001","Horizontal.png" });
	MiniMapSpriteName.insert({ "100111101","Horizontal.png" });
	MiniMapSpriteName.insert({ "001111101","Horizontal.png" });
	MiniMapSpriteName.insert({ "101111101","Horizontal.png" });
	
	MiniMapSpriteName.insert({ "000110010","RightTop.png" });
	MiniMapSpriteName.insert({ "100110010","RightTop.png" });
	MiniMapSpriteName.insert({ "001110010","RightTop.png" });
	MiniMapSpriteName.insert({ "000110011","RightTop.png" });
	MiniMapSpriteName.insert({ "101110010","RightTop.png" });
	MiniMapSpriteName.insert({ "100110011","RightTop.png" });
	MiniMapSpriteName.insert({ "001110011","RightTop.png" });
	MiniMapSpriteName.insert({ "101110011","RightTop.png" });
	
	MiniMapSpriteName.insert({ "010010010","Vertical.png" });
	MiniMapSpriteName.insert({ "110010010","Vertical.png" });
	MiniMapSpriteName.insert({ "011010010","Vertical.png" });
	MiniMapSpriteName.insert({ "010010110","Vertical.png" });
	MiniMapSpriteName.insert({ "010010011","Vertical.png" });
	MiniMapSpriteName.insert({ "111010010","Vertical.png" });
	MiniMapSpriteName.insert({ "110010110","Vertical.png" });
	MiniMapSpriteName.insert({ "110010011","Vertical.png" });
	MiniMapSpriteName.insert({ "011010110","Vertical.png" });
	MiniMapSpriteName.insert({ "011010011","Vertical.png" });
	MiniMapSpriteName.insert({ "010010111","Vertical.png" });
	MiniMapSpriteName.insert({ "111010110","Vertical.png" });
	MiniMapSpriteName.insert({ "110010111","Vertical.png" });
	MiniMapSpriteName.insert({ "111010011","Vertical.png" });
	MiniMapSpriteName.insert({ "011010111","Vertical.png" });
	MiniMapSpriteName.insert({ "111010111","Vertical.png" });
	
	MiniMapSpriteName.insert({ "000010000","Void.png" });
	MiniMapSpriteName.insert({ "100010000","Void.png" });
	MiniMapSpriteName.insert({ "001010000","Void.png" });
	MiniMapSpriteName.insert({ "000010100","Void.png" });
	MiniMapSpriteName.insert({ "000010001","Void.png" });
	MiniMapSpriteName.insert({ "101010000","Void.png" });
	MiniMapSpriteName.insert({ "100010100","Void.png" });
	MiniMapSpriteName.insert({ "100010001","Void.png" });
	MiniMapSpriteName.insert({ "001010100","Void.png" });
	MiniMapSpriteName.insert({ "001010001","Void.png" });
	MiniMapSpriteName.insert({ "000010101","Void.png" });
	MiniMapSpriteName.insert({ "101010100","Void.png" });
	MiniMapSpriteName.insert({ "101010001","Void.png" });
	MiniMapSpriteName.insert({ "001010101","Void.png" });
	MiniMapSpriteName.insert({ "101010101","Void.png" });
	MiniMapSpriteName.insert({ "100010101","Void.png" });
	
	MiniMapSpriteName.insert({ "010011000","LeftBottom.png" });
	MiniMapSpriteName.insert({ "110011000","LeftBottom.png" });
	MiniMapSpriteName.insert({ "010011100","LeftBottom.png" });
	MiniMapSpriteName.insert({ "010011001","LeftBottom.png" });
	MiniMapSpriteName.insert({ "110011100","LeftBottom.png" });
	MiniMapSpriteName.insert({ "110011001","LeftBottom.png" });
	MiniMapSpriteName.insert({ "010011101","LeftBottom.png" });
	MiniMapSpriteName.insert({ "110011101","LeftBottom.png" });
	
	MiniMapSpriteName.insert({ "010110000","RightBottom.png" });
	MiniMapSpriteName.insert({ "011110000","RightBottom.png" });
	MiniMapSpriteName.insert({ "010110100","RightBottom.png" });
	MiniMapSpriteName.insert({ "010110001","RightBottom.png" });
	MiniMapSpriteName.insert({ "011110100","RightBottom.png" });
	MiniMapSpriteName.insert({ "011110001","RightBottom.png" });
	MiniMapSpriteName.insert({ "010110101","RightBottom.png" });
	MiniMapSpriteName.insert({ "011110101","RightBottom.png" });

	MiniMapSpriteName.insert({ "000010010","Vertical.png" });
	MiniMapSpriteName.insert({ "100010010","Vertical.png" });
	MiniMapSpriteName.insert({ "001010010","Vertical.png" });
	MiniMapSpriteName.insert({ "000010110","Vertical.png" });
	MiniMapSpriteName.insert({ "000010011","Vertical.png" });
	MiniMapSpriteName.insert({ "101010010","Vertical.png" });
	MiniMapSpriteName.insert({ "100010110","Vertical.png" });
	MiniMapSpriteName.insert({ "100010011","Vertical.png" });
	MiniMapSpriteName.insert({ "001010110","Vertical.png" });
	MiniMapSpriteName.insert({ "001010011","Vertical.png" });
	MiniMapSpriteName.insert({ "000010111","Vertical.png" });
	MiniMapSpriteName.insert({ "101010110","Vertical.png" });
	MiniMapSpriteName.insert({ "101010011","Vertical.png" });
	MiniMapSpriteName.insert({ "100010111","Vertical.png" });
	MiniMapSpriteName.insert({ "001010111","Vertical.png" });
	MiniMapSpriteName.insert({ "101010111","Vertical.png" });
	
	MiniMapSpriteName.insert({ "000011000","Horizontal.png" });
	MiniMapSpriteName.insert({ "100011000","Horizontal.png" });
	MiniMapSpriteName.insert({ "001011000","Horizontal.png" });
	MiniMapSpriteName.insert({ "000011100","Horizontal.png" });
	MiniMapSpriteName.insert({ "000011001","Horizontal.png" });
	MiniMapSpriteName.insert({ "101011000","Horizontal.png" });
	MiniMapSpriteName.insert({ "100011100","Horizontal.png" });
	MiniMapSpriteName.insert({ "100011001","Horizontal.png" });
	MiniMapSpriteName.insert({ "001011100","Horizontal.png" });
	MiniMapSpriteName.insert({ "001011001","Horizontal.png" });
	MiniMapSpriteName.insert({ "000011101","Horizontal.png" });
	MiniMapSpriteName.insert({ "101011100","Horizontal.png" });
	MiniMapSpriteName.insert({ "100011101","Horizontal.png" });
	MiniMapSpriteName.insert({ "101011001","Horizontal.png" });
	MiniMapSpriteName.insert({ "001011101","Horizontal.png" });
	MiniMapSpriteName.insert({ "101011101","Horizontal.png" });
	
	MiniMapSpriteName.insert({ "010111010","Void.png"});
	
	MiniMapSpriteName.insert({ "100110000","Horizontal.png" });
	MiniMapSpriteName.insert({ "001110000","Horizontal.png" });
	MiniMapSpriteName.insert({ "000110100","Horizontal.png" });
	MiniMapSpriteName.insert({ "000110001","Horizontal.png" });
	MiniMapSpriteName.insert({ "101110000","Horizontal.png" });
	MiniMapSpriteName.insert({ "100110100","Horizontal.png" });
	MiniMapSpriteName.insert({ "100110001","Horizontal.png" });
	MiniMapSpriteName.insert({ "001110100","Horizontal.png" });
	MiniMapSpriteName.insert({ "001110001","Horizontal.png" });
	MiniMapSpriteName.insert({ "000110101","Horizontal.png" });
	MiniMapSpriteName.insert({ "101110100","Horizontal.png" });
	MiniMapSpriteName.insert({ "101110001","Horizontal.png" });
	MiniMapSpriteName.insert({ "100110101","Horizontal.png" });
	MiniMapSpriteName.insert({ "001110101","Horizontal.png" });
	MiniMapSpriteName.insert({ "101110101","Horizontal.png" });
	MiniMapSpriteName.insert({ "000110000","Horizontal.png" });
	
	MiniMapSpriteName.insert({ "110010000","Vertical.png" });
	MiniMapSpriteName.insert({ "011010000","Vertical.png" });
	MiniMapSpriteName.insert({ "010010100","Vertical.png" });
	MiniMapSpriteName.insert({ "010010001","Vertical.png" });
	MiniMapSpriteName.insert({ "111010000","Vertical.png" });
	MiniMapSpriteName.insert({ "110010100","Vertical.png" });
	MiniMapSpriteName.insert({ "110010001","Vertical.png" });
	MiniMapSpriteName.insert({ "011010100","Vertical.png" });
	MiniMapSpriteName.insert({ "011010001","Vertical.png" });
	MiniMapSpriteName.insert({ "010010101","Vertical.png" });
	MiniMapSpriteName.insert({ "111010100","Vertical.png" });
	MiniMapSpriteName.insert({ "111010001","Vertical.png" });
	MiniMapSpriteName.insert({ "011010101","Vertical.png" });
	MiniMapSpriteName.insert({ "111010101","Vertical.png" });
	MiniMapSpriteName.insert({ "110010101","Vertical.png" });
	MiniMapSpriteName.insert({ "010010000","Vertical.png" });
	
	MiniMapSpriteName.insert({ "000111010","Top.png" });
	MiniMapSpriteName.insert({ "100111010","Top.png" });
	MiniMapSpriteName.insert({ "001111010","Top.png" });
	MiniMapSpriteName.insert({ "101111010","Top.png" });
	
	MiniMapSpriteName.insert({ "110011010","Left.png" });
	MiniMapSpriteName.insert({ "010011110","Left.png" });
	MiniMapSpriteName.insert({ "110011110","Left.png" });
	MiniMapSpriteName.insert({ "010011010","Left.png" });
	
	MiniMapSpriteName.insert({ "011110010","Right.png" });
	MiniMapSpriteName.insert({ "010110011","Right.png" });
	MiniMapSpriteName.insert({ "011110011","Right.png" });
	MiniMapSpriteName.insert({ "010110010","Right.png" });
	
	MiniMapSpriteName.insert({ "010111000","Bottom.png" });
	MiniMapSpriteName.insert({ "010111100","Bottom.png" });
	MiniMapSpriteName.insert({ "010111001","Bottom.png" });
	MiniMapSpriteName.insert({ "010111101","Bottom.png" });
												
	MiniMapSpriteName.insert({ "111111010","Void.png" });
	MiniMapSpriteName.insert({ "110111110","Void.png" });
	MiniMapSpriteName.insert({ "011111011","Void.png" });
	MiniMapSpriteName.insert({ "010111111","Void.png" });
												
	MiniMapSpriteName.insert({ "111111110","Void.png" });
	MiniMapSpriteName.insert({ "111111011","Void.png" });
	MiniMapSpriteName.insert({ "110111111","Void.png" });
	MiniMapSpriteName.insert({ "011111111","Void.png" });
												
	MiniMapSpriteName.insert({ "011011010","Void.png" });
	MiniMapSpriteName.insert({ "111011010","Void.png" });
	MiniMapSpriteName.insert({ "011011110","Void.png" });
	MiniMapSpriteName.insert({ "111011110","Void.png" });
												
	MiniMapSpriteName.insert({ "110110010","Void.png" });
	MiniMapSpriteName.insert({ "111110010","Void.png" });
	MiniMapSpriteName.insert({ "110110011","Void.png" });
	MiniMapSpriteName.insert({ "111110011","Void.png" });
												
	MiniMapSpriteName.insert({ "110011011","Void.png" });
	MiniMapSpriteName.insert({ "010011111","Void.png" });
	MiniMapSpriteName.insert({ "110011111","Void.png" });
	MiniMapSpriteName.insert({ "010011011","Void.png" });
												
	MiniMapSpriteName.insert({ "011110110","Void.png" });
	MiniMapSpriteName.insert({ "010110111","Void.png" });
	MiniMapSpriteName.insert({ "011110111","Void.png" });
	MiniMapSpriteName.insert({ "010110110","Void.png" });
												
	MiniMapSpriteName.insert({ "100111110","Top.png" });
	MiniMapSpriteName.insert({ "001111110","Top.png" });
	MiniMapSpriteName.insert({ "101111110","Top.png" });
	MiniMapSpriteName.insert({ "000111110","Top.png" });
												
	MiniMapSpriteName.insert({ "100111011","Top.png" });
	MiniMapSpriteName.insert({ "001111011","Top.png" });
	MiniMapSpriteName.insert({ "101111011","Top.png" });
	MiniMapSpriteName.insert({ "000111011","Top.png" });
												
	MiniMapSpriteName.insert({ "110111100","Bottom.png" });
	MiniMapSpriteName.insert({ "110111001","Bottom.png" });
	MiniMapSpriteName.insert({ "110111101","Bottom.png" });
	MiniMapSpriteName.insert({ "110111000","Bottom.png" });
												
	MiniMapSpriteName.insert({ "011111100","Bottom.png" });
	MiniMapSpriteName.insert({ "011111001","Bottom.png" });
	MiniMapSpriteName.insert({ "011111101","Bottom.png" });
	MiniMapSpriteName.insert({ "011111000","Bottom.png" });
												
	MiniMapSpriteName.insert({ "010111011","Void.png" });
	MiniMapSpriteName.insert({ "010111110","Void.png" });
	MiniMapSpriteName.insert({ "011111010","Void.png" });
	MiniMapSpriteName.insert({ "110111010","Void.png" });
	MiniMapSpriteName.insert({ "011111110","Void.png" });
	MiniMapSpriteName.insert({ "110111011","Void.png" });
}



