class Solution {
public:
    int rec(vector<int>& v, int i, int j, vector<vector<int>>& dp) {
        if (j - i == 1)
            return 0;

        if (dp[i][j] != INT_MAX)
            return dp[i][j];

        for (int k = i + 1; k < j; k++) {
            dp[i][j] = min(dp[i][j], v[i] * v[k] * v[j] + rec(v, i, k, dp) +
                                         rec(v, k, j, dp));
        }

        return dp[i][j];
    }
    int minScoreTriangulation(vector<int>& values) {

        int n = values.size();
        if (n < 3)
            return 0;

        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        return rec(values, 0, n - 1, dp);
    }
};