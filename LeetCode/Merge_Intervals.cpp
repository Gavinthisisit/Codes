#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Definition for an interval.
 **/
struct Interval {
   int start;
   int end;
   Interval() : start(0), end(0) {}
   Interval(int s, int e) : start(s), end(e) {}
};
 
bool compare(const Interval& a,const Interval& b){
	if(a.start == b.start)
		return a.end < b.end;
	return a.start < b.start;
} 

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        cout<<intervals.size();
        vector<Interval> retval;
        
        if(intervals.size()==0)
        	return retval;
        int pre_end = intervals[0].end;
        Interval s(intervals[0].start,pre_end);
        
        for(int i=1;i<intervals.size();i++){
        	if(intervals[i].start > pre_end){
        		s.end = pre_end;
        		retval.push_back(s);
        		s.start = intervals[i].start;
        		pre_end = intervals[i].end;
        	}
        	else
        		pre_end = max(intervals[i].end,pre_end);
        }
        s.end = pre_end;
        retval.push_back(s);
        return retval;
    }
};


int main(){
	Interval a1(1,3);
	Interval a2(2,6);
	Interval a3(8,10);
	Interval a4(15,18);
	
	vector<Interval> inter;
	inter.push_back(a1);
	inter.push_back(a3);
	inter.push_back(a2);
	inter.push_back(a4);
	Solution s;
	vector<Interval> vec;
	vec = s.merge(inter);
	cout<<vec.size();
	return 0;
}
