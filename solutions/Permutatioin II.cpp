class Solution {
public:
	bool toNextPermutation(vector<int> &num){
		int pre = num.size()-2;
		while(pre >= 0 && num[pre] >= num[pre+1])
			pre--;
		
		if(pre >= 0){
			int post = num.size()-1;
			while(post > pre && num[post] <= num[pre])
				post--;
			if(post > pre){
				int tmp_post = num[post];
				num.erase(num.begin()+post);
				num.insert(num.begin()+pre, tmp_post);
				sort(num.begin()+pre+1, num.end());
				return true;
			}
		}
		return false;
	}
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<vector<int>> rets;
		if(num.size() == 0) return rets;
		if(num.size() == 1){
			rets.push_back(num);
			return rets;
		}
		
		sort(num.begin(), num.end());
		rets.push_back(num);
		
		while(toNextPermutation(num))
			rets.push_back(num);
		return rets;
    }
};