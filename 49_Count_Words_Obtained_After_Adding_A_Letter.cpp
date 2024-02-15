class Solution {
private:
    int findNumberEquivalent(string &s){
        int number=0;
        for(auto &ch:s)
            number|=(1<<(ch-'a'));
        return number;
    }
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        set<int>st;
        for(auto &s:startWords){
            int number=findNumberEquivalent(s);
            st.insert(number);
        }
        int ans=0;
        for(auto &w:targetWords){
            int targetNumber=findNumberEquivalent(w);
            for(int i=0;i<w.size();i++){
                int candidate=(targetNumber - ( 1<<(w[i]-'a') ));
                if(st.find(candidate)!=st.end()){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};