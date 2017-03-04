/*
Given an directed graph, a topological order of the graph nodes is defined as follow:
-For each directed edge A-->B in graph, A must before B in the order list.
-The first node in the order can be any node in the graph with no nodes direct to it.
Find any topological order for the given graph.

Note:
You can assume that there is at least one topological order in the graph.

Example:
For graph as follow: 
       1 ----> 4     (0->1, 0->2, 0->3)
0 -->  2----->       (1->4)
       3-----> 5     (2->4, 2->5)
                     (3->4, 3->5)  
The topological order can be:
[0, 1, 2, 3, 4, 5]
or
[0, 2, 3, 1, 5, 4]
or
....

Challenge:
Can you do it in both BFS and DFS?
*/

/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
 /**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
 
 //Optimized
class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        // write your code here
        unordered_map<DirectedGraphNode*, bool> v;
        vector<DirectedGraphNode*> res;

        for(DirectedGraphNode* e : graph){
            if(v.find(e) == v.end())
                topSortDFS(e, v, res);
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    void topSortDFS(DirectedGraphNode* node, unordered_map<DirectedGraphNode*, bool> &v, vector<DirectedGraphNode*> &res) {
        if(v.find(node) != v.end())
            return;

        v[node] = true;
        for(int i = 0; i < node->neighbors.size(); i++)
            topSortDFS(node->neighbors[i], v, res);
        res.push_back(node);
    }
};
 
class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        // write your code here
        unordered_map<DirectedGraphNode*, int> uv;
        vector<DirectedGraphNode*> res;
        for(DirectedGraphNode* e : graph)
            uv[e] = 0;

        for(DirectedGraphNode* e : graph){
            if(uv.find(e) != uv.end()){
                topSortDFS(e, uv, res);
            }
        }
        return res;
    }
    
    void topSortDFS(DirectedGraphNode* node, unordered_map<DirectedGraphNode*, int> &uv, vector<DirectedGraphNode*> &res) {
        if(uv.find(node) == uv.end())
           return;

        uv.erase(node);
        for(int i = 0; i < node->neighbors.size(); i++){
            topSortDFS(node->neighbors[i], uv, res);
        }
        res.insert(res.begin(), node);
    }
};
