class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<vector<int>> rets;
		if(S.size() == 0) return rets;
		sort(S.begin(), S.end());
		vector<int> tmp;
		rets.push_back(tmp);
		vector<vector<int>> rets_tmp;
		for(int i=0; i<S.size(); i++){
			if(i == 0 || S[i] != S[i-1])
				rets_tmp = rets;
			vector<vector<int>>::iterator ite = rets_tmp.begin();
			for(; ite != rets_tmp.end(); ite++){
				ite->push_back(S[i]);
			}
			rets.insert(rets.end(), rets_tmp.begin(), rets_tmp.end());
		}
        return rets;
    }
};