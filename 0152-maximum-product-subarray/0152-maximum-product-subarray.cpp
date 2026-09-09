class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxprod = nums[0];
        int n = nums.size();

        int iprod = 1;
        int xprod = 1;

        for (int i = 0; i < n; i++) {
            int tempx = xprod;
            int tempi = iprod;

            xprod = max({nums[i], tempx * nums[i], tempi * nums[i]});

            iprod = min({nums[i], tempx * nums[i], tempi * nums[i]});

            maxprod = max(maxprod, xprod);
        }

        return maxprod;
    }
};