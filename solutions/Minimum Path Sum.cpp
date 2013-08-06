class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(grid.size() == 0) return 0;
		if(grid[0].size() == 0) return 0;
		vector<vector<int> > steps(grid.size(), vector<int>(grid[0].size(), 0));
		steps[0][0] = grid[0][0];
		for(int i = 1; i < grid.size(); i++)
			steps[i][0] = steps[i-1][0] + grid[i][0];
			
		for(int i = 1; i < grid[0].size(); i++)
			steps[0][i] = steps[0][i-1] + grid[0][i];
		
		for(int i = 1; i < grid.size(); i++){
			for(int j = 1; j < grid[0].size(); j++){
				steps[i][j] = min(steps[i-1][j], steps[i][j-1]) + grid[i][j];
			}
		}
		
		return steps[grid.size()-1][grid[0].size()-1];
    }
};