/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
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
    int cnt;
    unordered_map<string, int> hash;
    unordered_map<int, int> count;
    vector<TreeNode*> ans;

    string dfs(TreeNode* root) {
        if (!root) return to_string(hash["#"]);

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        string tree = to_string(root->val) + ',' + left + ',' + right;
        if (!hash.count(tree)) hash[tree] = ++ cnt;
        int t = hash[tree];
        count[t] ++;
        if (count[t] == 2) ans.push_back(root);

        return to_string(t);

    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        hash["#"] = ++ cnt;
        dfs(root);
        return ans;
    }
};
// @lc code=end

