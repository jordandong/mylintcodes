/*
Given string A representative a positive integer which has N digits, remove any k digits of the number, the remaining digits are arranged according to the original order to become a new minimum positive integer. 
N <= 240 and k <=N, 
Example:
Given an integer A = 178542, k = 4
return a string "12"

Given an integer A = 90123549, k = 2
return a string "12349"
*/

class Solution {
public:
    /**
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    string DeleteDigits(string A, int k){
        // wirte your code here
        int sz = A.size();
        int i = 0;
        while(k){
            while(i < sz - 1 && A[i] <= A[i+1]) // find the first one bigger than the right digit
                i++;
            if(i == sz - 1){ // in increasing order, delete the tailing digits
                sz -= k;
                k = 0;
            }else{
                int j = i;
                while(j < sz -1){ // remove the found digit
                    A[j] = A[j+1];
                    j++;
                }
                i--;
                k--;
                sz--;
            }
        }
        
        i = 0;
        while(i < sz && A[i] == '0') // deleting beginning zeors
            i++;
        return A.substr(i, sz - i);
    }
};
