class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX;
        int maxprofit = 0;

        for(int i : prices){
            // min price seen so far 
            minprice = min(minprice , i);

            // max profit calculation
            maxprofit = max(maxprofit , i - minprice);
        }

        return maxprofit;
    }
};