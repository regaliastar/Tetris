#include"gameData.h"
#include"gameFunctions.h"
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<mmsystem.h>
#include<string.h>
#pragma comment(lib,"WINMM.LIB")

//声明一个声音对象
MUSIC mus;

//实现矩阵的转置
void transpose(int b[][numberOfBrick]){
	int t;
	for (int i = 0; i < numberOfBrick; i++)
		for (int j = i; j < numberOfBrick; j++){
			t = b[j][i];
			b[j][i] = b[i][j];
			b[i][j] = t;
		}

}


//实现矩阵的旋转
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


//在初始位置创造 brick[numberOfBrick]
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

////创造提示砖块
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

//砖块变形
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

		//这个类型的砖块每变形一次会往→移动一格，故需要将其整体往←平移一格
		for (int i = 0; i < numberOfBrick; i++){
			brick[i].left = brick[i].left - brickSize * 2;
			brick[i].right = brick[i].right - brickSize * 2;
		}

		//解决砖块会卡在墙里的bug



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
						}	//内层for

					}
					else{
						temp++;
						for (int j = 0; j < numberOfBrick; j++){
							brick[j].left = brick[j].left - brickSize;
							brick[j].right = brick[j].right - brickSize;
						}	//内层for

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

			}	//外层for


			if (flag == 1){
				flag = 0;
				temp = 0;
				break;
			}

		}	//while

		//该 语句解决卡下面的bug
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

		//解决砖块会卡在墙里的bug



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
						}	//内层for

					}
					else{
						temp++;
						for (int j = 0; j < numberOfBrick; j++){
							brick[j].left = brick[j].left + brickSize;
							brick[j].right = brick[j].right + brickSize;
						}	//内层for

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

			}	//外层for


			if (flag == 1){
				flag = 0;
				temp = 0;
				break;
			}

		}	//while

		//该 语句解决卡下面的bug
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

		//该砖块每变形一次，向上位移 1个单位


		//解决砖块会卡在墙里的bug



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
						}	//内层for

					}
					else{

						for (int j = 0; j < numberOfBrick; j++){
							brick[j].left = brick[j].left + brickSize;
							brick[j].right = brick[j].right + brickSize;
						}	//内层for

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

			}	//外层for


			if (flag == 1){
				flag = 0;
				temp = 0;
				break;
			}

		}	//while


		//该 语句解决卡下面的bug
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
			}	//外层for

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

		//解决砖块会卡在墙里的bug

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
						}	//内层for

					}
					else{
						temp++;
						for (int j = 0; j < numberOfBrick; j++){
							brick[j].left = brick[j].left + brickSize;
							brick[j].right = brick[j].right + brickSize;
						}	//内层for

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

			}	//外层for


			if (flag == 1){
				flag = 0;
				temp = 0;
				break;
			}

		}	//while

		//该 语句解决卡下面的bug
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


