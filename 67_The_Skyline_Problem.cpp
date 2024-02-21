class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> points;
        for (auto b : buildings) {
            points.push_back({b[0], -b[2]});
            points.push_back({b[1], b[2]});
        }
        sort(points.begin(), points.end());
        int prev = 0, cur = 0;
        multiset<int> m;
        vector<vector<int>> ans;
        m.insert(0);
        for (auto i:points) {
            if (i.second < 0) {
                m.insert(-i.second);
            } else { 
                m.erase(m.find(i.second));
            } 
            cur = *m.rbegin();
            if (cur != prev) {
                ans.push_back({i.first, cur});
                prev = cur;
            }
        }
        return ans;
    }
};