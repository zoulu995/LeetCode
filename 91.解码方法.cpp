/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        int n = s.size();
        vector<long long> f(n + 1);
        f[0] = 1;
        for (int i = 1; i <= n; i ++) {
            if (s[i - 1] - '0' != 0)
                f[i] += f[i - 1];
            if (i >= 2) {
                int a = s[i - 1] - '0';
                int b = s[i - 2] - '0';
                int t = a + 10 * b;
                if (t >= 10 && t <= 26) f[i] += f[i - 2];
            }
        }
        return f[n];
    }
};
// @lc code=end

