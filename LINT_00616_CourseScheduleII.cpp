/*
There are a total of n courses you have to take, labeled from 0 to n - 1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

Example
Given n = 2, prerequisites = [[1,0]]
Return [0,1]

Given n = 4, prerequisites = [1,0],[2,0],[3,1],[3,2]]
Return [0,1,2,3] or [0,2,1,3]

Tags 
Amazon Breadth First Search Topological Sort Zenefits Facebook
*/

class Solution {
public:
    /**
     * @param numCourses a total of n courses
     * @param prerequisites a list of prerequisite pairs
     * @return the course order
     */
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        // Write your code here
        vector<vector<int> > g(numCourses, vector<int>()); //edge x->y
        vector<int> indgree(numCourses);//indgree for y
        vector<int> res;
        stack<int> stk;
        int taken = 0;

        for (int i = 0; i < prerequisites.size(); i++) { //build graph
            int x = prerequisites[i].second;
            int y = prerequisites[i].first;
            g[x].push_back(y);
            indgree[y]++;
        }
        
        for (int i = 0; i < numCourses; i++){
            if (indgree[i] == 0) { //take independent first
                stk.push(i);
                taken++;
            }
        }
       
        while (stk.size()) {
            int n = stk.top();
            stk.pop();
            res.push_back(n);
            for (int i = 0; i < g[n].size(); i++) {
                indgree[g[n][i]]--; //reduce the indgree after taking one course
                if (indgree[g[n][i]] == 0) {
                    stk.push(g[n][i]);
                    taken++;
                }
            }
        }
        if(taken != numCourses)
            res.clear();
        return res;
    }
};
