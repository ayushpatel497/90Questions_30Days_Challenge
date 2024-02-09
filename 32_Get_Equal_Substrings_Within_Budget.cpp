class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int sum = 0, c = 0, start = 0;
        for (int i = 0; i < n; i++) {
            sum += (int)abs(s[i] - t[i]);
            c++;
            if (sum > maxCost) {
                sum -= abs(s[start] - t[start]);
                start++;
                c--;
            }
        }
        return c;
    }
};