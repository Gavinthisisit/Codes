#include <iostream>
#include <string>
using namespace std;

//复制构造函数不能进行值传复制
class A{
private:
	int value;
public:
	A(int n){ value = n;}
	A(const A& other){ value = other.value; }
	void Print(){
		cout << value << endl;
	}

};


/*复制运算函数：
	1.要返回该对象的引用，否则不能连续赋值
	2.将传入的参数类型声明为const引用
	3.先释放自身内存，在进行分配
	4.是否进行同一个实例的判断
*/
class CMyString{		
public:
	CMyString(char* pData = NULL);
	CMyString(const CMyString& str);
	~CMyString(void);
	void Print(){ cout << m_pData << endl; }
	CMyString& operator =(const CMyString &str);
private:
	char* m_pData;
};
/*
CMyString& CMyString::operator =(const CMyString &str){  //普通非高安全版本
 	if (this == &str)
		return *this;
	delete[] m_pData;
	m_pData = NULL;
	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);
	return *this;
}
*/
/*安全版本，赋值失败原实例依然有效
	1.首先通过临时变量申请内存，进行复制构造
	2.最后通过临时变量来释放原内存
*/


CMyString& CMyString::operator =(const CMyString &str){  
	if (this == &str)
		return *this;
	CMyString strTmp(str);
	char* pTmp = strTmp.m_pData;
	strTmp.m_pData = m_pData;
	m_pData = pTmp;

	return *this;
}

int main(){
	CMyString ss = "141412";
	CMyString aa = "111111";
	CMyString bb, cc, dd;
	aa = cc = aa;
	dd = aa;
	aa.Print();
	dd.Print();
	return 0;
}