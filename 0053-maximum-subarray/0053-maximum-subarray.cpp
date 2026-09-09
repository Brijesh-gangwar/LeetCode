class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxsum = nums[0];

        for (int i : nums) {
            sum = max(i, sum + i);
            maxsum = max(maxsum, sum);
        }
        return maxsum;
    }
};