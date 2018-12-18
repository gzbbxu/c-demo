#pragma once
using namespace std;
#include <string>
#include <iostream>
class Student
{
public:
	Student(int, string, float);

	virtual void display();

protected:
	int num;
	string name;
	float score;
};

Student::Student(int n, string nam, float s) {
	num = n;
	name = nam;
	score = s;
}


void Student::display() {
	cout << "student num:" << num << "\nname:" << name << "\nscore:" << score << "\n\n";
}


class Graduate : public Student {
public:
	Graduate(int, string, float, float);
private:
	float pay;
	void display();
};

void Graduate::display() {
	cout << "Graduate num:" << num << "\nname:" << name << "\nscore:" << score << "\npay=" << pay << endl;
}

Graduate::Graduate(int n, string nam, float s, float p) :Student(n, nam, s), pay(p) {

}
//主函数
int main1112()
{
	Student stud1(1001, "Li", 87.5);//定义Student类对象stud1
	Graduate grad1(2001, "Wang", 98.5, 563.5);//定义Graduate类对象grad1
	Student *pt = &stud1;//定义指向基类对象的指针变量pt
	pt->display();
	pt = &grad1;
	pt->display();
	return 0;
}








