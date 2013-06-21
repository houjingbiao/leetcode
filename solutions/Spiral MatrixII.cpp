class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0)
        {
            vector<vector<int>> ret;
            return ret;
        }
        
        vector<vector<int>> ret(n, vector<int>(n, 0));
        int n2 = n*n;
        int num = 1;
            int nrounds = (n+1)/2;
            int iround = 0;
            while(iround < nrounds)
            {
                int i = iround;
                int j = iround;
                while(j <= n - 1 - iround)
                {
                    ret[i][j] = num;
                    num++;
                    if(num > n2)
                        return ret;
                    j++;
                }
                j = n-1-iround;
                i++;
                if(i > n-1-iround)
                    break;
                while(i <= n-1-iround)
                {
                    ret[i][j] = num;
                    num++;
                    if(num > n2)
                        return ret;
                    i++;
                }
                i = n-1-iround;
                j--;
                if(j < iround)
                    break;
                while(j >= iround)
                {
                    ret[i][j] = num;
                    num++;
                    if(num > n2)
                        return ret;
                    j--;
                }
                j = iround;
                i--;
                if(i < iround+1)
                    break;
                while(i >= iround+1)
                {
                    ret[i][j] = num;
                    num++;
                    if(num > n2)
                        return ret;
                    i--;
                }
                iround++;
            }
            return ret;
        
    }
};