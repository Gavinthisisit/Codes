#include <iostream>
#include <string>
using namespace std;

//���ƹ��캯�����ܽ���ֵ������
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


/*�������㺯����
	1.Ҫ���ظö�������ã�������������ֵ
	2.������Ĳ�����������Ϊconst����
	3.���ͷ������ڴ棬�ڽ��з���
	4.�Ƿ����ͬһ��ʵ�����ж�
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
CMyString& CMyString::operator =(const CMyString &str){  //��ͨ�Ǹ߰�ȫ�汾
 	if (this == &str)
		return *this;
	delete[] m_pData;
	m_pData = NULL;
	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);
	return *this;
}
*/
/*��ȫ�汾����ֵʧ��ԭʵ����Ȼ��Ч
	1.����ͨ����ʱ���������ڴ棬���и��ƹ���
	2.���ͨ����ʱ�������ͷ�ԭ�ڴ�
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