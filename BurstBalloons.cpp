/*
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.
Find the maximum coins you can collect by bursting the balloons wisely.
-You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
-0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

Have you met this question in a real interview? Yes

Example:
Given [4, 1, 5, 10]
Return 270
nums = [4, 1, 5, 10] burst 1, get coins 4 * 1 * 5 = 20
nums = [4, 5, 10]    burst 5, get coins 4 * 5 * 10 = 200 
nums = [4, 10]       burst 4, get coins 1 * 4 * 10 = 40
nums = [10]          burst 10, get coins 1 * 10 * 1 = 10
Total coins 20 + 200 + 40 + 10 = 270

Tags:
Dynamic Programming
*/

/*
We then think can we apply the divide and conquer technique? After all there seems to be many self similar sub problems from the previous analysis.

Well, the nature way to divide the problem is burst one balloon and separate the balloons into 2 sub sections one on the left and one one the right. However, in this problem the left and right become adjacent and have effects on the maxCoins in the future.

Then another interesting idea come up. Which is quite often seen in dp problem analysis. That is reverse thinking. Like I said the coins you get for a balloon does not depend on the balloons already burst. Therefore instead of divide the problem by the first balloon to burst, we divide the problem by the last balloon to burst.

Why is that? Because only the first and last balloons we are sure of their adjacent balloons before hand!

For the first we have nums[i-1]*nums[i]*nums[i+1] for the last we have nums[-1]*nums[i]*nums[n].

OK. Think about n balloons if i is the last one to burst, what now?

We can see that the balloons is again separated into 2 sections. But this time since the balloon i is the last balloon of all to burst, the left and right section now has well defined boundary and do not affect each other! Therefore we can do either recursive method with memoization or dp.

Final

Here comes the final solutions. Note that we put 2 balloons with 1 as boundaries and also burst all the zero balloons in the first round since they won't give any coins. The algorithm runs in O(n^3) which can be easily seen from the 3 loops in dp solution.
*/

class Solution {
public:
    /**
     * @param nums a list of integer
     * @return an integer, maximum coins
     */  
    int maxCoins(vector<int>& nums) {
        // Write your code here
        int nums_all[nums.size() + 2];
        int n = 1;
        for (int x : nums) {
            if (x > 0) {
                //0 could be burst first without changing the results
                nums_all[n++] = x;
            }
        }
        nums_all[0] = 1;
        nums_all[n++] = 1;
        
        vector<vector<int> > dp(n, vector<int>(n, 0));
        //dp from ending to begining
        for (int k = 2; k < n; ++k) { //burst (k-1)th ballon from the ending
            for (int left = 0; left < n - k; ++left) {
                int right = left + k;
                for (int i = left + 1; i < right; ++i) {
                    //burst balloon at i will not affect the results on the left or right side on next step 
                    dp[left][right] = max(dp[left][right],
                         nums_all[left] * nums_all[i] * nums_all[right] + dp[left][i] + dp[i][right]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
