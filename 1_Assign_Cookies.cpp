class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(begin(g),end(g));
        sort(begin(s),end(s));
        int i=g.size()-1,j=s.size()-1,ans=0;
        while(i>=0 && j>=0){
            if(g[i]>s[j]) i--;
            else ans++,j--,i--;
        }
        return ans;
    }
};