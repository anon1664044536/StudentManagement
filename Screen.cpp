#include "Screen.h"
using namespace std;
Screen::Screen()
{
	screen_width = 1300;
	screen_height = 800;
	botton_width = 200;
	botton_height = 100;
	text_size = 50;
}
void Screen::setnorbk()
{
	initgraph(screen_width, screen_height,EX_NOCLOSE);
}
void Screen::runbk()    //运行背景
{
	IMAGE img;
	loadimage(&img, "./iamges\\bk.jpg", screen_width,screen_height);
	putimage(0, 0, &img);
	setbkmode(TRANSPARENT);
}
void Screen::runbotton_ordin(int n, int width1, int height1, const char** a)  //画出方框
{
	IMAGE botton;
	loadimage(&botton, "./iamges\\botton.jpg", width1, height1);
	int i, x1, x2, y1, y2;
	double b;        //小的长度（矩形与边框之间）
	b = (screen_height - n * height1) / (n + 1.0);
	for (i = 0; i < n; i++) {                             //画矩形
		x1= (screen_width - width1) / 2.0;
		y1 = (i + 1) * b + i * height1;
		x2=x1 + width1;
		y2 = y1 + height1;
		putimage(x1, y1, &botton);
		print_char(x1, x2, y1, y2, a[i]);
	}
}
void Screen::print_char(int x1, int x2, int y1, int y2,const char* a)  
{
	int width,height, x11, y11;
	char str[30];
	setbkmode(TRANSPARENT);
	settextcolor(RGB(18,171,215));
	settextstyle(50, 0, "微软雅黑");
	strcpy(str, a);
	width = textwidth(str);
	height = textheight(str);                      
	x11 = (x1+x2-width) / 2.0;
	y11 = (y1 + y2 - height) / 2.0;
	outtextxy(x11, y11,str);
}
int Screen::monitor(int n, int width1, int height1)
{
	double b;
	double  * x1, * x2, * y1, * y2;
	int i;
	x1 = new double[n];
	x2 = new double[n];
	y1 = new double[n];
	y2 = new double[n];
	b = (screen_height - n * height1) / (n + 1.0);
	for (i = 0; i < n; i++) {                             //画矩形
		x1[i] = (screen_width - width1) / 2.0;
		y1[i] = (i + 1) * b + i * height1;
		x2[i] = x1[i] + width1;
		y2[i] = y1[i] + height1;
	}
	ExMessage msg;
	while (1) {
		if (peekmessage(&msg, EM_MOUSE)) {
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				for (i = 0; i < n; i++) {
					if (msg.x >= x1[i] && msg.x <= x2[i] && msg.y >= y1[i] && msg.y <= y2[i]) {
						setfillcolor(RED);
						solidrectangle(x1[i], y1[i], x2[i], y2[i]);
						Sleep(100);
						cleardevice();
						return i;
					}
				}
				break;
			}
		}
	}
}
int Screen::dottonfunc(int n, int width1, int height1, const char** a)
{
	int x;
	runbotton_ordin(n, width1, height1, a);
	x = monitor(n, width1, height1);
	setbkmode(TRANSPARENT);
	settextcolor(BLUE);
	settextstyle(50, 0, "微软雅黑");
	switch (x)
	{
	case 0:
		return 0;
		outtextxy(10, 10, "学生信息");
		break;
	case 1:
		return 1;
		outtextxy(10, 10, "学生录入");
		break;
	case 2:
		return 2;
		outtextxy(10, 10, "学生删除");
		break;
	case 3:
		return 3;
		outtextxy(10, 10, "学生查询");
		break;
	case 4:
		return 4;
		outtextxy(10, 10, "增添管理员");
		break;
	case 5:
		return 5;
		outtextxy(10, 10, "删除管理员");
		break;
	case 6:
		return 6;     //退出系统
	}
}
int Screen::keyboard()
{
	char key;
	while (1) {
		do {
			key = _getch();
		} while (key != 27);
		cleardevice();
		return 0;
	}
}
int Screen::total_keyboard()
{
	char key;
	while (1) {
		do {
			key = _getch();
		} while (key != 27 && key != 'd' && key != 'a' && key != 'w' && key != 's');
		cleardevice();
		switch (key)
		{
		case 27:
			return 0;
		case 'd':
			return 1;
		case 'a':
			return 2;
		case 'w':
			return 3;
		case 's':
			return 4;
		}
	}
}
int Screen::getwidth()
{
	return screen_width;
}
int Screen::getheight()
{
	return screen_height;
}
void Screen::login_id(char* id)
{
	id[0] = '\0';
	do {
		InputBox(id, 20, "学号：");
		if (id[0] == '\0') {
			outerror(9, 1);
		}
	} while (id[0] == '\0');
}
void Screen::login_sec(char* sec)
{
	sec[0] = '\0';
	do {
		InputBox(sec, 20, "密码：");
		if (sec[0] == '\0') {
			outerror(9, 1);
		}
	} while (sec[0] == '\0');
}
void Screen::login_name(char* name)
{
	name[0] = '\0';
	do {
		InputBox(name, 20, "姓名：");
		if (name[0] == '\0') {
			outerror(9, 1);
		}
	} while (name[0] == '\0');
}
void Screen::outerror(int n, int index)
{
	setbkmode(TRANSPARENT);
	settextcolor(RGB(18, 171, 215));
	settextstyle(50, 0, "微软雅黑");
	char *inf[12] = { "没有该学生！请检查是否输入错误或联系老师增添信息！",  "密码输入错误！" ,
	"学生录入成功！" ,"学生删除成功！" ,"没有该学生！","管理员设置成功！","管理员设置失败！",
	"该学生已为管理员或者高级管理员！","该学生不是管理员或者为高级管理员！",
	"请输入信息后再点击确认！","该学生已经存在！","该学生为管理员或者高级管理员！不可被删除！"};
	int width = textwidth(inf[n]);
	int height = textheight(inf[n]);
	int x = (screen_width - width) / 2;
	int y = (screen_height - height) / 2;
	outtextxy(x, y, inf[n]);
	if (index == 1) {
		Sleep(1000);
		cleardevice();
		runbk();
	}
}