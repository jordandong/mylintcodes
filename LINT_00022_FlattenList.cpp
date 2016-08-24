/*
Given a list, each element in the list can be a list or integer. flatten it into a simply list with integers.

Notice
If the element in the given list is a list, it can contain list too.

Example
Given [1,2,[1,2]], return [1,2,1,2].
Given [4,[3,[2,[1]]]], return [4,3,2,1].

Challenge 
Do it in non-recursive.

Tags 
LintCode Copyright Recursion Non Recursion
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
 
class Solution {
public:
    // @param nestedList a list of NestedInteger
    // @return a list of integer
    vector<int> flatten(vector<NestedInteger> &nestedList) {
        // Write your code here
        using IT = vector<NestedInteger>::const_iterator;
        stack<pair<IT, IT>> depth_;
        vector<int> res;
        depth_.emplace(nestedList.cbegin(), nestedList.cend());
        while (!depth_.empty()) {
            auto &cur = depth_.top();
            if (cur.first == cur.second) {
                depth_.pop();
            } else if (cur.first->isInteger()) {
                res.push_back((depth_.top().first++)->getInteger());
            } else {
                auto &nestedList = cur.first->getList();
                ++cur.first;
                depth_.emplace(nestedList.cbegin(), nestedList.cend());
            }
        }
        return res;
    }
};

class Solution {
public:
    // @param nestedList a list of NestedInteger
    // @return a list of integer
    vector<int> flatten(vector<NestedInteger> &nestedList) {
        // Write your code here
        vector<int> result;
        for (const auto& node : nestedList)
            if (node.isInteger()) {
                result.push_back(node.getInteger());
            } else {
                vector<NestedInteger> sub_list = node.getList();
                auto temp = flatten(sub_list);
                result.insert(result.end(), temp.begin(), temp.end());
            }

        return result;
    }
};
