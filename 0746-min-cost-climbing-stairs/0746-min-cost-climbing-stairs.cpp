class Solution {
public:
    int fxn(vector<int>& cost, int i , vector<int> &dp) {
        if (i == 0 || i== 1)
            return cost[i];
        
        if(dp[i]!= -1) return dp[i];

        dp[i] =  cost[i] + min(fxn(cost, i - 1 , dp),fxn(cost, i - 2 , dp));
        return dp[i];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int> dp(n+1,-1);

        return min(fxn(cost, n - 1 ,dp),
                   fxn(cost, n - 2,dp));
    }
};