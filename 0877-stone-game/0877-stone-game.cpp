class Solution {
public:
    int rec(vector<int>& piles , int i , int j , vector<vector<int>>& dp){
        if(i == j) return piles[i];

        if(dp[i][j] != -1) return dp[i][j];

        int ith = piles[i] - rec(piles , i + 1 , j ,dp);
        int jth = piles[j] - rec(piles , i , j - 1 ,dp);

        dp[i][j] = max(ith , jth);

        return dp[i][j];
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        vector<vector<int>> dp(n ,vector<int>(n,-1));

        int dif = rec(piles , 0 , n-1 , dp);

        if(dif > 0) return true;
        return false;
    }
};