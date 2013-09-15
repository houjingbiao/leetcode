class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(s1 == s2) return true;
		if(s1.length() != s2.length()) return false;
		
		vector<vector<vector<bool>>> scrabled(s1.length(), vector<vector<bool>>(s1.length(), vector<bool>(s1.length()+1, false)));
		
		for(int i = 0; i < s1.length(); i++){
			for(int j = 0; j < s2.length(); j++){
				scrabled[i][j][0] = true;
				scrabled[i][j][1] = s1[i] == s2[j];
			}
		}
		
		for(int k = 2; k < s1.length()+1; k++){
			for(int i = 0; i+k <= s1.length(); i++){
				for(int j = 0; j+k <= s1.length(); j++){
					for(int l = 1; l < k; l++){
						scrabled[i][j][k] = (scrabled[i+l][j][k-l] && scrabled[i][j+k-l][l])
						|| (scrabled[i][j][l] && scrabled[i+l][j+l][k-l]);
						if(scrabled[i][j][k]) 
							break;
					}
				}
			}
		}
		return scrabled[0][0][s1.length()];
    }
};