#include "gameData.h"

//��ʼ����������
void initData(){

	//��Ϸ����ɷֽ�Ϊ 20*30 ������
	brickInfo[21][31] = { 0 };

	//���ڼ��������¼�
	keyCode = { 0 };

	//�������ֲ�ͬ���͵�ש�飬Ĭ��Ϊ 3
	brickType = 3;

	//������¼ʱ��
	TIME = 0;

	//�м��������û��ʲô����
	temp = 0;
	tempTwo = 0;
	tempThree = 0;
	tempFour = 0;
	b[numberOfBrick][numberOfBrick] = { 0 };
	tempArray[numberOfBrick][numberOfBrick] = { 0 };

	//��ʼ�� drawBrick
	drawBrick = 0;					
	//��ʼ�� flag
	flag = 0;						
	//��ʼ�� rLine
	rLine = 0;			
	//��ʼ��keyFlag
	keyFlag = 0;
	//��ʼ��nextRandom
	nextRandom = rand() % 4 + 1;	
	//��ʼ��skillCounts
	skillCounts = 0;

	lastCounts = 0;

	AGAIN = 0;

	memset(playerGrade, 0, sizeof(playerGrade));
}


//��ʼ��brickInfo
void initBrickInfo(){
	for (int i = 0; i < 21; i++)
		for (int j = 0; j < 31; j++)
			if (i == 0 || i == 20 || j == 0 || j == 30)
				brickInfo[i][j] = 1;

}


