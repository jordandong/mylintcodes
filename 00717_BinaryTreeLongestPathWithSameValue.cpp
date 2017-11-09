/*
We consider an undirected tree with N nodes, numbered from 1 to N, Additionally, each node also has a label attached to it and the label is an integer value. Note that different nodes can have identical labels. You need to write a function , that , given a zero-indexed array A of length N, where A[J] is the label value of the (J + 1)-th node in the tree, and a zero-indexed array E of length K = (N - 1) * 2 in which the edges of the tree are described (for every 0 <= j <= N -2 values E[2 * J] and E[2 * J + 1] represents and edge connecting node E[2 * J] with node E[2 * J + 1])， returns the length of the longest path such that all the nodes on that path have the same label. Then length of a path if defined as the number of edges in that path.

 Notice

Assume that: 1 <= N <= 1000

Have you met this question in a real interview? Yes
Example
Give A = [1, 1, 1 ,2, 2] and E = [1, 2, 1, 3, 2, 4, 2, 5]
described tree appears as follows:

                   1 （value = 1）
                 /   \
    (value = 1) 2     3 (value = 1)
               /  \
 (value = 2)  4     5 (value = 2)
and your function should return 2, because the longest path (in which all nodes have the save value of 1) is (2 -> 1 -> 3). The number of edges on this path is 2, thus, that is the answer.

Tags 
Binary Tree Google Depth First Search
*/

class Solution {
public:
    /*
     * @param : as indicated in the description
     * @param : as indicated in the description
     * @return: Return the number of edges on the longest path with same value.
     */
    int LongestPathWithSameValue(vector<int> &A, vector<int> &E) {
        // write your code here
        int n = A.size();
        if (n == 0)
            return 0;
        map<int, set<int>> edges;
        for (int j = 0; j < n; j++) {
            if (E[j*2 + 1] == E[j * 2])
                continue;
            edges[E[j*2]].insert(E[j*2 + 1]);
            edges[E[j*2 + 1]].insert(E[j*2]);
        }
        int res = 0;
        DFS(0, 1, A, edges, res);
        return res;
    }
    
    vector<int> DFS(int parent, int node, vector<int> &A, map<int, set<int>> &edges, int &res) {
        if (edges[node].size() == 1 && *(edges[node].begin()) == parent)
            return {0, A[node - 1]};
        vector<vector<int>> childs;
        for (auto it : edges[node]) {
            int child = it;
            if (child == parent)
                continue;
            childs.push_back(DFS(node, child, A, edges, res));
        }
        
        if (childs.size() == 1) {
            if (childs[0][1] == A[node - 1]) {
                childs[0][0]++;
                res = max(res, childs[0][0]);
                return childs[0];
            } else {
                return {0, A[node - 1]};
            }
        } else {
            if (childs[0][1] == A[node - 1] && childs[1][1] == A[node - 1]) {
                childs[0][0]++;
                childs[1][0]++;
                res = max(res, childs[0][0] + childs[1][0]);
                return childs[0][0] > childs[1][0] ? childs[0] : childs[1];
            } else if (childs[0][1] == A[node - 1]) {
                childs[0][0]++;
                res = max(res, childs[0][0]);
                return childs[0];
            } else if (childs[1][1] == A[node - 1]) {
                childs[1][0]++;
                res = max(res, childs[1][0]);
                return childs[1];
            } else {
                return {0, A[node - 1]};
            }
        }
    }
};
