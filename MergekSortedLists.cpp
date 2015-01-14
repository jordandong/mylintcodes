/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
 
class min_heap {
    public:
    bool operator() (const ListNode* a, const ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        priority_queue<ListNode*, vector<ListNode*>, min_heap> q;
        ListNode* head = new ListNode(-1);
        ListNode* cur = head;
        for(ListNode* e : lists){
            if(e) q.push(e);
        }
        
        while(q.size()){
            cur->next = q.top();
            q.pop();
            cur = cur->next;
            if(cur->next)
                q.push(cur->next);
        }
        
        cur = head->next;
        delete head;
        return cur;
    }
};
