class Solution {
public:
	int bsearch(vector<int> &num, int l, int h, int val){
		while(h - l > 1){
			int mid =(l+1)/2 + h/2;
			if(num[mid] >= val) h = mid;
			else l = mid;
		}
		if(num[l] == val) return l;
		if(num[h] == val) return h;
		return -1;
	}
    vector<vector<int> > fourSum(vector<int> &num, int target) {
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
					if(k+1 < num.size()){
						int l = bsearch(num, k+1, num.size()-1, target - num[i] - num[j] - num[k]);
						if(l != -1){
							vector<int> ret;
							ret.push_back(num[i]);
							ret.push_back(num[j]);
							ret.push_back(num[k]);
							ret.push_back(num[l]);
							rets.push_back(ret);
						}
					}
				}
			}
		}
		return rets;
    }
};