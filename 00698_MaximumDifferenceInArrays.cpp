/*
Given m arrays, and each array is sorted in ascending order. Now you can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the difference between two integers a and b to be their absolute difference |a-b|. Your task is to find the maximum difference.

 Notice

Each given array will have at least 1 number. There will be at least two non-empty arrays.
The total number of the integers in all the m arrays will be in the range of [2, 10000].
The integers in the m arrays will be in the range of [-10000, 10000].
Have you met this question in a real interview? Yes
Example
Given arrays = [[1,2,3], [4,5], [1,2,3]]
Return 4

One way to reach the maximum difference 4 is to pick 1 in the first or third array and pick 5 in the second array.
Tags 
Array Hash Table Yahoo
*/

class Solution {
public:
    /*
     * @param : an array of arrays
     * @return: return the max distance among arrays
     */
    int maxDiff(vector<vector<int>> &arrs) {
        // write your code here
        int N = arrs.size();
        if (N < 2)
            return 0;
        int mi = arrs[0][0], mx = arrs[0].back(), res = 0;
        for (int i = 1; i < N; i++) {
            res = max(abs(mx - arrs[i][0]), res);
            res = max(abs(arrs[i].back() - mi), res);
            mi = min(mi, arrs[i][0]);
            mx = max(mx, arrs[i].back());
        }
        return res;
    }
};
