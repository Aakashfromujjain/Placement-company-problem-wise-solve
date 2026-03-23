#include <bits/stdc++.h>
using namespace std;

int main() {
int month;
cout<<"Enter the Month: ";
cin>>month;
if(month<=0) cout<< "Invalid input";
else if(month==1) cout<< "Cost: 2000";
else if(month==2 || month==3) cout<< "Cost: 5000";
else if(month>=4 && month <=6) cout<<"Cost: 9000";
else cout<<"Cost: 15000";
return 0;
}
