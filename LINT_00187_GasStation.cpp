/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note
The solution is guaranteed to be unique.

Example
Given 4 gas stations with gas[i]=[1,1,3,1], and the cost[i]=[2,2,1,1]. The starting gas station's index is 2.

Challenge
O(n) time and O(1) extra space

Tags Expand 
Greedy LeetCode
*/

class Solution {
public:
    /**
     * @param gas: a vector of integers
     * @param cost: a vector of integers
     * @return: an integer 
     */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // write your code here
        int total_left = 0;
        int cur_left = 0;
        int i = 0, start = -1;
        for(i = 0, start = 0; i < cost.size(); i++){
            total_left += gas[i] - cost[i];
            cur_left += gas[i] - cost[i];
            if(cur_left < 0){
                cur_left = 0;
                start = i + 1;
            }
        }
        if(total_left < 0)
            return -1;
        else
            return start;
    }
};
