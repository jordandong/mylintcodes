/*
Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:
Only one letter can be changed at a time
Each intermediate word must exist in the dictionary

Note:
All words have the same length.
All words contain only lowercase alphabetic characters.

Example:
Given,
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]

Return,
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
*/

class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return a list of lists of string
      */
    //find the possible relationship between prev words and next words, one next word mapping to mutiple prev words
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // write your code here
        vector<vector<string> > res;
        vector<string> path;
        if(end == start){
            path.push_back(start);
            path.push_back(end);
            res.push_back(path);   
            return res;
        }
        queue<string> q[2];
        unordered_map<string, vector<string> > pMap;
        unordered_map<string, vector<string> > curL;
        int cnt = 0;	
        bool found = false;

        q[cnt].push(start);
        pMap[start] = vector<string>(1, start);
        while(q[cnt].size()){
            string prev = q[cnt].front();
            string next = prev;
            q[cnt].pop();
            for(int i = 0; i < next.length(); i++){
                char p = next[i];
                for(char c = 'a'; c <= 'z'; c++){
                    if(p == c)
                        continue;
                    next[i] = c;
                    if(next == end)
                        found = true;
                    if((pMap.find(next) == pMap.end()) && (dict.find(next) != dict.end())){
                        if(curL.find(next) == curL.end()){
                            q[cnt^1].push(next);
                            curL[next] = vector<string>(1, prev);
                        }else{
                            curL[next].push_back(prev);
                        }
                    }
                }
                next[i] = p;
            }
            if(q[cnt].empty()){
                cnt^=1;    
                pMap.insert(curL.begin(), curL.end());
                curL.clear();
                if(found)
                    break;
            }
        }
        findPath(pMap, end, path, res);
        for(int i = 0; i < res.size(); i++)
            reverse(res[i].begin(), res[i].end());
        return res;
    }

    //reconstruct the path from end to start, DFS
    void findPath(unordered_map<string, vector<string> > &pMap, string &end, vector<string> &path, vector<vector<string>> &res) {
        if(pMap.find(end) == pMap.end())
            return;
        if(pMap[end][0] == end){
            path.push_back(end);
            res.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(end);
        for(int i = 0; i < pMap[end].size(); i++)
            findPath(pMap, pMap[end][i], path, res);
        path.pop_back();
    }
};
