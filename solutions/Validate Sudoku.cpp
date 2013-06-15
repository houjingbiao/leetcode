class Solution {
public:
    void resetCounts()
    {
        for(int i = 0; i < 9; i++)
        {
            m_Counts[i] = 0;
        }
    }
    bool validateCounts()
    {
        for(int i = 0; i < 9; i++)
        {
            if(m_Counts[i] > 1)
                return false;
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //validate row
        for(int i = 0; i < 9; i++)
        {
            resetCounts();
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] != '.')
                {
                    m_Counts[board[i][j] - '1']++;
                }
            }
            if(!validateCounts())
                return false;
        }
        
        //validate col
        for(int i = 0; i < 9; i++)
        {
            resetCounts();
            for(int j = 0; j < 9; j++)
            {
                if(board[j][i] != '.')
                {
                    m_Counts[board[j][i] - '1']++;
                }
            }
            if(!validateCounts())
                return false;
        }
        
        //validate block
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                resetCounts();
                for(int m = 0; m < 3; m++)
                {
                    for(int n = 0; n < 3; n++)
                    {
                        if(m_Counts[board[i*3 + m][j*3 + n]] - '1')
                            m_Counts[board[i*3 + m][j*3 + n] - '1']++;
                    }
                }
                if(!validateCounts())
                    return false;
            }            
        }
        return true;
    }
private:
    int m_Counts[9];
};