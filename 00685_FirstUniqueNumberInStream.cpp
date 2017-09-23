/*
Given a continuous stream of numbers, write a function that returns the first unique number whenever terminating number is reached(include terminating number).
If there no unique number before terminating number or you can't find this terminating number, return -1.

Example
Given a stream [1, 2, 2, 1, 3, 4, 4, 5, 6] and a number 5
return 3

Given a stream [1, 2, 2, 1, 3, 4, 4, 5, 6] and a number 7
return -1

Tags 
Queue Hash Table
*/

class Solution {
public:
    /*
     * @param : a continuous stream of numbers
     * @param : a number
     * @return: returns the first unique number
     */
    int firstUniqueNumber(vector<int> nums, int number) {
        // Write your code here
        unordered_set<int> st1, st2;
        queue<int> q;
        for (auto e : nums) {
            if (e == number) {
                if (q.size())
                    return q.front();
                return -1;
            }
            if (st2.find(e) != st2.end())
                continue;
            if (st1.find(e) != st1.end()) {
                st1.erase(e);
                st2.insert(e);
            } else {
                st1.insert(e);
            }
            q.push(e);
            while (q.size() && (st2.find(q.front()) != st2.end()))
                q.pop();
        }
        return -1;
    }
};
