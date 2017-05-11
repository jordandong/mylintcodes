/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Example
Given s = "lintcode", return 0.
Given s = "lovelintcode", return 2.

Tags 
Amazon Microsoft Bloomberg
*/

class Solution {
public:
    /**
     * @param s a string
     * @return it's index
     */
    int firstUniqChar(string& s) {
        // Write your code here
        vector<int> map(256, 0);
        for (auto c : s)
            map[c]++;
        for (int i = 0; i < s.length(); i++)
            if (1 == map[s[i]])
                return i;
        return -1;
    }
};

class Solution {
public:
    /**
     * @param s a string
     * @return it's index
     */
    int firstUniqChar(string& s) {
        // Write your code here
        vector<int> map(256, 0);
        queue<int> q;
        for (int i = 0; i < s.length(); i++) {
            if (++map[s[i]] == 1) {
                q.push(i);
            } else {
                while (!q.empty() && map[s[q.front()]] > 1)
                    q.pop();
            }
        }
        return q.empty() ? -1 : q.front();
    }
};
