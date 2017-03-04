/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

Have you met this question in a real interview? Yes

Example
Given "25525511135", return
[
  "255.255.11.135",
  "255.255.111.35"
]
Order does not matter.

Tags Expand 
String Backtracking Recursion
*/

class Solution {
public:
    /**
     * @param s the IP string
     * @return All possible valid IP addresses
     */
    vector<string> restoreIpAddresses(string& s) {
        // Write your code here
        if (s.size() < 4 || s.size() > 12)
            return {};
        vector<string> res;
        string sol;
        restoreIpAddressesHelper(s, 0, 1, sol, res);
        return res;
    }
    
    //start is the index which will be used in the string and k is the kth section in the IP
    void restoreIpAddressesHelper(string &s, int start, int k, string &sol, vector<string> &res) {
        if (start == s.size()) {
            if (k == 5)
            	res.push_back(sol);
            return;
        }

        if(k != 1)//add . if it is not the first section
            sol.push_back('.');
        
        int val = 0; // value in this section
        for (int i = start; i < s.size(); i++) {
            val = 10 * val + (s[i] - '0');
            if (val > 255)
            	break;
            sol.push_back(s[i]);
            restoreIpAddressesHelper(s, i + 1, k + 1, sol, res);
            if (val == 0)
            	break;
        }

        while (sol.size()) {
            if (sol.back() != '.') {
                sol.pop_back();//pop all the num in this section
            } else {
                sol.pop_back();//pop the "."
                break;
            }
        }
    }
};
