class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maxval = INT_MIN;
        int minval = INT_MAX;

        int n = nums.size();

        // finding minarr -> minarr[i] = min(nums[i..n - 1])
        vector<int> minarr(n);
        for (int i = n - 1; i >= 0; i--) {
            minval = min(minval, nums[i]);

            minarr[i] = minval;
        }

        int index = 0;

        for (int i = 0; i < n; i++) {
            // max(nums[0..i])
            maxval = max(maxval, nums[i]);
             
            if (maxval - minarr[i] <= k)
                return i;
        }
        return -1;
    }
};