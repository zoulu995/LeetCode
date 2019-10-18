/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    int n;
    vector<vector<int>> ans;
    
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        for (int i = 0; i < 1 << n; i ++) {
            vector<int> path;
            for (int j = 0; j < n; j ++)
                if (i >> j & 1) path.push_back(nums[j]);
            ans.push_back(path);
        }
        return ans;
    }
};
// @lc code=end

