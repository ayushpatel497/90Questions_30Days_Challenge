class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<int> dp(k + 1);
        int i = 0;
        while (dp[k] < n) {
            i++;
            for (int j = k; j > 0; --j) {
                dp[j] += dp[j - 1] + 1;
            } 
        }
        return i;
    }
};