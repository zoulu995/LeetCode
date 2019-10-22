/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 */

// @lc code=start
class Solution {
public:
    unordered_map<int, int> hash;
    int subarraySum(vector<int>& nums, int k) {
        hash[0] = 1;
        int sum = 0, ans = 0;
        for (int i = 0; i < nums.size(); i ++) {
            sum += nums[i];
            if (hash.count(sum - k)) ans += hash[sum - k];
            hash[sum] ++;
        }
        return ans;
    }
};
// @lc code=end

