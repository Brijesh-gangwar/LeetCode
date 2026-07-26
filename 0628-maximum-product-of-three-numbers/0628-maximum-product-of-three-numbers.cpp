class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // int n = nums.size();

        int smallest1 =INT_MAX;
        int smallest2 = INT_MAX;
        int smallest3 = INT_MAX;

        int largest1 = INT_MIN;
        int largest2 = INT_MIN;
        int largest3 = INT_MIN;

        for(int i : nums){
            // largest 
            if(i > largest1){
                largest3 = largest2;
                largest2 = largest1;
                largest1 = i;
            }else if( i > largest2){
                largest3 = largest2;
                largest2 = i;
            }else if(i > largest3){
                largest3 = i;
            }

            // smallest 
               if(i < smallest1){
                smallest3 = smallest2;
                smallest2 = smallest1;
                smallest1 = i;
            }else if( i < smallest2){
                smallest3 = smallest2;
                smallest2 = i;
            }else if(i < smallest3){
                smallest3 = i;
            }
            
        }


        if(largest1 < 0) return largest1 * largest2 * largest3;

        if((smallest1 * smallest2) > (largest2 * largest3))
            return smallest1 * smallest2 * largest1;

        return largest1 * largest2 * largest3;
    }
};