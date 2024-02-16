class Solution {
private:
    string ones[20] = {"", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine", " Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen"};
    string tens[10] = {"", " Ten", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety"};
    string thousands[4] = {"", " Thousand", " Million", " Billion"};

    string solve(int n){
        if(n<20)
            return ones[n];
        if(n<100)
            return tens[n/10] + solve(n%10);
        if(n<1000)
            return solve(n/100) + " Hundred" + solve(n%100);
        for(int i=3;i>=0;i--)
            if(n>=pow(1000,i))
                return solve(n/pow(1000,i)) + thousands[i] + solve(n%(int)pow(1000,i));
        return "";
    }
public:
    string numberToWords(int num) {
        if(num ==0)
            return "Zero";
        return solve(num).substr(1);
    }
};