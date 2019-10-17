/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        int k = 0; 
        for (int i = 0; i < s.size(); i ++) {
            while (i < s.size() && s[i] == ' ') i ++;
            if (i >= s.size()) break;
            int j = i;
            while (j < s.size() && s[j] != ' ') j ++;
            reverse(s.begin() + i, s.begin() + j);
            if (k) s[k ++] = ' ';
            while (i < j) s[k ++] = s[i ++];            
        }
        s.erase(s.begin() + k, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};
// @lc code=end

