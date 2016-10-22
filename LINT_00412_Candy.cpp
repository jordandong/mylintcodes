/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:
Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

Example
Given ratings = [1, 2], return 3.
Given ratings = [1, 1, 1], return 3.
Given ratings = [1, 2, 2], return 4. ([1,2,1]).

Tags Expand 
Greedy Array
*/

class Solution {
public:
    /**
     * @param ratings Children's ratings
     * @return the minimum candies you must give
     */
    int candy(vector<int>& ratings) {
        // Write your code here
        int sum = 0;
        int N = ratings.size();
        vector<int> assign(N, 1);
        for (int i = 1; i < N; i++)
            if (ratings[i] > ratings[i - 1])
                assign[i] = assign[i - 1] + 1;
        sum = assign[N - 1];
        for (int i = N - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1] && assign[i] <= assign[i + 1])
                assign[i] = assign[i + 1] + 1;
            sum += assign[i];
        }
        return sum;
    }
};
