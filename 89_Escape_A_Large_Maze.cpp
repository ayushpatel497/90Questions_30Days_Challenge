class Solution {
public:
    unordered_map<int, unordered_map<int,bool>> block;
    bool isvalid(int x,int y) {
        if(x<0 || y<0 || x>=1e6 || y>=1e6) return false;
        return !block[x][y];
    }
    
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        int cnt=0;
        for (auto it : blocked) {
            cnt++;
            block[it[0]][it[1]]=1;
        }
        if (block[source[0]-1][source[1]] && block[source[0]+1][source[1]] && block[source[0]][source[1]-1] && block[source[0]][source[1]+1]) return false;
        if (block[target[0]-1][target[1]] && block[target[0]+1][target[1]] && block[target[0]][target[1]-1] && block[target[0]][target[1]+1]) return false;
        int maxarea=(cnt*(cnt-1))/2;
        unordered_map<int, unordered_map<int, bool>> vis;
        vis[source[0]][source[1]]=1;
        queue<pair<int, int>> q;
        int area=1;
        q.push({source[0], source[1]});
        while (!q.empty()) {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            if (r==target[0] && c==target[1]) return true;
            if (area>maxarea) return true;
            if (isvalid(r-1, c) && !vis[r-1][c]) {
                vis[r-1][c]=1;
                area++;
                q.push({r-1, c});
            } 
            if (isvalid(r, c+1) && !vis[r][c+1]) {
                vis[r][c+1]=1;
                area++;
                q.push({r, c+1});
            } 
            if (isvalid(r+1, c) && !vis[r+1][c]) {
                vis[r+1][c]=1;
                area++;
                q.push({r+1, c});
            }
            if (isvalid(r, c-1) && !vis[r][c-1]) {
                vis[r][c-1]=1;
                area++;
                q.push({r, c-1});
            }
        }
        return false;
    }
};