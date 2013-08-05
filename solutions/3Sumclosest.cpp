class Solution {
public:
	int bsearch(vector<int> &num, int l, int h, int val){
		while(h - l > 1){
			int mid = (l+1)/2 + h/2;
			if(num[mid] >= val)
				h = mid;
			else
				l = mid;
		}
		if(abs(val - num[l]) <= abs(val - num[h])) return l;
		else return h;
	}
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(num.size() < 3) return -1;
		sort(num.begin(), num.end());
		int mindiff = 999999;
		for(int i = 0; i < num.size()-2; i++){
			for(int j = i + 1; j < num.size()-1; j++){
				if(j > i+1 && num[j] == num[j-1]) continue;
				int curr_target = target - num[i] - num[j];
				int k = bsearch(num, j+1, num.size()-1, curr_target);
				int new_diff = curr_target - num[k];
				if(new_diff == 0) return target;
				if(abs(mindiff) > abs(new_diff)) mindiff = new_diff;
			}
		}
        return target - mindiff;
    }
};