/*
LFU (Least Frequently Used) is a famous cache eviction algorithm.
For a cache with capacity k, if the cache is full and need to evict a key in it, the key with the lease frequently used will be kicked out.

Implement set and get method for LFU cache.

Example
Given capacity=3
set(2,2)
set(1,1)
get(2)
>> 2
get(1)
>> 1
get(2)
>> 2
set(3,3)
set(4,4)
get(3)
>> -1
get(2)
>> 2
get(1)
>> 1
get(4)
>> 4 
*/

#include <list>

class LFUCache {
private:
    struct ListNode {
        list<pair<int, int>> kvs;
        int freq;
        ListNode(int k, int v, int f) : kvs({{k, v}}), freq(f) {}
    };

    unordered_map<int, pair<list<ListNode>::iterator, list<pair<int, int>>::iterator>> keymap;
    list<ListNode> matrix; 
    int cur_size, max_size;
public:
    // @param capacity, an integer
    LFUCache(int capacity) {
        // Write your code here
        cur_size = 0;   
        max_size = capacity;
    }

    // @return an integer
    int get(int key) {
        // Write your code here    
        if (keymap.find(key) == keymap.end())
            return -1;
        auto row = keymap[key].first;
        auto col = keymap[key].second;
        int val = col->second;
        set(key, val);
        return val;
    }

    // @param key, an integer
    // @param value, an integer
    // @return nothing
    void set(int key, int value) {
        // Write your code here    
        if (keymap.find(key) == keymap.end()) {
            if (max_size == 0)
                return;
            if (cur_size >= max_size)
                del();
            if (matrix.empty() || matrix.back().freq != 1) { //adding new key/val with freq(1) at the bottom
                auto newrow = matrix.emplace(matrix.end(), key, value, 1);
                keymap[key] = make_pair(newrow, newrow->kvs.begin());
            } else { //adding new key/val with freq(1) into the exsiting row
                auto newrow = --matrix.end();
                newrow->kvs.push_front({key, value});
                keymap[key] = make_pair(newrow, newrow->kvs.begin());
            }
            cur_size++;
        } else {
            auto row = keymap[key].first;
            auto col = keymap[key].second;
            auto lastrow = row;
            --lastrow;
            //if (lastrow == matrix.end() || lastrow->freq != row->freq + 1) {
            if (row == matrix.begin() || lastrow->freq != row->freq + 1) { //sorted by freqs from bigger to smaller
                auto newrow = matrix.emplace(row, key, value, row->freq + 1); //insert different freq with new kv list
                keymap[key] = make_pair(newrow, newrow->kvs.begin());
            } else { //update existing kv list
                auto newrow = lastrow;
                newrow->kvs.push_front({key, value});
                keymap[key] = make_pair(newrow, newrow->kvs.begin());
            }
            row->kvs.erase(col); //remove the key/val from old kvs list
            if (row->kvs.empty())
                matrix.erase(row);
        } 
    }

    void del() {
        if (cur_size <= 0)
            return;
        auto row = matrix.end(); //found key/val with least freq at the bottom
        row--;
        auto col = row->kvs.end();
        col--;
        int key = col->first;
        row->kvs.erase(col); //remove the kv from old kv list
        if (row->kvs.empty())
            matrix.erase(row);
        keymap.erase(key);
        cur_size--;
    }
};
