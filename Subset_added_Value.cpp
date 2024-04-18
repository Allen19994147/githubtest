#include<iostream>
//Input an integer array and a number.
//The task is to find all possible subset summation that equal to the number. 
void subsetSum(int *arr,int num, int len,int *result,int length,int target);
using namespace std;
int main ()
{
	int num,len=1;
	while(len)
	{
		cout<<"\nInput the length of the integer array! Or zero to escape.\n";
		cin>>len;
		if(len==0)
		{
			break;
		 } 
		cout<<"Input the elements of the array.(Integer only!)\n";
		int arr[len+1],result[len+1];
		for(int i=0;i<len;i++)
		{
			cout<<"Input the "<<i+1<<" th element: ";
			cin>>arr[i];
		}
		cout<<"Input the target number: ";
		cin>>num;
		subsetSum(arr,num,len,result,0,num);		
	}
	return 0;
 } 
 
 void subsetSum(int *arr,int num, int len,int *result,int length,int target)
 {
 	if(len==0&&num==0)
 	{
		for(int i=0;i<length;i++)
 		{
 			cout<<result[i];
 			if(i<length-1)
 			{
 				cout<<" + ";
			}
		}
		cout<<" = "<<target<<"\n";
	}else if(len>0)
	{
		subsetSum(arr+1,num,len-1,result,length,target);
		result[length] = arr[0];
		subsetSum(arr+1,num-arr[0],len-1,result,length+1,target);	
	}
 }
