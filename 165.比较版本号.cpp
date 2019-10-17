/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */

// @lc code=start
class Solution {
public:
    int compareVersion(string v1, string v2) {
        int i = 0, j = 0;
        while (i < v1.size() || j < v2.size()) {
            int x = i, y = j;
            while (x < v1.size() && v1[x] != '.') x ++;
            while (y < v2.size() && v2[y] != '.') y ++;
            
            int a = x == i ? 0 : atoi(v1.substr(i, x).c_str());
            int b = y == j ? 0 : atoi(v2.substr(j, y).c_str());
            if (a > b) return 1;
            else if (a < b) return -1;

            i = x + 1;
            j = y + 1;

        }
        return 0;
    }
};
// @lc code=end

