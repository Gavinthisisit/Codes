/** 
 * @file Surrounded_Regions.cpp 
 * @Brief  
 * @author  Brian  
 * @version 1.0 
 * @date 2013-09-07 
 */ 
   
#include <iostream>  
#include <cstdio>  
#include <cstdlib>  
#include <cstring>  
#include <memory.h>  
#include <algorithm>  
#include <math.h>  
#include <queue>  
#include <vector>  
using namespace std;  
    
   
class Solution {  
    private:   
        struct point{  
            int x;  
            int y;  
            point(int _x,int _y):x(_x),y(_y){}  
            point(){}  
        };  
        int start;  
        int end;  
        point Points[100000];  
        void bfs(vector<vector<char> > &board, int r,int c, int row, int col){  
            vector<point> buf;  
            queue<point> q;  
            bool reachBoundary = false;  
            start = 0;  
            end =0;  
            //q.push(point(r,c));  
            Points[end++]=point(r,c);  
            //while(!q.empty()){  
            while(start<end){  
               /* point p = q.front(); 
                q.pop();*/ 
                point p = Points[start++];  
                board[p.x][p.y] = 'v';  
                //search up,down,left,right  
                reachBoundary |= expand(board,q,p.x-1,p.y,row,col,'O');  
                reachBoundary |= expand(board,q,p.x+1,p.y,row,col,'O');  
                reachBoundary |= expand(board,q,p.x,p.y-1,row,col,'O');  
                reachBoundary |= expand(board,q,p.x,p.y+1,row,col,'O');  
            }  
            char ch = reachBoundary?'k':'X';  
            for(int i=0;i<end;i++){  
                point p = Points[i];  
                board[p.x][p.y] = ch;  
            }  
    
        }  
            
        int expand(vector<vector<char> > &board , queue<point> &q, int x,int y, int row, int col,char c){  
            if(x<0||x>=row||y<0||y>=col)  
                return true;  
            else{  
                if(board[x][y]==c ){  
                    //q.push(point(x,y));  
                    Points[end++]=point(x,y);  
                    //这个是判重用的，防止同一个点入队多次。下一次到这一个点时  
                    // if判断就不成立了,也就防止了再次入队。  
                    board[x][y]=c+1;  
                        
                }  
                return false;  
            }  
        }  
    public:  
        Solution(){  
   
        }  
        void solve(vector<vector<char> > &board) {  
   
            int row = board.size();  
            if(row==0)  
                return ;  
            int col = board[0].size();  
            for(int r=0;r<row;r++){  
                for(int c=0;c<col;c++){  
                    if(board[r][c]=='O')  
                        bfs(board,r,c,row,col);  
                }  
            }  
            for(int r=0;r<row;r++){  
                for(int c=0;c<col;c++){  
                    if(board[r][c]=='k')  
                        board[r][c]='O';  
                }  
            }  
   
   
        }  
           
};  
int main(){  
    Solution s;  
    char src[30][30] = {{"XOOOOOOOOOOOOOOOOOOO"},{"OXOOOOXOOOOOOOOOOOXX"},{"OOOOOOOOXOOOOOOOOOOX"},{"OOXOOOOOOOOOOOOOOOXO"},{"OOOOOXOOOOXOOOOOXOOX"},{"XOOOXOOOOOXOXOXOXOXO"},{"OOOOXOOXOOOOOXOOXOOO"},{"XOOOXXXOXOOOOXXOXOOO"},{"OOOOOXXXXOOOOXOOXOOO"},{"XOOOOXOOOOOOXXOOXOOX"},{"OOOOOOOOOOXOOXOOOXOX"},{"OOOOXOXOOXXOOOOOXOOO"},{"XXOOOOOXOOOOOOOOOOOO"},{"OXOXOOOXOXOOOXOXOXOO"},{"OOXOOOOOOOXOOOOOXOXO"},{"XXOOOOOOOOXOXXOOOXOO"},{"OOXOOOOOOOXOOXOXOXOO"},{"OOOXOOOOOXXXOOXOOOXO"},{"OOOOOOOOOOOOOOOOOOOO"},{"XOOOOXOOOXXOOXOXOXOO"}};  
    //char src[30][30] = {{"OO"},{"OO"}};  
    vector<vector<char> > board;  
    int n=20;  
    for(int i=0;i<n;i++){  
        vector<char> row;  
        for(int j=0;j<n;j++){  
            row.push_back(src[i][j]);  
        }  
        board.push_back(row);  
    }  
    s.solve(board);  
    return 0;  
} 
