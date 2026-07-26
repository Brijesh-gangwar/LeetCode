class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(),nums.end());

        int s1 = nums[0];
        int s2 = nums[1];
        int s3 = nums[2];

        int l1 = nums[n-1];
        int l2 = nums[n-2];
        int l3 = nums[n-3];

        if(l1 < 0) return l1 * l2 * l3;

        if((s1 * s2) > (l2 * l3))
            return s1 * s2 * l1;


        
        return l1 * l2 * l3;
    }
};