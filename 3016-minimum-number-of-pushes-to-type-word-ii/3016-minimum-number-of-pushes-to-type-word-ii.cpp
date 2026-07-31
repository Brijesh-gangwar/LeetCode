class Solution {
public:

    static bool comparator(const pair<char, int>& a, const pair<char, int>& b) {
        return a.second > b.second;
    }

    int minimumPushes(string word) {

        unordered_map<char, int> mp;
        for (char ch : word)
            mp[ch]++;

        vector<pair<char, int>> freq;

        for (auto it : mp)
            freq.push_back(it);

        // sort(freq.begin(), freq.end(), comparator);
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