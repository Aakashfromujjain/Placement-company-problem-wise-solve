#include <iostream>
#include <algorithm>
#include <set>
#include <string> 

using namespace std;

int main()
{
	string st="I am the god of the new world";
	set<char> present_chars;
	
	for (int i=0; i<st.length(); i++)
	{
		if(st[i]>= 'a' && st[i]<= 'z'){
			present_chars.insert(st[i]);
		}
		else if(st[i] >= 'A' && st[i] <= 'Z') {
			present_chars.insert(tolower(st[i]));
		}
	}
	
	//check which characters are missing
	string missing_chars ="";
	for(char c='a'; c<='z'; c++){
		if(present_chars.find(c) == present_chars.end()){
			missing_chars += c;
		}
	}
	
	cout<<missing_chars<<endl;
	return 0;
}
