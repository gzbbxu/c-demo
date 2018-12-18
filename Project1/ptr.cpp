#define  _CRT_SECURE_NO_WARNINGS
#include<string>
#include<memory>
#include<iostream>
#include "SmartPoint.h"
#include "vpoint.h"
#include <thread>
using namespace PTRLib;
using namespace DTLib;
using namespace std;
class TestPoint{
public:
	TestPoint() {
		cout << "Test()" << endl;
	}
	~TestPoint() {
		cout << "~Test()" << endl;
	}
};

class Person
{
public:
	Person() {}
	Person(const Person& p)
	{
		cout << "Copy Constructor" << endl;
	}

	Person& operator=(const Person& p)
	{
		cout << "Assign" << endl;
		return *this;
	}

private:
	int age;
	string name;
};


int fun() {
	//SmartPoint<TestPoint> sp(new TestPoint);
	SmartPoint<TestPoint> sp;// = new TestPoint;
	SmartPoint<TestPoint> nsp;
	nsp = sp;
	cout << sp.isNull() << nsp.isNull()<< endl;
	return 0;
}

int fun2() {
	Person p;
	Person p1;    // 1
	p1 = p;
	return 0;
}

int main111() {
	/*fun();*/
	fun();
	SuperPointer<TestPoint> su1;
	SuperPointer<TestPoint> su2(su1);
	cout << "==============" << endl;
	return 0;
}