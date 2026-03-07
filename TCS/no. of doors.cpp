
#https://www.geeksforgeeks.org/problems/number-of-open-doors1552/1?page=1&company=TCS,IBM,Capgemini&difficulty=Easy&sortBy=submissions
*/
Number Of Open Doors
Difficulty: EasyAccuracy: 36.15%Submissions: 62K+Points: 2
Consider a long alley with a n number of doors on one side. All the doors are closed initially. You move to and fro in the alley changing the states of the doors as follows: you open a door that is already closed and you close a door that is already opened. You start at one end go on altering the state of the doors till you reach the other end and then you come back and start altering the states of the doors again.
In the first go, you alter the states of doors numbered 1, 2, 3, , n.
In the second go, you alter the states of doors numbered 2, 4, 6
In the third go, you alter the states of doors numbered 3, 6, 9
You continue this till the Nth go in which you alter the state of the door numbered N.
You have to find the number of open doors at the end of the procedure.

Example :

Input: n = 2
Output: 1
Explanation: Following the sequence 4 times, we can see that only 1st door will remain open.
Input: n = 4
Output: 2
Explanation: Following the sequence 4 times, we can see that only 1st and 4th doors will remain open.
Constraints:
1 <= n <= 109

*/
class Solution {
  public:
    int noOfOpenDoors(int n) {
        // code here
        return sqrt(n);
    }
};
