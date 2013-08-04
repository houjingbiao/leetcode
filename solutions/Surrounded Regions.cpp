class Solution {
public:
	int dir[4][2];
	typedef struct coods{
		int x;
		int y;
	} co;
	queue<co> q;
	
	void bfs(vector<vector<char>> &board, vector<vector<bool>> &board_visited){
		while(!q.empty()){
			int u = q.front().x;
			int v = q.front().y;
			for(int dir_i = 0; dir_i < 4; dir_i++){
				int i = u + dir[dir_i][0];
				int j = v + dir[dir_i][1];
				if(i == 2 && j == 2)
					int	xxxx = 0;
				if(i >= 0 && i < board.size()
				&& j >= 0 && j < board[0].size()
				&& board[i][j] == 'O'
				&& board_visited[i][j] == false){
					co cc;
					cc.x = i;
					cc.y = j;
					q.push(cc);
					board[i][j] = 'A';
					board_visited[i][j] == true;
				}
			}
			q.pop();
		}
	}
	
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(board.size() <= 2 || board[0].size() <= 2) return;
        vector<vector<bool>> board_visited(board.size(), vector<bool>(board[0].size(), false));
		dir[0][0] = 0, dir[0][1] = -1;
		dir[1][0] = -1, dir[1][1] = 0;
		dir[2][0] = 0, dir[2][1] = 1;
		dir[3][0] = 1, dir[3][1] = 0;
		
		int j = 0;
		for(int i = 0; i < board.size(); i++){
			if(i >= 0 && i < board.size()
			&& j >= 0 && j < board[0].size()
			&& board[i][j] == 'O'
			&& board_visited[i][j] == false){
				co cc;
				cc.x = i;
				cc.y = j;
				q.push(cc);
				board[i][j] = 'A';
				board_visited[i][j] == true;
				bfs(board, board_visited);
			}
		}
		
		j = board[0].size() - 1;
		for(int i = 0; i < board.size(); i++){
			if(i >= 0 && i < board.size()
			&& j >= 0 && j < board[0].size()
			&& board[i][j] == 'O'
			&& board_visited[i][j] == false){
				co cc;
				cc.x = i;
				cc.y = j;
				q.push(cc);
				board[i][j] = 'A';
				board_visited[i][j] == true;
				bfs(board, board_visited);
			}
		}
			
		int i = 0;
		for(int j = 0; j < board[0].size(); j++){
			if(i >= 0 && i < board.size()
			&& j >= 0 && j < board[0].size()
			&& board[i][j] == 'O'
			&& board_visited[i][j] == false){
				co cc;
				cc.x = i;
				cc.y = j;
				q.push(cc);
				board[i][j] = 'A';
				board_visited[i][j] == true;
				bfs(board, board_visited);
			}
		}
		
		i = board.size()-1;
		for(int j = 0; j < board[0].size(); j++){
			if(i >= 0 && i < board.size()
			&& j >= 0 && j < board[0].size()
			&& board[i][j] == 'O'
			&& board_visited[i][j] == false){
				co cc;
				cc.x = i;
				cc.y = j;
				q.push(cc);
				board[i][j] = 'A';
				board_visited[i][j] == true;
				bfs(board, board_visited);
			}
		}
		
		for(int i = 0; i < board.size(); i++){
			for(int j = 0; j < board[0].size(); j++){
				if(board[i][j] == 'O')
					board[i][j] = 'X';
				else if(board[i][j] == 'A')
					board[i][j] = 'O';
			}
		}
    }
};