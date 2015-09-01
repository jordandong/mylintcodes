/*
The structure of Segment Tree is a binary tree which each node has two attributes start and end denote an segment / interval.

start and end are both integers, they should be assigned in following rules:
1. The root's start and end is given by build method.
2. The left child of node A has start=A.left, end=(A.left + A.right) / 2.
3. The right child of node A has start=(A.left + A.right) / 2 + 1, end=A.right.
4. if start equals to end, there will be no children for this node.
Implement a build method with a given array, so that we can create a corresponding segment tree with every node value represent the corresponding interval max value in the array, return the root of this segment tree.

Have you met this question in a real interview? Yes

Example:
Given [3,2,1,4]. The segment tree will be:

                 [0,  3] (max = 4)
                  /            \
        [0,  1] (max = 3)     [2, 3]  (max = 4)
        /        \               /             \
[0, 0](max = 3)  [1, 1](max = 2)[2, 2](max = 1) [3, 3] (max = 4)

Clarification:
Segment Tree (a.k.a Interval Tree) is an advanced data structure which can support queries like:
which of these intervals contain a given point
which of these points are in a given interval

See wiki: Segment Tree Interval Tree

Tags Expand 
Segment Tree
*/

/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
 
class Solution {
public:
    /**
     *@param A: a list of integer
     *@return: The root of Segment Tree
     */
    SegmentTreeNode* build(vector<int>& A) {
        // write your code here
        int N = A.size();
        return buildHelper(0, N - 1, A);
    }
    
    SegmentTreeNode* buildHelper(int start, int end, vector<int>& A) {
        if (start > end)
            return NULL;
        if (start == end)
            return new SegmentTreeNode(start, end, A[start]);
        SegmentTreeNode* node = new SegmentTreeNode(start, end, 0);
        node->left = buildHelper(start, start + (end - start) / 2, A);
        node->right = buildHelper(start + (end - start) / 2 + 1, end, A);
        node->max = max(node->left->max, node->right->max);
        return node;
    }
};

class Solution {
public:
    /**
     *@param A: a list of integer
     *@return: The root of Segment Tree
     */
    SegmentTreeNode* build(vector<int>& A) {
        // write your code here
        int N = A.size();
        if (N == 0)
            return NULL;
        int idx = 0; 
        return buildHelper(0, N - 1, A, idx);
    }
    
    SegmentTreeNode* buildHelper(int start, int end, vector<int>& A, int &idx) {
        if (start == end)
            return new SegmentTreeNode(start, end, A[idx++]);
        SegmentTreeNode* l_node = buildHelper(start, start + (end - start) / 2, A, idx);
        SegmentTreeNode* r_node = buildHelper(start + (end - start) / 2 + 1, end, A, idx);
        SegmentTreeNode* node = new SegmentTreeNode(l_node->start, r_node->end, max(l_node->max, r_node->max));
        node->left = l_node;
        node->right = r_node;
        return node;
    }
};
