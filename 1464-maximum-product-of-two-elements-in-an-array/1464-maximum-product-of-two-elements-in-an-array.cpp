class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int largest = INT_MIN, secondLargest = INT_MIN;
        int smallest = INT_MAX, secondSmallest = INT_MAX;

        for (int x : nums) {
            // largest
            if (x > largest) {
                secondLargest = largest;
                largest = x;
            } else if (x > secondLargest) {
                secondLargest = x;
            }

            // smallest
            if (x < smallest) {
                secondSmallest = smallest;
                smallest = x;
            } else if (x < secondSmallest) {
                secondSmallest = x;
            }
        }

        return max((secondSmallest-1) * (smallest-1) , (largest-1) * (secondLargest -1 ));
    }
};