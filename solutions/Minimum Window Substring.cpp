class Solution {
public:
	bool isWindow(int S_sta[], int T_sta[]){
		for(int i = 0; i < 256; i++){
			if(S_sta[i] < T_sta[i]) return false;
		}
		return true;
	}
	
	void add(int A[], char c){
		A[c]++;
	}
	
	int get(int A[], char c){
		return A[c];
	}
	
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(S.length() < T.length()) return ""; 
		
		//1. statistic on T
		int T_sta[256];
		memset(T_sta, 0, 256*sizeof(int));
		for(int i = 0; i<T.length(); i++)
			add(T_sta, T[i]);
		
		//2. statistic on S
		int S_sta[256];
		int* S_count = new int[S.length()];
		memset(S_sta, 0, 256*sizeof(int));
		memset(S_count, 0, S.length()*sizeof(int));
		
		//2.1 for the first T.length() elements in S
		int i = 0;
		for(; i < T.length(); i++){
			add(S_sta, S[i]);
			S_count[i] = get(S_sta, S[i]);
		}
		if(isWindow(S_sta, T_sta))
			return S.substr(0, T.length());
			
		//2.2 To judge whether T is contained in S
		bool isContained = false;
		int minLen = S.length();
		int start = 0;
		for(; i < S.length(); i++){
			add(S_sta, S[i]);
			S_count[i] = get(S_sta, S[i]);
			if(isWindow(S_sta, T_sta)){
				isContained = true;
				minLen = i+1;
				start = 0;
				break;
			}
		}
		if(!isContained) return "";
		
		//2.3 To find the minimum sub string containing T in S
		int j = 0;
		while(1){
			while(get(S_sta, S[j])-S_count[j] >= get(T_sta, S[j]))
				j++;
			if(i-j+1 < minLen){
				minLen = i-j+1;
				start = j;
			}
			i++;
			if(i < S.length()){
				add(S_sta, S[i]);
				S_count[i] = get(S_sta, S[i]);
			}
			else break;
		}
        return S.substr(start, minLen);
    }
};