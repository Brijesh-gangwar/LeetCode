class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maxval = INT_MIN;
        int minval = INT_MAX;

        int n = nums.size();

        // finding minarr 
        vector<int> minarr(n,-1);
        for(int i = n - 1; i >= 0; i--){
            minval = min(minval , nums[i]);

            minarr[i] = minval;
        }

        int index = 0;

        for(int i : nums){
            // max(nums[0..i])
            maxval = max(maxval , i);
            // min(nums[i..n - 1])
            minval = minarr[index];

            if((maxval - minval) <= k) return index;
            index++;
        }
        return -1;
    }
};