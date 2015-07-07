
#include <iostream>
#include <map>
#include <vector>
#include <windows.h>

using namespace std;



/*
	bool CheckSafe(int[] a,int x,int y){
		int i;
		i = 0;
		bool flag = 0;
		if(x>=y)
		{
			while(i<n && (x-y+i)<n){
				if(i == x && (y-x+i) == y){
					i++;
					continue;
				}
				else if(a[i][y-x+i] == 1)
					return 0;
				i++;
			}
			i = 0;
			while(i<n && (n-1-i+x-y)<n){
				if(i == x && (n-1+x-y-i) == y){
					i++;
					continue;
				}
				else if(a[i][n-1-i+x-y] == 1)
					return 0;
				i++;
			}
		}
		else{
			while(i<n && (y-x+i)<n){
				if(i == x && (y-x+i) == y){
					i++;
					continue;
				}
				else if(a[i][y-x+i] == 1)
					return 0;
				i++;
			}
			i = 0;
			while(i<n && (n-1-i+y-x)<n){
				if(i == x && (n-1+y-x-i) == y){
					i++;
					continue;
				}
				else if(a[i][n-1-i+y-x] == 1)
					return 0;
				i++;
			}
		}
		i = 0;
		while(i<n){
			if(i == x){
				i++;
				continue;
			}
			else
				if(a[i][y] == 1)
					return 0;
			i++;
		}
		i = 0;
		while(i<n){
			if(i == y){
				i++;
				continue;
			}
			else
				if(a[x][i] == 1)
					return 0;
			i++;
		}
		return 1;
	}*/
#define MaxSize  50


/*
#define N		 11

class Solution{
public:
	map<int,int> mp;
	int count;
	void printQuene(int quene[MaxSize]){
		int i = 0;
		while(quene[i] != -1)
			cout<<i-1<<"--"<<quene[i++]<<"   ";
		cout<<endl;
		
	}

	bool checkSafe(int a[MaxSize],int x,int y,int q){
		int i = 0;
		int m,n;
		while(i<q && a[i] != -1){
			m = x-i;
			n = y-a[i];
			if(m==n && m!=0)
				return false;
			m = x-i;
			n = a[i]-y;
			if(m==n && m!=0)
				return false;
			i++;
		}
		return true;
	}
    void Que(int queneList[MaxSize],int row) {
		int j;
		if(row >= N){
//			printQuene(queneList);
			count++;
		}
		else{
			for(j=0;j<N;j++){
				if(mp[j] == 1)
					continue;

				queneList[row] = j;
				if(checkSafe(queneList,row,j,N)){
					mp[j] = 1;
					Que(queneList,row+1);
				}
				queneList[row] = -1;
				mp[j] = 0;
			}
		}
    }
};*/



#define MaxSize  50

class Solution {
public:
    map<int,int> mp;
    int count;
    int queneList[MaxSize];
    int totalNQueens(int n) {
        for(int i=0;i<MaxSize;i++)
		    queneList[i] = -1;
		Que(queneList,0,n);
		return count;
    }
    bool checkSafe(int a[MaxSize],int x,int y,int q){
		int i = 0;
		int m,n;
		while(i<q && a[i] != -1){
			m = x-i;
			n = y-a[i];
			if(m==n && m!=0)
				return false;
			m = x-i;
			n = a[i]-y;
			if(m==n && m!=0)
				return false;
			i++;
		}
		return true;
	}
    void Que(int queneList[MaxSize],int row,int N) {
		int j;
		if(row >= N){
//			printQuene(queneList);
			count++;
		}
		else{
			for(j=0;j<N;j++){
				if(mp[j] == 1)
					continue;

				queneList[row] = j;
				if(checkSafe(queneList,row,j,N)){
					mp[j] = 1;
					Que(queneList,row+1,N);
				}
				queneList[row] = -1;
				mp[j] = 0;
			}
		}
    }
    
};

int main(){
	DWORD startTime = GetTickCount();
	int a[MaxSize];
	for(int i=0;i<MaxSize;i++)
		a[i] = -1;
/*	a[0][0] = a[3][4] = a[2][1] = a[4][2] = 1;
	int x,y;
	x = 4;
	y = 3;
	a[x][y] = 1;*/
	int N;
	cin>>N;
	Solution s;
	s.count = 0;
	
	cout<<s.totalNQueens(N)<<endl;

	//�����ԵĴ���
	DWORD totalTime = GetTickCount()-startTime;
	return 0;
}

/*


//	N�ʺ�����

#include <iostream>
using namespace std;

#define N 8

bool matrix[N + 1][N + 1] = {0};

bool IsLegal(bool matrix[N + 1][N + 1], const int &i, const int &j)
{
	//	�ж�ǰ���i-1��������matrix[i][j]�Ƿ��ͻ��iΪ1ʱ�Ϸ�

	for (int m = 1; m <= i - 1; ++m) {
		for (int n = 1; n <= N; ++n) {	//	ʵ��ÿһ��ֻ��һ������
			if (matrix[m][n] == 1) {
				if ( n == j || abs(i - m) == abs(j - n) )	//	key, not bad
					return false;
			}
		}
	}
	return true;
}

void Print(bool matrix[N + 1][N + 1])
{
	static int count = 1;
	printf("Case %d:\n", count++);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			matrix[i][j] == 1 ? printf("%c ", 2) : printf(". ");
		}
		cout << endl;
	}
	cout << endl;
}

void Trial(const int i)
{
	//	���뱾����ʱ����N*N������ǰi-1���ѷ����˻���������i-1������
	//	�ִӵ�i�������Ϊ��������ѡ�����λ��

	if (i > N)	//	�����ǰ�ĺϷ�����
		Print(matrix);
	else
		for (int j = 1; j <= N; ++j) {
			matrix[i][j] = 1;
			if ( IsLegal(matrix, i, j) )
				Trial(i + 1);
			matrix[i][j] = 0;
		}
}

int main(void)
{
	Trial(1);

	return 0;
}

  */