class Solution {
public:
	vector<int> spiralOrder(vector<vector<int> > &matrix) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<int> ret;
		int nrows = matrix.size();
		if(nrows == 0)
			return ret;
		int ncols = matrix[0].size();
		if(ncols == 0)
			return ret;

		int nrounds = nrows < ncols ? nrows:ncols;
		int iround = 0;
		while(iround < (nrounds+1)/2)
		{
			int i = iround;
			int j = iround;

			while(j <= ncols - 1 - iround)
			{
				ret.push_back(matrix[i][j]);
				j++;
			}
			j = ncols - 1 - iround;
			i++;
			if(i > nrows - 1 - iround)
				break;
			while(i <= nrows - 1 - iround)
			{
				ret.push_back(matrix[i][j]);
				i++;
			}
			i = nrows - 1 - iround;
			j--;
			if(j < iround)
				break;
			while(j >= iround)
			{
				ret.push_back(matrix[i][j]);
				j--;
			}
			j = iround;
			i--;
			if(i < iround+1)
				break;
			while(i >= iround+1)
			{
				ret.push_back(matrix[i][j]);
				i--;
			}
                           
			iround++;
		}
		return ret;
	}
};