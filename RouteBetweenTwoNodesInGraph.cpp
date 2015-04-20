/*
Given a directed graph, design an algorithm to find out whether there is a route between two nodes.

Example
Given graph:

A----->B----->C
 \     |
  \    |
   \   |
    \  v
     ->D----->E

for s = B and t = E, return true
for s = D and t = C, return false

Tags Expand 
Cracking The Coding Interview Depth First Search Breadth First Search
*/

/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    bool hasRoute(vector<DirectedGraphNode*> graph,
                  DirectedGraphNode* s, DirectedGraphNode* t) {
        // write your code here
        unordered_map<DirectedGraphNode*, bool> v;   
        return hasRouteHelper(s, t, v);
    }

    bool hasRouteHelper(DirectedGraphNode* s, DirectedGraphNode* t, unordered_map<DirectedGraphNode*, bool> &v) {
        if(s == t)   
            return true;
        v[s] = true;
        for(int i = 0; i < s->neighbors.size(); i++){
            if(v.find(s->neighbors[i]) == v.end()){
                if(hasRouteHelper(s->neighbors[i], t, v))
                    return true;	
            }
        }
        return false;
    }
};
