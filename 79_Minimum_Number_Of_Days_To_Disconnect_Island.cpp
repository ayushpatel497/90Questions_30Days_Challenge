class Solution {
public:
    int dir[5] = {0,1,0,-1,0};
    int m, n;
    int t = 0;
    bool has_ap = false;
    int dis[900], low[900];

    int minDays(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        memset(dis, 0, sizeof(dis));
        memset(low, 0, sizeof(low));
        int c = 0, area = 0;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                int u = i*n+j;
                if (grid[i][j]){
                    area++;
                    if (!dis[u]){
                        dfs(grid, u, -1);
                        c++;
                    }
                }
            }
        }
        if (c>1)
            return 0;
        else if (has_ap)
            return 1; 
        else
            return min(area, 2);
    }

    void dfs(vector<vector<int>>& grid, int u, int p){
        low[u] = dis[u] = ++t;
        int r = u/n, c = u%n;
        bool is_ap = false;
        int children = 0;
        for (int di = 0; di < 4; ++di) {
            int nr = r+dir[di], nc = c+dir[di+1];
            if (nr < 0 || nr >= m || nc < 0 || nc >= n || !grid[nr][nc]) 
                continue;
            int v = nr*n+nc;
            if (v==p) 
                continue;
            if (dis[v]) 
            low[u] = min(low[u], dis[v]);
            else {
                dfs(grid, v, u);
                children++;
                low[u] = min(low[u], low[v]);
                if (low[v] >= dis[u] && p != -1) 
                    is_ap = true;
            }
        }
        is_ap |= (p==-1)&&(children>1);
        has_ap |= is_ap;
    }
};