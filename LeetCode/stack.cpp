#include <iostream>
#include <limits>
using namespace std;


class MinStack {
private:
	int sta[1000];
	int point; 
public:
    void push(int x) {
    	sta[point] = x;
		point++;	    
    }

    void pop() {
        point--;
    }

    int top() {
        return sta[point-1];
    }

    int getMin() {
        int m = 65535;
        int i = 0;
        while(i<point){
        	if(sta[i] < m)
        		m = sta[i];
        	i++;
        }
        return m;
    }
    MinStack(int a[],int n){
    	point = 0;
    	while(point < n){
    		sta[point] = a[point];
    		point++;
    	}
    }
};

int main(){
	int a[] = {1,2,3,4,5,6,7,8,9};
	MinStack min(a,9);
	min.push(10);
	min.pop();
	cout<<min.top()<<endl;;
	cout<<min.getMin()<<endl;
	return 0;
}
