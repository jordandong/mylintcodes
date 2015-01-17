/*
Numbers keep coming, return the median of numbers at every time a new number added.

Example:
For numbers coming list: [1, 2, 3, 4, 5], return [1, 1, 2, 2, 3]
For numbers coming list: [4, 5, 1, 3, 2, 6, 0], return [4, 4, 4, 3, 3, 3, 3]
For numbers coming list: [2, 20, 100], return [2, 2, 20]

Challenge:
O(nlogn) time

Clarification:
What's the definition of Median?
Median is the number that in the middle of a sorted array. If there are n numbers in a sorted array A, the median is A[(n-1)/2].
For example, if A=[1,2,3], median is 2. If A=[1,19], median is 1.
*/

class min_heap {
    public:
    bool operator() (const int a, const int b) {
        return a > b;
    }
};

class max_heap {
    public:
    bool operator() (const int a, const int b) {
        return a < b;
    }
};

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        // write your code here
        int sz = nums.size();
        vector<int> res;
        priority_queue<int, vector<int>, min_heap> mi_hp;
        priority_queue<int, vector<int>, max_heap> mx_hp;
        
        for(int i = 0; i < sz; i++){
            if(mx_hp.size() == 0){
                mx_hp.push(nums[i]);
            }else if(mi_hp.size() == 0){
                if(nums[i] >= mx_hp.top()){
                    mi_hp.push(nums[i]);
                }else{
                    mi_hp.push(mx_hp.top());
                    mx_hp.pop();
                    mx_hp.push(nums[i]);
                }
            }else if(mx_hp.size() == mi_hp.size()){
                if(nums[i] <= mi_hp.top()){
                    mx_hp.push(nums[i]);
                }else{
                    mx_hp.push(mi_hp.top());
                    mi_hp.pop();
                    mi_hp.push(nums[i]);
                }
            }else{
                if(nums[i] >= mx_hp.top()){
                    mi_hp.push(nums[i]);
                }else{
                    mi_hp.push(mx_hp.top());
                    mx_hp.pop();
                    mx_hp.push(nums[i]);
                }
            }
            res.push_back(mx_hp.top());
        }
        return res;
    }
};
