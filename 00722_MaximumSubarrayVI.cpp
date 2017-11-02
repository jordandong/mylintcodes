/*
Given an array of integers. find the maximum XOR subarray value in given array.

What's the XOR: https://en.wikipedia.org/wiki/Exclusive_or

 Notice

Expected time complexity O(n).

Example
Given nums = [1, 2, 3, 4], return 7
The subarray [3, 4] has maximum XOR value

Given nums = [8, 1, 2, 12, 7, 6], return 15
The subarray [1, 2, 12] has maximum XOR value

Given nums = [4, 6], return 6
The subarray [6] has maximum XOR value

Tags 
Bit Manipulation Trie Facebook
*/

class Solution {
public:
    /*
     * @param : the array
     * @return: the max xor sum of the subarray in a given array
     */
    int maxXorSubarray(vector<int> &nums) {
        // write code here
        int n = nums.size();
        vector<int> xors(n + 1, 0);
        for (int i = 0; i < n; i++) {
            xors[i + 1] = (xors[i] ^ nums[i]);
        }
        int res = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                res = max(res, xors[j] ^ xors[i]);
            }
        }
        return res;
    }
};
