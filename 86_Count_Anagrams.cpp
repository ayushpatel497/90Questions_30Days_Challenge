class Solution {
    int m = 1e9 + 7;
    inline int mulmod(int x, int y) {
        return (long long)x * y % m;
    }
    
public:
    int countAnagrams(string s) {
        int n = s.size(), m = 1e9 + 7;

        vector<int> fact(n + 1), inv_fact(n + 1);
        fact[0] = fact[1] = inv_fact[1] = 1;

        for (int i = 2; i <= n; ++i) {
            fact[i] = mulmod(i, fact[i - 1]);
            inv_fact[i] = (m - mulmod(m / i, inv_fact[m % i])) % m;
        }

        for (int i = 3; i <= n; ++i) {
            inv_fact[i] = mulmod(inv_fact[i], inv_fact[i - 1]);
        }

        int acc = 1;
        for (int i = 0; i < n;) {
            int j = i;
            array<int, 26> cnt = {0};

            while (j < n && s[j] != ' ') {
                ++cnt[s[j] - 'a'];
                ++j;
            }

            acc = mulmod(acc, fact[j - i]);
            for (int y : cnt) 
                if (y > 1) 
                    acc = mulmod(acc, inv_fact[y]);
            i = j + 1;
        }
        return acc;
    }
};