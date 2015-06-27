/*
Find the number connected component in the undirected graph. Each node in the graph contains a label and a list of its neighbors. (a connected component (or just component) of an undirected graph is a subgraph in which any two vertices are connected to each other by paths, and which is connected to no additional vertices in the supergraph.)

Have you met this question in a real interview? Yes

Example
Given graph:
A------B  C
 \     |  | 
  \    |  |
   \   |  |
    \  |  |
      D   E
Return {A,B,D}, {C,E}. Since there are two connected component which is {A,B,D}, {C,E}

Note

Tags Expand 
Breadth First Search
*/

/**
 * Definition for Undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param nodes a array of Undirected graph node
     * @return a connected set of a Undirected graph
     */
    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*>& nodes) {
        // Write your code here
        unordered_map<UndirectedGraphNode*, bool> v;
        queue<UndirectedGraphNode*> q;
        vector<vector<int>> res;
        for (auto e : nodes) {
            vector<int> sol;
            if (v[e])
                continue;
            
            if (q.empty()) {
                v[e] = true;
                q.push(e);
            }
                
            while (q.size()) {
                UndirectedGraphNode* t = q.front();
                q.pop();
                sol.push_back(t->label);
                for (auto nb : t->neighbors) {
                    if (!v[nb]) {
                        v[nb] = true;
                        q.push(nb);
                    }
                }
            }
            sort(sol.begin(), sol.end());//why needs increasing order, stupid OJ
            res.push_back(sol);
        }
        return res;
    }
};
