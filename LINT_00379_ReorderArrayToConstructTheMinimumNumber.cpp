/*
Construct minimum number by reordering a given non-negative integer array. Arrange them such that they form the minimum number.

Notice
The result may be very large, so you need to return a string instead of an integer.

Example
Given [3, 32, 321], there are 6 possible numbers can be constructed by reordering the array:
3+32+321=332321
3+321+32=332132
32+3+321=323321
32+321+3=323213
321+3+32=321332
321+32+3=321323
So after reordering, the minimum number is 321323, and return it.

Challenge 
Do it in O(nlogn) time complexity.

Tags 
Array
*/

bool str_cmp (string a, string b) {
    return (a + b < b + a);
}

class Solution {
public:
    /**
     * @param nums n non-negative integer array
     * @return a string
     */
    string minNumber(vector<int>& nums) {
        // Write your code here
        vector<string> nums_copy;
        string res = "";
        for(int e : nums){
            if(e == 0)
                continue;
            nums_copy.push_back(to_string(e));
        }
        if(0 == nums_copy.size())
            return "0";

        sort(nums_copy.begin(), nums_copy.end(), str_cmp);
        for(auto str : nums_copy)
            res += str;
        return res;
    }
};
