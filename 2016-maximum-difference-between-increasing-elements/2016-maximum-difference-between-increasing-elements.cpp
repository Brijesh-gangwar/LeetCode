class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minbefore = INT_MAX;

        int maxdif = -1;
        for(int i : nums){
            minbefore = min(minbefore , i);

            maxdif = max(maxdif , i- minbefore );
        }
        
        if(maxdif == 0) return -1;
        return maxdif;
    }
};