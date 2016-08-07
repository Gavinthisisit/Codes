#include <iostream>
#include <string>
using namespace std;

void swap1(int a, string str){
	a = 2;
	str = "值传引用";
}

void swap2(int& a, string& str){
	a = 3;
	str = "地址引用";
}

int main(){
	int num = 0;
	string str = "测试字符串";
	swap2(num, str);
	cout << num << " " << str << endl;
	return 0;
}