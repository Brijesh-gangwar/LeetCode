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
    int recMem(vector<int>& nums, int i, int j, vector<vector<int>>&dp) {
        // base case
        if (i > j)
            return 0;

        // dp base case
        if(dp[i][j] != -1) return dp[i][j];

        int ith = nums[i] - recMem(nums, i + 1, j,dp);

        int jth = nums[j] - recMem(nums, i, j - 1,dp);

        dp[i][j] = max(ith, jth);

        return dp[i][j];
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return true;

    vector<vector<int>> dp(n, vector<int>(n, -1));

        int dif = recMem(nums, 0, nums.size() - 1 ,dp);

        if (dif >= 0)
            return true;
        return false;
    }
};