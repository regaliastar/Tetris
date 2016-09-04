#ifndef _GAMEFUNCTIONS_H
#define _GAMEFUNCTIONS_H

#include "gameData.h"

//��ʼ����������
void initData();

//��ʼ��brickInfo
void initBrickInfo();

//ʵ�־����ת��
void transpose(int b[][numberOfBrick]);

//ʵ�־������ת
void rotate(int b[][numberOfBrick]);

//�ڳ�ʼλ�ô��� brick[numberOfBrick]
void createBrick();

//������ʾש��
void createPromptBrick();

//ש�����
void deformed();

//��Ӽ�����Ӧ��ͬʱʵ�ֱ߽���ײ�ж�
void keyListener();

//�ж�ש���Ƿ���أ�����أ�����һ��
void checkBrick();

//ש���ƶ�
void brickMove();

//���� brickInfo ����ש����Ϣ
void drawBrickInfo();

//��ʼ����
int startInterface();

//��Ϸ����
int gameInterface();

//��������
int endInterface(); 

//ѭ��ˢ����Ļ
void Loop();

void List();

#endif // !_GAMEFUNCTIONS_H
