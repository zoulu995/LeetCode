/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
class Solution {
public:
    vector<int> ans;
    void dfs(TreeNode* root) {
        if (root->left) dfs(root->left);
        ans.push_back(root->val);
        if (root->right) dfs(root->right);
    }

    // 递归写法
    vector<int> inorderTraversal1(TreeNode* root) {
        if (!root) return ans;
        dfs(root);
        return ans;
    }

    // 非递归写法，递归变成非递归，一般考虑用栈来考虑
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;

        auto p = root;
        while (p || stk.size()) {
            while (p) {
                stk.push(p);
                p = p->left;
            }

            p = stk.top();
            stk.pop();
            ans.push_back(p->val);
            p = p->right;
        }
        return ans;
    }
};
// @lc code=end

