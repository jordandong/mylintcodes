/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

The largest rectangle is shown in the shaded area, which has area = 10 unit.

Example:
Given height = [2,1,5,6,2,3],
return 10.
*/

class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &height) {
        // write your code here
        height.push_back(0);
        stack<int> idx;
        int sz = height.size();
        int i = 0;
        int mx = 0;

        while(i < sz){
            if(idx.empty() || height[idx.top()] <= height[i]){
                idx.push(i);
                i++;
            }else{
                int id = idx.top();
                idx.pop();
                int w = idx.empty()?i:i-idx.top()-1;
                mx = max(mx, height[id]*w);
            }
        }
        return mx;
    }
};
