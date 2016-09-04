#ifndef _GAMEDATA_H
#define _GAMEDATA_H

#include <graphics.h>



//面板高度
const int windowsHight = 600 ;

//面板宽度
const int windowsWidth = 600 ;

//控制游戏区域为400*600
const int windowsDevide = 400 ;
const int windowsLeft = 20;

//控制砖块尺寸为20
const int brickSize = 20;


const int initLeft = 200;
const int initTop = 20;

const int promptLeft = 470;
const int promptTop = 40;

//一次有四个小砖块同时下落
const int  numberOfBrick  =  4;

//砖块的结构体
typedef struct Brick{
	int left;
	int top;
	int right;
	int bottom;
	int mode;		//记录砖块的形状
};

//提示砖块的结构体
typedef struct Brick2{
int left;
int top;
int right;
int bottom;
int mode;		//记录砖块的形状
};

//记录玩家得分
extern int grade;

//游戏界面可分解为 20*30 个格子
extern int brickInfo[21][31];

//判断是否需要生成新砖块
extern int drawBrick;

//用于监听键盘事件
extern key_msg keyCode;

//判断是否应该清除一行
extern int flag;

//当前行
extern int rLine;

//代表四种不同类型的砖块，默认为 3
extern int brickType;

//用来记录时间
extern int TIME;

//中间变量，并没有什么意义
extern int temp;
extern int tempTwo;
extern int tempThree;
extern int tempFour;
extern int b[numberOfBrick][numberOfBrick];
extern int tempArray[numberOfBrick][numberOfBrick];

//储存下落的砖块信息
extern Brick brick[numberOfBrick];

//储存提示的砖块信息
extern Brick brick2[numberOfBrick];

//储存砖块的模式
extern int bt1[numberOfBrick][numberOfBrick];
extern int bt2[numberOfBrick][numberOfBrick];
extern int bt3[numberOfBrick][numberOfBrick];
extern int bt4[numberOfBrick][numberOfBrick];

//游戏界面可分解为 20*30 个格子
extern int brickInfo[21][31];

//记录本次循环状态是否按键
extern int keyFlag;

//记录下一个随机数
extern int nextRandom;

//记录分数
extern char gradeString[5];

//记录当前可以使用分数的次数
extern int skillCounts;
extern char skillCountsString[100];



//记录上一次可以使用技能的次数
extern int lastCounts;

extern int AGAIN;

extern int playerGrade[1000];

extern char playerGradeStringA[100];
extern char playerGradeStringB[100];
extern char playerGradeStringC[100];

#endif