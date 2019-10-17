/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        dfs1(root, ans);
        return ans;
    }

    void dfs1(TreeNode* root, string& str) {
        if (!root) {
            str += "#,";
            return ;
        }

        str += to_string(root->val) + ',';
        dfs1(root->left, str);
        dfs1(root->right, str);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int u = 0;
        TreeNode* root = dfs2(data, u);
        return root;
    }

    TreeNode* dfs2(string data, int& u) {
        if (data[u] == '#')  {
            u += 2;
            return NULL;
        }

        int s = u;
        while (data[u] != ',') u ++;
        int t = atoi(data.substr(s, u).c_str());
        u ++;

        auto root = new TreeNode(t);
        root->left = dfs2(data, u);
        root->right = dfs2(data, u);

        return root;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end

