
#include<bits/stdc++.h>

using namespace std;

int main() {
	int N=8;
	int arr[N]={4,5,0,1,9,0,5,0};
	
	int a=0;
	int b=sizeof(arr);
	for(int i=0;i<N ;i++)	{
	
		if(arr[i]!=0){
			swap(arr[a],arr[i]);
			a++;
	
		}
	}
	for(int i=0;i<N;i++)
	{
		cout<<arr[i]<<"  ";
	}
}
