class Solution {
public:
    int minimumPushes(string word) {

        vector<int> freq(26,0);

        for(char ch : word){
            freq[ch - 'a']++;
        }

        sort(freq.begin(), freq.end() , greater<int>());

        int weight = 1;
        int count = 0;
        int ans = 0;

        for (int it : freq) {
            
            if(it == 0) break;

            if (count != 0 && count % 8 == 0)
                weight++;

            ans += it * weight;
            count++;
        }

        return ans;
    }
};