/*
Given an unsorted array nums, reorder it such that
nums[0] < nums[1] > nums[2] < nums[3]....

Have you met this question in a real interview? Yes

Notice
You may assume all input has valid answer.

Example
Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6].
Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].

Challenge
Can you do it in O(n) time and/or in-place with O(1) extra space?
*/

// T:  O(n) ~ O(n^2), S : O(1)
// three way Partition (aka Dutch National Flag Problem) with virtual index solution.
class Solution {
public:
    /**
     * @param nums a list of integer
     * @return void
     */  
    void wiggleSort(vector<int>& nums) {
        // Write your code here
        int mid = (nums.size() - 1) / 2;
        nth_element(nums.begin(), nums.begin() + mid, nums.end());  // O(n) ~ O(n^2) time
        reversedTriPartition(nums, nums[mid]);  // O(n) time, O(1) space
    }

    void reversedTriPartition(vector<int>& nums, int val) {
        const int N = nums.size() / 2 * 2 + 1;
        //1, 3, 5, 7, 9, ..., 0, 2, 4, 6, 8, ...
        #define Nums(i) nums[(1 + 2 * (i)) % N]
        int i = 0, j = 0, n = nums.size() - 1;
        //place bigger value at 1,3,5,7,... and smaller value at 2,4,6,8,...
        while (j <= n) {
            if (Nums(j) > val) {
                swap(Nums(i++), Nums(j++));
            } else if (Nums(j) < val) {
                swap(Nums(j), Nums(n--));
            } else {
                ++j;
            }
        }
    }
};

//T:O(nlogn) S:O(n)
class Solution {
public:
    /**
     * @param nums a list of integer
     * @return void
     */  
    void wiggleSort(vector<int>& nums) {
        // Write your code here
        vector<int> res;
        int n = nums.size();
        int i = (n - 1)/2, j = n - 1;
        sort(nums.begin(), nums.end());
        while (j > (n - 1)/2) {
            res.push_back(nums[i--]);
            res.push_back(nums[j--]);
        }
        if (i >= 0)
            res.push_back(nums[i--]);
        nums = res;
    }
};
