/*
Given an array of integers, replace every element with the next greatest element (greatest element on the right side) in the array.
Since there is no element next to the last element, replace it with -1.
For example, if the array is [16, 17, 4, 3, 5, 2], then it should be modified to [17, 5, 5, 5, 2, -1].

Example
Give nums = [16, 17, 4, 3, 5, 2], change nums to [17, 5, 5, 5, 2, -1]
You should do it in place.

Tags 
Array Amazon
*/

class Solution {
public:
    /*
     * @param : An array of integers.
     * @return: nothing
     */
    void arrayReplaceWithGreatestFromRight(vector<int> &nums) {
        // Write your code here.
        int mx = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i == nums.size() - 1) {
                mx = nums[i];
                nums[i] = -1;
            } else {
                int tmp_mx = max(mx, nums[i]);
                nums[i] = mx;
                mx = tmp_mx;
            }
        }
    }
};

