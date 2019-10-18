/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    int n;
    set<vector<int>> hash;
    vector<vector<int>> ans;
    // 二进制的做法
    vector<vector<int>> subsetsWithDup1(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < 1 << n; i ++) {
            vector<int> path;
            for (int j = 0; j < n; j ++)
                if (i >> j & 1) 
                    path.push_back(nums[j]);
            hash.insert(path);
        }
        for (auto item : hash) {
            ans.push_back(item);
        }
        return ans;
    }

    //递归的做法。记录每个数字用过几次了
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return res;
    }

    void dfs(vector<int>& nums, int u) {
        if (u == n) {
            res.push_back(path);
            return ;
        }

        int k = 0;
        while (u + k < n && nums[u] == nums[u + k]) k ++;

        for (int i = 0; i <= k; k ++) {
            path.push_back(nums[u]);
            dfs(nums, u + k);
        }

        for (int i = 0; i <= k; i ++) path.pop_back();


    }
};
// @lc code=end

