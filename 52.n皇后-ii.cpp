/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution {
public:
    int ans;
    int n;
    vector<bool> col, d, nd;

    void dfs(int u) {
        if (u == n) {
            ans ++;
            return ;
        }

        for (int i = 0; i < n; i ++) {
            if (!col[i] && !d[u + i] && !nd[u - i + n]) {
                col[i] = d[u + i] = nd[u - i + n] = true;
                dfs(u + 1);
                col[i] = d[u + i] = nd[u - i + n] = false;
            }
        }
    }
    
    int totalNQueens(int _n) {
        n = _n;
        col = vector<bool>(n);
        d = nd = vector<bool>(2 * n);

        dfs(0);
        return ans;
    }
};
// @lc code=end

