/*
Given an integer array in the construct method, implement two methods query(start, end) and modify(index, value):

For query(start, end), return the sum from index start to index end in the given array.
For modify(index, value), modify the number in the given index to value
Example
Given array A = [1,2,7,8,5].

query(0, 2), return 10.
modify(0, 4), change A[0] from 1 to 4.
query(0, 1), return 6.
modify(2, 1), change A[2] from 7 to 1.
query(2, 4), return 14.
Note
We suggest you finish problem Segment Tree Build, Segment Tree Query and Segment Tree Modify first.

Challenge
O(logN) time for query and modify.

Tags Expand 
Binary Tree Segment Tree
*/

class STNode {
public:
    int start, end;
    long long sum;
    STNode *left, *right;
    STNode(int start, int end, int sum) {
        this->start = start;
        this->end = end;
        this->sum = sum;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    /* you may need to use some attributes here */
    STNode* root;

    /**
     * @param A: An integer vector
     */
    Solution(vector<int> A) {
        // write your code here
        root = buildST(A, 0, (int)A.size() - 1);
    }
    
    /**
     * @param start, end: Indices
     * @return: The sum from start to end
     */
    long long query(int start, int end) {
        // write your code here
        return queryST(root, start, end);
    }
    
    /**
     * @param index, value: modify A[index] to value.
     */
    void modify(int index, int value) {
        // write your code here
        modifyST(root, index, value);
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
        t->sum = l->sum + r->sum;
        return t;
    }
    
    long long queryST(STNode *root, int s, int e){
        if(!root || s > e)
            return -1;
        if(root->start == s && root->end == e)
            return root->sum;
        int mid = root->start + (root->end - root->start)/2;
        long l = queryST(root->left, max(root->start, s), min(mid, e));
        long r = queryST(root->right, max(mid + 1, s), min(e, root->end));
        if(s > mid)
            return r;
        if(e <= mid)
            return l;
        return l + r;
    }
    
    void modifyST(STNode *root, int index, int value){
        if(!root)
            return;
        if(root->start == index && root->end == index){
            root->sum = value;
        }else{
            int mid = root->start + (root->end - root->start)/2;
            if(index <= mid)
                modifyST(root->left, index, value);
            else
                modifyST(root->right, index, value);
            root->sum = root->left->sum + root->right->sum;
        }
    }
};
