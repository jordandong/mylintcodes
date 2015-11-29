/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
The update(i, val) function modifies nums by updating the element at index i to val.

Example:
Given nums = [1, 3, 5]
sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8

Note:
The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.

Subscribe to see which companies asked this question

Hide Tags Segment Tree Binary Indexed Tree
Hide Similar Problems (E) Range Sum Query - Immutable (H) Range Sum Query 2D - Mutable
Have you met this question in a real interview? Yes  No
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

class NumArray {
public:
    NumArray(vector<int> &nums) {
        root = buildST(nums, 0, (int)nums.size() - 1);
    }

    void update(int i, int val) {
        modifyST(root, i, val);
    }

    int sumRange(int i, int j) {
        return queryST(root, i, j);
    }
    
    STNode* buildST(vector<int> &nums, int s, int e){
        if(s > e)
            return NULL;
        if(s == e)
           return new STNode(s, e, nums[s]);

        STNode* t = new STNode(s, e, 0);
        int mid = s + (e - s)/2;
        STNode* l = buildST(nums, s, mid);
        STNode* r = buildST(nums, mid + 1, e);
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
private:
    STNode* root;
};
// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
