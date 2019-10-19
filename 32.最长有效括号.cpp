/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int work(string s) {
        int res = 0;
        for (int i = 0, start = 0, cnt = 0; i < s.size(); i ++) {
            
            if (s[i] == '(') cnt ++;
            else {
                cnt --;
                if (cnt < 0) start = i + 1, cnt = 0;
                if (cnt > 0) continue;
                if (cnt == 0) res = max(res, i - start + 1);
            }
        }
        return res; 
    }

    int longestValidParentheses(string s) {
        int res = work(s);
        reverse(s.begin(), s.end());
        for (auto& c : s) c ^= 1;
        return max(res, work(s));
    }
};
// @lc code=end

