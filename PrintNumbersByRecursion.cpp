/*
Print numbers from 1 to the largest number with N digits by recursion.

Example
Given N = 1, return [1,2,3,4,5,6,7,8,9].
Given N = 2, return [1,2,3,4,5,6,7,8,9,10,11,12,...,99].

Note
It's pretty easy to do recursion like:

recursion(i) {
    if i > largest number:
        return
    results.add(i)
    recursion(i + 1)
}
however this cost a lot of recursion memory as the recursion depth maybe very large. Can you do it in another way to recursive with at most N depth?

Challenge
Do it in recursion, not for-loop.

Tags Expand 
Recursion
*/

//Non Recursion
class Solution {
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    vector<int> numbersByRecursion(int n) {
        // write your code here
        int last_start = 0;
        int last_end = 0;
        vector<int> res;
        while (n > 0) {
            last_end = res.size() - 1;
            if (last_end < 0) {
                for (int i = 1; i < 10; i++)
                    res.push_back(i);
            } else {
                while (last_start <= last_end) {
                    for (int i = 0; i < 10; i++)
                        res.push_back(10*res[last_start] + i);
                    last_start++;
                }
            }
            n--;
        }
        return res;
    }
};

//Recursion
class Solution {
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    vector<int> numbersByRecursion(int n) {
        // write your code here
        vector<int> res;
        numbersByRecursionHelper(n, 0, res);
        return res;
    }
    
    void numbersByRecursionHelper(int n, int last_start, vector<int> &res) {
        if(n == 0)
            return;
        int last_end = res.size() - 1;
        if (last_end < 0) {
            for (int i = 1; i < 10; i++)
                res.push_back(i);
        } else {
            while (last_start <= last_end) {
                for (int i = 0; i < 10; i++)
                    res.push_back(10*res[last_start] + i);
                last_start++;
            }
        }
        numbersByRecursionHelper(n - 1, last_start, res);
    }
};
