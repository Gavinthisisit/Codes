#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
	void dfs(vector<vector<char> > &board,int i,int j){
	/*	
		a[i][j] = 't';
		int row = a.size();
		int col = a[0].size();
		
		if(i>0 && a[i-1][j] == 'O')
			dfs(i-1,j,a);
		if(j>0 && a[i][j-1] == 'O')
			dfs(i,j-1,a);
		if(i+1<row && a[i+1][j] == 'O')
			dfs(i+1,j,a);
		if(j+1<col && a[i][j+1] == 'O')
			dfs(i,j+1,a);	*/
	if (r < 0 || c < 0 || r >= board.size()  || c >= board[0].size() || board[r][c] != 'O') {
         return;
	}
	board[i][j] = 'P';
	int row = board.size();
	int col = board[0].size();
	if(i>0 && board[i-1][j] == 'O')
		dfs(board, i-1, j);
	if(j>0 && board[i][j-1] == 'O')
		dfs(board, i, j-1);
	if(i+1<row && board[i+1][j] == 'O')
		dfs(board, i+1, j);
	if(j+1<col && board[i][j+1] == 'O')
		dfs(board, i, j+1);			
	}
    void solve(vector<vector<char> > &board) {
     /*   int i,j;
        int row = board.size();
        if(row == 0)
        	return;
        int col = board[0].size();
        if(col == 0)
        	return;
        for(i=0;i<row;i++){
        	if(board[i][0] == 'O')
        		dfs(i,0,board);
        }
        for(j=0;j<col;j++){
        	if(board[0][j] == 'O')
        		dfs(0,j,board);
        }
        for(i=0;i<row;i++){
        	if(board[i][col-1] == 'O')
        		dfs(i,col-1,board);
        }
        for(j=0;j<col;j++){
        	if(board[row-1][j] == 'O')
        		dfs(row-1,j,board);
        }
        for(i=1;i<row;i++){
        	for(j=1;j<col;j++){
        		if(board[i][j] == 't')
        			board[i][j] = 'O';
        		else if(board[i][j] == 'O')
        			board[i][j] = 'X';			
        	}
        }*/
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row = board.size();
		if(row == 0) return;
		int col = board[0].size();
		if(col == 0) return;

		for(int j = 0; j < col; ++j)
			if(board[0][j] == 'O') 
				dfs(board,0,j);
		for(int i = 0; i < row; ++i)
			if(board[i][0] == 'O')
				dfs(board,i,0);
		for(int j = 0; j < col; ++j)
			if(board[row-1][j] == 'O')
				dfs(board,row-1,j);
		for(int i = 0; i < row; ++i)
			if(board[i][col-1] == 'O')
				dfs(board,i,col);
		//change O to X
		for(int i = 1; i < row; ++i)
		{
			for(int j = 1; j < col; ++j)
			{
				if(board[i][j] == 'O')
					board[i][j] = 'X';
			}
		}
		//change P to O
		for(int i = 0; i < row; ++i)
		{
			for(int j = 0; j < col; ++j)
			{
				if(board[i][j] == 'P')
					board[i][j] = 'O';
			}
		}
        
    }
    
};

int main(){
	char a[10][10] = {
			{'X','X','X','X'},
			{'X','O','X','O'},
			{'X','X','O','X'},
			{'X','O','X','X'}
	};
	vector<vector<char> >   vec;
	vector<char> v1(a[0],a[0]+4);
	vector<char> v2(a[1],a[1]+4);
	vector<char> v3(a[2],a[2]+4);
	vector<char> v4(a[3],a[3]+4);
	vec.push_back(v1);
	vec.push_back(v2);
	vec.push_back(v3);
	vec.push_back(v4);
	
	int i,j;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			cout<<vec[i][j]<<" "; 
		}
		cout<<endl;
	}
	cout<<endl;
	Solution s;
	
	s.solve(vec);
	
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			cout<<vec[i][j]<<" "; 
		}
		cout<<endl;
	}
	
	return 0;
}
