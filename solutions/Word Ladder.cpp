class Solution {
public:	
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int ret = 0;
		if(start == end) return ret;
		
		queue<string> que;
		unordered_set<string> visited_set;
		que.push(start);
		visited_set.insert(start);
		int lev1_count = 1;
		int lev2_count = 0;
		
		while(!que.empty()){
			string s = que.front();
			que.pop();
			lev1_count--;
			
			for(int i = 0; i < s.length(); i++){
				for(int j = 0; j < 26; j++){
					string t = s;
					t[i] = 'a'+j;
					if(t == end)
						return ret+2;
					else if(dict.find(t) != dict.end()
					&& visited_set.find(t) == visited_set.end()){
						que.push(t);
						visited_set.insert(t);
						lev2_count++;
					}
				}
			}
			
			if(lev1_count == 0){
				ret++;
				lev1_count = lev2_count;
				lev2_count = 0;;
			}
		}
		return 0;
    }
};