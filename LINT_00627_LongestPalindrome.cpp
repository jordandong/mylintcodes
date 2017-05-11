／*
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Notice
Assume the length of given string will not exceed 1010.

Example
Given s = "abccccdd" return 7
One longest palindrome that can be built is "dccaccd", whose length is 7.

Tags 
Hash Table Amazon
*／

class Solution {
public:
    /**
     * @param s a string which consists of lowercase or uppercase letters
     * @return the length of the longest palindromes that can be built
     */
    int longestPalindrome(string& s) {
        // Write your code here
        unordered_map<char, int> counter;
        int res = 0;
        for (auto &c : s) {
            if (++counter[c] % 2 == 0)
                res += 2;
        }
        if (res != s.length())
            res++;
        return res;
    }
};

class Solution {
public:
    /**
     * @param s a string which consists of lowercase or uppercase letters
     * @return the length of the longest palindromes that can be built
     */
    int longestPalindrome(string& s) {
        // Write your code here
        int odds = 0;
        for (auto c = 'A'; c <= 'z'; ++c) {
            odds += count(s.cbegin(), s.cend(), c) & 1;
        }
        return s.length() - odds + (odds > 0);
    }
};
