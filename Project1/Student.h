#pragma once
using namespace std;
#include <string>
#include <iostream>
class Student
{
public:
	Student(int, string, float);

	void display();

protected:
	int num;
	string name;
	float score;
};

Student::Student(int n,string nam,float s) {
	num = n;
	name = nam;
	score = s;
}


void Student::display() {
	cout << "student num:" << num << "\nname:" << name << "\nscore:" << score << "\n\n";
}


class Graduate : public Student {
public:
	Graduate(int ,string ,float ,float);
private:
	float pay;
	void display();
};

void Graduate::display() {
	cout << "Graduate num:" << num << "\nname:" << name << "\nscore:" << score << "\npay=" << pay << endl;
}

Graduate::Graduate(int n,string nam,float s,float p):Student(n,nam,s),pay(p) {

}

class Student
{
public:
	Student();
	~Student();
};








