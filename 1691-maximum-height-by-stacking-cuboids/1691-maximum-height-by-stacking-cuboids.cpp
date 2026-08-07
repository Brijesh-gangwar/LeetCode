class Solution {
public:
    bool check(vector<int>& base , vector<int>& newbox){
        if(newbox[0] <= base[0] && newbox[1] <= base[1] && newbox[2] <= base[2])
            return true;
        return false;
    }

    int lis(vector<vector<int>>& a){

        int n = a.size();

        vector<int> currow(n+1 ,0);
        vector<int> nextrow(n+1 ,0);

        for(int cur = n-1 ; cur >= 0 ; cur--){
            for(int prev = cur-1 ; prev >=-1 ; prev--){

                int take = 0;
                if(prev == -1 || check(a[cur] , a[prev]))
                    take = a[cur][2] + nextrow[cur + 1];

                int notake = nextrow[prev+1];

                currow[prev + 1] = max(take , notake);
            }
            nextrow = currow;
        }

        return nextrow[0];
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        // sorting each row 
        for (auto &it : cuboids)
            sort(it.begin(), it.end());

        // sorting whole matrix
        sort(cuboids.begin(), cuboids.end());

        return lis(cuboids);
    }
};