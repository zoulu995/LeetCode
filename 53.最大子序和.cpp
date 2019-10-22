/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    vector<int> dp;
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size(), ans = INT_MIN;
        dp = vector<int>(n + 1);
        for (int i = 1; i <= n; i ++) {
            dp[i] = max(dp[i - 1] + nums[i - 1], nums[i - 1]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
// @lc code=end

