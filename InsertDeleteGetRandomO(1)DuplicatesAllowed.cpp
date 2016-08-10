/*
Design a data structure that supports all following operations in average O(1) time.

Note: Duplicate elements are allowed.

1. insert(val): Inserts an item val to the collection.
2. remove(val): Removes an item val from the collection if present.
3. getRandom: Returns a random element from current collection of elements. The probability of each element being returned is linearly related to the number of same value the collection contains.

Example:
// Init an empty collection.
RandomizedCollection collection = new RandomizedCollection();
// Inserts 1 to the collection. Returns true as the collection did not contain 1.
collection.insert(1);
// Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
collection.insert(1);
// Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
collection.insert(2);
// getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
collection.getRandom();
// Removes 1 from the collection, returns true. Collection now contains [1,2].
collection.remove(1);
// getRandom should return 1 and 2 both equally likely.
collection.getRandom();

Hide Tags Array Hash Table Design
*/

// T : O(1), S : O(N)
class RandomizedCollection {
private:
    vector<int> list_;
    unordered_map<int, vector<int>> used_;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        used_[val].push_back(list_.size());
        list_.push_back(val);
        return 1 == used_[val].size(); 
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (used_.find(val) == used_.end())
            return false;

        used_[list_.back()].back() = used_[val].back();
        swap(list_[used_[val].back()], list_.back());

        used_[val].pop_back();
        if (used_[val].empty()) {
            used_.erase(val);
        }
        list_.pop_back();

        return true;  
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return list_[rand() % list_.size()];
    }
};
