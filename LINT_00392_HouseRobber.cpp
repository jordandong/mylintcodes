/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
Have you met this question in a real interview? Yes

Example
Given [3, 8, 4], return 8.

Challenge
O(n) time and O(1) memory.

Tags Expand 
Dynamic Programming
*/

class Solution {
public:
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> A) {
        // write your code here
        int N = A.size();
        long long rob_mx = 0, no_rob_mx = 0;
        for (auto e : A) {
            long long tmp_rob_mx = rob_mx;
            rob_mx = no_rob_mx + e;
            no_rob_mx = max(tmp_rob_mx, no_rob_mx);
        }
        return max(rob_mx, no_rob_mx);
    }
};
