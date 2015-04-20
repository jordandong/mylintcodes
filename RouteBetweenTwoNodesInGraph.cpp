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
 
//DFS
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

//Why do we need the graph???????????
//BFS
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
        if(s == t)
            return true;
        unordered_map<DirectedGraphNode*, bool> v;
        stack<DirectedGraphNode*> stk;
        stk.push(s);
        v[s] = true;
        while(stk.size()){
            DirectedGraphNode* node = stk.top();
            stk.pop();
            for(int i = 0; i < node->neighbors.size(); i++){
                if(node->neighbors[i] == t)
                    return true;
                if(v.find(node->neighbors[i]) == v.end()){
                    stk.push(node->neighbors[i]);
                    v[node->neighbors[i]] = true;
                }
            }
        }
        return false;
    }
};
