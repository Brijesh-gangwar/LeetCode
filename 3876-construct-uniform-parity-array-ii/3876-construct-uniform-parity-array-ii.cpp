class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minodd = INT_MAX;
        int mineven = INT_MAX;

        // finding min odd  , checking alleven
        for (int i : nums1) {
            if (i % 2 != 0)
                minodd = min(minodd, i);
            else
                mineven = min(mineven , i);
        }

        // all even or odd
        if (minodd == INT_MAX || mineven == INT_MAX)
            return true;

        // mixed case
        if(mineven < minodd) return false;

        return true;
    }
};