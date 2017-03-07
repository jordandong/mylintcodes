/*
Given an absolute path for a file (Unix-style), simplify it.

Have you met this question in a real interview? Yes

Example
"/home/", => "/home"
"/a/./b/../../c/", => "/c"

Challenge
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".

Tags Expand 
String Stack
*/

class Solution {
public:
    /**
     * @param path the original path
     * @return the simplified path
     */
    string simplifyPath(string& path) {
        // Write your code here
        vector<string> dirs;
        
        auto i = path.begin();
        while (i != path.end()) {
            auto j = find(i, path.end(), '/'); //find first
            string dir = string(i, j); //not include j

            if(dir.size() && dir != ".") {
                if(dir == "..") {
                    if(dirs.size())
                        dirs.pop_back();
                } else {
                    dirs.push_back(dir);
                }
            }
            i = ( j == path.end() ? j : j + 1); //move forward
        }

        if(dirs.empty())
            return "/";

        string res;
        for(auto dir : dirs)
            res.append("/" + dir);
        return res;
    }
};
