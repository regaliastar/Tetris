#ifndef _GAMEFUNCTIONS_H
#define _GAMEFUNCTIONS_H

#include "gameData.h"

//初始化基本参数
void initData();

//初始化brickInfo
void initBrickInfo();

//实现矩阵的转置
void transpose(int b[][numberOfBrick]);

//实现矩阵的旋转
void rotate(int b[][numberOfBrick]);

//在初始位置创造 brick[numberOfBrick]
void createBrick();

//创造提示砖块
void createPromptBrick();

//砖块变形
void deformed();

//添加键盘响应，同时实现边界碰撞判定
void keyListener();

//判断砖块是否落地，若落地，消除一行
void checkBrick();

//砖块移动
void brickMove();

//根据 brickInfo 绘制砖块信息
void drawBrickInfo();

//开始界面
int startInterface();

//游戏界面
int gameInterface();

//结束界面
int endInterface(); 

//循环刷新屏幕
void Loop();

void List();

#endif // !_GAMEFUNCTIONS_H
