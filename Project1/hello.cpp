#define  _CRT_SECURE_NO_WARNINGS
#include <string>
using namespace std;
#include <iostream>
#include <vector>
void showVector(const vector<string>& vlist) {
	cout << "vector 的 大小是 " << vlist.size() << endl;
	
	for (vector<string>::const_iterator iterator = vlist.cbegin(); iterator != vlist.cend(); iterator++) {
		cout << "遍历 " << *iterator << endl;
	}
}
int mainvector() {
	vector<string> vlist;
	vlist.push_back("test_a");
	vlist.push_back("test_b");
	vlist.resize(9,"a");
	//vlist.resize(3,"b");

	vector<string> vb;
	
	/*vb.insert(vlist.begin(),vlist[0]);*/
	//cout << "vlist[0] = "<< vlist[0] << endl;
	vb.insert(vb.cbegin(),vlist.begin(),vlist.begin()+2);
	showVector(vb);
	//vlist.pop_back();
	string s =vlist.back();
	cout << "back == " << s << endl;
	cout << "vector 的容量是" << vlist.capacity() << endl;

	//showVector(vlist);
	system("pause");
	return 0;
}

