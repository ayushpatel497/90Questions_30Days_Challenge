int dp[14][1<<14];
bool can_divide[14][14];
int mod = 1e9+7;

class Solution {
public:
    int specialPerm(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        memset(can_divide, 0, sizeof(can_divide));
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                can_divide[i][j] = nums[i] % nums[j] == 0;
            }
        }
        return solve(n, 0, 0);        
    }

    int solve(int n, int i, int mask) {
        if (mask == (1 << n) -1) { return 1; }
        if (dp[i][mask] != -1) { return dp[i][mask]; }
        long long res = 0;
        for (int j = 0; j < n; ++j) {
            if ((mask & (1<<j)) != 0) { continue; }
            if (mask == 0 || can_divide[i][j] || can_divide[j][i]) {
                res += solve(n, j, mask|(1<<j));
            }
        }
        return dp[i][mask] = res % mod;
    }
};