/*
Given two arrays, write a function to compute their intersection.

Notice,
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.

Example,
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Challenge, 
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to num2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

Tags, 
Binary Search Two Pointers Sort Hash Table
*/

class Solution {
public:
    /**
     * @param nums1 an integer array
     * @param nums2 an integer array
     * @return an integer array
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Write your code here
        vector<int> res;
        unordered_map<int, int> mp;
        for (auto &e : nums1)
            mp[e]++;
        for (auto &e : nums2)
            if (mp[e]-- > 0)
                res.push_back(e);
        return res;
    }
};

class Solution {
public:
    /**
     * @param nums1 an integer array
     * @param nums2 an integer array
     * @return an integer array
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Write your code here
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0, M = nums1.size(), N = nums2.size();
        while (i < M && j < N) {
            if (nums1[i] < nums2[j])
                i++;
            else if (nums1[i] > nums2[j])
                j++;
            else {
                res.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return res;
    }
};
