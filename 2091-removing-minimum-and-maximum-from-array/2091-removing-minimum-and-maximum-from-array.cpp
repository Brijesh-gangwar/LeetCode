class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n == 1 || n == 2)
            return n;

        int maxval = INT_MIN;
        int maxindex = -1;

        int minval = INT_MAX;
        int minindex = -1;

        for (int i = 0; i < n; i++) {
            int val = nums[i];

            // max element
            if (val > maxval) {
                maxval = val;
                maxindex = i;
            }

            // min element
            if (val < minval) {
                minval = val;
                minindex = i;
            }
        }

        // i = smaller index btw minindex and maxindex
        // j = larger index btw minindex and maxindex
        int i, j;
        if (minindex < maxindex) {
            i = minindex;
            j = maxindex;
        } else {
            i = maxindex;
            j = minindex;
        }

        vector<int> arr;
        arr.push_back(i + 1);
        arr.push_back(j - i);
        arr.push_back(n - j);

        sort(arr.begin(), arr.end());

        // ans = sum of 2 smallest pi
        return arr[0] + arr[1];
    }
};