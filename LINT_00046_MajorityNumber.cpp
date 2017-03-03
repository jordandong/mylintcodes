/*
Given an array of integers, the majority number is the number that occurs more than half of the size of the array. Find it.

Example
For [1, 1, 1, 1, 2, 2, 2], return 1

Challenge
O(n) time and O(1) space
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int cnt = 0;
        int last = 0;
        for(int e : nums){
            if(cnt == 0 || last == e){
                last = e;
                cnt++;
            }else{
                cnt--;
            }
        }
        return last;
    }
};
