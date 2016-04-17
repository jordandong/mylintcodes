/*
Given a nested list of integers, implement an iterator to flatten it.
Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example
Given the list [[1,1],2,[1,1]], By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].
Given the list [1,[4,[6]]], By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].

Tags 
Recursion Stack Data Structure Design Google

Related Problems 
Easy Flatten Binary Tree to Linked List
*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
 
class NestedIterator {
public:
    using IT = vector<NestedInteger>::const_iterator;
    NestedIterator(vector<NestedInteger> &nestedList) {
        // Initialize your data structure here.
        depth_.emplace(nestedList.cbegin(), nestedList.cend());
    }

    // @return {int} the next element in the iteration
    int next() {
        // Write your code here
        return (depth_.top().first++)->getInteger();
    }
    
    // @return {boolean} true if the iteration has more element or false
    bool hasNext() {
        // Write your code here
        while (!depth_.empty()) {
            auto& cur = depth_.top();
            if (cur.first == cur.second) {
                depth_.pop();
            } else if (cur.first->isInteger()) {
                return true;
            } else {
                auto& nestedList = cur.first->getList();
                ++cur.first;
                depth_.emplace(nestedList.cbegin(), nestedList.cend());
            }
        }
        return false;
    }

private:
    stack<pair<IT, IT>> depth_;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) v.push_back(i.next());
 */


/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
 
class NestedIterator {
private:
    queue<int> q;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        // Initialize your data structure here.
        construct_queue(nestedList);
    }

    // @return {int} the next element in the iteration
    int next() {
        // Write your code here
        int ret = q.front();
        q.pop();
        return ret;
    }

    // @return {boolean} true if the iteration has more element or false
    bool hasNext() {
        // Write your code here
        return !q.empty();
    }

    void construct_queue(const vector<NestedInteger> &nestedList) {
        for (auto& ni : nestedList) {
            if (ni.isInteger()) {
                q.push(ni.getInteger());
            } else {
                construct_queue(ni.getList());
            }
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) v.push_back(i.next());
 */
