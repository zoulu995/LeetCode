/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

// @lc code=start
/**、
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
    // 递归写法
    bool dfs(TreeNode* p, TreeNode* q) {
        if (!p || !q) return !p && !q;
        return p->val == q->val && dfs(p->left, q->right) && dfs(p->right, q->left);
    }

    bool isSymmetric1(TreeNode* root) {
        if (!root) return true;
        return dfs(root->left, root->right);
    }

    // 非递归写法，类似之前中序遍历的写法
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        stack<TreeNode*> left, right;
        auto p = root->left, q = root->right;
        while (p || q || left.size() || right.size()) {
            while (p && q) {
                if (p) left.push(p), p = p->left;
                if (q) right.push(q), q = q->right;
            }

            if (q || p) return false;

            p = left.top(), left.pop();
            q = right.top(), right.pop();

            if (p->val != q->val) return false;
            p = p->right;
            q = q->left;
        }
        return true;

    }
};
// @lc code=end

