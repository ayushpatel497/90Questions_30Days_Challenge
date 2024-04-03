class Solution {
private:
    void helper(string digits, vector<string>&answer, string &temp, vector<string>&pad, int idx){
        if(idx==digits.size()){
            answer.push_back(temp);
            return;
        }
        string value = pad[digits[idx]-'0'];
        for(auto i:value){
            temp.push_back(i);
            helper(digits,answer,temp,pad,idx+1);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};
        vector<string>pad={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>answer;
        string temp;
        helper(digits,answer,temp,pad,0);
        return answer;
    }
};
