/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        for (int i = 0; i < s.size(); i ++) {
            for (int j = i, k = i; j >= 0 && k < s.size() && s[j] == s[k]; j --, k ++) {
                if (k - j + 1 > ans.size()) ans = s.substr(j, k - j + 1);
            }
            for (int j = i, k = i + 1; j >= 0 && k < s.size() && s[j] == s[k]; j --, k ++) {
                if (k - j + 1 > ans.size()) ans = s.substr(j, k - j + 1);
            }
        }
        return ans;
        
    }
};
// @lc code=end

