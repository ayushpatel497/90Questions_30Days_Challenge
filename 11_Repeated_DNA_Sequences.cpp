class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.length()<10)
            return {};
        vector<string> ans;
        unordered_map<string,int> um;
        for(int i=0;i<s.size()-9;i++){
            um[s.substr(i,10)]++;
        }
        for(auto it : um)
            if(it.second > 1)
                ans.push_back(it.first);
        return ans;
    }
};