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
			if(start < tmp.start){
				start_pos = i;
				flag1 = 0;
				break;
			}
			else{
				if(start <= tmp.end){
					start_pos = i;
					flag1 = 1;
					break;
				}
			}
			i++;
		}
		if(i==n){
			intervals.push_back(newInterval);
			return intervals;
		}
		while(i<n){
			Interval tmp = intervals[i];
			if(end < tmp.start){
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
		if(i==n)
			end_pos = n;

		if(start_pos == end_pos && !flag1 && !flag2){
			intervals.insert(intervals.begin()+start_pos,newInterval);
			return intervals;
		}
		if(flag1 && flag2){
			intervals[start_pos].end = intervals[end_pos].end;
			transfer(intervals,start_pos,end_pos+1);
		}
		else if(flag1 && !flag2){
			intervals[start_pos].end = end;
			transfer(intervals,start_pos,end_pos);
		}
		else if(!flag1 && flag2){
			intervals[end_pos].start = start;
			transfer(intervals,start_pos-1,end_pos); 
		} 
		else{
			intervals[start_pos].start = start;
			intervals[start_pos].end = end;
			transfer(intervals,start_pos,end_pos);
		}
		return intervals;	    
    }
    void transfer(vector<Interval>& vec,int start,int end){
    	
    	while(end<vec.size()){
    		vec[++start] = vec[end++];
    	}
    	int n = vec.size();
    	start+=1;
    	vec.erase(vec.begin()+start,vec.begin()+n);
    }
    
};

int main(){
	Interval a1(1,5);
	Interval a2(12,15);
	Interval a3(6,7);
	Interval a4(9,11);
	Interval a5(26,27);
	Interval a6(28,31);
	vector<Interval> t;
	t.push_back(a1);
//	t.push_back(a2);
//	t.push_back(a3);
//	t.push_back(a4);
//	t.push_back(a5);
//	t.push_back(a6);
	Solution s;
	Interval aa(2,3);
	s.insert(t,aa);
//	t.erase(t.begin()+2,t.begin()+4);
//	transfer(t,2,6);
	for(int i=0;i<t.size();i++)
		cout<<"["<<t[i].start<<","<<t[i].end<<"] ";
	return 0;
} 
