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
	void setnorbk();  //���г�ʼ����
	void runbk();   //���б���
	void runbotton_ordin(int n, int width1, int height1,const char** a);    //��ʾ��ͨ��ť    nΪ������ٸ�����
	void print_char(int x1, int x2, int y1, int y2, const char* a);
	int monitor(int n, int width1, int height1);   //�����
	int dottonfunc(int n, int width1, int height1, const char** a);
	int keyboard();
	int total_keyboard();
	int getwidth();   //��û�������
	int getheight();	//��û������
	void login_id(char* id);   //��¼�˺�
	void login_sec(char* sec);  //��¼����
	void login_name(char* name);  //��������
	void outerror(int n,int index);            //�����ʾ�Ե���Ϣ
};

