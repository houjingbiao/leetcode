class Solution {
public:
	int dx[4];
	int dy[4];
	bool dfs(string word, int pos, vector<vector<char>> &board, int irow, int icol, vector<vector<bool>> &visited){
		visited[irow][icol] = true;
		if(pos == word.length())
			return true;
			
		for(int i = 0; i < 4; i++){
			int new_row = irow + dx[i];
			int new_col = icol + dy[i];
			if(new_row >= 0 && new_row < board.size() && new_col >= 0 && new_col < board[0].size() && !visited[new_row][new_col] && word[pos] == board[new_row][new_col]){
				if(dfs(word, pos+1, board, new_row, new_col, visited))
					return true;
				visited[new_row][new_col] = false;
			}
		}
		return false;
	}
    bool exist(vector<vector<char>> &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(board.size() == 0) return false;
		if(board[0].size() == 0) return false;
		if(word.length() > board.size() * board[0].size() == 1) return false;
		dx[0] = 0, dx[1] = -1, dx[2] = 0, dx[3] = 1;
		dy[0] = -1, dy[1] = 0, dy[2] = 1, dy[3] = 0;
		vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
		int pos = 0;
		for(int i = 0; i < board.size(); i++){
			for(int j = 0; j < board[0].size(); j++){
				if(word[pos] == board[i][j] && dfs(word, pos+1, board, i, j, visited))
					return true;
				visited[i][j] = false;
			}
		}
		return false;
    }
};