class Solution {
public:
    int n,minPrice;
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        minPrice =0;
        n = price.size();
        int rem = 0;
        for(int i=0;i<n;i++) {
            rem+=needs[i];
            minPrice+=price[i]*needs[i];
        }
        applyOffers(price,special,needs,0,rem);
        return minPrice;
    }
    
    void applyOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs,int sum,int remaining) {
        if(remaining<0 || sum>=minPrice) return;
        if(remaining == 0) {
            minPrice = min(minPrice,sum);
            return;
        }
        vector<int> needTemp;
        for(int i=0;i<special.size();i++) {
            int offerItems = 0;
            bool valid = true;
            needTemp.clear();
            for(int j=0;j<n;j++) {
                if(special[i][j]>needs[j]) {
                    valid = false;
                    break;
                }
                needTemp.push_back(needs[j]-special[i][j]);
                offerItems+=special[i][j];
            }
            if(valid) 
                applyOffers(price,special,needTemp,sum+special[i][n],remaining-offerItems);
        }
        int temp = 0;
        for(int i=0;i<n;i++) {
            temp+=price[i]*needs[i];
        }
        minPrice = min(minPrice,temp+sum);
    }
};


