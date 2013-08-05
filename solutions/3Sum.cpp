class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<vector<int>> rets;
		if(num.size() == 0) return rets;
		sort(num.begin(), num.end());
		for(int i = 0; i < num.size(); i++){
			if(i > 0 && num[i] == num[i-1]) continue;
			for(int j = i+1; j < num.size(); j++){
				if(j > i+1 && num[j] == num[j-1])  continue;
				for(int k = j+1; k < num.size(); k++){
					if(k > j+1 && num[k] == num[k-1])  continue;
					if(num[i]+num[j]+num[k] == 0){
						vector<int> ret;
						ret.push_back(num[i]);
						ret.push_back(num[j]);
						ret.push_back(num[k]);
						rets.push_back(ret);
					}
				}
			}
		}
		return rets;
    }
};