/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (!n || n == 1) return n;
        int i, j;
        for (i = 1, j = 1; j < n;) {
            while (j < n && nums[j] == nums[j - 1]) j ++;
            if (j < n) {
                nums[i ++] = nums[j ++];
            }
        }
        //cout << i << endl;
        return i;
        
    }
};
// @lc code=end

