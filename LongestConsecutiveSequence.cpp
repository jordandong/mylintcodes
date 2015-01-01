/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Example
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Clarification
Your algorithm should run in O(n) complexity.
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return an integer
     */
    int longestConsecutive(vector<int> &num) {
        // write you code here
        unordered_map<int, int> mp;
        int mx = 0;
        for(int e : num){
            mp[e] = e;
        }
        
        for(int e : num){
            int t = e;
            int cnt = 0;
            while(mp.find(e)!=mp.end()){
                cnt++;
                mp.erase(e);
                e++;
            }
            
            e = t-1;
            while(mp.find(e)!=mp.end()){
                cnt++;
                mp.erase(e);
                e--;
            }
            mx = max(mx, cnt);
        }
        return mx;
    }
};
