#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    
    // Start from the second last row and move upwards
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < triangle[i].size(); j++) {
            // Find the minimum of the two adjacent nodes below it
            int left_child = triangle[i + 1][j];
            int right_child = triangle[i + 1][j + 1];
            
            // Update the current position in-place
            triangle[i][j] += min(left_child, right_child);
        }
    }
    
    // The top element now contains the total minimum path sum
    return triangle[0][0];
}

int main() {
    vector<vector<int>> triangle_input = {
               {2},
              {3, 4},
             {6, 5, 7},
            {4, 1, 8, 3}
    };
    
    cout << "Minimum path sum: " << minimumTotal(triangle_input) << endl; // Output: 11
    return 0;
}