//用于监听键盘事件
void keyListener(){
	//监听键盘事件


	if (kbmsg()){

		keyCode = getkey();

		if (keyCode.key == key_left && keyCode.msg == key_msg_down){		//按 ←

			for (int i = 0; i < numberOfBrick; i++){
				brick[i].left = brick[i].left - brickSize;
				brick[i].right = brick[i].right - brickSize;


				/*if (brick[i].left <= brickSize){							//使砖块不越界
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

		if (keyCode.key == key_right && keyCode.msg == key_msg_down){		//按 →
			for (int i = 0; i < numberOfBrick; i++){
				brick[i].left = brick[i].left + brickSize;
				brick[i].right = brick[i].right + brickSize;



				/*if (brick[i].left <= brickSize){							//使砖块不越界
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

		if (keyCode.key == 38 && keyCode.msg == key_msg_down){		//按 ↑
			deformed();

		}

		if (keyCode.key == key_down && keyCode.msg == key_msg_down){		//按 ↓
			keyFlag = 1;
			for (int i = 0; i < numberOfBrick; i++){

				brick[i].top = brick[i].top + brickSize;

				brick[i].bottom = brick[i].bottom + brickSize;

			}


		}

		if (keyCode.key == key_space && keyCode.msg == key_msg_down){		//按 空格 使用技能
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

		if (keyCode.key == key_0 && keyCode.msg == key_msg_down){		//按 0 暂停； 按 其他键 继续
			while (getch() == '0');
		}

	}

}


//判断砖块是否落地，若落地，消除一行

void checkBrick(){
	//判断砖块是否落地
	for (int i = 0; i < numberOfBrick; i++){
		if (brickInfo[brick[i].right / brickSize - 1][brick[i].bottom / brickSize] == 1 && brick[i].bottom % 20 == 0){		//如果落地，更新 brickInfo 的信息，并初始化 brick

			for (int j = 0; j < numberOfBrick; j++){	//记录落地的砖块信息
				brickInfo[brick[j].right / brickSize - 1][brick[j].bottom / brickSize - 1] = 1;
			}

			drawBrick = 1;
		}
		if (drawBrick == 1) break;
	}

	//若落地，初始化砖块
	if (drawBrick == 1){

		brickType = nextRandom;
		nextRandom = rand() % 4 + 1;

		createBrick();
		
		//brickType = random;
		drawBrick = 0;
	}

	//判断游戏是否结束
	for (int i = 1; i < 19; i++){
		if (brickInfo[i][1] == 1){
			
			cleardevice();
			List();
			//结束界面
			endInterface();
			if (1 == AGAIN) break;
		}
	}

	//判断是否该消除一行
	for (int j = 1; j < 30; j++){
		if (1 == AGAIN)	break;

		for (int i = 1; i < 20; i++){
			if (brickInfo[i][j] != 1){
				flag = 0;		//非常重要！
				break;
			}
			flag = 1;
		}	//内层for
		if (flag == 1){
			rLine = j;
			break;
		}
	}	//外层for

	if (1 == flag){			//如果该清除一行
		//计算分数
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
		grade += 40 * num * num;	//说明：如果消除一行，加分40；	两行，加分200；	三行，加分360；	四行，加分520；
		sprintf(gradeString, "%d", grade);


		for (int i = 1; i < 20; i++){
			brickInfo[i][rLine] = 0;
			//drawBrickInfo();
			//mus.OpenFile("mus//bonus.wav");
			//mus.Play();
			//PlaySound(TEXT("mus//bonus.wav"), NULL, SND_FILENAME | SND_ASYNC |SND_NOSTOP);
			//PlaySound(TEXT("mus//game.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		}

		//判断是否已清除一行并开始音效
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


//根据 brickInfo 绘制砖块信息
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


//砖块移动
void brickMove(){

	if (TIME % 45 == 0){
		for (int i = 0; i < numberOfBrick; i++){
			brick[i].top = brick[i].top + brickSize;
			brick[i].bottom = brick[i].bottom + brickSize;
		}
	}
}


//循环刷新屏幕
void Loop(){
	//循环绘制图形，达到动态效果
	for (; is_run(); delay_fps(60)){

		//清屏
		cleardevice();

		TIME++;
		if (TIME >= 9999)  TIME = 0;

		//绘制游戏区域线
		line(windowsDevide, 0, windowsDevide, windowsHight);
		line(windowsLeft, 0, windowsLeft, windowsHight);
	
		//游戏界面
		gameInterface();

		//绘制砖块
		for (int i = 0; i < numberOfBrick; i++){
			rectangle(brick[i].left, brick[i].top, brick[i].right, brick[i].bottom);
		}

		//计分系统
		lastCounts = grade / 50;

		//添加键盘响应，同时实现边界碰撞判定
		keyListener();

		//砖块移动
		if (keyFlag == 0){
			brickMove();
		}
		else{
			keyFlag = 0;
		}

		//根据 brickInfo 绘制砖块信息
		drawBrickInfo();

		//判断砖块是否落地，若落地，消除一行
		checkBrick();

		if (1 == AGAIN){
			break;
		}

		//分数自然增长
		if (0 == TIME % 30){
			grade++;
			sprintf(gradeString, "%d", grade);
		}
		
		skillCounts += grade / 50 - lastCounts;
		sprintf(skillCountsString, "%d", skillCounts);
	
	}	//for循环结束，游戏退出

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
		printf("fp1文件打开失败");

	}

	fseek(fp1, 0, SEEK_END);
	fwrite(gs, strlen(gs), 1, fp1);

	fclose(fp1);

	if ((fp2 = fopen("test.txt", "r")) == NULL){
		printf("fp2文件打开失败");
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