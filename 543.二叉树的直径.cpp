/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int ans;
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;
    }

    int dfs(TreeNode* root) {
        if (!root) return 0;
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        ans = max(ans, left + right);
        return max(left + 1, right + 1);
    }
};
// @lc code=end

