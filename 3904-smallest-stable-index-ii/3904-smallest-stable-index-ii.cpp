class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int minval = INT_MAX;

        vector<int> minarr(n);

        for(int i = n-1; i>= 0; i--){
            minval = min(minval , nums[i]);

            minarr[i] = minval;
        }

        int maxval = INT_MIN;
        for(int i = 0; i< n; i++){
            maxval = max(maxval , nums[i]);

            if((maxval - minarr[i]) <= k) return i;
        }

        return -1;
    }
};