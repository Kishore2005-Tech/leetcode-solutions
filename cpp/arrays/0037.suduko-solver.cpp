class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int16_t col[9],row[9],subbox[3][3];

        memset(col,0,sizeof(col));
        memset(row,0,sizeof(row));
        memset(subbox,0,sizeof(subbox));

        for(int i = 0;i < 9; ++i) {
            for(int j = 0;j < 9; ++j) {
                if(board[i][j] == '.') continue;
                const int& x = board[i][j] - '0';
                col[j] |= (1 << x);
                row[i] |= (1 << x);

                const int& n = i/3;
                const int& m = j/3;

                subbox[n][m] |= (1 << x);
            }
        }
        
        const auto& checkrow = [&](int r,int num)->bool {
            return (row[r] >> num)&1;    
        };  
        const auto& checkcol = [&](int c,int num)->bool {
            return (col[c] >> num)&1; 
        };
        const auto& checksubbox = [&](int r,int c,int num)->bool {
            return (subbox[r/3][c/3] >> num)&1;
        };

        const auto& rec = [&](const auto &self, int r,int c)->bool {
            if(r >= 9) return true;
            if(c >= 9) return self(self, r + 1, 0);

            if(board[r][c] == '.') {
                bool fl = false; 
                for(int i = 1;i < 10; ++i) {
                    if(checkrow(r,i) || checkcol(c,i) || checksubbox(r,c,i)) continue;

                    board[r][c] = i + '0';
                    row[r] |= (1 << i);
                    col[c] |= (1 << i);
                    subbox[r/3][c/3] |= (1 << i);

                    fl = self(self,r,c + 1);

                    if(fl) return true;


                    board[r][c] = '.';
                    row[r] ^= (1 << i);
                    col[c] ^= (1 << i);
                    subbox[r/3][c/3] ^= (1 << i);
                }
                return fl;
            }else {
                return self(self,r,c + 1);
            }
        };
        rec(rec,0,0);
    }
};
