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

            if(freq[i] <= 2){
                ans = max(ans  , high - low + 1 );
                
            }
            else{

                while(freq[i] > 2){
                    int l = s[low]-'a';
                    freq[l]--;
                    low++;
                }
        
            }

            high++;
        }

        return ans;
    }
};