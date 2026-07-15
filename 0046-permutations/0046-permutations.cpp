class Solution {
public:
    void fxn(vector<vector<int>> &ans,
             vector<int> nums,
             unordered_map<int, bool> &mp,
             int i,
             vector<int> temp) {


if(i == nums.size()){
    ans.push_back(temp);
    return;
}

        for(int x : nums) {

            if(!mp[x]) {

                mp[x] = true;
                temp.push_back(x);



                fxn(ans, nums, mp, i + 1, temp);

                mp[x] = false;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> temp;

        unordered_map<int, bool> mp;

        for(int i : nums)
            mp[i] = false;

        fxn(ans, nums, mp, 0, temp);

        return ans;
    }
};