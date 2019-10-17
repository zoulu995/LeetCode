/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie {
public:
    struct Node
    {
        /* data */
        bool is_end;
        Node *son[26];
        Node() {
            is_end = false;
            for (int i = 0; i < 26; i ++) son[i] = NULL;
        }
    }*root;
    

    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto p = root;
        for (auto c : word) {
            int a = c - 'a';
            if (!p->son[a]) p->son[a] = new Node();
            p = p->son[a];
        }
        p->is_end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto p = root;
        for (auto c : word) {
            int a = c - 'a';
            if (!p->son[a]) return false;
            else p = p->son[a];
        }
        return p->is_end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto p = root;
        for (auto c : prefix) {
            int a = c - 'a';
            if (!p->son[a]) return false;
            p = p->son[a];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

