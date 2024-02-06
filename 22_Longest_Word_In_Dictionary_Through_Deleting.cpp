class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int len = 0;
        string ans = "";
        for(auto t: dictionary)
        {
            int n = s.size(), m = t.size();
            int i = 0, j = 0;
            while (i < n && j < m)
            {
                if (s[i] == t[j])
                ++i, ++j;
                else
                ++i;
            }
            if (j == m && len < t.size())
            len = t.size(), ans = t;
            else if (j == m && len == t.size() && t < ans)
            ans = t;
        }
        return ans;
    }
};