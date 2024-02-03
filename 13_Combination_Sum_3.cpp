class Solution {
private:
    vector<vector<int>> ans;
    void helper(vector<int>& temp, int cnum, int k, int n) {
        if(n < 0 || temp.size() > k) 
            return;
        if(n == 0 && temp.size() == k){
            ans.push_back(temp);
            return;
        }
        for(int i=cnum; i<=9; ++i) {
            temp.push_back(i);
            helper(temp, i+1, k, n-i);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        helper(temp, 1, k, n);
        return ans;
    }
};