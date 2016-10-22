/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // write your code here
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> old_new;
        unordered_map<UndirectedGraphNode*, bool> visited;
        UndirectedGraphNode *copy_node = NULL;
        cloneGraphHelper(node, copy_node, old_new, visited);
        return copy_node;
    }
    
    void cloneGraphHelper(UndirectedGraphNode* node,
                          UndirectedGraphNode* &copy_node,
                          unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> &old_new,
                          unordered_map<UndirectedGraphNode*, bool> &visited){
        if(!node)
            return;

        if(old_new.find(node) == old_new.end()){
            copy_node = new UndirectedGraphNode(node->label);
            old_new[node] = copy_node;
        }else{
            copy_node = old_new[node];
        }

        if(visited.find(node) == visited.end()){
            visited[node] = true;
            for(int i=0; i<node->neighbors.size(); i++){
                UndirectedGraphNode *tmp = NULL;
                copy_node->neighbors.push_back(tmp);
                cloneGraphHelper(node->neighbors[i], copy_node->neighbors[i], old_new, visited);
            }
        }
    }
};
