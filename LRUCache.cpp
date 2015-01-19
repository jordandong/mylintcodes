/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.

set(key, value) - Set or insert the value if the key is not already present. 
                  When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*/

#include<list>

class LRUCache{
private:
    int cap;
    int size;
    list<pair<int, int> > val_list; //<value>
    unordered_map<int, list<pair<int, int> >::iterator> kv_map; //<key, pos in val_list>
public:
    // @param capacity, an integer
    LRUCache(int capacity) {
        // write your code here
        cap = capacity;
        size = 0;
    }
    
    // @return an integer
    int get(int key) {
        // write your code here
        int val = -1;
        if(kv_map.find(key) == kv_map.end()){
            return val;
        }else{
            list<pair<int, int> >::iterator it = kv_map[key];
            val = it->second;
            val_list.erase(it);
            val_list.push_front(make_pair(key, val));
            kv_map[key] = val_list.begin();
        }
        return val;
    }

    // @param key, an integer
    // @param value, an integer
    // @return nothing
    void set(int key, int value) {
        // write your code here
        if(kv_map.find(key) == kv_map.end()){
            if(size >= cap){
                del();
            }
            val_list.push_front(make_pair(key, value));
            kv_map[key] = val_list.begin();
            size++;
        }else{
            list<pair<int, int> >::iterator it = kv_map[key];
            val_list.erase(it);
            val_list.push_front(make_pair(key, value));
            kv_map[key] = val_list.begin();
        }
    }
    
    void del(){
        if(size > 0){
            list<pair<int, int> >::reverse_iterator it = val_list.rbegin();
            kv_map.erase(it->first);
            val_list.pop_back();
            size--;
        }
    }
};
