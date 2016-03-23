#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char> > &board) {
        int row = board.size();
        int col = board[0].size();
        int i,j;
        i = 0;
        while(i < row){
        	if(board[i][0] == 'O')
        		board[i][0] = 't';
        	if(board[row-1][i] == 'O')
        		board[row-1][i] = 't';
        	if(board[i][col-1] == 'O')
        		board[i][col-1] = 't';
        	if(board[0][i] == 'O')
        		board[0][i] = 't';
        	i++;
        }
        i = 1;
        bool flag = 0;
        while(!flag && i < row){									//从上沿开始向下找
			flag = 1;
			j = 1; 
    		while(j < col){
    			if(board[i][j] == 'O' ){
    				if(board[i-1][j] == 't'){
    					board[i][j] = 't';
    					flag = 0;
    				}		
    			}
    			else if(board[i][j] == 't')
    				flag = 0;
    		j++;
    		}
    	i++;
		}
		flag = 0;
		i = row-2;
		
		while(!flag && i > 0){									//从下沿开始向上找
			flag = 1; 
			j = 1; 
    		while(j < col){
    			if(board[i][j] == 'O' ){
    				if(board[i+1][j] == 't'){
    					board[i][j] = 't';
    					flag = 0;
    				}		
    			}
    			else if(board[i][j] == 't')
    				flag = 0;
    		j++;
    		}
    	i--;
		}
		flag = 0;
		j = 1;
		
		while(!flag && i < col){									//从左沿开始向友找
			flag = 1;
			i = 1; 
    		while(i < row){
    			if(board[i][j] == 'O' ){
    				if(board[i][j-1] == 't'){
    					board[i][j] = 't';
    					flag = 0;
    				}		
    			}
    			else if(board[i][j] == 't')
    				flag = 0;
    		i++;
    		}
    	j++;
		}
		flag = 0;
		j = col-2;
		
		while(!flag && j >= 0){									//从右沿开始向左找
			flag = 1;
			i = 1; 
    		while(i < row){
    			if(board[i][j] == 'O' ){
    				if(board[i][j+1] == 't'){
    					board[i][j] = 't';
    					flag = 0;
    				}		
    			}
    			else if(board[i][j] == 't')
    				flag = 0;
    		i++;
    		}
    	j--;
		}
		
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				cout<<board[i][j]<<" "; 
			}
		cout<<endl;
		}
	cout<<endl;
//		i = j = 0;
		for(i=0;i<row;i++){
			for(j=0;j<col;j++){
				if(board[i][j] == 't')
					board[i][j] = 'O';
				else if(board[i][j] == 'O')
					board[i][j] = 'X';
	
			}
		}
	
	}
};



int main(){
	char a[10][10] = {
			{'X','X','X','X'},
			{'X','O','O','O'},
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
