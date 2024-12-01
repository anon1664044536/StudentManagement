#include "Excel.h"
Excel::Excel(Screen s)
{
	screen_width = s.getwidth();
	screen_height = s.getheight();
	textsize = 50;
}
void Excel::creatform(int n)
{
	double form_width, form_height, interval[7];
	getformsize(&form_width, &form_height, interval);
	double x = (screen_width - form_width)/2.0;
	double y = (screen_height - 10 * form_height) / 2.0;
	y += form_height * (n-1);
	setbkmode(TRANSPARENT);
	setlinestyle(PS_SOLID, 5);
	setlinecolor(RGB(223,222,36));
	double x1 = x + form_width;
	double y1 = y + form_height;
	line(x, y, x1, y);    //上横线
	line(x, y1, x1, y1);   //下横线
	line(x, y, x, y1);    //左竖线
	line(x1, y, x1, y1);  //右竖线
	for (int i = 0; i < 7; i++) {
		x += interval[i];
		line(x, y, x, y1);
	}
}
void Excel::printstuinf(Node* head,int n,int index)
{
	double form_width, form_height, interval[7];
	getformsize(&form_width, &form_height, interval);
	double x= (screen_width - form_width) / 2.0;
	double y= (screen_height - 10 * form_height) / 2.0;
	y += form_height * n;
	Node* move_p = head->next;
	if(index==0)
		move_p = head;
	char* a[8] = { (char*)move_p->name.c_str(),(char*)move_p->major.c_str(),(char*)move_p->id.c_str(),
	(char*)(to_string(move_p->class_number)).c_str(),(char*)to_string(move_p->math).c_str(),
	(char*)to_string(move_p->computer).c_str(),(char*)to_string(move_p->linear).c_str(),
	(char*)to_string(move_p->sum).c_str() };
	strcpy(a[3], (to_string(move_p->class_number)).c_str());
	strcpy(a[4], (to_string(move_p->math)).c_str());
	strcpy(a[5], (to_string(move_p->computer)).c_str());
	strcpy(a[6], (to_string(move_p->linear)).c_str());
	strcpy(a[7], (to_string(move_p->sum)).c_str());
	settextcolor(RGB(40,255,0));
	settextstyle(50, 0, "微软雅黑");
	int height = textheight(a[0]);
	int width;
	double string_x;
	double string_y;
	for (int i = 0; i <= 7; i++) {
		if (i)  x += interval[i - 1];
		width = textwidth(a[i]);
		if (i == 7)	string_x = x + ((interval[6] - width) / 2.0);
		else string_x = x+((interval[i] - width) / 2.0);
		string_y = y+((form_height - height) / 2.0);
		outtextxy(string_x, string_y, a[i]);
	}
	creatform(n+1);
}
void Excel::painthead()
{
	double form_width, form_height, interval[7];
	getformsize(&form_width, &form_height, interval);
	double x = (screen_width - form_width) / 2.0;
	double y = (screen_height - 10 * form_height) / 2.0;
	char *a[8] = { "姓名","专业","学号","班级","数学","信息","线代","总分" };
	settextcolor(RGB(18, 171, 215));
	settextstyle(50, 0, "微软雅黑");
	int height = textheight(a[0]);
	int width;
	double string_x;
	double string_y;
	for (int i = 0; i < 8; i++) {
		if (i)  x += interval[i - 1];
		width = textwidth(a[i]);
		if (i == 7)	 string_x = x + ((interval[6] - width) / 2.0);
		else   string_x = x + ((interval[i] - width) / 2.0);
		string_y = y + ((form_height - height) / 2.0);
		outtextxy(string_x, string_y, a[i]);
	}
	creatform(1);
}
void Excel::getformsize(double* form_width, double* form_height, double* interval)
{
	settextstyle(textsize, 0, "微软雅黑");
	const char* rect[5] = { "杜洪榜","电信","20221071418","2212","100" };
	int height = textheight(rect[0]);
	*form_height = height * 7 / 5.0;
	*form_width = 0;
	int width;
	for (int i = 0; i < 5; i++) {
		width = textwidth(rect[i]);
		interval[i] = width * 7 / 5.0;
		*form_width += interval[i];
	}
	for (int i = 5; i < 7; i++) interval[i] = interval[i - 1];
	*form_width += 3 * interval[4];
}
void Excel::printpage(int i)
{
	i++;
	settextcolor(RGB(250, 107, 61));
	settextstyle(50, 0, "微软雅黑");
	string head = "第";
	string tail = "页";
	string q = to_string(i);
	head += (q+tail);
	double height = textheight(head.c_str());
	double width = textwidth(head.c_str());
	double x = (screen_width - width) / 2.0;
	double y = screen_height - height;
	outtextxy(x, y, head.c_str());
}