/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for (auto str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            hash[key].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto item : hash) ans.push_back(item.second);
        return ans;
    }
};
// @lc code=end

