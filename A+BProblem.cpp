/*
For given numbers a and b in function aplusb, return the sum of them.

Note
You don't need to parse the input and output. Just calculate and return.

Example
If a=1 and b=2 return 3

Challenge Expand 
Can you do it with out + operation?

Clarification Expand 
Are a and b both 32-bit integers?
- Yes.
*/

class Solution {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        // Just submit this code, then you will get accepted!
        int carry = 0;
        do{
            carry = a & b;
            b = a ^ b;
            a=carry<<1;
        }while(a);
        return b;
    }
};
