class Solution {
public:
  void reversestring(vector<char> &s)
        {
            int i=0 , j=s.size()-1 ;
                while(i<j){
                    swap(s[i++],s[j--])
                      }
        }
}
