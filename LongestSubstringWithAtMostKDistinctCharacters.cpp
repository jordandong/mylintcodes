/*
Given a string s, find the length of the longest substring T that contains at most k distinct characters.

Example
For example, Given s = "eceba", k = 3,

T is "eceb" which its length is 4.

Challenge
O(n), n is the size of the string s.

Tags Expand 
String Two Pointers Hash Table
*/

class Solution {
public:
    /**
     * @param s : A string
     * @return : The length of the longest substring 
     *           that contains at most k distinct characters.
     */
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        // write your code here
        int l = 0, r = 0;
        int mp[256];
        int mx = 0;
        int cnt = 0;
        memset(mp, 0, sizeof(int)*256);

        for(r = 0; r < s.length(); r++) {
            if(mp[s[r]] == 0)
                cnt++;
            mp[s[r]]++;
            while(cnt > k){
                if(--mp[s[l++]] == 0)
                    cnt--;
            }
            mx = max(mx, r - l + 1);
        }
        return mx;
    }
};
