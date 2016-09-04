#include"gameData.h"
#include"gameFunctions.h"
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<mmsystem.h>
#include<string.h>
#pragma comment(lib,"WINMM.LIB")

//����һ����������
MUSIC mus;

//ʵ�־����ת��
void transpose(int b[][numberOfBrick]){
	int t;
	for (int i = 0; i < numberOfBrick; i++)
		for (int j = i; j < numberOfBrick; j++){
			t = b[j][i];
			b[j][i] = b[i][j];
			b[i][j] = t;
		}

}


//ʵ�־������ת
void rotate(int b[][numberOfBrick]){
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++){
			//b[j][4-i+1] = b[i][j];
			tempArray[i][j] = b[4 - j - 1][i];
		}

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			b[i][j] = tempArray[i][j];
}


//�ڳ�ʼλ�ô��� brick[numberOfBrick]
void createBrick(){

	for (int i = 0; i < numberOfBrick; i++){
		brick[i] = { initLeft, initTop, initLeft + brickSize, initTop + brickSize, brickType };
		//setfillcolor(EGERGB(0xFF, 0x0, 0x80));
	}


	switch (brickType){
	case 1:
		for (int i = 0; i < numberOfBrick; i++){
			for (int j = 0; j < numberOfBrick; j++){
				if (bt1[i][j] == 1){
					brick[temp] = { initLeft + i*brickSize, initTop + j*brickSize, initLeft + brickSize + i*brickSize, initTop + brickSize + j*brickSize, brickType };
					temp++;
				}
				if (temp == 4) break;
			}
			if (temp == 4) break;
		}
		temp = 0;

		break;
	case 2:
		for (int i = 0; i < numberOfBrick; i++){
			for (int j = 0; j < numberOfBrick; j++){
				if (bt2[i][j] == 1){
					brick[temp] = { initLeft + i*brickSize, initTop + j*brickSize, initLeft + brickSize + i*brickSize, initTop + brickSize + j*brickSize, brickType };
					temp++;
				}
				if (temp == 4) break;
			}
			if (temp == 4) break;
		}
		temp = 0;

		break;
	case 3:
		for (int i = 0; i < numberOfBrick; i++){
			for (int j = 0; j < numberOfBrick; j++){
				if (bt3[i][j] == 1){
					brick[temp] = { initLeft + i*brickSize, initTop + j*brickSize, initLeft + brickSize + i*brickSize, initTop + brickSize + j*brickSize, brickType };
					temp++;
				}
				if (temp == 4) break;
			}
			if (temp == 4) break;
		}
		temp = 0;

		break;
	case 4:
		for (int i = 0; i < numberOfBrick; i++){
			for (int j = 0; j < numberOfBrick; j++){
				if (bt4[i][j] == 1){
					brick[temp] = { initLeft + i*brickSize, initTop + j*brickSize, initLeft + brickSize + i*brickSize, initTop + brickSize + j*brickSize, brickType };
					temp++;
				}
				if (temp == 4) break;
			}
			if (temp == 4) break;
		}
		temp = 0;

		break;
	default:
		break;
	}


}

////������ʾש��
void createPromptBrick(){
	for (int i = 0; i < numberOfBrick; i++){
		brick2[i] = { promptLeft, promptTop, promptLeft + brickSize, promptTop + brickSize, brickType };
	}


	switch (nextRandom){
	case 1:
		for (int i = 0; i < numberOfBrick; i++){
			for (int j = 0; j < numberOfBrick; j++){
				if (bt1[i][j] == 1){
					brick2[temp] = { promptLeft + i*brickSize, promptTop + j*brickSize, promptLeft + brickSize + i*brickSize, promptTop + brickSize + j*brickSize, brickType };
					temp++;
				}
				if (temp == 4) break;
			}
			if (temp == 4) break;
		}
		temp = 0;
		break;
	case 2:
		for (int i = 0; i < numberOfBrick; i++){
			for (int j = 0; j < numberOfBrick; j++){
				if (bt2[i][j] == 1){
					brick2[temp] = { promptLeft + i*brickSize, promptTop + j*brickSize, promptLeft + brickSize + i*brickSize, promptTop + brickSize + j*brickSize, brickType };
					temp++;
				}
				if (temp == 4) break;
			}
			if (temp == 4) break;
		}
		temp = 0;

		break;
	case 3:
		for (int i = 0; i < numberOfBrick; i++){
			for (int j = 0; j < numberOfBrick; j++){
				if (bt3[i][j] == 1){
					brick2[temp] = { promptLeft + i*brickSize, promptTop + j*brickSize, promptLeft + brickSize + i*brickSize, promptTop + brickSize + j*brickSize, brickType };
					temp++;
				}
				if (temp == 4) break;
			}
			if (temp == 4) break;
		}
		temp = 0;

		break;
	case 4:
		for (int i = 0; i < numberOfBrick; i++){
			for (int j = 0; j < numberOfBrick; j++){
				if (bt4[i][j] == 1){
					brick2[temp] = { promptLeft + i*brickSize, promptTop + j*brickSize, promptLeft + brickSize + i*brickSize, promptTop + brickSize + j*brickSize, brickType };
					temp++;
				}
				if (temp == 4) break;
			}
			if (temp == 4) break;
		}
		temp = 0;

		break;
	default:
		break;
	}
}

