class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int> zeros;
        int ones = 0;

        int count = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0') count++;
            else {
                ones++;
                if(count > 0)
                zeros.push_back(count);

                count = 0;
            }
        }

                if(count > 0)
                zeros.push_back(count);


        int ans = 0;
        int x = zeros.size();
        
        for(int i = 0 ; i < x -1 ;i++)
             ans = max(zeros[i] + zeros[i+1] , ans);
            
        return ans+ones;
    

    }
};