/*
 * @lc app=leetcode.cn id=275 lang=cpp
 *
 * [275] H指数 II
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty()) return 0;
        int n = citations.size();
        
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            int h = n - mid;
            if (citations.size() - mid <= citations[mid]) r = mid;
            else l = mid + 1;
        }
        
        if (citations.size() - l <= citations[l]) return citations.size() - l;
        return 0;
    }
};
// @lc code=end

