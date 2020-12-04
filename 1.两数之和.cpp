/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    unordered_map<int, int> hash;
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i ++) hash[nums[i]] = i;
        for (int i = 0; i < nums.size(); i ++) {
            if (hash.count(target - nums[i]) && i != hash[target - nums[i]])
                return {i, hash[target - nums[i]]};
        }
        return {-1, -1};
    }
};
// @lc code=end