//ש�����
void deformed(){


	switch (brickType){

	case 1:
		//transpose(bt1);
		rotate(bt1);
		for (int j = 0; j < numberOfBrick; j++){
			b[j][1] = brick[j].left;
			b[j][2] = brick[j].top;
			b[j][3] = brick[j].right;
			b[j][4] = brick[j].bottom;
		}

		for (int i = 0; i < numberOfBrick; i++){
			for (int j = 0; j < numberOfBrick; j++){
				if (bt1[i][j] == 1){
					if (!tempTwo){
						tempThree = brick[0].left;
						tempFour = brick[0].top;
						tempTwo++;
					}

					brick[temp] = { tempThree + i*brickSize, tempFour + j*brickSize, tempThree + brickSize + i*brickSize, tempFour + brickSize + j*brickSize, brickType };
					temp++;

				}
				if (temp == 4){
					tempTwo = 0;
					break;
				}
			}
			if (temp == 4) break;
		}
		temp = 0;

		//������͵�ש��ÿ����һ�λ������ƶ�һ�񣬹���Ҫ������������ƽ��һ��
		for (int i = 0; i < numberOfBrick; i++){
			brick[i].left = brick[i].left - brickSize * 2;
			brick[i].right = brick[i].right - brickSize * 2;
		}

		//���ש��Ῠ��ǽ���bug



		while (true)
		{
			flag = 1;
			//temp = 0;
			//temp++;


			for (int i = 0; i < numberOfBrick; i++){


				if (brickInfo[brick[i].right / 20 - 1][brick[i].bottom / 20] == 1){

					flag = 0;
					if (temp <= 2){
						temp++;
						for (int j = 0; j < numberOfBrick; j++){
							brick[j].left = brick[j].left + brickSize;
							brick[j].right = brick[j].right + brickSize;
						}	//�ڲ�for

					}
					else{
						temp++;
						for (int j = 0; j < numberOfBrick; j++){
							brick[j].left = brick[j].left - brickSize;
							brick[j].right = brick[j].right - brickSize;
						}	//�ڲ�for

					}	//else

				}	//if

				if (temp >= 5){
					for (int j = 0; j < numberOfBrick; j++){
						brick[j].left = b[j][1];
						brick[j].top = b[j][2];
						brick[j].right = b[j][3];
						brick[j].bottom = b[j][4];
					}
					flag = 1;
					break;
				}	//if

			}	//���for


			if (flag == 1){
				flag = 0;
				temp = 0;
				break;
			}

		}	//while

		//�� ������������bug
		while (true)
		{

			flag = 1;
			for (int j = 0; j < numberOfBrick; j++){
				if (brickInfo[brick[j].right / 20 - 1][brick[j].bottom / 20 + 1] == 1){
					flag = 0;
					for (int i = 0; i < numberOfBrick; i++){
						brick[i].top = brick[i].top - brickSize;
						brick[i].bottom = brick[i].bottom - brickSize;
					}

				}	//if
			}	//for

			if (flag == 1){
				flag = 0;
				break;
			}
		}	//while


		break;
	case 2:
		//transpose(bt2);
		//rotate(bt2);
		for (int j = 0; j < numberOfBrick; j++){
			b[j][1] = brick[j].left;
			b[j][2] = brick[j].top;
			b[j][3] = brick[j].right;
			b[j][4] = brick[j].bottom;
		}

		for (int i = 0; i < numberOfBrick; i++){
			for (int j = 0; j < numberOfBrick; j++){
				if (bt2[i][j] == 1){
					if (!tempTwo){
						tempThree = brick[0].left;
						tempFour = brick[0].top;
						tempTwo++;
					}

					brick[temp] = { tempThree + i*brickSize, tempFour + j*brickSize, tempThree + brickSize + i*brickSize, tempFour + brickSize + j*brickSize, brickType };
					temp++;

				}
				if (temp == 4){
					tempTwo = 0;
					break;
				}
			}
			if (temp == 4) break;
		}
		temp = 0;

		//���ש��Ῠ��ǽ���bug



		while (true)
		{
			flag = 1;
			//temp = 0;
			//temp++;


			for (int i = 0; i < numberOfBrick; i++){


				if (brickInfo[brick[i].right / 20 - 1][brick[i].bottom / 20] == 1){

					flag = 0;
					if (temp <= 3){
						temp++;
						for (int j = 0; j < numberOfBrick; j++){
							brick[j].left = brick[j].left - brickSize;
							brick[j].right = brick[j].right - brickSize;
						}	//�ڲ�for

					}
					else{
						temp++;
						for (int j = 0; j < numberOfBrick; j++){
							brick[j].left = brick[j].left + brickSize;
							brick[j].right = brick[j].right + brickSize;
						}	//�ڲ�for

					}	//else

				}	//if

				if (temp >= 6){
					for (int j = 0; j < numberOfBrick; j++){
						brick[j].left = b[j][1];
						brick[j].top = b[j][2];
						brick[j].right = b[j][3];
						brick[j].bottom = b[j][4];
					}
					flag = 1;
					break;
				}	//if

			}	//���for


			if (flag == 1){
				flag = 0;
				temp = 0;
				break;
			}

		}	//while

		//�� ������������bug
		while (true)
		{

			flag = 1;
			for (int j = 0; j < numberOfBrick; j++){
				if (brickInfo[brick[j].right / 20 - 1][brick[j].bottom / 20 + 1] == 1){
					flag = 0;
					for (int i = 0; i < numberOfBrick; i++){
						brick[i].top = brick[i].top - brickSize;
						brick[i].bottom = brick[i].bottom - brickSize;
					}


				}	//if
			}	//for

			if (flag == 1){
				flag = 0;
				break;
			}
		}	//while
		break;
	case 3:

		for (int j = 0; j < numberOfBrick; j++){
			b[j][1] = brick[j].left;
			b[j][2] = brick[j].top;
			b[j][3] = brick[j].right;
			b[j][4] = brick[j].bottom;
		}

		transpose(bt3);
		//rotate(bt3);

		for (int i = 0; i < numberOfBrick; i++){
			for (int j = 0; j < numberOfBrick; j++){
				if (bt3[i][j] == 1){
					if (!tempTwo){
						tempThree = brick[0].left;
						tempFour = brick[0].top;
						tempTwo++;
					}

					brick[temp] = { tempThree + i*brickSize, tempFour + j*brickSize, tempThree + brickSize + i*brickSize, tempFour + brickSize + j*brickSize, brickType };
					temp++;

				}
				if (temp == 4){
					tempTwo = 0;
					break;
				}
			}
			if (temp == 4) break;
		}
		temp = 0;

		//��ש��ÿ����һ�Σ�����λ�� 1����λ


		//���ש��Ῠ��ǽ���bug



		while (true)
		{
			flag = 1;
			//temp = 0;
			//temp++;


			for (int i = 0; i < numberOfBrick; i++){


				if (brickInfo[brick[i].right / 20 - 1][brick[i].bottom / 20] == 1){

					flag = 0;
					temp++;

					if (temp <= 3){

						for (int j = 0; j < numberOfBrick; j++){
							brick[j].left = brick[j].left - brickSize;
							brick[j].right = brick[j].right - brickSize;
						}	//�ڲ�for

					}
					else{

						for (int j = 0; j < numberOfBrick; j++){
							brick[j].left = brick[j].left + brickSize;
							brick[j].right = brick[j].right + brickSize;
						}	//�ڲ�for

					}	//else

				}	//if

				if (temp >= 6){
					for (int j = 0; j < numberOfBrick; j++){
						brick[j].left = b[j][1];
						brick[j].top = b[j][2];
						brick[j].right = b[j][3];
						brick[j].bottom = b[j][4];
					}
					flag = 1;
					break;
				}	//if

			}	//���for


			if (flag == 1){
				flag = 0;
				temp = 0;
				break;
			}

		}	//while


		//�� ������������bug
		while (true)
		{

			flag = 1;
			temp = 0;
			for (int j = 0; j < numberOfBrick; j++){
				if (brickInfo[brick[j].right / 20 - 1][brick[j].bottom / 20] == 1){
					flag = 0;
					for (int i = 0; i < numberOfBrick; i++){
						brick[i].top = brick[i].top - brickSize;
						brick[i].bottom = brick[i].bottom - brickSize;
					}
				}	//if
				temp++;
				if (temp > 4){
					break;
				}
			}	//���for

			if (flag == 1){
				flag = 0;
				temp = 0;
				break;
			}
		}	//while

		break;
	case 4:
		//transpose(bt4);
		rotate(bt4);

		for (int j = 0; j < numberOfBrick; j++){
			b[j][1] = brick[j].left;
			b[j][2] = brick[j].top;
			b[j][3] = brick[j].right;
			b[j][4] = brick[j].bottom;
		}


		for (int i = 0; i < numberOfBrick; i++){
			for (int j = 0; j < numberOfBrick; j++){
				if (bt4[i][j] == 1){
					if (!tempTwo){
						tempThree = brick[0].left;
						tempFour = brick[0].top;
						tempTwo++;
					}

					brick[temp] = { tempThree + i*brickSize, tempFour + j*brickSize, tempThree + brickSize + i*brickSize, tempFour + brickSize + j*brickSize, brickType };
					temp++;

				}
				if (temp == 4){
					tempTwo = 0;
					break;
				}
			}
			if (temp == 4) break;
		}
		temp = 0;

		//���ש��Ῠ��ǽ���bug

		while (true)
		{
			flag = 1;
			//temp = 0;
			//temp++;


			for (int i = 0; i < numberOfBrick; i++){


				if (brickInfo[brick[i].right / 20 - 1][brick[i].bottom / 20] == 1){

					flag = 0;
					if (temp <= 3){
						temp++;
						for (int j = 0; j < numberOfBrick; j++){
							brick[j].left = brick[j].left - brickSize;
							brick[j].right = brick[j].right - brickSize;
						}	//�ڲ�for

					}
					else{
						temp++;
						for (int j = 0; j < numberOfBrick; j++){
							brick[j].left = brick[j].left + brickSize;
							brick[j].right = brick[j].right + brickSize;
						}	//�ڲ�for

					}	//else

				}	//if

				if (temp >= 6){
					for (int j = 0; j < numberOfBrick; j++){
						brick[j].left = b[j][1];
						brick[j].top = b[j][2];
						brick[j].right = b[j][3];
						brick[j].bottom = b[j][4];
					}
					flag = 1;
					break;
				}	//if

			}	//���for


			if (flag == 1){
				flag = 0;
				temp = 0;
				break;
			}

		}	//while

		//�� ������������bug
		while (true)
		{

			flag = 1;
			for (int j = 0; j < numberOfBrick; j++){
				if (brickInfo[brick[j].right / 20 - 1][brick[j].bottom / 20 + 1] == 1){
					flag = 0;
					for (int i = 0; i < numberOfBrick; i++){
						brick[i].top = brick[i].top - brickSize;
						brick[i].bottom = brick[i].bottom - brickSize;
					}

				}	//if
			}	//for

			if (flag == 1){
				flag = 0;
				break;
			}
		}	//while

		break;
	default:
		break;

	}

}


