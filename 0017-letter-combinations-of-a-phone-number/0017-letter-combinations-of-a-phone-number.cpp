class Solution {
public:

    vector<string> digitToLetters = {
            "",
            "",
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };



    void fxn(string &digits, vector<string> &ans,
        int i, string str) {
        if (i == digits.size()){
ans.push_back(str);
             return;
        }

        int dig = digits[i]-'0';
        string letters = digitToLetters[dig];

        for (char ch : letters) {
            fxn(digits, ans, i + 1, str + ch);
        }
    }

    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;

        int i = 0;
        string str = "";

        fxn(digits, ans, i, str);

        return ans;
    }
};