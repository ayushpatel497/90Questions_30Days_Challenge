class Solution {
public:
    long long sumScores(string s) {
        int i, prel, m;
        i = 1, prel = 0, m = s.size();
        vector<int> lps(m, 0);
        vector<int> ans(m, 1);
        long long res = 0;
        while (i < m) {
            if (s[i] == s[prel]) {
                ans[i] += ans[prel];
                lps[i] = prel + 1;
                prel++, i++;
            } else if (prel == 0)
                i++;
            else
                prel= lps[prel - 1];
        }
        for (int i : ans)
            res += i;
        return res;
    }
};