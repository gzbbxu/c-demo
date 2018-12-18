#include <iostream>
#include <string>
using namespace std;
#include <memory>
class Dog {
public:
	Dog(string name) {
		cout << "dog is create name == "<<name << endl;
		name_ = name;
	}
	Dog() {
		cout << "dog is create name = null" << endl;
		name_ = "nameless";
	}
	void bark() {
		cout << "dog " << name_ << "rules !" << endl;
	}
	~Dog()
	{
		cout << "dog is  " << name_ <<" ..destory"<< endl;
	}
private:
	string name_;
};

void foo() {
	shared_ptr<Dog> p(new Dog("Gunner")); //count =1 
	{
		shared_ptr<Dog> p2 = p; //count == 2;
		p2->bark();
		cout << p.use_count() << endl;
	}
	cout << p.use_count() << endl;
	//count =1 
	p->bark();
	
}//count == 0;

void  foo2() {
	shared_ptr<Dog> p = make_shared<Dog>("tank"); //faster and safer
	shared_ptr<Dog> p2 = make_shared<Dog>("Gunner");
	p = p2; //tank is delete

	cout << "fo2 end  ......." << endl;
}

void foo3() {
	shared_ptr<Dog> p = make_shared<Dog>("tank"); // using default deleter;operator delete
	shared_ptr<Dog> p2 = shared_ptr<Dog>(new Dog("Gunner"), [](Dog* p) {
		cout << "custom deleting " << endl;
	});
}

int main() {
	foo2();
	system("pause");
	return 0;
}
