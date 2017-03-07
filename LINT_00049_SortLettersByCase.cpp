/*
Given a string which contains only letters. Sort it by lower case first and upper case second.

Note
It's not necessary to keep the original order of lower-case letters and upper case letters.

Example
For "abAcD", a reasonable answer is "acbAD"

Challenge
Do it in one-pass and in-place.
*/

class Solution {
public:
    /** 
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string &letters) {
        // write your code here
        int lo = 0;
        int hi = letters.length() - 1;
        while(lo < hi){
            if(letters[lo] - 'a' < 0){
                swap(letters[lo], letters[hi--]);
            }else{
                lo++;
            }
        }
        
    }
};
