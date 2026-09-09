class Solution {
public:
    int missingNumber(vector<int>& nums) {
    int sum = 0;
        int n = nums.size();  

        for (int i : nums) {
            sum += i;
        }

        int expectedSum = n * (n + 1) / 2;
        return expectedSum - sum;
    }  
};