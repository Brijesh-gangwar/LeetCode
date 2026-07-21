class Solution {
public:
    int fxn(vector<int>& cost, int i , vector<int> &dp) {
        // base case
        if (i == 0 || i== 1)
            return cost[i];
        
        // check dp state exists or not
        if(dp[i]!= -1) return dp[i];

        // store state in dp and return state
        dp[i] =  cost[i] + min(fxn(cost, i - 1 , dp),fxn(cost, i - 2 , dp));
        return dp[i];
    }

    int minCostClimbingStairs(vector<int>& cost) {

           int a = cost[0];
        int b = cost[1];
        for(int i = 2; i < cost.size(); i++){
            int c = min(a,b) + cost[i];
            a = b;
            b = c;
        }
        return min(a,b);
        // int n = cost.size();

        // vector<int> dp(n+1,-1);
        
        // dp[0] = cost[0];
        // dp[1] = cost[1];

        // for(int i = 2 ; i < n;i++){
        //     dp[i] = cost[i] +  min( dp[i-1] , dp[i-2] );
            
        // }

        // return min(dp[n-1] , dp[n-2]);
    
        // return min(fxn(cost, n - 1 ,dp),
        //            fxn(cost, n - 2,dp));
    }
};