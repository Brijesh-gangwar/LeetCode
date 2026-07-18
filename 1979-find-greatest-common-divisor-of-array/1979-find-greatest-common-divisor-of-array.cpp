class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxv = INT_MIN;
        int minv = INT_MAX;

        for(int i : nums){
            minv = min(i , minv);
            maxv = max(i , maxv);
        }

        for(int i = minv;i>1;i--){
            if( minv % i == 0 && maxv % i == 0)
                return i;
        }
        return 1;
    }
};