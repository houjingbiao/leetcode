class Solution {
public:
	void dfs(int pos, bool* rows, bool* cols, bool* diag_l, bool* diag_r, int n, int irec, int &ret){
		rows[irec] = true;
		cols[pos] = true;
		diag_l[irec + pos] = true;
		diag_r[n - 1 - pos + irec] = true;
		if(irec == n-1){
			ret++;
			return;
		}
		
		for(int i = 0; i < n; i++){
			if(!rows[irec+1] && !cols[i] && !diag_l[irec+1 + i] && !diag_r[n - 1 - i + irec + 1]){
				dfs(i, rows, cols, diag_l, diag_r, n, irec+1, ret);
				rows[irec+1] = false;
				cols[i] = false;
				diag_l[irec + 1 + i] = false;
				diag_r[n - 1 - i + irec + 1] = false;
			}
		}
	}
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int ret = 0;
        bool* rows = new bool[n];
		bool* cols = new bool[n];
		bool* diag_l = new bool[2*n-1];
		bool* diag_r = new bool[2*n-1];
		memset(rows, 0, n*sizeof(bool));
		memset(cols, 0, n*sizeof(bool));
		memset(diag_l, 0, (2*n-1)*sizeof(bool));
		memset(diag_r, 0, (2*n-1)*sizeof(bool));
		for(int i = 0; i < n; i++){
			dfs(i, rows, cols, diag_l, diag_r, n, 0, ret);
			rows[0] = false;
			cols[i] = false;
			diag_l[0 + i] = false;
			diag_r[n - 1 - i + 0] = false;
		}
		return ret;
    }
};