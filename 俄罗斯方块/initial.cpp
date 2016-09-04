#include "gameData.h"

//初始化基本参数
void initData(){

	//游戏界面可分解为 20*30 个格子
	brickInfo[21][31] = { 0 };

	//用于监听键盘事件
	keyCode = { 0 };

	//代表四种不同类型的砖块，默认为 3
	brickType = 3;

	//用来记录时间
	TIME = 0;

	//中间变量，并没有什么意义
	temp = 0;
	tempTwo = 0;
	tempThree = 0;
	tempFour = 0;
	b[numberOfBrick][numberOfBrick] = { 0 };
	tempArray[numberOfBrick][numberOfBrick] = { 0 };

	//初始化 drawBrick
	drawBrick = 0;					
	//初始化 flag
	flag = 0;						
	//初始化 rLine
	rLine = 0;			
	//初始化keyFlag
	keyFlag = 0;
	//初始化nextRandom
	nextRandom = rand() % 4 + 1;	
	//初始化skillCounts
	skillCounts = 0;

	lastCounts = 0;

	AGAIN = 0;

	memset(playerGrade, 0, sizeof(playerGrade));
}


//初始化brickInfo
void initBrickInfo(){
	for (int i = 0; i < 21; i++)
		for (int j = 0; j < 31; j++)
			if (i == 0 || i == 20 || j == 0 || j == 30)
				brickInfo[i][j] = 1;

}


