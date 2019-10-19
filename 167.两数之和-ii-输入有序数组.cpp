/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for (int j = 0, i = n - 1; j < n; j ++) {
            while (i - 1 > j && numbers[i - 1] + numbers[j] >= target) i --;
            if (numbers[i] + numbers[j] == target) return {j + 1, i + 1};
        }
        return {-1, -1};
    }
};
// @lc code=end

