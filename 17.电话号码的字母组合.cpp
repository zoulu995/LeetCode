/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    vector<string> ans;
    char nums[10][10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs",
    "tuv", "wxyz"}; 
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return ans;
        dfs(digits, 0, "");
        return ans;
    }

    void dfs(string& s, int u, string path) {
        if (u == s.size()) {
            ans.push_back(path);
            return ;
        }

        int v = s[u] - '0';
        for (int i = 0; nums[v][i]; i ++) {
            path += nums[v][i];
            dfs(s, u + 1, path);
            path.pop_back();
        }

    }
};
// @lc code=end

