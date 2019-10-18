/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    int n;
    vector<bool> st;
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) return ans;
        n = nums.size();
        st = vector<bool>(n);
        
        dfs(nums, 0);
        return ans;
    }
    
    void dfs(vector<int>& nums, int u) {
        if (u == n) {
            ans.push_back(path);
            return ;
        }
        
        for (int i = 0; i < n; i ++) {
            if (!st[i]) {
                st[i] = true;
                path.push_back(nums[i]);
                dfs(nums, u + 1);
                st[i] = false;
                path.pop_back();
            }
        }
        
    }   
};
// @lc code=end

