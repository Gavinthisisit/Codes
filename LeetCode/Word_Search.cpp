#include <iostream>
#include <vector>

using namespace std;

bool flag;

class Solution {
public:
    bool exist(vector<vector<char> >& board, string word) {
        flag = 0;
        if(board.size()*board[0].size() < word.length())
        	return false;
		bool tag[100][100];
		int i,j;
		for(i=0;i<100;i++){
			for(j=0;j<100;j++)
				tag[i][j] = 0;
		}
        bool retval = 0;
        for(i=0;i<board.size();i++){
        	for(j=0;j<board[0].size();j++){
        		if(board[i][j] == word[0]){
        			tag[i][j] = 1;
        			retval = dfsSearch(board,word,i,j,1,tag);
        			tag[i][j] = 0;
        		}
        			
        		if(retval)
        			return retval;
        	}
        }
        return retval;
    }
    bool dfsSearch(vector<vector<char> > &board,string word,int x,int y,int pos,bool a[100][100]){
    	if(flag)
    		return true;
    	if(pos == word.length()){
    		flag = 1;
    		return true;
    	}	
		if(!flag && x-1 >=0 && a[x-1][y]!=1 && board[x-1][y] == word[pos]){
			a[x-1][y] = 1;
    		dfsSearch(board,word,x-1,y,pos+1,a);
			a[x-1][y] = 0;
		}
		if(!flag && y+1 < board[0].size() && a[x][y+1]!=1 && board[x][y+1] == word[pos]){
			a[x][y+1] = 1;
    		dfsSearch(board,word,x,y+1,pos+1,a);
			a[x][y+1] = 0;
		}
		if(!flag && x+1 < board.size() && a[x+1][y]!=1 && board[x+1][y] == word[pos]){
			a[x+1][y] = 1;
    		dfsSearch(board,word,x+1,y,pos+1,a);
			a[x+1][y] = 0;
		}
		if(!flag && y-1 >= 0 && a[x][y-1]!=1 && board[x][y-1] == word[pos]){
			a[x][y-1] = 1;
    		dfsSearch(board,word,x,y-1,pos+1,a);
			a[x][y-1] = 0;
		}
    	return flag;
    }
};



int main(){
	char a[] = {'A','B','C','E'};
	char b[] = {'S','F','C','S'};
	char c[] = {'A','D','E','E'};
	vector<char> v1(a,a+4);
	vector<char> v2(b,b+4);
	vector<char> v3(c,c+4);
	
	vector<vector<char> > vec;
	vec.push_back(v1);
	vec.push_back(v2);
	vec.push_back(v3);
	
	Solution s;
	cout<<s.exist(vec,"ASFBCCSE");
	
	return 0;
}
