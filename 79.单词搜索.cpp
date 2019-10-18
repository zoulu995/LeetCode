/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) return false;
        int n = board.size(), m = board[0].size();

        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++) {
                if (dfs(board, word, i, j, 0)) return true;
            }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int x, int y, int u) {
        if (board[x][y] != word[u]) return false;
        if (u == word.size() - 1) {
            return true;
        }

        board[x][y] = '.';
        for (int i = 0; i < 4; i ++) {
            int a = x + dx[i];
            int b = y + dy[i];
            if (a >= 0 && a < board.size() && b >= 0 && b < board[0].size()) {
                if (dfs(board, word, a, b, u + 1)) return true;
            }
        }
        board[x][y] = word[u];
        return false;


    }
};
// @lc code=end

