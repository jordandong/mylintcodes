/*
Follow up for N-Queens problem. Now, instead outputting board configurations, return the total number of distinct solutions.
Example:
For n=4, there are 2 distinct solutions.
*/

class Solution {
public:
    /**
     * Calculate the total number of distinct N-Queen solutions.
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    int totalNQueens(int n) {
        // write your code here
        int mp[n];
        int total = 0;
        memset(mp, 0, sizeof(int)*n);
        totalNQueen(n, 0, mp, total);
        return total;
    }
    
    void totalNQueen(int n, int c, int* mp, int &total){
        if(c == n){
            total++;
            return;
        }
        for(int r = 0; r < n; r++){
            if(checkValid(r, c, mp)){
                mp[c] = r;
                totalNQueen(n, c+1, mp, total);
            }
        }
    }

    bool checkValid(int r, int c, int* mp){
        for(int i = 0; i<c; i++){
            if(abs(mp[i] - r) == (c - i) || mp[i] == r)
                return false;
        }
        return true;
    }
};
