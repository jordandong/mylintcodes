/*
There is a room with n lights which are turned on initially and 4 buttons on the wall. After performing exactly m unknown operations towards buttons, you need to return how many different kinds of status of the n lights could be.

Suppose n lights are labeled as number [1, 2, 3 ..., n], function of these 4 buttons are given below:

You can flip all the lights.
You can flip lights with even numbers.
You can flip lights with odd numbers.
You can flip lights with (3k + 1) numbers, k = 0, 1, 2, ...

Example
Given n = 1, m = 1.
return 2 // Status can be: [on], [off]

Given n = 2, m = 1.
return 3 // Status can be: [on, off], [off, on], [off, off]
Tags 
Mathematics
*/

class Solution {
public:
    /*
     * @param : number of lights
     * @param : number of operations
     * @return: the number of status
     */
    int flipLights(int n, int m) {
        // write your code here
        if (n <= 0 || m <= 0)
            return 1;
        if (n == 1) // o -> o, f
            return 2;
        if (n == 2) //oo -> ff, of, fo -> oo, fo, of, ff -> ...
            return 4 - (m == 1);
        //ooo -> fff, ofo, fof, foo -> ooo, ofo, fof, off, fff, ffo, oof -> fff, fof, ofo, foo, ooo, ffo, oof, off
        //n == 4, the 4th bulk is the same as 1th bulk since 3k + 1 = 1, 4, 7 ...
        if (m == 1)
            return 4;
        if (m == 2)
            return 7;
        return 8;
    }
};

