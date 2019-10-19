/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */

// @lc code=start
class Solution {
public:
    unordered_map<string, int> hash;
    vector<string> ans;
    vector<string> findRepeatedDnaSequences(string s) {
        for (int i = 0; i + 10 <= s.size(); i ++) {
            string str = s.substr(i, 10);
            hash[str] ++;
            if (hash[str] == 2) ans.push_back(str);
        }
        return ans;

    }
};
// @lc code=end

