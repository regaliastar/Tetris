#include"gameFunctions.h"
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<windows.h>
#include<mmsystem.h>
#pragma comment(lib,"WINMM.LIB")

//用于监听鼠标事件
mouse_msg msg;

//用来接收输入
char str[100];

//声明图片对象
PIMAGE img;
PIMAGE img2;

//开始界面
int startInterface(){

	for (; is_run(); delay_fps(60)){

		//获取鼠标消息
		while (mousemsg()){
			msg = getmouse();
		}

		//创建图片对象
		img = newimage();

		//将图片保存到getimage
		getimage(img, "img//start.jpg");

		//插入图片
		putimage(1, 1, img);

		//文字颜色
		setcolor(EGERGB(0xFF, 0x0, 0x80));

		//设置字体
		setfont(36, 20, "宋体");

		//写文字
		outtextxy(200, 100, "俄罗斯方块");

		//设置字体
		setfont(20, 10, "宋体");

		//写文字
		outtextxy(255, 300, "开始游戏");

		//设置文字背景填充方式为透明，默认为OPAQUE不透明
		setbkmode(TRANSPARENT);

		//settextjustify(LEFT_TEXT, TOP_TEXT); //默认值
		settextjustify(LEFT_TEXT, TOP_TEXT);
		outtextxy(255, 350, "退出游戏");

		//判断是否进入游戏
		if ((int)msg.is_left() == 1 && (msg.x >= 255 && msg.x <= 335) && (msg.y >= 300 && msg.y <= 320)){

			//清屏
			cleardevice();

			//输入用户名
			//调用对话框函数
			while (1){
				inputbox_getline("请输入用户名", "任意输入一个用户名（回车确认）", str, 100);
				if (str[0] == '\0'){
					setcolor(EGERGB(0x80, 0x80, 0x80));
					outtextxy(0, 0, "用户名不得为空,请重新输入");
				}
				else{
					return 0;
				}
			}
		}

		//判断是否退出
		else if ((int)msg.is_left() == 1 && (msg.x >= 255 && msg.x <= 335) && (msg.y >= 350 && msg.y <= 370)){
			exit(0);
		}

		//删除对象
		delimage(img);

	}
	return 0;
}

//游戏界面
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

	//创建图片对象
	img = newimage();

	//将图片保存到getimage
	getimage(img, "img//game.jpg");

	//插入图片
	putimage(1, 1, img);

	//提示下一个砖块
	//划线
	/*line(420, 20, 580, 20);
	line(420, 20, 420, 200);
	line(580, 20, 580, 200);
	line(420, 200, 580, 200);*/
	rectangle(420, 20, 580, 120);

	//创造提示砖块
	createPromptBrick();

	//绘制提示砖块
	for (int i = 0; i < numberOfBrick; i++){
		rectangle(brick2[i].left, brick2[i].top, brick2[i].right, brick2[i].bottom);
	}

	//玩家信息
	//划线
	/*line(420, 210, 580, 210);
	line(420, 210, 420, 360);
	line(580, 210, 580, 360);
	line(420, 360, 580, 360);*/
	rectangle(420, 130, 580, 330);

	//设置字体
	setfont(20, 0, "宋体");

	//写文字
	outtextxy(440, 140, "用户名:");

	//写文字
	outtextxy(440, 170, str);

	//写文字
	outtextxy(440, 200, "分数:");

	//写文字
	outtextxy(440, 230, gradeString);

	//写文字
	outtextxy(440, 260, "技能：");

	//写文字
	outtextxy(440, 290, skillCountsString);

	//游戏说明
	//划线
	/*line(420, 370, 580, 370);
	line(420, 370, 420, 530);
	line(580, 370, 580, 530);
	line(420, 530, 580, 530);*/
	rectangle(420, 340, 580, 530);

	//写文字
	outtextxy(440, 350, "← →控制移动");

	//写文字
	outtextxy(440, 380, "↑变形");

	//写文字
	outtextxy(440, 410, "↓加速下落");

	//写文字
	outtextxy(440, 440, "空格键使用技能");

	//写文字
	outtextxy(440, 470, "0键暂停游戏");

	//写文字
	outtextxy(440, 500, "任意键继续游戏");

	//版本及作者
	//设置字体
	setfont(10, 5, "宋体");

	//写文字
	outtextxy(460, 550, "俄罗斯方块2.0版");

	//写文字
	outtextxy(480, 570, "Group3");

	//删除对象
	delimage(img);

	return 0;
}

//结束界面
int endInterface(){

	//音效
	PlaySound(TEXT("mus//end.wav"), NULL, SND_FILENAME | SND_ASYNC);

	//循环监听鼠标
	for (; is_run(); delay_fps(60)){

		//获取鼠标消息
		while (mousemsg()){
			msg = getmouse();
		}

		//创建图片对象
		img = newimage();

		//将图片保存到getimage
		getimage(img, "img//rank.jpg");

		//插入图片
		putimage(1, 1, img);

		//创建图片对象
		img2 = newimage();

		//将图片保存到getimage
		getimage(img2, "img//end.jpg");

		//插入图片
		putimage(80, 400, img2);

		//设字体
		setfont(20, 0, "宋体");
		setcolor(WHITE);

		//写文字
		outtextxy(500, 400, "EXIT");
		outtextxy(500, 460, "AGAIN");
		
		//设置颜色
		setcolor(EGERGB(0xFF, 0x0, 0x0));
		
		//设置字体
		setfont(40, 0, "宋体");

		//写文字
		outtextxy(270, 40, "RANK");

		//设字体
		setfont(20, 0, "宋体");

		//写文字
		outtextxy(100, 80, "第一名");
		outtextxy(200, 80, playerGradeStringA);
		outtextxy(100, 140, "第二名");
		outtextxy(200, 140, playerGradeStringB);
		outtextxy(100, 200, "第三名");
		outtextxy(200, 200, playerGradeStringC);
		
		//设字体
		setfont(40, 0, "宋体");
		
		//写文字
		outtextxy(400, 100, "本次得分");
		outtextxy(470, 150, gradeString);

		//判断是否退出
		if ((int)msg.is_left() == 1 && (msg.x >= 500 && msg.x <= 580) && (msg.y >= 400 && msg.y <= 420)){
			exit(0);
		}

		//删除对象
		delimage(img);

		//删除对象
		delimage(img2);

		//判断是否再来一次
		if ((int)msg.is_left() == 1 && (msg.x >= 500 && msg.x <= 580) && (msg.y >= 460 && msg.y <= 480)){
			AGAIN = 1;
			break;
		}
		if (1 == AGAIN)	break;
	}

	return 0;
}