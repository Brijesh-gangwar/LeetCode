class Solution {
public:
    int minimumPushes(string word) {

        vector<pair<char , int>> freq(26);

        for(char ch : word){
            freq[ch - 'a'].second++;
        }

        sort(freq.begin(), freq.end(), [](auto &a , auto &b){
            return a.second > b.second;
        });

        int weight = 1;
        int count = 0;
        int ans = 0;

        for (auto it : freq) {
            if (count != 0 && count % 8 == 0)
                weight++;

            ans += it.second * weight;
            count++;
        }

        return ans;
    }
};