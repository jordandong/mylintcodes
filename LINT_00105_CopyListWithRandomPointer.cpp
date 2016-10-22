/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        unordered_map<RandomListNode*, RandomListNode*> old_new;
        
        RandomListNode* pre = new RandomListNode(-1);
        RandomListNode* cur = pre;
        
        while(head){
            if(old_new.find(head)!=old_new.end()){
                cur->next = old_new[head];
                cur = cur->next;
            }else{
                cur->next = new RandomListNode(head->label);
                cur = cur->next;
                old_new[head] = cur;
            }
            
            if(head->random){
                if(old_new.find(head->random) != old_new.end()){
                    cur->random = old_new[head->random];
                }else{
                    cur->random = new RandomListNode(head->random->label);
                    old_new[head->random] = cur->random;
                }
            }
            
            head = head->next;
        }
        
        cur = pre->next;
        delete pre;
        return cur;
    }
};
