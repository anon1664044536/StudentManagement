#pragma once
#include "Screen.h"
#include "Student.h"
#include<stdlib.h>
class Excel
{
private:
	int screen_height;
	int screen_width;
	int textsize;
public:
	Excel(Screen s);
	void creatform(int n);  //画表格
	void printstuinf(Node* head,int n,int index);  //画出学生的数据
	void painthead();              //画表格的头部
	void getformsize(double* form_width, double* form_height, double* interval);
	void printpage(int i);  //显示这是第多少也页
};

