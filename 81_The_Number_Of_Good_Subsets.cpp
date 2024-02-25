int MOD = 1e9 + 7;
vector<int> invalid = {4, 8, 9, 12, 16, 18, 20, 24, 25, 27, 28};
vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
long long qpow2(int r) {
    long long res = 1, x = 2;
    while (r) {
        if (r & 1) 
            res = res * x % MOD;
        x = x * x % MOD;
        r >>= 1;
    }    
    return res;
}

class Solution {
public:
    int numberOfGoodSubsets(vector<int>& nums) {
        vector<int> cnt(31);
        for (auto& n : nums) cnt[n]++;
        for (auto& n : invalid) cnt[n] = 0;
        int mask = 1 << 10;
        long long dp[mask];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 2; i <= 30; ++i) {
            if (!cnt[i]) 
                continue;
            int cur = 0;
            for (int j = 0; j < 10; ++j)
                if (i % prime[j] == 0) cur |= 1 << j;
            for (int state = mask - 1; state >= 0; --state)
                if ((state & cur) == 0)
                    dp[state | cur] = (dp[state | cur] + dp[state] * cnt[i] % MOD) % MOD;
        }
        int res = 0;
        for (int i = 1; i < mask; ++i) res = (res + dp[i]) % MOD;
        cout << res;
        return res * qpow2(cnt[1]) % MOD;
    }
};