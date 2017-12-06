/*
A Digit Divide Numbers is a number that is divisible by every digit it contains.

For example, 128 is a Digit Divide Numbers because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.

Also, Digit Divide Numbers is not allowed to contain the digit zero.

Given a lower and upper number bound, output a list of every possible Digit Divide Numbers, including the bounds if possible.

Example
Given left = 1, right = 22, return [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]

Tags 
Mathematics
*/

class Solution {
public:
    /**
     * @param lower: Integer : lower bound
     * @param upper: Integer : upper bound
     * @return: a list of every possible Digit Divide Numbers
     */
    vector<int> digitDivideNums(int lower, int upper) {
        // write your code here
        vector<int> ans;
        for (long long num = lower; num <= upper; num++) {
            if (digitDivideNumsHelper(num))
                ans.push_back(num);
        }
        return ans;
    }
    
private:
    bool digitDivideNumsHelper(long long num) {
        int orig = num;
        while (num) {
            int d = num % 10;
            if (d == 0 || (orig % d))
                return false;
            num /= 10;
        }
        return true;
    }
};
