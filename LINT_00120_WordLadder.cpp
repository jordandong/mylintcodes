/*
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:
Only one letter can be changed at a time
Each intermediate word must exist in the dictionary

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.

Example,
Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]

As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
*/

class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return an integer
      */
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // write your code here
        stack<string> stk[2];
        int cnt = 1;
        if(start.compare(end) == 0)
            return cnt;
        
        stk[cnt%2].push(start);
        dict.erase(start);//if don't erase dict, then need to record visited words
        while(stk[cnt%2].size()){
            string cur_str = stk[cnt%2].top();
            stk[cnt%2].pop();

            for(int i = 0; i < cur_str.length(); i++){
                char t = cur_str[i];
                for(char c = 'a'; c <= 'z'; c++){
                    if(c != t){
                        cur_str[i] = c;
                        if(cur_str.compare(end) == 0)
                            return cnt + 1;
                        if(dict.find(cur_str) != dict.end()){
                            stk[(cnt+1)%2].push(cur_str);
                            dict.erase(cur_str);//if don't erase dict, then need to record visited words
                        }
                        cur_str[i] = t;
                    }
                }
            }
            
            if(stk[cnt%2].size() == 0)
                cnt++;
        }
        return 0;
    }
};
