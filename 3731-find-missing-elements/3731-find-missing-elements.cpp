class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;

        int start = *min_element(nums.begin(), nums.end());
        int end= *max_element(nums.begin(), nums.end());

        set<int>st(nums.begin(),nums.end());

        for(int i=start+1;i<=end-1;i++){
            if(st.count(i)==0)ans.push_back(i);
        }
        
        return ans;
    }
};