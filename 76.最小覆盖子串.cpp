/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    unordered_map<char, int> hash;
    int cnt;
    string minWindow(string s, string t) {

        for (auto c : t) hash[c] ++, cnt ++;
        string ans;
        for (int i = 0, j = 0; j < s.size(); j ++) {
            if (hash[s[j]] > 0) cnt --;
            hash[s[j]] --;
            while (hash[s[i]] < 0 && i < j) hash[s[i ++]] ++;
            if (!cnt)
                if (ans.empty() || ans.size() > j - i + 1) ans = s.substr(i, j - i + 1);


        }
        
        return ans;

    }
};
// @lc code=end

