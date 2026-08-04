class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = *min_element(nums.begin(),nums.end());
        int maxi = *max_element(nums.begin(),nums.end());

        unordered_map<int,bool> mp;

        for(int i : nums)
            mp[i] = true;
        
        vector<int> ans;

        for(int i = mini + 1 ; i < maxi ; i++){
            if(!mp[i]) ans.push_back(i);
        }

        return ans;
    }
};