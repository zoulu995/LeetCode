/*
 * @lc app=leetcode.cn id=929 lang=cpp
 *
 * [929] 独特的电子邮件地址
 */

// @lc code=start
class Solution {
public:
    unordered_set<string> set;
    int numUniqueEmails(vector<string>& emails) {
        for (auto email : emails) {
            int k = email.find('@');
            string name;
            for (auto c : email.substr(0, k)) {
                if (c == '+') break;
                else if (c != '.') name += c;
            }
            string domain = email.substr(k);
            set.insert(name + domain);
        }
        return set.size();
    }
};
// @lc code=end

