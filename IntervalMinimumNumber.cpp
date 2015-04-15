/*
Given an integer array (index from 0 to n-1, where n is the size of this array), and an query list. Each query has two integers [start, end]. For each query, calculate the minimum number between index start and end in the given array, return the result list.

Note
We suggest you finish problem Segment Tree Build, Segment Tree Query and Segment Tree Modify first.

Example
For array [1,2,7,8,5], and queries [(1,2),(0,4),(2,4)], return [2,1,5]

Challenge
O(logN) time for each query

Tags Expand 
Binary Tree Segment Tree
*/

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class STNode {
public:
    int start, end, min;
    STNode *left, *right;
    STNode(int start, int end, int min) {
        this->start = start;
        this->end = end;
        this->min = min;
        this->left = this->right = NULL;
    }
};

class Solution { 
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    vector<int> intervalMinNumber(vector<int> &A, vector<Interval> &queries) {
        // write your code here
        STNode* root = buildST(A, 0, (int)A.size() - 1);
        vector<int> res;
        if(!root)
            return res;
        for(int i = 0; i < (int)queries.size(); i++){
            res.push_back(queryST(root, queries[i].start, queries[i].end));	
        }
        return res;
    }

    STNode* buildST(vector<int> &A, int s, int e){
        if(s > e)
            return NULL;
        if(s == e)
           return new STNode(s, e, A[s]);

        STNode* t = new STNode(s, e, 0);
        int mid = s + (e - s)/2;
        STNode* l = buildST(A, s, mid);
        STNode* r = buildST(A, mid + 1, e);
        t->left = l;
        t->right = r;
        t->min = min(l->min, r->min);
        return t;
    }
    
    int queryST(STNode *root, int s, int e){
        if(!root || s > e)
            return -1;
        if(root->start == s && root->end == e)
            return root->min;
        int mid = root->start + (root->end - root->start)/2;
        int l = queryST(root->left, max(root->start, s), min(mid, e));
        int r = queryST(root->right, max(mid + 1, s), min(e, root->end));
        if(s > mid)
            return r;
        if(e <= mid)
            return l;
        return min(l, r);
    }
};
