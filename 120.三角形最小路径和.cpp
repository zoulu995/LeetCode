/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        if (t.empty() || t[0].empty()) return 0;
        int n = t.size();
        vector<vector<int>> dp(n, vector<int>(n));
        dp[0][0] = t[0][0];
        for (int i = 1; i < n; i ++) {
            for (int j = 0; j <= i; j ++) {
                dp[i][j] = INT_MAX;
                if (j > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + t[i][j]);
                if (j < i) dp[i][j] = min(dp[i][j], dp[i - 1][j] + t[i][j]);
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i ++) ans = min(ans, dp[n - 1][i]);
        return ans;
    }
};
// @lc code=end

