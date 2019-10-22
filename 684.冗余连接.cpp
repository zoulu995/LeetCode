/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */

// @lc code=start
class Solution {
public:
    vector<int> p;

    int find(int x) {
        if (x != p[x]) p[x] = find(p[x]);
        return p[x]; 
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        p = vector<int>(2 * n);
        for (int i = 0; i < 2 * n; i ++) p[i] = i;

        for (int i = 0; i < edges.size(); i ++) {
            int u = edges[i][0], v = edges[i][1];
            if (find(u) != find(v)) p[find(u)] = find(v);
            else return {u, v};
        }

        return {-1, -1};
    }
};
// @lc code=end

