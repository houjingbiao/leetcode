class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(matrix.size() == 0)
            return false;
        if(matrix[0].size() == 0)
            return false;
        if(target < matrix[0][0])
            return false;
        if(target > matrix[matrix.size() - 1][matrix[0].size()-1])
            return false;
        int ncols = matrix[0].size();
        int start = 0;
        int end = matrix.size()-1;
        while(start < end)
        {
            int mid = start/2 + end/2;
            if(target <= matrix[mid][ncols - 1])
                end = mid;
            else
                start = mid + 1;
        }
        int irow = end;
        start = 0; 
        end = ncols - 1;
        while(start < end)
        {
            int mid = start/2 + end/2;
            if(target <= matrix[irow][mid])
                end = mid;
            else
                start = mid+1;
        }
        if(matrix[irow][end] == target)
            return true;
        return false;
    }
};