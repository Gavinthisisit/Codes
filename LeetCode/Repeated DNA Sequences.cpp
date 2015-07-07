#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstring>

using namespace std;


///最朴素的方法，会超时 
/*
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s){
    	vector<string> retval;
    	if(s.length() < 10)
    		return retval;
    	map<string,int> mapstr;
    	
		for(int i=0;i<s.length()-10;i++){
			string tmp = s.substr(i,i+10);
			if(mapstr[tmp] == 1)
				continue;
			string source = s.substr(i+1);
			if(source.find(tmp) == 1){
				mapstr.insert(pair<string,int>(tmp,1));
				retval.push_back(tmp);
			}
		}
		return retval;		    
    }
};*/
bool hashMap[1024*1024];
map<int,int> has_Input;
class Solution{
public:
	vector<string> findRepeatedDnaSequences(string s){
		vector<string> retval; 
		if(s.length() <= 10)
			return retval;
		int trans[26];
		trans[0] = 0;
		trans['C'-'A'] = 1;
		trans['G'-'A'] = 2;
		trans['T'-'A'] = 3;
		
		memset(hashMap,false,sizeof(hashMap));
		has_Input.clear();
		int i;
		int hashValue = 0;
		for(i=0;i<10;i++){
			hashValue <<= 2;
			hashValue |= trans[s[i]-'A'];
		}
		hashMap[hashValue] = true;
		
		for(i=10;i<s.length();i++){
			hashValue <<= 2;
			hashValue |= trans[s[i]-'A'];
			hashValue &= ~(0x300000);
			
			if(hashMap[hashValue]){
				if(has_Input[hashValue] == 0){
					retval.push_back(s.substr(i-9,10));
					has_Input[hashValue] = 1;
				}
			}
			else
				hashMap[hashValue] = true;
		}
		return retval;
	}		
}; 


int main(){
	string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
/*	string s1 = s.substr(1);
	cout<<s1<<endl;
	int t = s.find("sabc");
	map<string,int> mapstr;
	mapstr.insert(pair<string,int>("abc",1));
	mapstr["bbb"] = 1;
	cout<<mapstr["abc"]<<" "<<mapstr["bbb"]<<endl;
	cout<<mapstr["abcd"]<<endl;
	cout<<t;*/
	
	
	
	vector<string> v;
	Solution so;
	v = so.findRepeatedDnaSequences(s);
	
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
	return 0;
}
