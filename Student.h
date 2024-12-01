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
		, int math, int computer, int linear, string sec, int admin);      //创建一个新的节点        
	void print_list();               //输出链表
	void insert(Node* newNode);        //链表的插入
	int Delete(string id);        //链表的删除
	Node* seek(string id);		        //链表的精确查询
	void listline_sum(Node* left, Node* right);     //链表以总分排序
	void listline_math(Node* left, Node* right);     //链表以数学排序
	void listline_computer(Node* left, Node* right);     //链表以计算机排序
	void listline_linear(Node* left, Node* right);     //链表以线代排序
	void listswap(Node* target, Node* ord);    //交换两个节点的数据
	void txtread(string filename);   //从txt中读取数据
	void txtwrite(string filename);  //在txt中写入数据
	string char_transfer(string name, string major, string id, int class_number
		, int math, int computer, int linear, string sec, int admin); //转化成字符串类型，方便写入数据
	void creatStudent();           //创建一个新的学生
	Node* head();       //返回头节点
	Node* tail();       //返回尾节点
};


