#include"gameFunctions.h"
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<windows.h>
#include<mmsystem.h>
#pragma comment(lib,"WINMM.LIB")

//���ڼ�������¼�
mouse_msg msg;

//������������
char str[100];

//����ͼƬ����
PIMAGE img;
PIMAGE img2;

//��ʼ����
int startInterface(){

	for (; is_run(); delay_fps(60)){

		//��ȡ�����Ϣ
		while (mousemsg()){
			msg = getmouse();
		}

		//����ͼƬ����
		img = newimage();

		//��ͼƬ���浽getimage
		getimage(img, "img//start.jpg");

		//����ͼƬ
		putimage(1, 1, img);

		//������ɫ
		setcolor(EGERGB(0xFF, 0x0, 0x80));

		//��������
		setfont(36, 20, "����");

		//д����
		outtextxy(200, 100, "����˹����");

		//��������
		setfont(20, 10, "����");

		//д����
		outtextxy(255, 300, "��ʼ��Ϸ");

		//�������ֱ�����䷽ʽΪ͸����Ĭ��ΪOPAQUE��͸��
		setbkmode(TRANSPARENT);

		//settextjustify(LEFT_TEXT, TOP_TEXT); //Ĭ��ֵ
		settextjustify(LEFT_TEXT, TOP_TEXT);
		outtextxy(255, 350, "�˳���Ϸ");

		//�ж��Ƿ������Ϸ
		if ((int)msg.is_left() == 1 && (msg.x >= 255 && msg.x <= 335) && (msg.y >= 300 && msg.y <= 320)){

			//����
			cleardevice();

			//�����û���
			//���öԻ�����
			while (1){
				inputbox_getline("�������û���", "��������һ���û������س�ȷ�ϣ�", str, 100);
				if (str[0] == '\0'){
					setcolor(EGERGB(0x80, 0x80, 0x80));
					outtextxy(0, 0, "�û�������Ϊ��,����������");
				}
				else{
					return 0;
				}
			}
		}

		//�ж��Ƿ��˳�
		else if ((int)msg.is_left() == 1 && (msg.x >= 255 && msg.x <= 335) && (msg.y >= 350 && msg.y <= 370)){
			exit(0);
		}

		//ɾ������
		delimage(img);

	}
	return 0;
}

//��Ϸ����
int gameInterface(){

	if (brickType == 1){
		setfillcolor(EGERGB(0xFF, 0x0, 0x0));
	}
	else if (brickType == 2){
		setfillcolor(EGERGB(0x80, 0x0, 0x80));
	}
	else if (brickType == 3){
		setfillcolor(EGERGB(0x0, 0x0, 0xFF));
	}
	else {
		setfillcolor(EGERGB(0x0, 0x40, 0x80));
	}

	//����ͼƬ����
	img = newimage();

	//��ͼƬ���浽getimage
	getimage(img, "img//game.jpg");

	//����ͼƬ
	putimage(1, 1, img);

	//��ʾ��һ��ש��
	//����
	/*line(420, 20, 580, 20);
	line(420, 20, 420, 200);
	line(580, 20, 580, 200);
	line(420, 200, 580, 200);*/
	rectangle(420, 20, 580, 120);

	//������ʾש��
	createPromptBrick();

	//������ʾש��
	for (int i = 0; i < numberOfBrick; i++){
		rectangle(brick2[i].left, brick2[i].top, brick2[i].right, brick2[i].bottom);
	}

	//�����Ϣ
	//����
	/*line(420, 210, 580, 210);
	line(420, 210, 420, 360);
	line(580, 210, 580, 360);
	line(420, 360, 580, 360);*/
	rectangle(420, 130, 580, 330);

	//��������
	setfont(20, 0, "����");

	//д����
	outtextxy(440, 140, "�û���:");

	//д����
	outtextxy(440, 170, str);

	//д����
	outtextxy(440, 200, "����:");

	//д����
	outtextxy(440, 230, gradeString);

	//д����
	outtextxy(440, 260, "���ܣ�");

	//д����
	outtextxy(440, 290, skillCountsString);

	//��Ϸ˵��
	//����
	/*line(420, 370, 580, 370);
	line(420, 370, 420, 530);
	line(580, 370, 580, 530);
	line(420, 530, 580, 530);*/
	rectangle(420, 340, 580, 530);

	//д����
	outtextxy(440, 350, "�� �������ƶ�");

	//д����
	outtextxy(440, 380, "������");

	//д����
	outtextxy(440, 410, "����������");

	//д����
	outtextxy(440, 440, "�ո��ʹ�ü���");

	//д����
	outtextxy(440, 470, "0����ͣ��Ϸ");

	//д����
	outtextxy(440, 500, "�����������Ϸ");

	//�汾������
	//��������
	setfont(10, 5, "����");

	//д����
	outtextxy(460, 550, "����˹����2.0��");

	//д����
	outtextxy(480, 570, "Group3");

	//ɾ������
	delimage(img);

	return 0;
}

//��������
int endInterface(){

	//��Ч
	PlaySound(TEXT("mus//end.wav"), NULL, SND_FILENAME | SND_ASYNC);

	//ѭ���������
	for (; is_run(); delay_fps(60)){

		//��ȡ�����Ϣ
		while (mousemsg()){
			msg = getmouse();
		}

		//����ͼƬ����
		img = newimage();

		//��ͼƬ���浽getimage
		getimage(img, "img//rank.jpg");

		//����ͼƬ
		putimage(1, 1, img);

		//����ͼƬ����
		img2 = newimage();

		//��ͼƬ���浽getimage
		getimage(img2, "img//end.jpg");

		//����ͼƬ
		putimage(80, 400, img2);

		//������
		setfont(20, 0, "����");
		setcolor(WHITE);

		//д����
		outtextxy(500, 400, "EXIT");
		outtextxy(500, 460, "AGAIN");
		
		//������ɫ
		setcolor(EGERGB(0xFF, 0x0, 0x0));
		
		//��������
		setfont(40, 0, "����");

		//д����
		outtextxy(270, 40, "RANK");

		//������
		setfont(20, 0, "����");

		//д����
		outtextxy(100, 80, "��һ��");
		outtextxy(200, 80, playerGradeStringA);
		outtextxy(100, 140, "�ڶ���");
		outtextxy(200, 140, playerGradeStringB);
		outtextxy(100, 200, "������");
		outtextxy(200, 200, playerGradeStringC);
		
		//������
		setfont(40, 0, "����");
		
		//д����
		outtextxy(400, 100, "���ε÷�");
		outtextxy(470, 150, gradeString);

		//�ж��Ƿ��˳�
		if ((int)msg.is_left() == 1 && (msg.x >= 500 && msg.x <= 580) && (msg.y >= 400 && msg.y <= 420)){
			exit(0);
		}

		//ɾ������
		delimage(img);

		//ɾ������
		delimage(img2);

		//�ж��Ƿ�����һ��
		if ((int)msg.is_left() == 1 && (msg.x >= 500 && msg.x <= 580) && (msg.y >= 460 && msg.y <= 480)){
			AGAIN = 1;
			break;
		}
		if (1 == AGAIN)	break;
	}

	return 0;
}