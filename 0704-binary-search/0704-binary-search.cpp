class Solution {
public:
    int rec(vector<int>& nums , int& target , int low , int high){
        if(low > high) return -1;

        int mid = low + (high-low)/2;

        if(nums[mid] == target)
            return mid;
        else if(nums[mid] > target)
            return rec(nums, target, low , mid-1);
        else return rec(nums, target, mid +1 , high);

    }
    int search(vector<int>& nums, int target) {
        return rec(nums, target , 0 , nums.size()-1);
    }
};