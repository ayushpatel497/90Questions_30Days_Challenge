class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size(); 
        vector<int> dp(n+1,1),par(n,-1);
        int en=0,mxlen=1;
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(nums[i]%nums[j]==0)
                {
                    if(dp[i]<dp[j]+1)
                    {
                        dp[i]=dp[j]+1;
                        par[i]=j;
                        if(mxlen<dp[i])
                        {
                            mxlen=dp[i];
                            en=i;
                        }
                    }
                }
            }
        } 
        vector<int> ans;
        int j=en;
        while(j>=0)
        {
            ans.push_back(nums[j]);
            j=par[j];
        }
        return ans;
    }
};