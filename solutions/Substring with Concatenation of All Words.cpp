class Solution {
public:
	void initMymap(map<string, int>& mymap, vector<string> &L){
		mymap.clear();
		for(int i = 0; i < L.size(); i++) {
			if(mymap.count(L[i]) > 0)
				mymap[L[i]]++;
			else
				mymap[L[i]] = 1;
		}
	}
	void resetMymap(map<string, int>& mymap, map<string, int>& mymap_back, int& count, vector<string> &L){
		mymap.clear();
		mymap = mymap_back;
		count = L.size();
	}
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
		int len = L[0].length();
        if(S.length() == 0 || L.size() == 0 || S.size() < len*L.size())
            return ret;
		
		map<string, int> mymap_back;
		initMymap(mymap_back, L);
		int count = 0;
		map<string, int> mymap;
		
		for(int k = 0; k < len; k++){
			int S_len = (S.length()-k)/len;
			int L_len = L.size();
			resetMymap(mymap, mymap_back, count, L);
			for(int i = 0; i <= S_len-L_len; ){
				for(int j = i; j <= S_len - count; j++){
					string sub_str = S.substr(j*len+k, len);
					if(mymap.find(sub_str) == mymap.end()){
						i = j + 1;
						resetMymap(mymap, mymap_back, count, L);
						break;
					}
					else if(mymap[sub_str] < 1){
						i++;
						resetMymap(mymap, mymap_back, count, L);
						break; 
					}
					else{
						mymap[sub_str]--;
						count--;
						if(count == 0){
							ret.push_back(i*len+k);
							mymap[S.substr(i*len+k, len)]++;
							count++;
							i++;
						}
					}
				}
			}
		}
		return ret;
	}
};