/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        for (int i = 0; i < 1 << 9; i ++) {
            vector<int> path;
            int cnt = 0;
            int sum = 0;
            for (int j = 0; j < 9; j ++) {
                if (i >> j & 1) {
                    path.push_back(j + 1);
                    cnt ++;
                    sum += j + 1;
                }
            }
            if (cnt == k && sum == n) ans.push_back(path);
        }
        return ans;
    }
};
// @lc code=end

