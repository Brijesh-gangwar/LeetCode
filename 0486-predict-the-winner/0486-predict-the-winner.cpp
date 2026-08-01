class Solution {
public:
    bool rec(vector<int>& nums , int score1 , int score2 , int i , int j, int count){
        // base case
        if(i > j){
            if(score1 >= score2) return true;
            else return false;
        }

        bool ith = false;
        bool jth = false;
        // count % 2 == 1 -> player1 take turns
        if(count %2 == 1){
            
            // taking ith element to add in score
            ith = rec(nums , score1 + nums[i] , score2, i+1 , j , count+1);
            // taking jth element to add in score
            jth = rec(nums , score1 + nums[j] , score2, i , j-1 , count+1);

            return ith || jth;

        }
        // count % 2 == 0 -> player2 take turns
        else{
            // taking ith element to add in score
            ith = rec(nums , score1 , score2 + + nums[i], i+1 , j, count+1);
            // taking jth element to add in score
            jth = rec(nums , score1 , score2 + nums[j] , i , j-1 , count+1);

            return ith && jth;
        }

    }

    bool predictTheWinner(vector<int>& nums) {
        
        if(nums.size() == 1) return true;

        return rec(nums, 0 , 0 , 0 , nums.size()-1 , 1);
    }
};