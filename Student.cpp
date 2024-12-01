#include "Student.h"
using namespace std;
Student::Student()			//���캯��
{
	headNode = new Node();
	if(headNode)
	 headNode->next = nullptr;
}
Student::~Student()       //��������
{
	Node* move_p = nullptr;
	while (headNode) {
		move_p = headNode->next;
		delete headNode;
		headNode = move_p;
	}
	delete headNode;
}
Node* Student::creatnewNode(string name, string major, string id, int class_number
	, int math, int computer, int linear,string sec, int admin)	//����һ���µĽڵ� 
{      
	Node* newNode = new Node();
	if (newNode) {
		newNode->name = name;
		newNode->major = major;
		newNode->id = id;
		newNode->class_number = class_number;
		newNode->sec = sec;
		newNode->admin = admin;
		newNode->math = math;
		newNode->computer = computer;
		newNode->linear = linear;
		newNode->next = nullptr;
		newNode->sum = math + computer + linear;
	}
	return newNode;
}
void Student::print_list()             //��ӡ����
{
	Node* move_p = headNode->next;
	cout << "����" << "\t" << "רҵ" << "\t" << "ѧ��" << "\t\t" << "�༶" << "\t" << "��ѧ"
		<< " \t" << "�����" << " " << " �ߴ�" << "\t" << "�ܷ�" << endl;
	while (move_p) {
		cout<<"------------------------------------------------------------------\n"<<endl;
		cout << move_p->name <<"\t" << move_p->major << "\t" << move_p->id << "\t"
			<< move_p->class_number << "\t" << move_p->math << "\t" << move_p->computer 
			<< "\t" << move_p->linear<<"\t"<<move_p->sum<<endl;
		move_p = move_p->next;
	}
}
void Student::insert(Node* newNode)		//����Ĳ���
{
	newNode->next = headNode->next;
	headNode->next = newNode;
}
int Student::Delete(string id)		//�����ɾ��
{
	Node* q = headNode;
	Node* p = headNode->next;
	int acc = 1;
	while (p) {
		if (p->id == id) {
			if (p->admin!=0)	return -1;
			q->next = p->next;
			delete p;
			acc = 0;
			break;
		}
		else {
			p = p->next;
			q = q->next;
		}
	}
	if (acc) return 0;
	else	 return 1;
}
Node* Student::seek(string id)			//����Ĳ�ѯ
{
	Node* move_p = headNode->next;
	while (move_p->id != id&&move_p->next) {
		move_p = move_p->next;
	}
	if (move_p->id == id) {
		return move_p;
	}
	else return NULL;
}
void Student::listline_sum(Node* left, Node* right)
{
	if (left == NULL || left->next == NULL || left == right) return;
	Node* i, * j, * i_pre;
	i = left->next;
	j = left->next;
	i_pre = left;
	int std = left->sum;
	while (j != right->next) {
		if (j->sum < std) {
			listswap(i, j);
			i_pre = i;
			i = i->next;
		}
		j = j->next;
	}
	listswap(left, i_pre);
	listline_sum(left, i_pre);
	listline_sum(i, right);
}
void Student::listline_math(Node* left, Node* right)
{
	if (left == NULL || left->next == NULL || left == right) return;
	Node* i, * j, * i_pre;
	i = left->next;
	j = left->next;
	i_pre = left;
	int std = left->math;
	while (j != right->next) {
		if (j->math < std) {
			listswap(i, j);
			i_pre = i;
			i = i->next;
		}
		j = j->next;
	}
	listswap(left, i_pre);
	listline_math(left, i_pre);
	listline_math(i, right);
}
void Student::listline_computer(Node* left, Node* right)
{
	if (left == NULL || left->next == NULL || left == right) return;
	Node* i, * j, * i_pre;
	i = left->next;
	j = left->next;
	i_pre = left;
	int std = left->computer;
	while (j != right->next) {
		if (j->computer < std) {
			listswap(i, j);
			i_pre = i;
			i = i->next;
		}
		j = j->next;
	}
	listswap(left, i_pre);
	listline_computer(left, i_pre);
	listline_computer(i, right);
}
void Student::listline_linear(Node* left, Node* right)
{
	if (left == NULL || left->next == NULL || left == right) return;
	Node* i, * j, * i_pre;
	i = left->next;
	j = left->next;
	i_pre = left;
	int std = left->linear;
	while (j != right->next) {
		if (j->linear < std) {
			listswap(i, j);
			i_pre = i;
			i = i->next;
		}
		j = j->next;
	}
	listswap(left, i_pre);
	listline_linear(left, i_pre);
	listline_linear(i, right);
}
void Student::listswap(Node* target, Node* ord)    //���������ڵ������
{
	string middles;
	int middlei;
	middles = ord->name;
	ord->name = target->name;
	target->name = middles;
	middles = ord->major;
	ord->major = target->major;
	target->major = middles;
	middles = ord->id;
	ord->id = target->id;
	target->id = middles;
	middlei = ord->class_number;
	ord->class_number = target->class_number;
	target->class_number = middlei;
	middlei = ord->math;
	ord->math = target->math;
	target->math = middlei;
	middlei = ord->computer;
	ord->computer = target->computer;
	target->computer = middlei;
	middlei = ord->linear;
	ord->linear = target->linear;
	target->linear = middlei;
	middlei = ord->sum;
	ord->sum = target->sum;
	target->sum = middlei;
	middles = ord->sec;
	ord->sec = target->sec;
	target->sec = middles;
	middlei = ord->admin;
	ord->admin = target->admin;
	target->admin = middlei;
}
Node* Student::head()		//����ͷ�ڵ�
{
	return headNode;
}
Node* Student::tail()
{
	Node* tail=headNode;
	while (tail->next)	tail = tail->next;
	return tail;
}
void Student::txtread(string filename)
{
	fstream txt(filename, ios::in);  //�����ĵ�
	if (!txt.is_open()) {
		return;
	}
	char red[1024] = { 0 };
	char date[1024] = { 0 };
	//��ȡ��ͷ
	txt.getline(red, 1024);
	txthead = red;
	//��ȡ����
	string name;
	string major;
	string id;
	string sec;
	int admin;
	int class_number;
	int math;
	int computer;
	int linear;
	char text[100];
	while (!txt.eof()) {
		txt >> text;
		if (txt.eof())	break;
		txt.getline(date, 1024);
		stringstream qq(text);
		stringstream ss(date);
		qq >> name;
		ss >>  major>>id>>class_number>>math>>computer>> linear>>sec>>admin;
		insert(creatnewNode(name,major,id,class_number ,math ,computer,linear,sec,admin));
	}
	txt.close();
}
string Student::char_transfer(string name, string major, string id, int class_number
	, int math, int computer, int linear, string sec, int admin)
{
	stringstream middle;
	middle << name << "\t" << major << "\t" << id << "\t" << class_number << "\t" 
		<< math << "\t\t"<< computer << "\t\t" << linear <<"\t\t" << sec<<"\t\t" << admin<<endl;
	return middle.str();
}
void Student::txtwrite(string filename)
{
	fstream writedate(filename, ios::out);  //�����ĵ�
	if (!writedate.is_open()) {
		return;
	}
	//д��ͷ
	txthead += "\n";
	writedate.write(txthead.c_str(), txthead.size());
	//д����
	Node* move_p = headNode->next;
	string date;
	while (move_p) {
		date = char_transfer(move_p->name, move_p->major, move_p->id, move_p->class_number
			, move_p->math, move_p->computer, move_p->linear, move_p->sec, move_p->admin);
		writedate.write(date.c_str(), date.size());
		move_p = move_p->next;
	}
	writedate.close();
}
void Student::creatStudent()
{
	Screen src;
	char infor[20] = { '\0' };
	Node* this_new = NULL;
	do {
		do {
			InputBox(infor, 20, "ѧ��ѧ�ţ�");
			if (infor[0] == '\0')
				src.outerror(9, 1);
		} while (infor[0] == '\0');
		this_new = seek(infor);
		if (this_new != NULL)
			src.outerror(10, 1);
	} while (this_new != NULL);
	string id = infor;
	do {
		InputBox(infor, 20, "ѧ��������");	
		if (infor[0] == '\0') {
			src.outerror(9, 1);
		}
	} while (infor[0] == '\0');
	string name = infor;
	infor[0] = '\0';
	do {
		InputBox(infor, 20, "ѧ��רҵ��");
		if (infor[0] == '\0') {
			src.outerror(9, 1);
		}
	} while (infor[0] == '\0');
	string major = infor;
	do {
		InputBox(infor, 20, "ѧ���༶��");
		if (infor[0] == '\0') {
			src.outerror(9, 1);
		}
	} while (infor[0] == '\0');
	int class_number = atoi(infor);
	do {
		InputBox(infor, 20, "ѧ����ѧ�ɼ���");
		if (infor[0] == '\0') {
			src.outerror(9, 1);
		}
	} while (infor[0] == '\0');
	int math = atoi(infor);
	do {
		InputBox(infor, 20, "ѧ��������ɼ���");
		if (infor[0] == '\0') {
			src.outerror(9, 1);
		}
	} while (infor[0] == '\0');
	int computer = atoi(infor);
	do {
		InputBox(infor, 20, "ѧ���ߴ��ɼ���");
		if (infor[0] == '\0') {
			src.outerror(9, 1);
		}
	} while (infor[0] == '\0');
	int linear = atoi(infor);
	do {
		InputBox(infor, 20, "ѧ�����룺");
		if (infor[0] == '\0') {
			src.outerror(9, 1);
		}
	} while (infor[0] == '\0');
	string sec = infor;
	insert(creatnewNode(name, major, id, class_number, math, computer, linear, sec, 0));
}