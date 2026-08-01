class Solution {
public:
    // bool rec(vector<int>& nums , int netscore , int i , int j){
    //     // base case
    //     if(i > j){
    //         if(netscore >= 0) return true;
    //         else return false;
    //     }

    //     bool ith = false;
    //     bool jth = false;
    //     // count % 2 == 1 -> player1 take turns
    //     if ((nums.size() - (j - i + 1)) % 2 == 0){

    //         // taking ith element to add in score
    //         ith = rec(nums , netscore  + nums[i] , i+1 , j );
    //         // taking jth element to add in score
    //         jth = rec(nums , netscore  + nums[j] , i , j-1 );

    //         return ith || jth;
    //     }
    //     // count % 2 == 0 -> player2 take turns
    //     else{
    //         // taking ith element to add in score
    //         ith = rec(nums , netscore - nums[i], i+1 , j );
    //         // taking jth element to add in score
    //         jth = rec(nums , netscore -  nums[j] , i , j-1 );

    //         return ith && jth;
    //     }

    // }

    int rec(vector<int>& nums, int i, int j) {
        // base case
        if (i > j)
            return 0;

        int ith = nums[i] - rec(nums, i + 1, j);

        int jth = nums[j] - rec(nums, i, j - 1);

        return max(ith, jth);
    }

    // int recMem(vector<int>& nums, int i, int j, vector<vector<int>>&dp) {
    //     // base case
    //     if (i == j)
    //         return nums[i];

    //     // dp base case
    //     if(dp[i][j] != -1) return dp[i][j];

    //     int ith = nums[i] - recMem(nums, i + 1, j,dp);

    //     int jth = nums[j] - recMem(nums, i, j - 1,dp);

    //     dp[i][j] = max(ith, jth);

    //     return dp[i][j];
    // }

    // int tab(vector<int>& nums, vector<vector<int>>& dp) {
    //     // base case
    //     int n = nums.size();
    //     for (int i = 0; i < n; i++) {
    //         dp[i][i] = nums[i];
    //     }

    //     for (int i = n - 1; i >= 0; i--) {
    //         for(int j = i + 1 ; j < n;j++){

    //             int ith = nums[i] - dp[i + 1][j];

    //             int jth = nums[j] - dp[i][j-1];

    //             dp[i][j] = max(ith, jth);
    //         }
    //     }

    //     return dp[0][n-1];
    // }

    int tabspace(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n,0);

        for (int i = n - 1; i >= 0; i--) {
            vector<int> cur(n,0);

            // base case
            cur[i] = nums[i];

            int maxval =0;

            for(int j = i + 1 ; j < n;j++){

                int ith = nums[i] - next[j];

                int jth = nums[j] - cur[j-1];

                cur[j] = max(ith, jth);
            }

            next = cur;
        }

        return next[n-1];
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return true;

        // vector<vector<int>> dp(n, vector<int>(n, -1));

        // int dif = recMem(nums, 0, nums.size() - 1 ,dp);
        // int dif = recMem(nums, dp);
        // int dif = tab(nums, dp);
        int dif = tabspace(nums);

        if (dif >= 0)
            return true;
        return false;
    }
};