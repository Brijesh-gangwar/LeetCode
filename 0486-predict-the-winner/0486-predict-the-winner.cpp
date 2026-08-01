class Solution {
public:
    bool rec(vector<int>& nums , int netscore , int i , int j){
        // base case
        if(i > j){
            if(netscore >= 0) return true;
            else return false;
        }

        bool ith = false;
        bool jth = false;
        // count % 2 == 1 -> player1 take turns
        if ((nums.size() - (j - i + 1)) % 2 == 0){
            
            // taking ith element to add in score
            ith = rec(nums , netscore  + nums[i] , i+1 , j );
            // taking jth element to add in score
            jth = rec(nums , netscore  + nums[j] , i , j-1 );

            return ith || jth;

        }
        // count % 2 == 0 -> player2 take turns
        else{
            // taking ith element to add in score
            ith = rec(nums , netscore - nums[i], i+1 , j );
            // taking jth element to add in score
            jth = rec(nums , netscore -  nums[j] , i , j-1 );

            return ith && jth;
        }

    }

    bool predictTheWinner(vector<int>& nums) {
        
        if(nums.size() == 1) return true;

        return rec(nums, 0 , 0 , nums.size()-1 );
    }
};