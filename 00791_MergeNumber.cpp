/*
Given n numbers, now we need to merge n numbers into one number. And each time we can only select and merge two numbers a,b. Each merger needs to consume a+b energy. Output the minimum energy consumed by merging n numbers.

 Notice
2 <= n <= 50000, the combined number will not exceed the int range

Have you met this question in a real interview? Yes
Example
Given [1,2,3,4], return 19

Explanation:
Merge 1,2, which consumes 3 energy, and the rest is [3,4,3]. Merge 3,3, which consumes 6 energy, and the rest is [6,4]. Merge the last two numbers, which consumes 10 energy, and a total of 19 energy was consumed.
Given [2,8,4,1], return 25

explanation:
Merge 1,2, which consumes 3 energy, and the rest is [8,4,3]. Merge 3,4, which consumes 7 energy, and the rest is [7,8]. Merge the last two numbers, which consumes 15 energy, and a total of 25 energy was consumed.
Tags 
Greedy
*/

class Solution {
public:
    /**
     * @param numbers: the numbers
     * @return: the minimum cost
     */
    int mergeNumber(vector<int> &numbers) {
        // Write your code here
        priority_queue<int, vector<int>, greater<int>> q;
        int sum = 0;
        for (auto num : numbers)
            q.push(num);
        while (q.size() > 1) {
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            q.push(a + b);
            sum += (a + b);
        }
        return sum;
    }
};
