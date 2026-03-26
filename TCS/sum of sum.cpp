#include<iostream>

using namespace std;

int main()	{
	int n;
	cin>>n;
	int r;
	cin>>r;
	int sum=0;
	
	
	while(n>0 ){
	
	sum+=n%10;
	n=n/10;
}
sum = sum*r;

while(sum>9)
{
	int ans = 0;
	while(sum>0)
	{
		ans+=(sum%10);
		sum=sum/10;
	}
	sum=ans;
}
cout<<sum;
return 0;
}
