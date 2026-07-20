class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> arr;

        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0 ; i < m;i++)
            for(int j = 0; j < n;j++)
                arr.push_back(grid[i][j]);

        int N = arr.size();

        vector<int> temp(N);

         for (int i = 0; i < N; i++)
            temp[(i + k) % N] = arr[i];

        for (int i = 0; i < N; i++)
            grid[i / n][i % n] = temp[i];


        return grid;
        
    }
};