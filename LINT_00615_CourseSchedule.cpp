/*
There are a total of n courses you have to take, labeled from 0 to n - 1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example
Given n = 2, prerequisites = [[1,0]]
Return true

Given n = 2, prerequisites = [[1,0],[0,1]]
Return false

Tags 
Amazon Breadth First Search Apple Topological Sort Zenefits
*/

class Solution {
public:
    /**
     * @param numCourses a total of n courses
     * @param prerequisites a list of prerequisite pairs
     * @return true if can finish all courses or false
     */
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        // Write your code here
        vector<vector<int> > g(numCourses, vector<int>()); //edge x->y
        vector<int> indgree(numCourses);//indgree for y
        stack<int> stk;
        int taken = 0;

        for (int i = 0; i < prerequisites.size(); i++) { //build graph
            int x = prerequisites[i].first;
            int y = prerequisites[i].second;
            g[x].push_back(y);
            indgree[y]++;
        }
        
        for (int i = 0; i < numCourses; i++){
            if (indgree[i] == 0) { //take most dependent first
                stk.push(i);
                taken++;
            }
        }
       
        while (stk.size()) {
            int n = stk.top();
            stk.pop();
            for (int i = 0; i < g[n].size(); i++) {
                indgree[g[n][i]]--; //reduce the indgree after taking one course
                if (indgree[g[n][i]] == 0) {
                    stk.push(g[n][i]);
                    taken++;
                }
            }
        }
        return taken == numCourses;
    }
};
