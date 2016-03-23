
//没有使用STL的map,但是对于边缘数据会报错
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define MaxSize   65536

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
		int flag[MaxSize];
//		int array[MaxSize];
		map<int,int> mp;
		map<int,int> value;
//		int seq[100];
		int i;
		for(i=0;i<num.size();i++){
			mp[num[i]] = 1;
			value[num[i]] = 1;
		}
		for(i=0;i<num.size();i++){
			int tmp = num[i];
			int add;
			if(mp.count(tmp+1) && mp[tmp+1] != 0 && mp.count(tmp-1) && mp[tmp-1] != 0 && mp[tmp+1] != 2 && mp[tmp-1] != -1){
					add = value[tmp]+value[tmp+1]+value[tmp-1];
					value[tmp] = value[tmp+1] = value[tmp-1] = add;
					mp[tmp-1] = -1;
					mp[tmp+1] = 2;
			}
			else if(mp.count(tmp-1) && mp[tmp-1] != 0 && mp[tmp-1] != -1){
				add = value[tmp]+value[tmp-1];
				value[tmp] = value[tmp-1] = add;
				mp[tmp-1] = -1;
			}
			else if(mp.count(tmp+1) && mp[tmp+1] != 0 && mp[tmp+1] != 2){
				add = value[tmp]+value[tmp+1];
				value[tmp] = value[tmp+1] = add;
				mp[tmp+1] = 2;
			}
			mp[num[i]] = 0;
		}
		int retval = 0;
		for(i=0;i<num.size();i++){
			if(retval<value[num[i]])
				retval = value[num[i]];
		}

	    return retval;
    }
};
/*

#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define MaxSize   65536

class Solution {
public:
	map<int,int> mp;
   int longestConsecutive(vector<int> &num) {	
		int i;
		for(i=0;i<num.size();i++)
			mp[num[i]] = 1;
		int res = 0;
		for(i=0;i<num.size();i++){
			int sum = 1;
			if(mp.count(num[i])){
				mp[num[i]] = 0;
				int left = num[i]-1;
				while(mp.count(left) && mp[left]!=0){
					mp[left--] = 0;
					sum++;
				}
				int right = num[i]+1;
				while(mp.count(right) && mp[right]!=0){
					mp[right++] = 0; 
					sum++;
				}
			}
			if(res<sum)
				res = sum;
		}
		return res;
    }
/* 	map<int,int> mp;  
    int longestConsecutive(vector<int> &num) {  
        // Start typing your C/C++ solution below  
        // DO NOT write int main() function  
        int i,j;  
        for(i=0;i<num.size();i++)  
            mp[num[i]]=1;  
        int res=0;  
        for(i=0;i<num.size();i++){  
            int sum=1;  
            if(mp.count(num[i])){  
                mp[num[i]]=0;  
                int left=num[i]-1;  
                while(mp.count(left)&&mp[left]!=0){  
                    mp[left--]=0;  
                    sum++;  
                }  
                int right=num[i]+1;  
                while(mp.count(right)&&mp[right]!=0){  
                    mp[right++]=0;  
                    sum++;  
                }  
            }  
            if(res<sum)  
                res=sum;  
        }  
        return res;  
    }  
};*/

int main(){
	int t[] = {0,3,7,2,5,8,4,6,0,1};
	vector<int> vv(t,t+sizeof(t)/sizeof(t[0]) );
	Solution s;
	cout<<s.longestConsecutive(vv)<<endl;
	return 0;

}

