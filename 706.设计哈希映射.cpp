/*
 * @lc app=leetcode.cn id=706 lang=cpp
 *
 * [706] 设计哈希映射
 */

// @lc code=start
class MyHashMap {
public:

    const int N = 2e4 + 10;
    vector<list<pair<int, int>>> hash;
    /** Initialize your data structure here. */
    MyHashMap() {
        hash = vector<list<pair<int, int>>> (N);
    }

    list<pair<int, int>>::iterator find(int key) {
        int t = key % N;
        for (auto it = hash[t].begin(); it != hash[t].end(); it ++) {
            if (it->first == key) return it;
        }
        return hash[t].end();
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int t = key % N;
        auto it = find(key);
        if (it == hash[t].end()) hash[t].push_back({key, value});
        else it->second = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int t = key % N;
        auto it = find(key);
        if (it == hash[t].end()) return -1;
        else return it->second;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int t = key % N;
        auto it = find(key);
        if (it != hash[t].end()) hash[t].erase(it);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end

