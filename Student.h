#pragma once
#include<string>
#include<fstream>
#include<sstream>
#include "Screen.h"
using namespace std;
typedef struct Node {
	string name;
	string major;
	string id;
	string sec;
	int admin;
	int class_number;
	int math;
	int computer;
	int linear;
	int sum;
	Node* next;
}Node;
class Student
{
private:
	Node* headNode;
	string txthead;
public:
	Student();
	~Student();
	Node* creatnewNode(string name, string major, string id, int class_number
		, int math, int computer, int linear, string sec, int admin);      //����һ���µĽڵ�        
	void print_list();               //�������
	void insert(Node* newNode);        //����Ĳ���
	int Delete(string id);        //�����ɾ��
	Node* seek(string id);		        //����ľ�ȷ��ѯ
	void listline_sum(Node* left, Node* right);     //�������ܷ�����
	void listline_math(Node* left, Node* right);     //��������ѧ����
	void listline_computer(Node* left, Node* right);     //�����Լ��������
	void listline_linear(Node* left, Node* right);     //�������ߴ�����
	void listswap(Node* target, Node* ord);    //���������ڵ������
	void txtread(string filename);   //��txt�ж�ȡ����
	void txtwrite(string filename);  //��txt��д������
	string char_transfer(string name, string major, string id, int class_number
		, int math, int computer, int linear, string sec, int admin); //ת�����ַ������ͣ�����д������
	void creatStudent();           //����һ���µ�ѧ��
	Node* head();       //����ͷ�ڵ�
	Node* tail();       //����β�ڵ�
};


