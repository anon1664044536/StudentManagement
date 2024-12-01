#include"Student.h"
#include"Screen.h"
#include"Excel.h"
int get_sort_method();  //获得排序方式
int get_seek_method();	//获得查找方式
int main()
{
	Student stu;
	Screen form;
	Excel fo(form);
	int x;
	const char* total[7] = { "学生信息","学生录入" ,"学生删除","学生查询","增添管理员","删除管理员","退出系统"};
	const char* student[2] = { "个人信息","退出系统" };
	const char* nor_total[5] = { "学生信息","学生录入" ,"学生删除","学生查询","退出系统" };
	stu.txtread("./iamges\\Student_date.txt");
	form.setnorbk();
	int des = 1;
	int lock = 0;
	Node* this_stu = NULL;
	while (1) {
		form.runbk();
		/*登录模块*/ {
			if (des) {
				char id[20], sec[20];
				do {
					form.login_id(id);
					this_stu = stu.seek(id);
					if (this_stu == NULL) form.outerror(0,1);
				} while (this_stu == NULL);
				while (1) {
					form.login_sec(sec);
					if (this_stu->sec == sec)	break;
					else  form.outerror(1,1);
				}
				des = 0;
				lock = this_stu->admin;
			} 
			if (lock == 2 && this_stu != NULL)
				x = form.dottonfunc(7, 300, 65, total);
			else if (lock == 1) {
				x = form.dottonfunc(5, 300, 65, nor_total);
				if (x == 4)	x = 6;
			}
			else if (lock == 0) {
				x = form.dottonfunc(2, 300, 65, student);
				if (x == 0) x = -1;
				if (x == 1)	x = 6;
			}
		}
		/*打印个人信息*/ if (x == -1) {
			while (1) {
				form.runbk();
				fo.painthead();
				fo.printstuinf(this_stu, 1, 0);
				int acc = form.keyboard();
				if (acc == 0) break;
			}
		}
		/*打印学生信息*/	if (x == 0) {
			/*获取排序方式*/ {
				int qc = get_sort_method();
				if (qc == 0)			stu.listline_sum(stu.head(), stu.tail());
				else if (qc == 1)	stu.listline_math(stu.head(), stu.tail());
				else if (qc == 2)	stu.listline_computer(stu.head(), stu.tail());
				else if (qc == 3)	stu.listline_linear(stu.head(), stu.tail());
			}
			Node* mid = stu.head();
			int acc,n = 0;
			while (mid->next) {
				n++;
				mid = mid->next;
			}
			if (n % 9 != 0) n = (n / 9) + 1;
			else n /= 9;                        //n为一共有多少页
			mid = stu.head();
			Node** memory = new Node * [n];
			mid = stu.head();
			int k = 0;                          //
			while (k<n) {						//
				memory[k] = mid;				//
				for (int j = 0; j < 9&&mid->next; j++) {	//储存每一页的首节点
					mid = mid->next;			//
				}								//
				k++;							//
			}
			int i = 0;
			mid = stu.head();
			while (1){
				form.runbk();
				fo.painthead();
				fo.printpage(i);
				for (int j = 1; j < 10 && mid->next; j++) {
					fo.printstuinf(mid, j,1);
					mid = mid->next;
				}
				acc = form.total_keyboard();
				if (acc == 0) break;
				else if (acc == 1) {     //下一页
					if (i == n - 1)	mid = memory[n - 1];
					else i++;
				}
				else if (acc == 2) {     //上一页
					if (i == 0) mid = memory[0];
					else {
						mid = memory[i - 1];
						i--;
					}
				}
				else if (acc==3){		 //第一页
					mid = memory[0];
					i = 0;
				}
				else if (acc == 4) {     //最后一页
					mid = memory[n - 1];
					i = n - 1;
				}
			}
		}
		/*学生录入*/if (x == 1) {
			while (1) {
				form.runbk();
				stu.creatStudent();
				form.outerror(2, 0);
				fo.painthead();
				Node* newstu = stu.head();
				fo.printstuinf(newstu, 1, 1);
				int acc = form.keyboard();
				if (acc == 0)  break;
			}
		}
		/*学生删除*/if (x == 2) {
			while (1) {
				form.runbk();
				char id[20];
				form.login_id(id);
				int de = stu.Delete(id);
				if (de == 0)	form.outerror(4,0);
				else if(de==1)	form.outerror(3, 0);
				else if(de==-1)	form.outerror(11, 0);
				int acc = form.keyboard();
				if (acc == 0) break;
			}
		}
		/*学生查询*/if (x == 3) {
			while (1) {
				int op = get_seek_method();
				form.runbk();
				char id[20];
				if (op == 0) {
					int num = 0,n=1;
					char need[20];
					Node* those_stu = stu.head()->next;
					form.login_name(id);
					while (those_stu)
					{
						strcpy(need, those_stu->name.c_str());
						for (int i = 0; i < strlen(need); i += 2)
						{
							for (int j = 0; j < strlen(id); j += 2)
							{
								if (need[i] == id[j] && need[i + 1] == id[j + 1])
								{
									num++;
								}
							}
						}
						if (num == strlen(id) / 2)
						{
							fo.printstuinf(those_stu, n, 0);
							n++;
						}
						num = 0;
						those_stu = those_stu->next;
					}
					if(n==1)	form.outerror(4, 0);
					else 	fo.painthead();
				}
				/*精确查找*/if (op == 1) {
					form.login_id(id);
					Node* find_stu = stu.seek(id);
					if (find_stu == NULL)	form.outerror(4, 0);
					else {
						fo.painthead();
						fo.printstuinf(find_stu, 1, 0);
					}
				}
				int acc = form.keyboard();
				if (acc == 0) break;
			}
		}
		/*管理员设置*/if (x == 4) {
			while (1) {
				form.runbk();
				char id[20];
				form.login_id(id);
				Node* set_admin = stu.seek(id);
				if (set_admin == NULL)	form.outerror(4, 0);
				else {
					if (set_admin->admin == 0) {
						set_admin->admin = 1;
						form.outerror(5, 0);
					}
					else form.outerror(7, 0);
					fo.painthead();
					fo.printstuinf(set_admin, 1, 0);
					
				}
				int acc = form.keyboard();
				if (acc == 0) break;
			}
		}
		/*管理员删除*/if (x == 5) {
			while (1) {
				form.runbk();
				char id[20];
				form.login_id(id);
				Node* set_admin = stu.seek(id);
				if (set_admin == NULL)	form.outerror(4, 0);
				else {
					if (set_admin->admin == 1) {
						set_admin->admin = 0;
						form.outerror(6, 0);
					}
					else	form.outerror(8, 0);
					fo.painthead();
					fo.printstuinf(set_admin, 1, 0);	
				}
				int acc = form.keyboard();
				if (acc == 0) break;
			}
		}
		/*退出系统*/if(x == 6){
			stu.txtwrite("./iamges\\Student_date.txt");
			exit(0);
		}
	}
}
int get_sort_method()
{
	Screen scr;
	scr.runbk();
	const char* a[4] = { "总分","数学","信息","线代 " };
	int x = scr.dottonfunc(4, 300, 65, a);
	return x;
}
int get_seek_method()
{
	Screen scr;
	scr.runbk();
	const char* a[2] = { "模糊查找（姓名）","精确查找（学号）"};
	int x = scr.dottonfunc(2, 400, 80, a);
	return x;
}
