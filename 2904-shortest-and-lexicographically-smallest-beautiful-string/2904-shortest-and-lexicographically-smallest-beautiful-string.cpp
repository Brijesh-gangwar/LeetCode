class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        // take i and j
        // variable length sliding window
        string ans = "";

        int n = s.size();
        int i = 0;
        int j = 0;

        string temp = "";
        int count = 0;
        while (j < n) {
            if (s[j] == '1')
                count++;

            if (count > k) {
                while (count != k) {
                    if (s[i] == '1')
                        count--;
                    i++;
                }
            }

            if (count == k) {
                  while (i < j && s[i] == '0')
                    i++;


                temp = s.substr(i, j - i + 1);
                if (ans == "" ||
                    temp.size() < ans.size() ||
                    (temp.size() == ans.size() && temp < ans)) {
                    ans = temp;
                }

            
            }
            j++;
        }

        return ans;
    }
};