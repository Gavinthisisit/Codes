#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if(board.empty()) return;
        int M = board.size(), N = board[0].size();
        
        int i,j;
        //上面一行, 下面一行
        for(int j = 0; j < N; j++){
            i = 0;
            if(board[i][j] == 'O'){
                bfs(board, M, N, i, j);
            }
            i = M-1;
            if(board[i][j] == 'O'){
                bfs(board, M, N, i, j);
            }
        }
        
        //左边一列，右边一列
        for(int i = 0; i < M; i++){
            j = 0;
            if(board[i][j] == 'O'){
                bfs(board, M, N, i, j);
            }
            j = N-1;
            if(board[i][j] == 'O'){
                bfs(board, M, N, i, j);
            } 
        }
        //把O换成X,把#换成O
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                } else if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }
    void bfs(vector<vector<char>> &board, int M, int N, int x, int y){
        queue<pair<int, int> > q;
        
        board[x][y] = '#';
        q.push(pair<int, int>(x,y));

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            pushQ(board, M, N, q, i-1, j);
            pushQ(board, M, N, q, i+1, j);
            pushQ(board, M, N, q, i, j-1);
            pushQ(board, M, N, q, i, j+1);
        }
    }
    
    void pushQ(vector<vector<char>> &board, int M, int N, queue<pair<int, int> > &q, int i, int j){
        if(inMatrix(i,j, M, N) && board[i][j] == 'O'){
            board[i][j] = '#';
            q.push(pair<int, int>(i,j));
        }
        
    }
    
    bool inMatrix(int i, int j, int M, int N){
        return i>=0 && i < M && j>=0 && j < N;
    }
};*/

class Solution{
	public:
		void solve(vector<vector<char> > &board){
			if(board.empty())
				return;
			int row = board.size();
			int col = board[0].size();
			int i,j;
		//上下两行 
		for(int j = 0; j < col; j++){
            i = 0;
            if(board[i][j] == 'O'){
                bfs(i, j,board);
            }
            i = row-1;
            if(board[i][j] == 'O'){
                bfs(i, j,board);
            }
        }
        
        //左右两列 
        for(int i = 0; i < row; i++){
            j = 0;
            if(board[i][j] == 'O'){
                bfs(i, j,board);
            }
            j = col-1;
            if(board[i][j] == 'O'){
                bfs(i, j,board);
            } 
        }
                //把O换成X,把#换成O  
        for(int i = 0; i < row; i++){  
            for(int j = 0; j < col; j++){  
                if(board[i][j] == 'O'){  
                    board[i][j] = 'X';  
                } else if(board[i][j] == 't'){  
                    board[i][j] = 'O';  
                }  
            }  
        } 
			
		}
		void bfs(int x,int y,vector<vector<char> > &a){
			queue<pair<int,int> > q;
			a[x][y] = 't';
			
			q.push(pair<int,int>(x,y));
			
			while(!q.empty()){
				int i = q.front().first;
				int j = q.front().second;
				q.pop();
				pushQ(a,q,i-1,j);
				pushQ(a,q,i+1,j);
				pushQ(a,q,i,j-1);
				pushQ(a,q,i,j+1);
				
			}
		}
		void pushQ(vector<vector<char> > &a,queue<pair<int,int> > &q,int x,int y){
			int row = a.size();
			int col = a[0].size();
			if(x<0 || y<0 || x>=row || y>=col)
				return;
			if(a[x][y] == 'O'){
				a[x][y] = 't';
				q.push(pair<int,int>(x,y));
			}else
				return;
			
			
			
			
		}
};

int main(){
	char a[10][10] = {
			{'X','O','X','O','X','O'},
			{'O','X','O','X','O','X'},
			{'X','O','X','O','X','O'},
			{'O','X','O','X','O','X'}
	};
	vector<vector<char> >   vec;
	vector<char> v1(a[0],a[0]+6);
	vector<char> v2(a[1],a[1]+6);
	vector<char> v3(a[2],a[2]+6);
	vector<char> v4(a[3],a[3]+6);
	vec.push_back(v1);
	vec.push_back(v2);
	vec.push_back(v3);
	vec.push_back(v4);
	
	int i,j;
	for(i=0;i<vec.size();i++){
		for(j=0;j<vec[0].size();j++){
			cout<<vec[i][j]<<" "; 
		}
		cout<<endl;
	}
	cout<<endl;
	Solution s;
	
	s.solve(vec);
	
	for(i=0;i<vec.size();i++){
		for(j=0;j<vec[0].size();j++){
			cout<<vec[i][j]<<" "; 
		}
		cout<<endl;
	}
	
	return 0;
} 
