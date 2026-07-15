class Solution {
public:
    void fxn(vector<vector<int>> &ans,
             vector<int> nums,
             unordered_map<int, bool> &mp,
             int i,
             vector<int> temp) {

        // Base case
        if (i == nums.size()) {
            ans.push_back(temp);
            return;
        }

        // CHANGE: rename loop variable from i to x
        for (int x : nums) {

            if (!mp[x]) {

                mp[x] = true;
                temp.push_back(x);

                // CHANGE: increase recursion depth
                fxn(ans, nums, mp, i + 1, temp);

                temp.pop_back();
                mp[x] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> temp;

        unordered_map<int, bool> mp;

        for (int x : nums)
            mp[x] = false;

        fxn(ans, nums, mp, 0, temp);

        return ans;
    }
};