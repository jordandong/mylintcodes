/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

Trapping Rain Water
       *  
   *xxx**x*
 *x**x******
************

Example
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

Challenge
O(n) time and O(1) memory

O(n) time and O(n) memory is also acceptable.

Tags Expand 
Two Pointers Forward-Backward Traversal Array
*/

//T: O(n), S: O(1)
class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        // write your code here
        int sz = heights.size();
        if(sz <= 0)
            return 0;
        int res = 0;
        int hi = 0, lo = 0;
        
        for(int i = 0; i < sz; i++)
            hi = heights[i] > heights[hi] ? i : hi;
        
        int k = 0;
        while(k < hi){
            if(heights[k] >= heights[lo]){
                lo = k;
            }else{
                res += heights[lo] - heights[k];
            }
            k++;
        }
        
        lo = sz - 1;
        k = sz - 1;
        while(k > hi){
            if(heights[k] >= heights[lo]){
                lo = k;
            }else{
                res += heights[lo] - heights[k];
            }
            k--;
        }
        return res;
    }
};

//T: O(n), S: O(n)
class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        // write your code here
        int sz = heights.size();
        if(sz <= 0)
            return 0;

        int res = 0;
        int mx[sz];
        mx[0] = heights[0];
        mx[sz - 1] = heights[sz - 1];

        for(int i = 1; i < sz - 1; i++)
            mx[i] = max(mx[i - 1],  heights[i]);
        
        for(int i = sz - 2; i > 0; i--){
            mx[i] = min(mx[i], max(mx[i + 1], heights[i]));
            res += mx[i] - heights[i];
        }
        return res;
    }
};
