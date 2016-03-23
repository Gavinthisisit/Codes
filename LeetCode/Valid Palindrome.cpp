#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {
    	int len = s.length();
		int head,tail;
		bool flag = false;
		bool char1,char2,char3,char4;
		bool number1,number2;
		head = 0;
		tail = len-1;
		char sub_head,sub_tail;
		while(head != tail && head<tail){
			char1 = s[head] > 96 && s[head] <123;
			char2 = s[head] > 64 && s[head] <91;
			number1 = s[head] >47 && s[head] <58;
		   	char3 = s[tail] > 96 && s[tail] <123;
			char4 = s[tail] > 64 && s[tail] <91;
			number2 = s[tail] >47 && s[tail] <58;
			if(char2)
				sub_head = 	s[head]+32;
			else if(char1 || number1)
				sub_head = s[head];
			else{
				head++;
				continue;
			}
			if(char4)
				sub_tail = s[tail]+32;
			else if(char3 || number2)
				sub_tail = s[tail];
			else{
				tail--;
				continue;
			}	 	   	
		   	if(sub_tail != sub_head){
		   		flag = true;
				break;	
		   	}
		   	head++;
		   	tail--;
		   	
	   	}
	  if(!flag)
	  	 return true;
	  else
	  	 return false;	
	}
};


int main(){
	string str = "1a2";
	Solution s;
	cout<<s.isPalindrome(str)<<endl;
	cout<<str<<endl;
//	cout<<ch2<<endl;
	return 0;
}
