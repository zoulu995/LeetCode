/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
        if (nums.empty() || nums[0].empty()) return 0;
        int n = nums.size(), m = nums[0].size();
        vector<vector<long long>> f(n, vector<long long>(m));
        for (int i = 0; i < n; i ++) if (nums[i][0] == 0) f[i][0] = 1;
        for (int i = 0; i < m; i ++) if (nums[0][i] == 0) f[0][i] = 1;

        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (nums[i][j] == 0) {
                    if (i > 0) f[i][j] = f[i - 1][j];
                    if (j > 0) f[i][j] = f[i][j - 1];
                    if (i > 0 && j > 0) f[i][j] = f[i - 1][j] + f[i][j - 1];
                }
            }
        }

        return f[n - 1][m - 1];
    }
};
// @lc code=end

