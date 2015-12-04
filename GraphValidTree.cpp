/*
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

Have you met this question in a real interview? Yes

Example
Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.
Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.

Note
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

Tags Expand 
Depth First Search Breadth First Search Union Find Facebook Zenefits Google
*/

//T : O(E + V), S : O(E*V)
class Solution {
public:
    struct node {
        int parent = -1;
        vector<int>neighbors;
    };
    /**
     * @param n an integer
     * @param edges a list of undirected edges
     * @return true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>>& edges) {
        // Write your code here
        if (edges.size() != n - 1) { //only one tree is allowed
            return false;
        } else if (n == 1) {
            return true;
        }

        unordered_map<int, node> nodes;
        for (const auto& edge : edges) {
            nodes[edge.front()].neighbors.push_back(edge.back());
            nodes[edge.back()].neighbors.push_back(edge.front());
        }

        if (nodes.size() != n) {
            return false;
        }

        unordered_set<int> visited;
        queue<int> q;
        q.push(0);
        while (q.size()) { //BFS
            const int i = q.front();
            q.pop();
            visited.insert(i);
            for (const auto& node : nodes[i].neighbors) {
                if (node != nodes[i].parent) {
                    if (visited.find(node) != visited.end()) {
                        return false;
                    } else {
                        visited.insert(node);
                        nodes[node].parent = i;
                        q.push(node);
                    }
                }
            }
        }
        return visited.size() == n;
    }
};
