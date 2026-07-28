class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> arr(26, 0);

        for (char ch : s) {
            int i = ch - 'a';
            arr[i] = arr[i] + 1;
        }

        string ans;
        ans.reserve(s.size());
        int odd = -1;

        // creating first half of ans
        for (int i = 0; i < 26; i++) {
            int freq = arr[i];

            if (freq % 2 != 0) {
                odd = i;
                arr[i] = arr[i] - 1;
            }
            int half = arr[i] / 2;

            while (half > 0) {
                ans.push_back('a' + i);
                half--;
            }
        }

        // adding odd freq item to middle of ans
        if (odd != -1)
            ans.push_back('a' + odd);

        // adding second half of string in reverse order to ensure it is
        // palindrome
        for (int i = 25; i >= 0; i--) {
            int half = arr[i] / 2;

            while (half > 0) {
                ans.push_back('a' + i);
                half--;
            }
        }

        return ans;
    }
};