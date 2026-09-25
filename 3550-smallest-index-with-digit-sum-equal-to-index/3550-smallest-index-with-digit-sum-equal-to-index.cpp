class Solution {
public:
    int digsum(int n){
        int sum = 0;
        while(n){
            sum += n%10;
            n /=10;
        }
        return sum;
    }

    int smallestIndex(vector<int>& nums) {
        
        for(int i = 0; i< nums.size();i++){
            if(nums[i] < 10 && nums[i] == i){
                return i;
            }else if(nums[i] < 10 && nums[i] != i) continue;
            else {
                if(digsum(nums[i]) == i) return i;
            }
        }
        return -1;
    }
};