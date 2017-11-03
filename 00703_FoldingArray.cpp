/*
Given an array nums of length n and an array req of length k , you need to fold the array as required, and output the result of the fold.
1.If req[i] = 0 means you should fold from left to right
for example:

1 2 3 4 5 6 7 8  ==>   4 3 2 1
                       5 6 7 8
2.If req[i] = 1 means you should fold from right to left
for example:

1 2 3 4 5 6 7 8  ==>   8 7 6 5
                       1 2 3 4
More example:

fold from left to right
4 3 2 1  ==>  6 5
5 6 7 8       3 4
              2 1
              7 8


fold from right to left
6 5  ==>   8
3 4        1
2 1        4
7 8        5
           6
           3
           2
           7 
 Notice

n is power of two.
k is index.(e.g. n = 2^3 = 8，k = 3)

Example
Given array nums = [1, 2, 3, 4, 5, 6, 7, 8] and array req = [0, 0, 1]
change array in place to be [8, 1, 4, 5, 6, 3, 2, 7]

Challenge 
How to do in place?

Tags 
Mathematics Array Amazon
*/

class Solution {
public:
    /*
     * @param : the original array
     * @param : the direction each time
     * @return: the final folded array 
     */
    vector<int> folding(vector<int> &nums, vector<int> &req) {
        // write your code here
        vector<vector<int>> data(1, nums);
        vector<vector<int>> res;
        vector<int> ans;
        for (auto flap : req) {
            res = foldingHelper(data, flap);
            data = res;
        }
        for (auto e : res)
            ans.push_back(e[0]);
        return ans;
    }
    
private:
    vector<vector<int>> foldingHelper(vector<vector<int>> &data, int flap) {
        int m = data.size(), n = data[0].size();
        vector<vector<int>> res(2 * m, vector<int>(n / 2, 0));
        for (int i = 0; i < m; i++) {
            if (flap) {
                for (int j = 0; j < n / 2; j++)
                    res[m + i][j] = data[i][j];
                for (int j = n / 2; j < n; j++)
                    res[m - 1 - i][ n - 1 - j] = data[i][j];
            } else {
                for (int j = 0; j < n / 2; j++)
                    res[m - 1 - i][n /2 - 1 - j] = data[i][j];
                for (int j = n / 2; j < n; j++)
                    res[m + i][j - n / 2] = data[i][j];
            }
        }
        return res;
    }
};
