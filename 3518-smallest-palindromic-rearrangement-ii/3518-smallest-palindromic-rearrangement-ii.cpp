class Solution {
public:
    const long long LIMIT = 1000000LL + 1;

    long long countPermutations(vector<int>& freq) {

        int total = 0;
        for (int f : freq)
            total += f;

        long long ans = 1;
        int remaining = total;

        for (int f : freq) {

            if (f == 0)
                continue;

            long long comb = 1;

            for (int i = 1; i <= f; i++) {
                comb = comb * (remaining - f + i) / i;

                if (comb > LIMIT)
                    comb = LIMIT;
            }

            ans *= comb;

            if (ans > LIMIT)
                ans = LIMIT;

            remaining -= f;
        }

        return ans;
    }

    string smallestPalindrome(string s, int k) {

        string ans = "";

        vector<int> freq(26, 0);

        // Count frequency
        for (char ch : s)
            freq[ch - 'a']++;

        // Find middle character
        int mid = -1;
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2)
                mid = i;
        }

        // freq updating as needed n/2 
        for (int i = 0; i < 26; i++)
            freq[i] /= 2;

        // Half length
        int halfLen = s.size() / 2;

        // total palindromes < k
        if (countPermutations(freq) < k)
            return "";

        string half = "";

        for (int pos = 0; pos < halfLen; pos++) {

            for (int ch = 0; ch < 26; ch++) {

                if (freq[ch] == 0)
                    continue;

                freq[ch]--;

                long long cnt = countPermutations(freq);

                if (cnt >= k) {
                    half += char('a' + ch);
                    break;
                }

                k -= cnt;

                freq[ch]++;
            }
        }

        // First half
        ans += half;

        if (mid != -1)
            ans.push_back(char('a' + mid));

        reverse(half.begin(), half.end());
        ans += half;

        return ans;
    }
};