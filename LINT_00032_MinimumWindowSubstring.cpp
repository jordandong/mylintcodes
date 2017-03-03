/*
Given a string source and a string target, find the minimum window in source which will contain all the characters in target.

Note:
If there is no such window in source that covers all characters in target, return the emtpy string "".
If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in source.

Example:
source = "ADOBECODEBANC" target = "ABC" Minimum window is "BANC".

Challenge:
Can you do it in time complexity O(n) ?

Clarification:
Should the characters in minimum window has the same order in target?
    - Not necessary.
*/

class Solution {
public:    
    /**
     * @param source: A string
     * @param target: A string
     * @return: A string denote the minimum window
     *          Return "" if there is no such a string
     */
    string minWindow(string &source, string &target) {
        // write your code here
        int to_find[256] = {0};
        int found[256] = {0};
        int found_len = 0;
        int mi_indx = source.length();
        int mi_len = source.length() + 1;
        
        for(char c : target)
            to_find[c]++;
        
        
        for(int start = 0, end = 0; end < source.length(); end++){
            char c = source[end];
            if(to_find[c] == 0)
                continue;
            
            if(++found[c] <= to_find[c])
                found_len++;
            
            if(found_len == target.length()){
                while(to_find[source[start]] == 0 || found[source[start]] > to_find[source[start]]){
                    if(found[source[start]] > to_find[source[start]])
                        found[source[start]]--;
                    start++;
                }
                
                if(end - start + 1 < mi_len){
                    mi_len = end - start + 1;
                    mi_indx = start;
                }
            }
        }
        return (mi_len == source.length() + 1) ? "":source.substr(mi_indx, mi_len);
    }
};
