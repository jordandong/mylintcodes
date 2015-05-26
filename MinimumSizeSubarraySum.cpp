/*
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.
Have you met this question in a real interview? Yes

Example
Given the array [2,3,1,2,4,3] and s = 7, the subarray [4,3] has the minimal length under the problem constraint.

Challenge
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).

Tags Expand 
Two Pointers Array
*/

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @param s: an integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        // write your code here
        int N = nums.size();
        if (N == 0)
            return 0;
        vector<int> sum(N + 1, 0);
        for (int i = 1; i <= N; i++) 
                sum[i] = sum[i - 1] + nums[i - 1];
        int i = 0, j = 1;
        int mi = N + 1;
        while (j <= N) {
            if (sum[j] - sum[i] >= s) {
                if (j - i < mi)
                    mi = j - i;
                i++;
            } else {
                j++;
            }
        }
        return mi == N + 1 ? 0 : mi;
    }
};
