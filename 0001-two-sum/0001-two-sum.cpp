class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        unordered_map<int , int> mp;

        mp[nums[0]] = 1;

        for( int i = 1 ; i < n ; i++ ){
            int rem = target - nums[i];

            // rem exists
            if(mp[rem])
                return { mp[rem] - 1, i };
            
            // nums[i] insert
            else 
                mp[nums[i]] = i+1;
        }

        return {-1,-1};
    }
};