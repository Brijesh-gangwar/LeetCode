class Solution {
public:
    void generate_map(unordered_map<char, vector<char>> &mp) {
        mp['2'] = {'a', 'b', 'c'};
        mp['3'] = {'d', 'e', 'f'};
        mp['4'] = {'g', 'h', 'i'};
        mp['5'] = {'j', 'k', 'l'};
        mp['6'] = {'m', 'n', 'o'};
        mp['7'] = {'p', 'q', 'r', 's'};
        mp['8'] = {'t', 'u', 'v'};
        mp['9'] = {'w', 'x', 'y', 'z'};
    }

    void fxn(string &digits, vector<string> &ans,
             unordered_map<char, vector<char>> &mp, int i, string str) {
        if (i == digits.size()){
ans.push_back(str);
             return;
        }

        vector<char> arr = mp[digits[i]];

        for (char ch : arr) {
            fxn(digits, ans, mp, i + 1, str + ch);
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char, vector<char>> mp;

        vector<string> ans;

        int i = 0;
        string str = "";

        generate_map(mp);

        fxn(digits, ans, mp, i, str);

        return ans;
    }
};