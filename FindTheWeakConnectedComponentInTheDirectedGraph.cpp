/*
Find the number Weak Connected Component in the directed graph. Each node in the graph contains a label and a list of its neighbors. (a connected set of a directed graph is a subgraph in which any two vertices are connected by direct edge path.)

Have you met this question in a real interview? Yes

Example
Given graph:

A----->B  C
 \     |  | 
  \    |  |
   \   |  |
    \  v  v
     ->D  E <- F
Return {A,B,D}, {C,E,F}. Since there are two connected component which are {A,B,D} and {C,E,F}

Note
Sort the element in the set in increasing order

Tags Expand 
Union Find
*/
/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
 
bool sort_nodes(const DirectedGraphNode* a, const DirectedGraphNode* b) {
    return a->label < b->label;
}

class Solution {
public:
    /**
     * @param nodes a array of directed graph node
     * @return a connected set of a directed graph
     */
    vector<vector<int>> connectedSet2(vector<DirectedGraphNode*>& nodes) {
        unordered_map<int, int> sets;
        unordered_map<int, vector<int>> comps;
        vector<vector<int>> result;

        sort(nodes.begin(), nodes.end(), sort_nodes);
        for (const auto& node : nodes) //each node is one set
            sets[node->label] = node->label;

        // Union each neighbor node for all nodes.
        for (const auto& node : nodes)
            for (const auto& neighbor : node->neighbors)
                union_set(node->label, neighbor->label, sets);

        // find different comps
        for (const auto& node : nodes)
            comps[find_set(node->label, sets)].push_back(node->label);

        //output sorted vomp.
        for (auto& e : comps)
            result.push_back(e.second);
        return result;
    }

    int find_set(int x, unordered_map<int, int> &sets) {
        //all the nodes in one set points to the same key
        if (sets[x] != x)
            sets[x] = find_set(sets[x], sets);
        return sets[x];
    }

    void union_set(int x, int y, unordered_map<int, int> &sets) {
        int x_key = find_set(x, sets);
        int y_key = find_set(y, sets);
        //all the nodes in one set points to the same key
        sets[min(x_key, y_key)] = max(x_key, y_key);
    }
};
