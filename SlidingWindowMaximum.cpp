/*
Given an array of n integer with duplicate number, and a moving window(size k), move the window at each iteration from the start of the array, find the maximum number inside the window at each moving.

Example
For array [1, 2, 7, 7, 8], moving window size k = 3. return [7, 7, 8]

At first the window is at the start of the array like this
[|1, 2, 7| ,7, 8] , return the maximum 7;

then the window move one step forward.
[1, |2, 7 ,7|, 8], return the maximum 7;

then the window move one step forward again.
[1, 2, |7, 7, 8|], return the maximum 8;

Challenge
O(n) time and O(k) memory

Tags Expand 
LintCode Copyright Deque
*/

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The maximum number inside the window at each moving.
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        // write your code here
        deque<int> q;
        vector<int> res;
        int sz = nums.size();

        for(int i = 0; i < sz; i++){
            while(q.size() && nums[q.back()] <= nums[i])
                q.pop_back();
            while(q.size() && q.front() <= i - k)
                q.pop_front();
            q.push_back(i);
            if(i >= k - 1)
                res.push_back(nums[q.front()]);
        }
        return res;
    }
};
