/*
Given a non-negative number represented as an array of digits, plus one to the number.
The digits are stored such that the most significant digit is at the head of the list.

Example
Given [1,2,3] which represents 123, return [1,2,4].
Given [9,9,9] which represents 999, return [1,0,0,0].

Tags Expand 
Array
*/

class Solution {
public:
    /**
     * @param digits a number represented as an array of digits
     * @return the result
     */
    vector<int> plusOne(vector<int>& digits) {
        // Write your code here
        vector<int> res;
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            int val = digits[i] + carry;
            res.push_back(val%10);
            carry = val/10;
        }
        if (carry)
            res.push_back(carry);
        if (res.size() != 0)
            reverse(res.begin(), res.end());
        return res;
    }
};
