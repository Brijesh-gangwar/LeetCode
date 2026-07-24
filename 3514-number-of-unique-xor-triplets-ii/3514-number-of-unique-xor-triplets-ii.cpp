class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<bool> one(MAXX, false);
        vector<bool> two(MAXX, false);
        vector<bool> three(MAXX, false);

        // XOR using one element
        for (int x : nums)
            one[x] = true;

        // XOR using two elements (repetition allowed)
        for (int x = 0; x < MAXX; x++) {
            if (!one[x]) continue;
            for (int y : nums) {
                two[x ^ y] = true;
            }
        }

        // XOR using three elements (repetition allowed)
        for (int x = 0; x < MAXX; x++) {
            if (!two[x]) continue;
            for (int y : nums) {
                three[x ^ y] = true;
            }
        }

        int ans = 0;
        for (bool x : three)
            ans += x;

        return ans;
    }
};