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
	void creatform(int n);  //�����
	void printstuinf(Node* head,int n,int index);  //����ѧ��������
	void painthead();              //������ͷ��
	void getformsize(double* form_width, double* form_height, double* interval);
	void printpage(int i);  //��ʾ���ǵڶ���Ҳҳ
};

