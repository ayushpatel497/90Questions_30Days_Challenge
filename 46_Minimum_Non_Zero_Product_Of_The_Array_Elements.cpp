class Solution {
public:
    int minNonZeroProduct(int p) {
        long long ans = ((long long)(1)<<p) -1;
        int mod = 1000000007;
        long long cur = ans - 1; 
        cur = cur%mod;
        ans = ans%mod;
        int k = 0;
        while(k<=p-2){
            ans *= cur;
            cur *= cur;
            ans %= mod;
            cur %= mod;
            k++;
        } 
        return ans;
    }
};