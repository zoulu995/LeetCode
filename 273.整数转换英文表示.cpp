/*
 * @lc app=leetcode.cn id=273 lang=cpp
 *
 * [273] 整数转换英文表示
 */

// @lc code=start
class Solution {
public:
    string small[20] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", 
    "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen",
    "Nineteen"};
    string decade[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy",
    "Eighty", "Ninety"};
    string big[4] = {"Billion", "Million", "Thousand", ""};
    string numberToWords(int num) {
        string ans;
        if (!num) return small[0];
        for (int i = 1e9, j = 0; i > 0 ; i /= 1000, j ++) {
            if (num >= i) {
                ans += getpart(num / i) + big[j] + " ";
                num %= i;
            }
        }
        while (ans.back() == ' ') ans.pop_back();
        return ans;
    }

    string getpart(int num) {
        string res;
        if (num >= 100) {
            res += small[num/100] + " Hundred ";
            num %= 100;
        }
        if (!num) return res;
        if (num >= 20) {
            res += decade[num / 10] + ' ';
            num %= 10; 
        }
        if (!num) return res;
        res += small[num] + ' ';
        return res;
    }
};
// @lc code=end

