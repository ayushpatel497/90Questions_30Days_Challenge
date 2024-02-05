class Solution {
public:
    string frequencySort(string s) {
        string ans = "";
        unordered_map<char,int>um;
        for(auto c:s)
            um[c]++;
        priority_queue<pair<int, char>> pairs;
        for(auto [c, freq] : um)
            pairs.push({freq, c});
        while(!pairs.empty()){
            auto curr = pairs.top();
            pairs.pop();
            ans += string(curr.first, curr.second);
        }
        return ans;
    }
};