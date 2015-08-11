#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for an interval.
*/ 
struct Interval {
   int start;
   int end;
   Interval() : start(0), end(0) {}
   Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    	int n = intervals.size();
		if(n==0){
			intervals.push_back(newInterval);
			return intervals;
		}
		int flag1 = 0;
		int flag2 = 0;
		int end_pos = 0;
		int start_pos = n;
		int i=0;
		int start = newInterval.start;
		int end = newInterval.end;
		while(i<n){
			Interval tmp = intervals[i];
			if(start <= tmp.start){
				start_pos = i;
				flag1 = 0;
				break;
			}
			else{
				if(start <= tmp.end){
					start_pos == i;
					flag1 = 1;
					break;
				}
			}
			i++;
		}
		while(i<n){
			Interval tmp = intervals[i];
			if(end <= tmp.start){
				end_pos = i;
				flag2 = 0;
				break;
			}
			else{
				if(end <= tmp.end){
					end_pos = i;
					flag2 = 1;
					break;
				}
			}
			i++;
		}
		if(flag1 && flag2){
			
		}
		
		
			
			    
    }
    
};

int main(){
	return 0;
} 
