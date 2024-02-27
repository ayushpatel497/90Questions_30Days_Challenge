class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
		int dp[n][n][2];
		fill(**dp, dp[n][0], 0);
		for (int i = 0; i < n; ++i) {
			dp[0][i][0] = dp[0][i][1] = dp[i][0][0] = dp[i][0][1] = 1;
			dp[i][i][0] = dp[i][i][1] = 2;
		}

		bool done = false;
		while (!done) {
			done = true;
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j) {
					if (!dp[i][j][0]) {
						bool chance = false;
						for (auto v: graph[i]) {
							if (dp[v][j][1] == 1) {
								dp[i][j][0] = 1;
								done = false;
							}
							chance |= !dp[v][j][1];
						}
						if (!dp[i][j][0] && !chance) {
							dp[i][j][0] = 2;
							done = false;
						}
					}
					if (!dp[i][j][1]) {
						bool chance = false;
						for (auto v: graph[j]) {
							if (dp[i][v][0] == 2) {
								dp[i][j][1] = 2;
								done = false;
							}
							chance |= !dp[i][v][0];
						}
						if (!dp[i][j][1] && !chance) {
							dp[i][j][1] = 1;
							done = false;
						}
					}
				}
		}
		return dp[1][2][0];
    }
};