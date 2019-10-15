/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> stk;
    BSTIterator(TreeNode* root) {
        while (root) {
            stk.push(root);
            root = root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        auto p = stk.top();
        stk.pop();
        int ans = p->val;
        p = p->right;
        while (p) {
            stk.push(p);
            p = p->left;
        }
        return ans;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return stk.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

