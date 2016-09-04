#ifndef _GAMEDATA_H
#define _GAMEDATA_H

#include <graphics.h>



//���߶�
const int windowsHight = 600 ;

//�����
const int windowsWidth = 600 ;

//������Ϸ����Ϊ400*600
const int windowsDevide = 400 ;
const int windowsLeft = 20;

//����ש��ߴ�Ϊ20
const int brickSize = 20;


const int initLeft = 200;
const int initTop = 20;

const int promptLeft = 470;
const int promptTop = 40;

//һ�����ĸ�Сש��ͬʱ����
const int  numberOfBrick  =  4;

//ש��Ľṹ��
typedef struct Brick{
	int left;
	int top;
	int right;
	int bottom;
	int mode;		//��¼ש�����״
};

//��ʾש��Ľṹ��
typedef struct Brick2{
int left;
int top;
int right;
int bottom;
int mode;		//��¼ש�����״
};

//��¼��ҵ÷�
extern int grade;

//��Ϸ����ɷֽ�Ϊ 20*30 ������
extern int brickInfo[21][31];

//�ж��Ƿ���Ҫ������ש��
extern int drawBrick;

//���ڼ��������¼�
extern key_msg keyCode;

//�ж��Ƿ�Ӧ�����һ��
extern int flag;

//��ǰ��
extern int rLine;

//�������ֲ�ͬ���͵�ש�飬Ĭ��Ϊ 3
extern int brickType;

//������¼ʱ��
extern int TIME;

//�м��������û��ʲô����
extern int temp;
extern int tempTwo;
extern int tempThree;
extern int tempFour;
extern int b[numberOfBrick][numberOfBrick];
extern int tempArray[numberOfBrick][numberOfBrick];

//���������ש����Ϣ
extern Brick brick[numberOfBrick];

//������ʾ��ש����Ϣ
extern Brick brick2[numberOfBrick];

//����ש���ģʽ
extern int bt1[numberOfBrick][numberOfBrick];
extern int bt2[numberOfBrick][numberOfBrick];
extern int bt3[numberOfBrick][numberOfBrick];
extern int bt4[numberOfBrick][numberOfBrick];

//��Ϸ����ɷֽ�Ϊ 20*30 ������
extern int brickInfo[21][31];

//��¼����ѭ��״̬�Ƿ񰴼�
extern int keyFlag;

//��¼��һ�������
extern int nextRandom;

//��¼����
extern char gradeString[5];

//��¼��ǰ����ʹ�÷����Ĵ���
extern int skillCounts;
extern char skillCountsString[100];



//��¼��һ�ο���ʹ�ü��ܵĴ���
extern int lastCounts;

extern int AGAIN;

extern int playerGrade[1000];

extern char playerGradeStringA[100];
extern char playerGradeStringB[100];
extern char playerGradeStringC[100];

#endif