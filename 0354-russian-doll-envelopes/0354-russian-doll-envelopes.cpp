class Solution {
public:
   static bool comparator(vector<int>& a, vector<int>& b){
    if(a[0] == b[0])
        return a[1] > b[1];
    return a[0] < b[0];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // sorting envelopes 
        // first -> width - increasing order
        // second -> heigh - decreasing order
        sort(envelopes.begin(), envelopes.end(),comparator);

        // tails vector 
        vector<int> tails;

        int n = envelopes.size();

        for(int i = 0; i< n ; i++){

            int height = envelopes[i][1];
            // pushing height to tails
            if(tails.empty() || tails.back() < height){
                tails.push_back(height);
            }
            // replacing smallest value at index >= height
            else{
                int index = lower_bound(tails.begin() , tails.end(), height) - tails.begin();

                tails[index] = height;
            }
        }

        return tails.size();
    }
};