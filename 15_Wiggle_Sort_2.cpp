class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        if(n==0 || n==1) 
            return;
        nth_element(nums.begin(),nums.begin() + n/2,nums.end());
        int mid = nums[n/2];
        int largePos = 1;
        int smallPos = n%2==0 ? n-2: n-1;
        int cur = 0;
        while(cur<n) {
            if(nums[cur]<mid && (cur<smallPos || (cur>=smallPos && cur%2!=0))) {
                swap(nums[cur],nums[smallPos]);
                smallPos-=2;
            }
            else if(nums[cur]>mid && (largePos<cur || (largePos>=cur && cur%2==0))) {
                swap(nums[cur],nums[largePos]);
                largePos+=2;
            }
            else cur++;
        }
    }
};