class Solution {
    static bool comparator(pair<string,int> p1, pair<string,int> p2)
    {
        if(p1.second>p2.second || (p1.second==p2.second && p1.first<p2.first))
            return true;
        return false;
    }
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>um;
        vector<pair<string,int>>v;
        vector<string> ans;
        for(auto i:words)
            um[i]++;
        for(auto i:um)
            v.push_back({i.first,i.second});
        sort(v.begin(),v.end(),comparator);
        for(int i=0;i<k;i++)
            ans.push_back(v[i].first);
        return ans;
    }
};