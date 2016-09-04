#include "gameData.h"
#include "gameFunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//记录玩家得分
 int grade;

//游戏界面可分解为 20*30 个格子
 int brickInfo[21][31];

//判断是否需要生成新砖块
 int drawBrick;

//用于监听键盘事件
 key_msg keyCode;

//判断是否应该清除一行
 int flag;

//当前行
 int rLine;

//代表四种不同类型的砖块，默认为 3
 int brickType;

//用来记录时间
 int TIME;

 //中间变量，并没有什么意义
 int temp;
 int tempTwo;
 int tempThree;
 int tempFour;

 int b[numberOfBrick][numberOfBrick];
 int tempArray[numberOfBrick][numberOfBrick];

//储存下落的砖块信息
 Brick brick[numberOfBrick];

 //储存提示的砖块信息
Brick brick2[numberOfBrick];

 int keyFlag;

 int nextRandom;

 char gradeString[5];

 int skillCounts;
 
 char skillCountsString[100];

 int lastCounts;

 int AGAIN;

 int playerGrade[1000];
 
 char playerGradeStringA[100];
 char playerGradeStringB[100];
 char playerGradeStringC[100];

//矩阵实现砖块
 int bt1[4][4] = {
	0, 0, 0, 0,
	1, 1, 1, 0,
	1, 0, 0, 0,
	0, 0, 0, 0
};

 int bt2[4][4] = {
	1, 1, 0, 0,
	1, 1, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0
};

 int bt3[4][4] = {
	0, 0, 0, 0,
	1, 1, 1, 1,
	0, 0, 0, 0,
	0, 0, 0, 0
};

 int bt4[4][4] = {
	0, 0, 0, 0,
	1, 1, 1, 0,
	0, 1, 0, 0,
	0, 0, 0, 0
};

//主函数
int main(){
	again:
		//音效
		PlaySound(TEXT("mus//start.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

		//初始化基本参数
		initData();

		//初始化动画
		setinitmode(INIT_ANIMATION);

		//绘制游戏面板
		initgraph(windowsWidth, windowsHight);

		//开始界面
		startInterface();

		//音效
		PlaySound(TEXT("mus//game.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

		//设置边界颜色
		setcolor(WHITE);
		//setfillcolor(BLUE);

		//初始化 brickInfo 数组
		initBrickInfo();

		//生成砖块
		createBrick();

		//生成随机种子
		srand((unsigned)time(NULL));

		//循环刷新屏幕
		Loop();

		if (1 == AGAIN){
			AGAIN = 0;
			goto again;
		}

		//关闭绘图设备
		closegraph();

	return 0;
}