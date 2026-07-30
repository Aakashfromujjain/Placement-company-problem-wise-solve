#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int getLongestSubarray(const vector<int> &arr,int L)	{
	if(arr.empty()) return 0;
	
	int max_len = 1;
	int current_streak=1;
	
	for(size_t i=1;i<arr.size();i++)	{
		if(abs(arr[i] - arr[i-1] <=L))	{
			current_streak++;
		}else{
			max_len = max(max_len , current_streak);
			current_streak= 1;
		}
	}
	return max(max_len,current_streak);
}


int main()	{
	vector <int> arr={10,11,12,15,17};
	int L=2;
	
	cout<<getLongestSubarray(arr,L)<<"\n";
	
	return 0;
}
