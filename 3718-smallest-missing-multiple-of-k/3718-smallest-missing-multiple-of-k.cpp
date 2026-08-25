class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int> st;

        for(int i : nums)
            st.insert(i);
        
        int i = 1;
        while(i){
            int n = k * i;
            if(st.count(n) == 0)
                return n;
            i++;
        }
        return -1;
    }
};