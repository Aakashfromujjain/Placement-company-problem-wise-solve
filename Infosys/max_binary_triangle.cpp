#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        // heights array size is cols + 1 to include a trailing 0 
        // which automatically flushes the remaining elements out of the stack
        vector<int> heights(cols + 1, 0); 
        int maxArea = 0;

        for (int i = 0; i < rows; ++i) {
            // Step 1: Update the histogram heights for the current row
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == 1) {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }

            // Step 2: Find the largest rectangle in the current histogram using a monotonic stack
            stack<int> s;
            for (int j = 0; j < heights.size(); ++j) {
                while (!s.empty() && heights[j] < heights[s.top()]) {
                    int h = heights[s.top()];
                    s.pop();
                    int w = s.empty() ? j : j - s.top() - 1;
                    maxArea = max(maxArea, h * w);
                }
                s.push(j);
            }
        }

        return maxArea;
    }
};

int main() {
    // Sample Input from the video
    vector<vector<int>> matrix = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0}
    };

    Solution solver;
    int result = solver.maximalRectangle(matrix);

    cout << "Maximum Rectangle Size: " << result << endl; // Output: 8

    return 0;
}
