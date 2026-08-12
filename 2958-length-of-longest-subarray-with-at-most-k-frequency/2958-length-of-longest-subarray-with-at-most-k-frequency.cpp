class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;
        int ans = 0;
        int i = 0;

        int culprit = 0;

        for (int j = 0; j < n; j++) {
            int num = nums[j];

            mp[num]++;

            // if (mp[num] > k) {

            //     while (mp[num] > k) {
            //         mp[nums[i]]--;
            //         i++;
            //     }

            // } else {
            //     ans = max(ans, j - i + 1);
            // }

            if (mp[num] == k + 1) {
                culprit++;
            }

            if (culprit > 0) {
                if (mp[nums[i]] == k+1) {
                    culprit--;
                }

                mp[nums[i]]--;
                i++;
            }

            if (culprit == 0)
                ans = max(ans, j - i + 1);
        }
        return ans;
    }
};