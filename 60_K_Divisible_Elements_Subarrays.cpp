class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        long long val = 0, mod = 1000000016531LL;
        int i, j, n = nums.size(), cnt = 0, ans = 0;
        unordered_set<int> hst;
        for (i = 0; i < n; i++) {
            for (j = i; j < n; j++) {
                cnt += nums[j] % p == 0;
                if (cnt > k) break;
                val = (val * 201 + nums[j]) % mod;
                ans += !hst.count(val);
                hst.insert(val);
            }
            cnt = 0, val = 0;
        }
        return ans;
    }
};