//���ڼ��������¼�
void keyListener(){
	//���������¼�


	if (kbmsg()){

		keyCode = getkey();

		if (keyCode.key == key_left && keyCode.msg == key_msg_down){		//�� ��

			for (int i = 0; i < numberOfBrick; i++){
				brick[i].left = brick[i].left - brickSize;
				brick[i].right = brick[i].right - brickSize;


				/*if (brick[i].left <= brickSize){							//ʹש�鲻Խ��
				flag = 1;
				}*/
				if (brickInfo[brick[i].left / 20][brick[i].bottom / 20] == 1){
					flag = 1;
				}


			}	//for

			if (flag == 1){

				for (int j = 0; j < numberOfBrick; j++){
					brick[j].left = brick[j].left + brickSize;
					brick[j].right = brick[j].right + brickSize;
				}
				flag = 0;
			}

		}

		if (keyCode.key == key_right && keyCode.msg == key_msg_down){		//�� ��
			for (int i = 0; i < numberOfBrick; i++){
				brick[i].left = brick[i].left + brickSize;
				brick[i].right = brick[i].right + brickSize;



				/*if (brick[i].left <= brickSize){							//ʹש�鲻Խ��
				flag = 1;
				}*/
				if (brickInfo[brick[i].right / 20 - 1][brick[i].bottom / 20] == 1){
					flag = 1;
				}


			}	//for

			if (flag == 1){

				for (int j = 0; j < numberOfBrick; j++){
					brick[j].left = brick[j].left - brickSize;
					brick[j].right = brick[j].right - brickSize;
				}
				flag = 0;
			}

		}

		if (keyCode.key == 38 && keyCode.msg == key_msg_down){		//�� ��
			deformed();

		}

		if (keyCode.key == key_down && keyCode.msg == key_msg_down){		//�� ��
			keyFlag = 1;
			for (int i = 0; i < numberOfBrick; i++){

				brick[i].top = brick[i].top + brickSize;

				brick[i].bottom = brick[i].bottom + brickSize;

			}


		}

		if (keyCode.key == key_space && keyCode.msg == key_msg_down){		//�� �ո� ʹ�ü���
			if (skillCounts > 0){
				if (4 == nextRandom){
					nextRandom = 1;
				}
				else
				{
					nextRandom++;
				}
				skillCounts--;
			}
			
		
		}	//if (keyCode.key == key_space && keyCode.msg == key_msg_down)

		if (keyCode.key == key_0 && keyCode.msg == key_msg_down){		//�� 0 ��ͣ�� �� ������ ����
			while (getch() == '0');
		}

	}

}


