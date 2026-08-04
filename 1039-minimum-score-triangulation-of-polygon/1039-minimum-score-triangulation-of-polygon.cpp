class Solution {
public:
    // int recMem(vector<int>& v, int i, int j, vector<vector<int>>& dp) {
    //     if (j - i == 1)
    //         return 0;

    //     if (dp[i][j] != INT_MAX)
    //         return dp[i][j];

    //     for (int k = i + 1; k < j; k++) {
    //         dp[i][j] = min(dp[i][j], v[i] * v[k] * v[j] + recMem(v, i, k, dp)
    //         +
    //                                      recMem(v, k, j, dp));
    //     }

    //     return dp[i][j];
    // }

    int tab(vector<int>& v) {

    int n = v.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = n - 1; i >= 0; i--) {

        for (int j = i + 2; j < n; j++) {

            dp[i][j] = INT_MAX;

            for (int k = i + 1; k < j; k++) {

                dp[i][j] = min(dp[i][j],
                               v[i] * v[k] * v[j] +
                               dp[i][k] +
                               dp[k][j]);
            }
        }
    }

    return dp[0][n - 1];
}

    int minScoreTriangulation(vector<int>& values) {

        int n = values.size();
        if (n < 3)
            return 0;

        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        // return recMem(values, 0, n - 1, dp);
        return tab(values);
    }
};