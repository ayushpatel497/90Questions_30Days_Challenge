class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size(), i = 0;
        vector<int> ans;
        while(k>0){
            ans.push_back(nums[i]);
            i++;
            k--;
        }
        for(int j=i;j<n;j++)
        {
            int minn = min_element(ans.begin(), ans.end()) - ans.begin();
            if(ans[minn] < nums[j]){
                ans.erase(ans.begin()+minn);
                ans.push_back(nums[j]);
            }
        }
        return ans;
    }
};
