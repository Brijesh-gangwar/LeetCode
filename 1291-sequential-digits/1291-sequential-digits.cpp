#include <bits/stdc++.h>
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        string s = to_string(low);

        int nl = s.size();

        // find first val >= low , in sequence
        int digit = s[0] - '0';
        string temp = "";

        while (temp.size() != s.size() && digit <= 9) {
            temp = temp + to_string(digit);

            if (temp.size() == nl && stoi(temp) < low)
                temp.erase(0, 1);

            digit++;
        }


        if (temp.size() != nl)
            temp = "";


        // insert value to ans
        while (!temp.empty() && stoi(temp) >= low && stoi(temp) <= high) {
            ans.push_back(stoi(temp));

            // remove first char
            temp.erase(0, 1);

            // insert new dig at last
            int dig = temp[temp.size() - 1] - '0';
            dig++;

            if (dig <= 9)
                temp = temp + to_string(dig);
            else
                break;
        }


        // Handle lengths greater than low's length
        int len = nl + 1;

        while (len <= to_string(high).size()) {

            // Generate first sequential number of this length
            string temp = "";
            int digit = 1;

            while (temp.size() < len && digit <= 9) {
                temp += to_string(digit);
                digit++;
            }

            // Slide the window
            while (temp.size() == len) {

                int num = stoi(temp);

                if (num > high)
                    break;

                if (num >= low)
                    ans.push_back(num);

                // Can't generate next sequential number
                if (temp.back() == '9')
                    break;

                temp.erase(0, 1);
                temp += char(temp.back() + 1);
            }

            len++;
        }

        return ans;
    }
};