class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) return arr;

        unordered_map<int ,int> mp;
        vector<int> temp = arr;

        // sorting ans array
        sort(temp.begin(),temp.end());

        // assigning rank to elements
        int rank = 1;
        mp[temp[0]] = rank;

        for( int i = 1 ; i < n ; i++ ) {
            if( temp[i] != temp[i-1] ) rank++;

            mp[temp[i]] = rank;
        }

        // updating ranks in arr 
        for(int i=0;i<n;i++)
            arr[i] =  mp[arr[i]];

        return arr;
    }
};