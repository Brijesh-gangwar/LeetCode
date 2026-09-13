class Solution {
public:
    vector<int> shiftfxn(vector<int>& row, int shift, int& n) {
        vector<int> finalrow = row;

        for (int i = 0; i < n; i++) {
            int finalindex = (i - shift + n) % n;

            finalrow[finalindex] = row[i];
        }

        return finalrow;
    }

    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid,
                                    vector<int>& rowShift,
                                    vector<int>& colShift) {
        int index = 0;
        // row shift
        for (vector<int>& row : grid) {
            row = shiftfxn(row, rowShift[index], n);
            index++;
        }

        // col shift
        for (int colIndex = 0; colIndex < n; colIndex++) {

            vector<int> col;

            for (int rowIndex = 0; rowIndex < n; rowIndex++) {
                col.push_back(grid[rowIndex][colIndex]);
            }

            
            col = shiftfxn(col, colShift[colIndex], n);

            // writing in col 
            for (int rowIndex = 0; rowIndex < n; rowIndex++) {
                grid[rowIndex][colIndex] = col[rowIndex];
            }
        }

        return grid;
    }
};