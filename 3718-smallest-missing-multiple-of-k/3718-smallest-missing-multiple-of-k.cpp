class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int , bool> mp;

        for(int i : nums)
            mp[i] = true;
        
        int i = 1;
        while(i){
            int n = k * i;
            if(!mp[n])
                return n;
            i++;
        }
        return -1;
    }
};