/*
You have 4 cards each containing a number from 1 to 9.
You need to compute whether they could operated through *, /, +, -, (, ) to get the value of 24.

 Notice

The division operator / represents real division, not integer division. so 4 / (1 - 2/3) = 12.
Every operation done is between two numbers. In particular, we cannot use - as a unary operator.
For example, with [1, 1, 1, 1] as input, the expression -1 - 1 - 1 - 1 is not allowed.
You cannot concatenate numbers together. For example, if the input is [1, 2, 1, 2], we cannot write this as 12 + 12.

Example
Given nums = [4, 1, 8, 7], return true // 8 * （7 - 4） * 1 = 24

Given nums = [1, 1, 1, 2], return false

Given nums = [3, 3, 8, 8], return true // 8 / ( 3 - 8 / 3) = 24

Tags 
Depth First Search
*/

class Solution {
private:
    double eps;
public:
    /**
     * @param nums: 4 cards
     * @return: whether they could get the value of 24
     */
    bool compute24(vector<double> &nums) {
        // write your code here
        eps = 0.001;
        return compute24Helper(nums);
    }        
    
    bool compute24Helper(vector<double> &A) {
        int N = A.size();
        if (N == 1)
            return abs(A[0] - 24.0) < eps;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < i; j++) {
                vector<double> next;
                for (int k = 0; k < N; k++) {
                    if (k != i && k != j)
                        next.push_back(A[k]);
                }
                
                next.push_back(A[i] + A[j]);
                if (compute24Helper(next))
                    return true;
                
                next[next.size() - 1] = (A[i] * A[j]);
                if (compute24Helper(next))
                    return true;
                
                next[next.size() - 1] = (A[i] - A[j]);
                if (compute24Helper(next))
                    return true;
                
                next[next.size() - 1] = (A[j] - A[i]);
                if (compute24Helper(next))
                    return true;
                
                if (abs(A[j]) > eps) {
                    next[next.size() - 1] = (A[i] / A[j]);
                    if (compute24Helper(next))
                        return true;
                }
                
                if (abs(A[i]) > eps) {
                    next[next.size() - 1] = (A[j] / A[i]);
                    if (compute24Helper(next))
                        return true;
                }
            }
        }
        return false;
    }
};
