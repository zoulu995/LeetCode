/*
 * @lc app=leetcode.cn id=473 lang=cpp
 *
 * [473] 火柴拼正方形
 */

// @lc code=start
class Solution {
public:
    int n;
    vector<bool> cnt;
    bool makesquare(vector<int>& nums) {
        n = nums.size();
        int sum = 0;
        for (auto num:nums) sum += num;
        if (!sum || sum % 4) return false;
        cnt = vector<bool>(n);
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());

        return dfs(nums, 0, 0, sum / 4);
    }

    bool dfs(vector<int>& nums, int u, int sum, int length) {
        if (u == 4) return true;
        if (sum == length) return dfs(nums, u + 1, 0, length);

        for (int i = 0; i < n; i ++) {
            if (!cnt[i] && sum + nums[i] <= length) {
                cnt[i] = true;
                if (dfs(nums, u, sum + nums[i], length)) return true;
                cnt[i] = false;
                if (!sum ) return false;
                if (sum + nums[i] == length) return false;
            }
        }
        return false;
    }
};
// @lc code=end

