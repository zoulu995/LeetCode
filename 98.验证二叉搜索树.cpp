/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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

    vector<int> treenums;
    void dfs(TreeNode* root) {
        if (root->left) dfs(root->left);
        treenums.push_back(root->val);
        if (root->right) dfs(root->right);
        return ;
    }
    // 采用中序遍历的写法
    bool isValidBST1(TreeNode* root) {
        if (!root) return true;
        dfs(root);
        int n = treenums.size();
        if (n == 1) return true;
        for (int i = 1; i < n; i ++) {
            if (treenums[i] <= treenums[i - 1]) return false;
        }
        return true;
    }


    bool dfs1(TreeNode* root, long long minv, long long maxv) {
        if (!root) return true;
        if (root->val < minv || root->val > maxv) return false;
        return dfs1(root->left, minv, root->val - 1ll) && dfs1(root->right, root->val + 1ll, maxv);

    }
    //直接采用递归的写法
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        return dfs1(root, INT_MIN, INT_MAX);
    }
};
// @lc code=end

