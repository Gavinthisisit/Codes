
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <map>

using namespace std;

vector<vector<string> >  QuenePrint(20);

#define MaxSize   50
class Solution {
public:
	 
	map<int,int> mp;
    int count;
    int queneList[MaxSize];
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
	void printQuene(int queneList[MaxSize],int n){
		
		int i,j,k;
		string str;
		char ch[10];
		itoa(count,ch,10);
		str = "[\"";
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(queneList[j] != -1)
					str += "Q";
				else
					str += ".";
			}
			if(i != n-1)
				str += "\",";
			else
				str += "\"],";
			if(i == 0){
				str += " // Solution ";
				str += ch;
			}
				
			QuenePrint[count].push_back(str);
			str = "[\"";
			}
			
		}
			
    void Que(int queneList[MaxSize],int row,int N) {
		int j;
		if(row >= N){
			count++;
			printQuene(queneList,N);
			
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
    vector<vector<string> > solveNQueens(int n) {
        for(int i=0;i<MaxSize;i++)
		    queneList[i] = -1;
		Que(queneList,0,n);
		
		return QuenePrint;
    }
};


int main(){
	
	vector<vector<string> > ou1(20);
/*	vector<string>  ou;
	string str = "hdksjdkashdksahj";
	string str1 = "11111111111111";
	ou.push_back(str);
	int t = 11111111;
	ou1[0].push_back(str);
	ou1[0].push_back(str1);
	char ch[20];
	itoa(t,ch,10);
//	ou1[0][0] += "aaaaa"; 
	cout<<ou1[0][0]<<endl<<ou1[0][1]<<endl;
	str += ch;
	cout<<str<<endl;
	cout<<"First thing I do with Dev-C++"<<endl;*/
	Solution s;
	ou1 = s.solveNQueens(4);
	cout<<ou1[0][0]<<endl;
	cout<<ou1[0][1]<<endl;
	
	return 0;
	
}
