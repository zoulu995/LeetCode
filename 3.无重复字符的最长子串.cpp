/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int ans = 0;
        for (int i = 0, j = 0; i < s.size(); i ++) {
            hash[s[i]] ++;
            while (hash[s[i]] > 1 && j <= i) hash[s[j ++]] --;
            ans = max(ans, i - j + 1);

        }
        return ans;
    }
};
// @lc code=end

