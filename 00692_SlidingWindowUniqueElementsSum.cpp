/*
Given an array and a window size that is sliding along the array, find the sum of the count of unique elements in each window.

Example
Given a array nums = [1, 2, 1, 3, 3] and k = 3

First window [1, 2, 1], only 2 is unique, count is 1.
Second window [2, 1, 3], all elements unique, count is 3.
Third window [1,3,3] only 1 is unique, count is 1.
sum of count = 1 + 3 + 1 = 5

Return 5

Tags 
Array
*/

class Solution {
public:
    /*
     * @param : the given array
     * @param : the window size
     * @return: the sum of the count of unique elements in each window
     */
    int slidingWindowUniqueElementsSum(vector<int> nums, int k) {
        // write your code here
        unordered_map<int, int> mp;
        queue<int> q;
        int res = 0, cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            q.push(nums[i]);
            ++mp[nums[i]];
            if (1 == mp[nums[i]])
                cur += 1;
            else if (2 == mp[nums[i]]) {
                cur -= 1;
            }
            
            while (q.size() > k) {
                --mp[q.front()];
                if (0 == mp[q.front()]) {
                    cur -= 1;
                } else if (1 == mp[q.front()]) {
                    cur += 1;
                }
                q.pop();
            }
            if (i + 1 >= k || i == nums.size() - 1) {
                if (0) {
                    for (auto it = mp.begin(); it != mp.end(); it++) {
                        if (it->second == 1)
                            res++;
                    }
                } else {
                    res += cur;
                }
            }
        }
        return res;
    }
};
