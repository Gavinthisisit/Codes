#include <iostream>
#include <string>
using namespace std;

void swap1(int a, string str){
	a = 2;
	str = "ֵ������";
}

void swap2(int& a, string& str){
	a = 3;
	str = "��ַ����";
}

int main(){
	int num = 0;
	string str = "�����ַ���";
	swap2(num, str);
	cout << num << " " << str << endl;
	return 0;
}