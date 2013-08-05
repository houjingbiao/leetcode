class Solution {
public:
	int getMaxArea(vector<vector<char> > &matrix, int nrows, int ncols){
		int* lengths = new int[nrows*ncols];
		memset(lengths, 0, nrows*ncols*sizeof(int));
		int ret = 0;
		int area = 0;
		for(int i = 0; i < nrows; i++){//the first colomn
			if(matrix[i][0] == '1'){
				lengths[i*ncols] =  1;
				area++;
			}
			else{
				ret = max(ret, area);
				area = 0;
			}
		}
		ret = max(ret, area);
		area = 0;
		for(int j = 1; j < ncols; j++){//the first row
			if(matrix[0][j] == '1'){
				lengths[j] = lengths[j-1] + 1;
				area = lengths[j];
			}
			else{
				lengths[j] = 0;
				ret = max(ret, area);
				area = 0;
			}
		}
		ret = max(ret, area);

		for(int j = 1; j < ncols; j++){
			for(int i = 1; i < nrows; i++){
				if(matrix[i][j] == '1'){
					lengths[i*ncols+j] = lengths[i*ncols+j-1]+1;
					int ii = i;
					int minlen = lengths[i*ncols+j];
					while(ii>=0){
						if(matrix[ii][j] == '1'){
							minlen = min(minlen, lengths[ii*ncols+j]);
							area = minlen*(i-ii+1);
							ret = max(area, ret);
						}
						else break;
						ii--;
					}
				}
			}
		}
		delete[] lengths;
		return ret;
	}
	
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(matrix.size() == 0) return 0;
		if(matrix[0].size() == 0) return 0;
		int nrows = matrix.size();
		int ncols = matrix[0].size();
		return getMaxArea(matrix, nrows, ncols);
    }
};