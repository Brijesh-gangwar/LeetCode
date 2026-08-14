class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans = 0;
        int n = s.size();

        int low = 0;
        int high = 0;

        unordered_map<char,int> mp;

        while (high < n) {
            char ch = s[high];

            mp[ch]++;

            if(mp[ch] <= 2){
                ans = max(ans  , high - low + 1 );
                
            }
            else{

                while(mp[ch] > 2){
                    char lowchar = s[low];
                    mp[lowchar]--;
                    low++;
                }
        
            }
            high++;
        }

        return ans;
    }
};