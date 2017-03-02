/*
Giving a string with number from 1-n in random order, but miss 1 number. Find that number.

Notice
1. n <= 30

Example
Given n = 20, str = 19201234567891011121314151618
return 17

Tags 
Backtracking Depth First Search
*/

#include <bitset>

class Solution {
public:
    /**
     * @param n an integer
     * @param str a string with number from 1-n in 
     *            random order and miss one number
     * @return an integer
     */
    int findMissing2(int n, string& str) {
        // Write your code here
        int data = 0;
        findMissing2(n, n, 0, str, data);
        for (int i = n; i >= 1; i--)
            if ((data & (1 << i)) == 0)
                return i;
        return -1;
    }

private:
    bool findMissing2(int n, int cnt, int idx, string &str, int &data) {
        if (idx == str.length())
            return cnt == 1;

        int val = str[idx] - '0';
        if (val == 0)
            return false;

        if ((data & (1 << val)) == 0) {
            data |= (1 << val);
            if (findMissing2(n, cnt - 1, idx + 1, str, data))
                return true;
            data &= (~(1 << val));
        }
        
        if (idx + 1 < str.length()) {
            val = 10*val + str[idx + 1] - '0';
            if (val <= n && (data & (1 << val)) == 0) {
                data |= (1 << val);
                if (findMissing2(n, cnt - 1, idx + 2, str, data))
                    return true;
                data &= (~(1 << val));
            } 
        }
        return false;
    }
};