//�ж�ש���Ƿ���أ�����أ�����һ��

void checkBrick(){
	//�ж�ש���Ƿ����
	for (int i = 0; i < numberOfBrick; i++){
		if (brickInfo[brick[i].right / brickSize - 1][brick[i].bottom / brickSize] == 1 && brick[i].bottom % 20 == 0){		//�����أ����� brickInfo ����Ϣ������ʼ�� brick

			for (int j = 0; j < numberOfBrick; j++){	//��¼��ص�ש����Ϣ
				brickInfo[brick[j].right / brickSize - 1][brick[j].bottom / brickSize - 1] = 1;
			}

			drawBrick = 1;
		}
		if (drawBrick == 1) break;
	}

	//����أ���ʼ��ש��
	if (drawBrick == 1){

		brickType = nextRandom;
		nextRandom = rand() % 4 + 1;

		createBrick();
		
		//brickType = random;
		drawBrick = 0;
	}

	//�ж���Ϸ�Ƿ����
	for (int i = 1; i < 19; i++){
		if (brickInfo[i][1] == 1){
			
			cleardevice();
			List();
			//��������
			endInterface();
			if (1 == AGAIN) break;
		}
	}

	//�ж��Ƿ������һ��
	for (int j = 1; j < 30; j++){
		if (1 == AGAIN)	break;

		for (int i = 1; i < 20; i++){
			if (brickInfo[i][j] != 1){
				flag = 0;		//�ǳ���Ҫ��
				break;
			}
			flag = 1;
		}	//�ڲ�for
		if (flag == 1){
			rLine = j;
			break;
		}
	}	//���for

	if (1 == flag){			//��������һ��
		//�������
		int num = 1;

		for (int j = 1; j <= 20; j++){
			if (j == 20){
				num++;
				break;
			}
			if (brickInfo[j][rLine - 1] == 1){
				continue;
			}
			else
			{
				break;
			}
		}
		grade += 40 * num * num;	//˵�����������һ�У��ӷ�40��	���У��ӷ�200��	���У��ӷ�360��	���У��ӷ�520��
		sprintf(gradeString, "%d", grade);


		for (int i = 1; i < 20; i++){
			brickInfo[i][rLine] = 0;
			//drawBrickInfo();
			//mus.OpenFile("mus//bonus.wav");
			//mus.Play();
			//PlaySound(TEXT("mus//bonus.wav"), NULL, SND_FILENAME | SND_ASYNC |SND_NOSTOP);
			//PlaySound(TEXT("mus//game.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		}

		//�ж��Ƿ������һ�в���ʼ��Ч
		if (brickInfo[flag][rLine] == 0){
			mus.OpenFile("mus//bonus.wav");
			mus.Play();
			flag = 0;
		}

		for (; rLine > 1; rLine--)
			for (int i = 1; i < 20; i++)
				brickInfo[i][rLine] = brickInfo[i][rLine - 1];

		flag = 0;
	}	//if (1 == flag)
}


//���� brickInfo ����ש����Ϣ
void drawBrickInfo(){
	
	for (int i = 1; i < 20; i++)
		for (int j = 1; j < 31; j++)
			if (brickInfo[i][j] == 1){
				rectangle(i*brickSize, j*brickSize, (i + 1)*brickSize, (j + 1)*brickSize);
				floodfill(i*brickSize + 1, j*brickSize + 1, WHITE);
				/*if (brickType == 1){
					setfillcolor(EGERGB(0xFF, 0x0, 0x0));
				}*/
				//setfillcolor(EGERGB(0xFF, 0x0, 0x80));
			}
			
}


//ש���ƶ�
void brickMove(){

	if (TIME % 45 == 0){
		for (int i = 0; i < numberOfBrick; i++){
			brick[i].top = brick[i].top + brickSize;
			brick[i].bottom = brick[i].bottom + brickSize;
		}
	}
}


//ѭ��ˢ����Ļ
void Loop(){
	//ѭ������ͼ�Σ��ﵽ��̬Ч��
	for (; is_run(); delay_fps(60)){

		//����
		cleardevice();

		TIME++;
		if (TIME >= 9999)  TIME = 0;

		//������Ϸ������
		line(windowsDevide, 0, windowsDevide, windowsHight);
		line(windowsLeft, 0, windowsLeft, windowsHight);
	
		//��Ϸ����
		gameInterface();

		//����ש��
		for (int i = 0; i < numberOfBrick; i++){
			rectangle(brick[i].left, brick[i].top, brick[i].right, brick[i].bottom);
		}

		//�Ʒ�ϵͳ
		lastCounts = grade / 50;

		//��Ӽ�����Ӧ��ͬʱʵ�ֱ߽���ײ�ж�
		keyListener();

		//ש���ƶ�
		if (keyFlag == 0){
			brickMove();
		}
		else{
			keyFlag = 0;
		}

		//���� brickInfo ����ש����Ϣ
		drawBrickInfo();

		//�ж�ש���Ƿ���أ�����أ�����һ��
		checkBrick();

		if (1 == AGAIN){
			break;
		}

		//������Ȼ����
		if (0 == TIME % 30){
			grade++;
			sprintf(gradeString, "%d", grade);
		}
		
		skillCounts += grade / 50 - lastCounts;
		sprintf(skillCountsString, "%d", skillCounts);
	
	}	//forѭ����������Ϸ�˳�

}


void List(){
	FILE *fp1;
	FILE *fp2;
	int g;
	int i = 0;
	char gs[5];
	char ch = 'w';

	sprintf(gs, "%d%c", grade, ch);

	if ((fp1 = fopen("test.txt", "a+")) == NULL){
		printf("fp1�ļ���ʧ��");

	}

	fseek(fp1, 0, SEEK_END);
	fwrite(gs, strlen(gs), 1, fp1);

	fclose(fp1);

	if ((fp2 = fopen("test.txt", "r")) == NULL){
		printf("fp2�ļ���ʧ��");
	}

	while (!feof(fp2)){
		fscanf(fp2, "%dw", &g);
		playerGrade[i] = g;
		i++;
	}

	for (int m = 0; m < i - 1; m++)
		for (int n = m; n < i - 1; n++){
			if (playerGrade[m] < playerGrade[n]){
				g = playerGrade[m];
				playerGrade[m] = playerGrade[n];
				playerGrade[n] = g;
			}
		}
	int a = playerGrade[0];
	int b = playerGrade[1];
	int c = playerGrade[2];
	sprintf(playerGradeStringA, "%d", a);
	sprintf(playerGradeStringB, "%d", b);
	sprintf(playerGradeStringC, "%d", c);
	fclose(fp2);
}