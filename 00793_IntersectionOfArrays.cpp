/*
Give a number of arrays, find their intersection, and output their intersection size.

 Notice
The total number of all array elements is not more than 500000.
There are no duplicated elements in each array.
Have you met this question in a real interview? Yes
Example
Given [[1,2,3],[3,4,5],[3,9,10]], return 1

explanation:
Only element 3 appears in all arrays, the intersection is [3], and the size is 1.
Given [[1,2,3,4],[1,2,5,6,7][9,10,1,5,2,3]], return 2

explanation:
Only element 1,2 appear in all arrays, the intersection is [1,2], the size is 2.
*/

class Solution {
public:
    /**
     * @param arrs: the arrays
     * @return: the number of the intersection of the arrays
     */
    int intersectionOfArrays(vector<vector<int>> &arrs) {
        // write your code here
        unordered_map<int, bool> mp;
        vector<int> res;
        int n = arrs.size();
        if (n == 0)
            return 0;
        for (auto num : arrs[0])
            mp[num] = true;
        for (int i = 1; i < n; i++) {
            unordered_map<int, bool> tmp;
            for (int j = 0; j < arrs[i].size(); j++) {
                if (mp.find(arrs[i][j]) != mp.end())
                    tmp[arrs[i][j]] = true;
            }
            mp = tmp;
        }
        return mp.size();
    }
};
