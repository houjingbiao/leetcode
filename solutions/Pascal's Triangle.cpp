class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> rets;
        for(int i = 0; i < numRows; i++)
        {
            vector<int> ret;
            if(i == 0)
                ret.push_back(1);
            else
            {
                for(int j = 0; j < i+1; j++)
                {
                    if(j == 0 || j == i)
                        ret.push_back(1);
                    else
                        ret.push_back(rets[i-1][j-1] + rets[i-1][j]);
                }
            }
            rets.push_back(ret);
        }
        return rets;
    }
};