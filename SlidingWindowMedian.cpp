/*
Given an array of n integer, and a moving window(size k), move the window at each iteration from the start of the array, find the median of the element inside the window at each moving. (If there are even numbers in the array, return the N/2-th number after sorting the element in the window. )

Example
For array [1,2,7,8,5], moving window size k = 3. return [2,7,7]

At first the window is at the start of the array like this
[ | 1,2,7 | ,8,5] , return the median 2;

then the window move one step forward.
[1, | 2,7,8 | ,5], return the median 7;

then the window move one step forward again.
[1,2, | 7,8,5 | ], return the median 7;

Challenge
O(nlog(n)) time

Tags Expand 
Heap
*/

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of the element inside the window at each moving
     */
    vector<int> medianSlidingWindow(vector<int> &nums, int k) {
        // write your code here
        multiset<int> lo, hi; //internally it is balanced BST
        int sz = nums.size();
        vector<int> res;
        for(int i = 0; i < sz; i++){
            if(i - k >= 0){
                auto it = lo.lower_bound(nums[i - k]);//log(k)
                if(it != lo.end())
                    lo.erase(it);//log(k)
                else
                    hi.erase(hi.lower_bound(nums[i - k]));//log(k)
            }
            
            if(lo.size() <= hi.size()){
                if((lo.empty() && hi.empty()) || nums[i] <= *hi.begin()){
                    lo.insert(nums[i]);//log(k)
                }else{
                    hi.insert(nums[i]);//log(k)
                    lo.insert(*hi.begin());//log(k)
                    hi.erase(hi.begin());//log(k)
                }
            }else{
                if(nums[i] >= *lo.rbegin()){
                    hi.insert(nums[i]);//log(k)
                }else{
                    lo.insert(nums[i]);//log(k)
                    hi.insert(*lo.rbegin());//log(k)
                    lo.erase(lo.lower_bound(*lo.rbegin()));//log(k) + log(k)
                }
            }
            if(i >= k - 1)
                res.push_back(*lo.rbegin());
        }
        return res;
    }
};
