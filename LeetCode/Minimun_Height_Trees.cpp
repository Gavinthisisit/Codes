#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
	vector<int> findMinHeightTrees(int n, vector<pair<int, int> >& edges){
		vector<int> retval;
		int size = edges.size();
		if (size == 1){
			retval.push_back(0);
			return retval;
		}
		if (size == 2){
			retval.push_back(0);
			retval.push_back(1);
			return retval;
		}
		int* count = new int[n];
		memset(count, 0, n*sizeof(int));
		
		int i = 0;
		while (i < size){
			++count[edges[i].first];
			++count[edges[i].second];
			++i;
		}
		vector<int> root_candi;
		i = 0;
		while (i < n){
			if (count[i]>1)
				root_candi.push_back(i);
			++i;
		}
		if (root_candi.size() == 1)
			return root_candi;
		i = 0;
		int min = INT_MAX;
		
		while (i < root_candi.size()){
			
			int ret = bfs(root_candi[i], edges, min);
			if ( ret!= -1 && ret < min){
				retval.clear();
				retval.push_back(root_candi[i]);
				min = ret;
			}
			else if (ret == min)
				retval.push_back(root_candi[i]);
			++i;
		}
		delete count;
		return retval;
	}
	int bfs(int x, vector<pair<int, int> > edges, int min){
		
		int size = edges.size();
		int front = -1, tail = -1;
		int queue[100];
		bool flag[100];
		memset(flag, true, 100*sizeof(bool));
		queue[++tail] = x;
		queue[++tail] = -1;
		int deep = 0;
		while (front != tail && deep<=min){
			int root = queue[++front];
			if (root == -1){
				++deep;
				if (queue[tail] != -1)
					queue[++tail] = -1;
				continue;
			}
			int i = 0;
			while (i < size){
				if (flag[i]){
					int f = edges[i].first;
					int s = edges[i].second;
					if (edges[i].first == root){
						queue[++tail] = edges[i].second;
						flag[i] = 0;
					}
					else if (edges[i].second == root){
						queue[++tail] = edges[i].first;
						flag[i] = 0;
					}
				} 
				++i;
			}
		}
		if (deep > min)
			return -1;
		else
			return deep;
	}
};



int main(){
	
	pair<int, int> p1(0, 3);
	pair<int, int> p2(1, 3);
	pair<int, int> p3(2, 3);
	pair<int, int> p4(4, 3);
	pair<int, int> p5(5, 4);
	vector<pair<int, int> > edges;
	edges.push_back(p1);
	edges.push_back(p2);
	edges.push_back(p3);
	edges.push_back(p4);
	edges.push_back(p5);

	Solution s;
	vector<int> retval;
	
	retval = s.findMinHeightTrees(6, edges);
	for (int i = 0; i < retval.size(); ++i)
		cout << retval[i] << " ";
	cout << endl;
	return 0;
}