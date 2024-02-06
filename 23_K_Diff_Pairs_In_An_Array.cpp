class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        for(int i:nums)
            um[i]++;
        int ans=0;
        for(auto x:um)
        {
            if(k==0)
            {    
                if(x.second>1)
                ans++;
            }
            else if(um.find(x.first+k)!=um.end())
                ans++;
        }
        return ans;
    }
};