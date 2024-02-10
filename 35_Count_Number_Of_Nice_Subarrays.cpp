class Solution {
private:
    int atMost(vector<int>&nums,int k)
    {
        int i=0;
        int j=0;
        int result=0;
        int sum=0;
        while(j<nums.size())
        {
            sum+=nums[j];
            while(sum>k)
            {
                sum-=nums[i];
                i++;
            }
            result+=j-i+1;
            j++;
        }
        return result;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(auto &i:nums){
            if(i%2)
                i=1;
            else
                i=0;
        }
        return atMost(nums,k) - atMost(nums,k-1);
    }
};