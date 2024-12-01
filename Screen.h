#pragma once
#include<easyx.h>
#include<graphics.h>
#include<string.h>
#include<iostream>
#include <conio.h>
using std::string;
class Screen
{
private:
	int screen_width;
	int screen_height;
	int botton_width;
	int botton_height;
	int text_size;
public:
	Screen();
	void setnorbk();  //运行初始背景
	void runbk();   //运行背景
	void runbotton_ordin(int n, int width1, int height1,const char** a);    //显示普通按钮    n为输出多少个矩形
	void print_char(int x1, int x2, int y1, int y2, const char* a);
	int monitor(int n, int width1, int height1);   //鼠标检测
	int dottonfunc(int n, int width1, int height1, const char** a);
	int keyboard();
	int total_keyboard();
	int getwidth();   //获得画布长度
	int getheight();	//获得画布宽度
	void login_id(char* id);   //登录账号
	void login_sec(char* sec);  //登录密码
	void login_name(char* name);  //姓名查找
	void outerror(int n,int index);            //输出提示性的信息
};

