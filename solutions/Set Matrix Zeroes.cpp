class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(matrix.size() == 0) return;
		if(matrix[0].size() == 0) return;
		
		int row = -1, col = -1;
		for(int i = 0; i < matrix.size(); i++){
			for(int j = 0; j < matrix[0].size(); j++){
				if(matrix[i][j] == 0){
					row = i;
					col = j;
					break;
				}
			}
		}
		if(row == -1) return;
		
		for(int i = 0; i < matrix.size(); i++) {
			for(int j = 0; j < matrix[0].size(); j++) {
				if(matrix[i][j] == 0) {
					matrix[row][j] = 0;
					matrix[i][col] = 0;
				}
			}
		}
		
		for(int i = 0; i < matrix.size(); i++){
			if(matrix[i][col] == 0 && i != row){
				for(int j = 0; j < matrix[0].size(); j++)
					matrix[i][j] = 0;
			}
		}
		
		for(int j = 0; j < matrix[0].size(); j++){
			if(matrix[row][j] == 0 && j != col){
				for(int i = 0; i < matrix.size(); i++)
					matrix[i][j] = 0;
			}
		}
		
		for(int i = 0; i < matrix.size(); i++)
			matrix[i][col] = 0;
		
		for(int j = 0; j < matrix[0].size(); j++)
			matrix[row][j] = 0;
    }
};