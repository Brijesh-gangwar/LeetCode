class Solution {
public:
    int maximumDifference(vector<int>& nums) {
 
        int maxdif = -1;
        int minbefore = nums[0];

        for(int i = 1 ; i < nums.size(); i++){
            maxdif = max(maxdif , nums[i] - minbefore);

            minbefore = min(minbefore , nums[i]);
        }
        
        if(maxdif == 0) return -1;
        return maxdif;
    }
};