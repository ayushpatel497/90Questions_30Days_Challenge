class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        vector<vector<int>> indices(201);
        for(int i = 0; i < aliceValues.size(); i++)
            indices[aliceValues[i] + bobValues[i]].push_back(i);
        bool turn = true;
        int turnA = 0, turnB = 0;
        for(int i = 200; i >= 0; i--){
            for(auto idx : indices[i]){
                if(turn)
                    turnA += aliceValues[idx];
                else
                    turnB += bobValues[idx];
                turn = !turn;
            }
        }
        if(turnA > turnB)
            return 1;
        else if(turnA < turnB)
            return -1;
        return 0;
    }
};