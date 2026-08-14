class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans = 0;
        int n = s.size();

        int low = 0;
        int high = 0;

        int freq[26] = {};

        while (high < n) {
            int i = s[high] - 'a';

            freq[i]++;

            while (freq[i] > 2) {
                int l = s[low] - 'a';
                freq[l]--;
                low++;
            }

            ans = max(ans, high - low + 1);
            high++;
        }

        return ans;
    }
};