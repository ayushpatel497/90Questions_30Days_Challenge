class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        map<string, vector<int>> when;
        for (auto v : access_times) {
            string a = v[0], b = v[1];
            when[a].push_back(stoi(b));
        }
        vector<string> ret;
        for (auto &[x, lst] : when) {
            sort(begin(lst), end(lst));
            int k = lst.size();
            bool flag = false;
            for (int i = 0; i + 3 <= k; ++i)
                flag |= lst[i + 2] < lst[i] + 100;
            if (flag) ret.push_back(x);
        }
        return ret;
    }
};