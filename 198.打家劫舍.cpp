/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    //f[i] 表示不偷i的最大金额 f[i] = max(f[i - 1], g[i - 1]);
    //g[i] 表示偷i的最大金额 g[i] =  max(f[i-1]) + nums[i];
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n + 1);
        vector<int> g(n + 1);

        for (int i = 1; i <= n; i++) {
            g[i] = f[i - 1] + nums[i - 1];
            f[i] = max(f[i - 1], g[i - 1]);
        }

        return max(f[n], g[n]);
    }
};
// @lc code=end

