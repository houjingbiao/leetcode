class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0) return 0;
		
		vector<vector<int>> roads(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
		if(obstacleGrid[0][0] == 0) roads[0][0]= 1;
		for(int i = 1; i < obstacleGrid.size(); i++){
			if(obstacleGrid[i][0] == 1) roads[i][0] = 0;
			else roads[i][0] = roads[i-1][0];
		}
		for(int j = 1; j < obstacleGrid[0].size(); j++){
			if(obstacleGrid[0][j] == 1) roads[0][j] = 0;
			else roads[0][j] = roads[0][j-1];
		}
		
		for(int i = 1; i < obstacleGrid.size(); i++){
			for(int j = 1; j < obstacleGrid[0].size(); j++){
				if(obstacleGrid[i][j] == 1) roads[i][j] = 0;
				else roads[i][j] = roads[i-1][j] + roads[i][j-1];
			}
		}
		return roads[roads.size()-1][roads[0].size()-1];
    }
};