#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;


//int store[1000000000];			//用来存储已经遍历的回文数
//int point = 1;				//指向当前回文数

void Parlindrome_Check(int arr[],int &length);

int Creat_Parlindrome(int t){
	int arr[10];
	int count = 1;
	int length = 1;
	arr[0] = 1;
	int flag = 0;					//位数发生变化 
	int retval;
	while(count < t){
		if(length%2){
			arr[length/2] += 1;		
		}
		else{
			arr[length/2-1] += 1;
			arr[length/2] += 1;
		}
		Parlindrome_Check(arr,length);
		count++;
	}
	int i = 0;
	retval = 0;
	while(i<length)
		retval = retval*10 + arr[i++];
	return retval; 
	
}
void Parlindrome_Check(int arr[],int &length){
	if(length%2){
		int mid = length/2;
		if(arr[mid] == 10 ){
			arr[mid] = 0;
			int flag = 1;
			int i = 1;
			while(flag && mid-i >= 0){
				flag = 0;
				arr[mid-i] += 1;
				arr[mid+i] += 1;
				if(arr[mid-i] == 10){
					arr[mid-i] = 0;
					arr[mid+i] = 0;
					flag = 1; 
				}
				i++;		
			}
			if(flag){
				length += 1;
				i = 1;
				while(i<length-1)
					 arr[i++] = 0;
				arr[0] = 1;
				arr[length-1] = 1;
			}
		}
	}
	if(length%2 == 0){
		int mid_left = length/2-1;
		int mid_right = length/2;
		if(arr[mid_left] == 10){
			arr[mid_left] = 0;
			arr[mid_right] = 0;
			int flag = 1;
			int i = 1;
			while(flag && mid_left-i >= 0){
				flag = 0;
				arr[mid_left-i] += 1;
				arr[mid_right+i] += 1;
				if(arr[mid_left-i] == 10){
					flag = 1;
					arr[mid_left-i]  = 0;
					arr[mid_right+i] = 0;
				}
				i++;
			}
			if(flag){
				length += 1;
				i = 1;
				while(i<length-1)
					arr[i++] = 0;
				arr[0] = 1;
				arr[length-1] = 1;
			} 
		}
	}
} 

int Creat_Parlindrome_2(int t,int length,int count,int arr[]){
//	int arr[10];
//	int count = 1;
//	int length = 1;
//	arr[0] = 1;
	int flag = 0;					//位数发生变化 
	int retval;
	while(count < t){
		if(length%2){
			arr[length/2] += 1;		
		}
		else{
			arr[length/2-1] += 1;
			arr[length/2] += 1;
		}
		Parlindrome_Check(arr,length);
		count++;
	}
	int i = 0;
	retval = 0;
	while(i<length)
		retval = retval*10 + arr[i++];
	return retval; 
	
}




int main(){
	int input[10000];
	int i = 0;
	int t;
	cin>>t;
	while(t != 0){
		input[i++] = t;
		cin>>t;
	}
	input[i++] = 0;
	i = 0;
	while(input[i] != 0){
			cout<<Creat_Parlindrome(input[i])<<endl;
		i++;
	}
/*	int a[10] = {9,1,1,9};
	Creat_Parlindrome_2(200,4,190,a);*/
	
	return 0;
}
