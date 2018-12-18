#define  _CRT_SECURE_NO_WARNINGS
#include<string>
#include<memory>
#include<iostream>

using namespace std;


class String {
public:
	~String();
	String(const String & str);
	String(const char* p);
	char * m_data;
private:
};

String::~String() {
	delete[] m_data;
}


String::String(const char* p) {
	if (p != NULL) {
		int lenth = strlen(p);
		m_data = new char[lenth+1];
		strcpy(m_data,p);
	}
	else {
		m_data = new char[1];
		strcpy(m_data,'\0');
	}

}

String::String(const String& str) {
	int length = strlen(str.m_data);
	m_data = new char[length+1];
	strcpy(m_data,str.m_data);
}

int main11() {

	return 0;
}