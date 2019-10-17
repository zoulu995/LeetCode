/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int m) {
        if (m == 1) return s;
        string res;
        int n = s.size();
        for (int i = 0; i < m; i ++) {
            if (!i || i == m - 1) {
                for (int j = i, k = 0; j + k < n; k += 2 * (m - 1)) {
                    if (j + k < n) res += s[j + k];
                }
            }
            else {
                for (int j = i, t = 2 * (m - 1) - i, k = 0; j + k < n || t + k < n; k += 2 * (m - 1)) {
                    if (j + k < n) res += s[j + k];
                    if (t + k < n) res += s[t + k];
                }
            }
        }
        return res;
    }
};
// @lc code=end

