/*
Design a data structure that supports all following operations in average O(1) time.
1. insert(val): Inserts an item val to the set if not already present.
2. remove(val): Removes an item val from the set if present.
3. getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.

Example
// Init an empty set.
RandomizedSet randomSet = new RandomizedSet();

// Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomSet.insert(1);

// Returns false as 2 does not exist in the set.
randomSet.remove(2);

// Inserts 2 to the set, returns true. Set now contains [1,2].
randomSet.insert(2);

// getRandom should return either 1 or 2 randomly.
randomSet.getRandom();

// Removes 1 from the set, returns true. Set now contains [2].
randomSet.remove(1);

// 2 was already in the set, so return false.
randomSet.insert(2);

// Since 2 is the only number in the set, getRandom always return 2.
randomSet.getRandom();

Tags 
Twitter Hash Table Array Facebook Amazon Yelp Data Structure Design Google
*/

class RandomizedSet {
private:
    unordered_map<int, int> v2idx;
    vector<int> data;
public:
    RandomizedSet() {
        // do initialize if necessary
    }
    
    // Inserts a value to the set
    // Returns true if the set did not already contain the specified element or false
    bool insert(int val) {
        // Write your code here
        if (v2idx.find(val) != v2idx.end())
            return false;
        data.push_back(val);
        v2idx[val] = data.size() - 1;
        return true;
    }
    
    // Removes a value from the set
    // Return true if the set contained the specified element or false
    bool remove(int val) {
        // Write your code here
        if (v2idx.find(val) == v2idx.end())
            return false;
        int idx = v2idx[val];
        data[idx] = data.back();
        v2idx[data[idx]] = idx;
        v2idx.erase(val);
        data.pop_back();
        return true;
    }

    // Get a random element from the set
    int getRandom() {
        // Write your code here
        if (data.size() == 0)
            return 0;
        return data[rand()%data.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param = obj.insert(val);
 * bool param = obj.remove(val);
 * int param = obj.getRandom();
 */
