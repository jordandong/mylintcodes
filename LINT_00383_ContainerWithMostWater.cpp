/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Example
Given [1,3,2], the max area of the container is 2.

Note
You may not slant the container.

Tags Expand 
Two Pointers Array
*/

class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &heights) {
        // write your code here
        int l = 0;
        int r = heights.size() - 1;
        int res = 0;
        while(l < r){
            res = max(res, (r - l) * min(heights[l], heights[r]));
            if(heights[l] < heights[r])
                l++;
            else
                r--;
        }
        return res;
    }
};
