//version 1: using binary code to generate the subsets
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> ret;
        vector<int> subset;

        ret.push_back(subset); //the null set
		if(S.size() == 0) return ret;
		
		sort(S.begin(), S.end());
		
		ret.push_back(S); //origin set
        
		int count = (1 << (S.size()))-1;
        for(int i = 1; i < count; i++)
        {
            subset.clear();
            int num = i;
            int digit_idx = 0;
            while(num > 0)
            {
                if(num%2)
                    subset.push_back(S[S.size() - 1 - digit_idx]);
                num = num >> 1;
                digit_idx++;
            }
            ret.push_back(subset);
        }
        return ret;
    }
};

//version2: this is a version that just use the index updating
class Solution {
public:
	void addToResult(vector<int> &S, vector<int>& subsetIdx,  vector<vector<int>> &ret){
		vector<int> subset;
		for(int i = 0; i < subsetIdx.size(); i++)
			subset.push_back(S[subsetIdx[i]]);
		ret.push_back(subset);
	}

	void generateCombination(vector<int>& S, int len, vector<vector<int>> &ret){
		vector<int> subsetIdx;
		for(int i = 0; i < len; i++) //initialize index in the S for each element in subset
			subsetIdx.push_back(i);
		generateCombination(S, subsetIdx, ret);
	}

	void generateCombination(vector<int>& S, vector<int>& subsetIdx, vector<vector<int>> &ret){//m is the total length, n is the number of 1 in this binary number
		addToResult(S, subsetIdx, ret);
		while(1){
			int len = subsetIdx.size();
			int m = len-1;
			for(; m >= 0; m--){//check and generate the next combination from end to begin
				if(subsetIdx[m]+len-m < S.size()){
					subsetIdx[m]++;
					for(int k = m+1; k < len; k++)
						subsetIdx[k] = subsetIdx[k-1]+1;
					addToResult(S, subsetIdx, ret);
					break;
				}
			}
			if(m < 0)  break;
		}
	}

	vector<vector<int>> subsets(vector<int> &S){
		vector<vector<int>> ret;
		vector<int> subset;
		ret.push_back(subset);
		if(S.size() == 0)
			return ret;
		sort(S.begin(), S.end());

		for(int len = 1; len < S.size(); len++)//different length
			generateCombination(S, len, ret);

		ret.push_back(S);
		return ret;
	}
};


//version3: dfs

//version4: