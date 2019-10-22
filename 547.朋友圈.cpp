/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 朋友圈
 */

// @lc code=start
class Solution {
public:
    vector<int> p;

    int find(int x) {
        if (x != p[x]) p[x] = find(p[x]);
        return p[x];
    }

    int findCircleNum(vector<vector<int>>& M) {
        if (M.empty()) return 0;
        int n = M.size();
        p = vector<int>(n);
        int ans = n;

        for (int i = 0; i < n; i ++) p[i] = i;

        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < i; j ++) {
                if (M[i][j] == 1) {
                    if (find(i) != find(j)) {
                        p[find(i)] = find(j);
                        ans --;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

