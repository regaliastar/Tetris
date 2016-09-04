#include "gameData.h"
#include "gameFunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//��¼��ҵ÷�
 int grade;

//��Ϸ����ɷֽ�Ϊ 20*30 ������
 int brickInfo[21][31];

//�ж��Ƿ���Ҫ������ש��
 int drawBrick;

//���ڼ��������¼�
 key_msg keyCode;

//�ж��Ƿ�Ӧ�����һ��
 int flag;

//��ǰ��
 int rLine;

//�������ֲ�ͬ���͵�ש�飬Ĭ��Ϊ 3
 int brickType;

//������¼ʱ��
 int TIME;

 //�м��������û��ʲô����
 int temp;
 int tempTwo;
 int tempThree;
 int tempFour;

 int b[numberOfBrick][numberOfBrick];
 int tempArray[numberOfBrick][numberOfBrick];

//���������ש����Ϣ
 Brick brick[numberOfBrick];

 //������ʾ��ש����Ϣ
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

//����ʵ��ש��
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

//������
int main(){
	again:
		//��Ч
		PlaySound(TEXT("mus//start.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

		//��ʼ����������
		initData();

		//��ʼ������
		setinitmode(INIT_ANIMATION);

		//������Ϸ���
		initgraph(windowsWidth, windowsHight);

		//��ʼ����
		startInterface();

		//��Ч
		PlaySound(TEXT("mus//game.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

		//���ñ߽���ɫ
		setcolor(WHITE);
		//setfillcolor(BLUE);

		//��ʼ�� brickInfo ����
		initBrickInfo();

		//����ש��
		createBrick();

		//�����������
		srand((unsigned)time(NULL));

		//ѭ��ˢ����Ļ
		Loop();

		if (1 == AGAIN){
			AGAIN = 0;
			goto again;
		}

		//�رջ�ͼ�豸
		closegraph();

	return 0;
}