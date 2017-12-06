/*
Given a matrix, find a element that appear in all the rows in the matrix.You can assume that there is only one such element.

Example
For example:
Given a matrix:

[
  [2,5,3],
  [3,2,1],
  [1,3,5]
]
return 3

Tags 
Hash Table Matrix
*/

class Solution {
public:
    /**
     * @param Matrix: the input
     * @return: the element which appears every row
     */
    int FindElements(vector<vector<int>> &Matrix) {
        // write your code here
        unordered_map<int, int> mp;
        int n = Matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < Matrix[0].size(); j++) {
                if (mp[Matrix[i][j]] == i)
                    mp[Matrix[i][j]]++;
            }
        }
        
        for (auto m : mp) {
            if (m.second == n)
                return m.first;
        }
        
        return 0;
    }
};
