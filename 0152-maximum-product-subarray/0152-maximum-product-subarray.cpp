class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int maxprod = nums[0];
int n = nums.size();
        int iprod = nums[0];
        int xprod = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i]>= 0) {
                iprod = min(nums[i], iprod * nums[i]);
                xprod = max(nums[i], xprod * nums[i]);
            }
            // negative num 
            else {
                int temp = xprod;
                xprod = max(nums[i], iprod * nums[i]);
                iprod = min(nums[i], temp * nums[i]);
            }
            maxprod = max(maxprod , xprod);

        }

        return maxprod;
    }
};