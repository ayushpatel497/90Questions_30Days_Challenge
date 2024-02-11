class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,char> masks;
        for(int i=0;i<reservedSeats.size();i++){
            int row=reservedSeats[i][0];
            int col=reservedSeats[i][1];
            if(col>1 && col<10) masks[row-1]|=(1<<(col-2));
        }
        int max_seat=n*2;
        int res=0;
        for(auto &[row,seat]:masks){
            bool left=seat&0b11110000;
            bool right=seat&0b00001111;
            bool mid=seat&0b00111100;
            res+=left&&right&&mid?2:1;
        }
        return max_seat-res;
    }
};