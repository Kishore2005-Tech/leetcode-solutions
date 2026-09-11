// intution phase-1 (scan matrix -> remember which row and column contains zeros) -> phase-2 (scan matrix -> set those rows/columns to 0)

class Solution {
private:
    void findZeros(int i, int j, int rows, int cols, vector<vector<int>>& matrix, vector<bool>& zeroRow, vector<bool>& zeroCol) {

        if (i >= rows)
            return;

        if (j >= cols) {
            findZeros(i + 1, 0, rows, cols,
                      matrix, zeroRow, zeroCol);
            return;
        }

        if (matrix[i][j] == 0) {
            zeroRow[i] = true;
            zeroCol[j] = true;
        }

        findZeros(i, j + 1, rows, cols,
                  matrix, zeroRow, zeroCol);
    }

    void setZeros(int i, int j, int rows, int cols, vector<vector<int>>& matrix, vector<bool>& zeroRow, vector<bool>& zeroCol) {

        if (i >= rows)
            return;

        if (j >= cols) {
            setZeros(i + 1, 0, rows, cols,
                     matrix, zeroRow, zeroCol);
            return;
        }

        if (zeroRow[i] || zeroCol[j])
            matrix[i][j] = 0;

        setZeros(i, j + 1, rows, cols,
                 matrix, zeroRow, zeroCol);
    }

public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<bool> zeroRow(rows, false);
        vector<bool> zeroCol(cols, false);

        findZeros(0, 0, rows, cols, matrix, zeroRow, zeroCol);

        setZeros(0, 0, rows, cols,
                 matrix, zeroRow, zeroCol);
    }
};
