class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder.empty())
            return false;
        int ct=1,i=0;
        while(i<preorder.size()){
            if(preorder[i]=='#')
                ct--;
            else 
                ct++;
            if(ct==0)
                break;
            while(i<preorder.size() && preorder[i++]!=',');
        }
        return ct==0 && i==preorder.size()-1;
    }
};