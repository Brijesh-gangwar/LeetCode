class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();

        int nChar = n / 8;

        int bIndex = n % 8;

        int ans = 0;
        int weight =  1;
        for( int i  = 1; i <= nChar ; i++){
            ans = ans + 8 * weight;
            weight++;
        }

        ans =  ans + bIndex * weight;

        return ans;
    }
};