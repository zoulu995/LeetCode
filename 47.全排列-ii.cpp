/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    int n;
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> st;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.empty()) return ans;
        n = nums.size();
        st = vector<bool>(n);
        path = vector<int>(n);

        sort(nums.begin(), nums.end());
        dfs(nums, 0, 0);
        return ans;
    }
    //枚举每个数放到哪个位置上
    void dfs(vector<int>& nums, int u, int start) {
        if (u == n) {
            ans.push_back(path);
            return ;
        }

        for (int i = start; i < n; i ++) {
            if (!st[i]) {
                st[i] = true;
                path[i] = nums[u];
                dfs(nums, u + 1, u + 1 < n && nums[u + 1] == nums[u] ? i + 1 : 0);
                st[i] = false;
            }
        }
    }
};
// @lc code=end

