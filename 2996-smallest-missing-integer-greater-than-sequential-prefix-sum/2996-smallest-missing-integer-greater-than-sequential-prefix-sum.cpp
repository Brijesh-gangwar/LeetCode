class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];

        for (int j = 1; j < n; j++) {
            if (nums[j] != (nums[j - 1] + 1)) break;

            sum = sum + nums[j];
        }

        set<int> st;
        for (int i : nums)
            st.insert(i);

        int ans = sum;

        while(st.count(ans)!=0){
            ans++;
        }

        return ans;
    }
};