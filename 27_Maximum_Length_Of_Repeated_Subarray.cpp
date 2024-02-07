class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), ans = 0;
        if (n < m) {
            swap(nums1, nums2);
            swap(n, m);
        }
        vector<int> dp(n + 1), dp2(n + 1);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[j] = dp2[j - 1] + 1; 
                } else {
                    dp[j] = 0;
                }
                ans = max(ans, dp[j]);
            }
            dp2 = dp;
        }
        return ans;
    }
};