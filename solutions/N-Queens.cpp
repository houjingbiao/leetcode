class Solution {
public:
	void dfs(int pos, bool* rows, bool* cols, bool* diag_l, bool* diag_r, int n, int irec, vector<string> &ret, vector<vector<string>> &rets){
		ret[irec][pos] = 'Q';
		rows[irec] = true;
		cols[pos] = true;
		diag_l[irec + pos] = true;
		diag_r[n - 1 - pos + irec] = true;
		if(irec == n-1){
			rets.push_back(ret);
			return;
		}
		
		for(int i = 0; i < n; i++){
			if(!rows[irec+1] && !cols[i] && !diag_l[irec+1 + i] && !diag_r[n - 1 - i + irec + 1]){
				dfs(i, rows, cols, diag_l, diag_r, n, irec+1, ret, rets);
				ret[irec+1][i] = '.';
				rows[irec+1] = false;
				cols[i] = false;
				diag_l[irec + 1 + i] = false;
				diag_r[n - 1 - i + irec + 1] = false;
			}
		}
	}
    vector<vector<string>> solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<vector<string>> rets;
        bool* rows = new bool[n];
		bool* cols = new bool[n];
		bool* diag_l = new bool[2*n-1];
		bool* diag_r = new bool[2*n-1];
		memset(rows, 0, n*sizeof(bool));
		memset(cols, 0, n*sizeof(bool));
		memset(diag_l, 0, (2*n-1)*sizeof(bool));
		memset(diag_r, 0, (2*n-1)*sizeof(bool));
		vector<string> ret(n, string(n, '.'));
		for(int i = 0; i < n; i++){
			dfs(i, rows, cols, diag_l, diag_r, n, 0, ret, rets);
			ret[0][i] = '.';
			rows[0] = false;
			cols[i] = false;
			diag_l[0 + i] = false;
			diag_r[n - 1 - i + 0] = false;
		}
		return rets;
    }
};