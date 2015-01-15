/*
The size of the hash table is not determinate at the very beginning. If the total size of keys is too large (e.g. size >= capacity / 10), we should double the size of the hash table and rehash every keys. Say you have a hash table looks like below:

size=3, capacity=4
[null, 21->9->null, 14->null, null]

The hash function is:
int hashcode(int key, int capacity) {
    return key % capacity;
}

here we have three numbers, 9, 14 and 21, where 21 and 9 share the same position as they all have the same hashcode 1 (21 % 4 = 9 % 4 = 1). We store them in the hash table by linked list.
rehashing this hash table, double the capacity, you will get:
size=3, capacity=8
index:           0    1    2     3      4    5     6    7
hash table: [null, 9, null, null, null, 21, 14, null]

Given the original hash table, return the new hash table after rehashing .

Note:
For negative integer in hash table, the position can be calculated as follow:
In C++/Java, if you directly calculate -4 % 3 you will get -1. You can use function: a % b = (a % b + b) % b to make it is a non negative integer.
In Python, you can directly use -1 % 3, you will get 2 automatically.

Example:
Given [null, 21->9->null, 14->null, null], return [null, 9->null, null, null, null, 21->null, 14->null, null]
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
class Solution {
public:
    /**
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */    
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        // write your code here
        int sz = hashTable.size();
        int sz1 = 2*sz;
        if(sz == 0)
            return hashTable;
        vector<ListNode*> res(sz1);
        
        for(int i = 0; i < sz; i++){
            if(!hashTable[i])
                continue;
            ListNode* cur = hashTable[i];
            while(cur){
                int id = (cur->val)%sz1;
                id +=  (id<0 ? sz1:0);
                ListNode* tmp = res[id];
                if(tmp){
                    while(tmp->next)
                        tmp = tmp->next;
                    tmp->next = cur;
                    cur=cur->next;
                    tmp->next->next = NULL;
                }else{
                    res[id] = cur;
                    cur=cur->next;
                    res[id]->next = NULL;
                }
            }
        }
        return res;
    }
};
