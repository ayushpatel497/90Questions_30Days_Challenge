class Solution {
    long long dist[26][26];
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        for (int i = 0; i != 26; ++i) {
            for (int j = 0; j != 26; ++j) {
                if (i == j) {
                    dist[i][j] = 0;
                } else {
                    dist[i][j] = INT_MAX;
                }
            }
        }
        for (int i = 0; i != original.size(); ++i) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        for (int k = 0; k != 26; ++k) {
            for (int i = 0; i != 26; ++i) {
                for (int j = 0; j != 26; ++j) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
                        dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        long long result = 0;
        for (int i = 0; i < source.size() && source.size() == target.size();
             ++i) {
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            if (dist[u][v] != INT_MAX) {
                result += dist[u][v];
            } else {
                return -1;
            }
        }
        return result;
    }
};