class Solution {
  public:
    int missingNum(vector<int>& arr) {
        int n = arr.size() + 1;
        int xorSum = 0;

        // Step 1: XOR all numbers from 1 to n
        for (int i = 1; i <= n; i++) {
            xorSum ^= i;
        }

        // Step 2: XOR all elements currently in the array
        for (int num : arr) {
            xorSum ^= num;
        }

        // The remaining value is the missing number
        return xorSum;
    }
};
