class Solution {
public:
    bool isRowValid(char ch, int irow, int icol, vector<vector<char>> &board)
    {
        for(int i = 0; i < 9; i++)
        {
            if(ch == board[irow][i])
                return false;
        }
        return true;
    }
    bool isColValid(char ch, int irow, int icol, vector<vector<char>> &board)
    {
        for(int i = 0; i < 9; i++)
        {
            if(ch == board[i][icol])
                return false;
        }
        return true;
    }
    bool isBlockValid(char ch, int irow, int icol, vector<vector<char>> &board)
    {
        int block_irow = irow / 3;
        int block_icol = icol / 3;
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(board[block_irow*3+i][block_icol*3+j] == ch)
                    return false;
            }
        }
        return true;
    }
    bool dfs(int irow, int icol, vector<vector<char>> &backup, vector<vector<char>> &board)
    {
        bool isEnd = false;
        int next_irow = irow;
                int next_icol = (icol+1)%9;
                if(next_icol == 0)
                {
                    next_irow = (irow+1)%9;
                    if(next_irow == 0)
                        isEnd = true;
                }

        if(backup[irow][icol] != '.')
        {
            if(isEnd)
                 return true;
            return dfs(next_irow, next_icol, backup, board);
        }
        else
        {
            for(int i = 0; i < 9; i++)
            {
                char ch = '1'+i;
                if(isRowValid(ch, irow, icol, board) && isColValid(ch, irow, icol, board) &&isBlockValid(ch, irow, icol, board))
                {
                    board[irow][icol] = ch;
                    if(isEnd)
                        return true;
                    else if(dfs(next_irow, next_icol, backup, board))
                        return true;
                    else
                        board[irow][icol] = '.';
                }
            }
        }
    }
    void solveSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<char>> backup = board;
        dfs(0, 0, backup, board);
    }
};