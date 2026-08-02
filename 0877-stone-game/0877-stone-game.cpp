class Solution {
public:
    int solveMem(vector<int> &piles,int i,vector<int> &dp)
    {
        if(i >= piles.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int op1 = piles[i] + solveMem(piles,i+2,dp);

        int op2 = 0 + solveMem(piles,i+1,dp);

        int ans = max(op1,op2);

        dp[i] = ans;

        return dp[i];
    }
    int solveRec(vector<int> &piles,int i)
    {
        if(i >= piles.size()) return 0;

        int op1 = piles[i] + solveRec(piles,i+2);

        int op2 = 0 + solveRec(piles,i+1);

        int ans = max(op1,op2);

        return ans;
    }
    bool stoneGame(vector<int>& piles) {
        sort(piles.begin(),piles.end());

        int sum = 0;

        vector<int> dp(piles.size()+1,-1);

        for(auto i : piles) sum += i;

        int i = 0;
        int op1 = solveMem(piles,i,dp);

        cout<<op1;

        int op2 = sum - op1;

        return op1 > op2;
    }
};

// class Solution {
// public:
//     // int rec(vector<int>& piles , int i , int j , vector<vector<int>>& dp){
//     //     if(i == j) return piles[i];

//     //     if(dp[i][j] != -1) return dp[i][j];

//     //     int ith = piles[i] - rec(piles , i + 1 , j ,dp);
//     //     int jth = piles[j] - rec(piles , i , j - 1 ,dp);

//     //     dp[i][j] = max(ith , jth);

//     //     return dp[i][j];
//     // }

//     // int tab(vector<int>& piles, int i, int j) {
//     //     int n = piles.size();

//     //     vector<vector<int>> dp(n, vector<int>(n, 0));

//     //   for (int i = 0; i < n; i++)
//     //         dp[i][i] = piles[i];

//     //     for (int i = n - 1; i >= 0; i--) {
//     //         for (int j = i + 1; j < n; j++) {
//     //             int ith = piles[i] - dp[i + 1][j];
//     //             int jth = piles[j] - dp[i][j - 1];

//     //             dp[i][j] = max(ith, jth);
//     //         }
//     //     }

//     //     return dp[0][n - 1];
//     // }

//         int tabspace(vector<int>& piles) {
//         int n = piles.size();

//     vector<int> next(n,0);


//         for (int i = n - 1; i >= 0; i--) {

//             vector<int> cur(n,0);

//             cur[i] = piles[i];

//             for (int j = i + 1; j < n; j++) {

//                 int ith = piles[i] - next[j];
//                 int jth = piles[j] - cur[j - 1];

//                 cur[j] = max(ith, jth);

//             }

//             next = cur;
//         }

//         return next[n-1];
//     }


//     bool stoneGame(vector<int>& piles) {
//         int n = piles.size();

//         // vector<vector<int>> dp(n ,vector<int>(n,-1));

//         // int dif = rec(piles , 0 , n-1 , dp);
//         int dif = tabspace(piles);

//         if (dif > 0)
//             return true;
//         return false;
//     }
// };