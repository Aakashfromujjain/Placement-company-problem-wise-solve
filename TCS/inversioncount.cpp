class Solution {
  public:
    int inversionCount(vector<int> &arr) {
        // Code Here
        int siz=arr.size();
        int count;
        for(int i=0;i<=siz;i++)
        {
            for(int j=0;j<siz;j++)
            {
                if(i<j && arr[i]>arr[j])
                {
                    count++;
                }
            }
        }
        return count;
    }
};
