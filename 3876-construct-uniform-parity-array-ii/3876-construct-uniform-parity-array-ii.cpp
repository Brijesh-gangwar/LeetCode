class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minodd = INT_MAX;
        bool alleven = false;

        // finding min odd  , checking alleven
        for (int i : nums1) {
            if (i % 2 != 0)
                minodd = min(minodd, i);
            else
                alleven = true;
        }

        // all even
        if (minodd == INT_MAX)
            return true;

        // all odd
        if (alleven == false)
            return true;

        for (int i : nums1) {
            // odd -> entry in nums2
            if (i % 2 == 0) {
                // if nums1[i] - nums1[j] >= 1 -> fails
                if (i - minodd < 1)
                    return false;
            }
        }

        return true;
    }
};