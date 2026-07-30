class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();

        int nChar = n / 8;

        int bIndex = n % 8;

        int ans = 0;
        int weight;
        for( weight = 1; weight <= nChar ; weight++){
            ans = ans + 8 * weight;
        }
        
        ans =  ans + bIndex * weight;

        return ans;
    }
};