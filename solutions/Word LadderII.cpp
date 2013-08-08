//version 4: from discuss
class Solution {
    vector<string> vdict;
    vector<vector<int> > adj;

    void build(unordered_set<string> &dict){
        int i, j;
        vdict.clear();
        unordered_map<string, int> ids;
        for(auto it=dict.begin(); it != dict.end(); it++){
            ids[*it] = vdict.size();
            vdict.push_back(*it);

        }
        adj.clear();
        adj.resize(vdict.size());
        for(int i = 0; i < vdict.size(); i++){
            string w = vdict[i];
            for(int j = 0; j < vdict[i].size(); j++){
                for(char c = 'a'; c <= 'z'; c++)
                    if(c != vdict[i][j]){
                        w[j] = c;
                        if(ids.count(w)){
                            adj[i].push_back(ids[w]);
                        }
                        w[j] = vdict[i][j];
                    }
            }
        }
    }

    void gen(int v1, int v2, vector<vector<int> >& prev, vector<int>& path, vector<vector<string> >&ans){
        path.push_back(v2);
        if(v2 == v1 and path.size() > 1){
            ans.push_back(vector<string>());
            for(auto rit = path.rbegin(); rit != path.rend(); rit++){
                ans.back().push_back(vdict[*rit]);
            }
        }else{
            int i;
            for(i = 0; i < prev[v2].size(); i++){
                gen(v1, prev[v2][i], prev, path, ans);
            }
        }
        path.pop_back();
    }
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        dict.insert(start);
        dict.insert(end);
        build(dict);
        queue<int> que;
        vector<vector<int> > prev(vdict.size());
        vector<int> distance(vdict.size());

        int v, v1, v2;
        for(v1 = 0; vdict[v1] != start; v1++);
        for(v2 = 0; vdict[v2] != end; v2++);
        for(int i = 0; i < adj[v1].size(); i++){
            v = adj[v1][i];
            que.push(v);
            prev[v].push_back(v1);
            distance[v] = 1;
        }
        while(not que.empty()){
            int v1 = que.front(); que.pop();
            if(v1 == v2) break;
            int d = distance[v1] + 1;
            for(int i = 0; i < adj[v1].size(); i++){
                v = adj[v1][i];
                if(prev[v].size() == 0){
                    prev[v].clear();
                    prev[v].push_back(v1);
                    distance[v] = d;
                    que.push(v);
                }else if(distance[v] == d){
                    prev[v].push_back(v1);
                }
            }
        }

        vector<vector<string> > ans;

        vector<int> path;
        gen(v1, v2, prev, path, ans);

        return ans;
    }
};

//version 3: the differenece from version 1 is that do the DFS on the 
class Solution {
public:
	bool isConnected(string s1, string s2){
		int count = 0;
		for(int i = 0; i < s1.length(); i++){
			if(s1[i] != s2[i]){
				count++;
				if(count > 1) return false;
			}
		}
		return count == 1;
	}
	
	int ladderLength(string start, string end, unordered_set<string> &dict, vector<unordered_set<string>> &level_unor_sets) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int ret = 0;
		if(start == end) return ret;
		
		queue<string> que;
		unordered_set<string> que_set1;
		unordered_set<string> que_set2;
		unordered_set<string> visited_set;
		que.push(start);
		que_set1.insert(start);
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
					{
						//vector<string> tmp_que;
						//tmp_que.push_back(t);
						//level_unor_sets.push_back(tmp_que);
						level_unor_sets.push_back(que_set1);
						que_set2.clear();
						que_set2.insert(t);
						level_unor_sets.push_back(que_set2);
						return ret+2;
					}
					else if(dict.find(t) != dict.end()
					&& visited_set.find(t) == visited_set.end()){
						que.push(t);
						visited_set.insert(t);
						que_set2.insert(t);
						lev2_count++;
					}
				}
			}
			
			if(lev1_count == 0){
				ret++;
				lev1_count = lev2_count;
				level_unor_sets.push_back(que_set1);
				que_set1 = que_set2;
				que_set2.clear();
				lev2_count = 0;
			}
		}
		return 0;
    }
	
	void DFS(string start, vector<unordered_set<string>> &level_ques, int len_i, vector<string> &ret, vector<vector<string>> &rets){
		if(level_ques.size() == len_i){
			rets.push_back(ret);
			return;
		}
		for(int i = 0; i < start.length(); i++){
			for(char c = 'a'; c <= 'z'; c++){
				if(start[i] != c){
					string t = start;
					t[i] = c;
					if(level_ques[len_i].find(t) != level_ques[len_i].end() && len_i < level_ques.size()){
						ret.push_back(t);
						DFS(t, level_ques, len_i+1, ret, rets);
						ret.pop_back();
					}
				}
			}
		}
	}
	
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<vector<string>> rets;
		vector<string> ret;
		
		vector<unordered_set<string>> level_ques;
		int len = ladderLength(start, end, dict, level_ques);
		if(len == 0)
			return rets;
		unordered_set<string> visited_set;
		visited_set.insert(start);
		ret.push_back(start);
		
		int len_i = 1;
		for(int i = 0; i < start.length(); i++){
			for(char c = 'a'; c <= 'z'; c++){
				if(c != start[i]){
					string t = start;
					t[i] = c;
					if(level_ques[len_i].find(t) != level_ques[len_i].end() && len_i < level_ques.size()){
						ret.push_back(t);
						DFS(t, level_ques, len_i+1, ret, rets);
						ret.pop_back();
					}
				}
			}
		}
        return rets;
    }
};

//version 2: the differenece from version 1 is that do the DFS on the 
class Solution {
public:
	bool isConnected(string s1, string s2){
		int count = 0;
		for(int i = 0; i < s1.length(); i++){
			if(s1[i] != s2[i]){
				count++;
				if(count > 1) return false;
			}
		}
		return count == 1;
	}
	
	int ladderLength(string start, string end, unordered_set<string> &dict, vector<vector<string>> &level_ques) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int ret = 0;
		if(start == end) return ret;
		
		vector<string> que;
		unordered_set<string> visited_set;
		que.push_back(start);
		visited_set.insert(start);
		int lev1_count = 1;
		int lev2_count = 0;
		level_ques.push_back(que);
		
		while(!que.empty()){
			string s = que.front();
			que.erase(que.begin());
			lev1_count--;
			
			for(int i = 0; i < s.length(); i++){
				for(int j = 0; j < 26; j++){
					string t = s;
					t[i] = 'a'+j;
					if(t == end)
					{
						vector<string> tmp_que;
						tmp_que.push_back(t);
						level_ques.push_back(tmp_que);
						return ret+2;
					}
					else if(dict.find(t) != dict.end()
					&& visited_set.find(t) == visited_set.end()){
						que.push_back(t);
						visited_set.insert(t);
						lev2_count++;
					}
				}
			}
			
			if(lev1_count == 0){
				ret++;
				lev1_count = lev2_count;
				lev2_count = 0;
				level_ques.push_back(que);
			}
		}
		return 0;
    }
	
	void DFS(vector<vector<string>> &level_ques, int len_i, int idx, vector<string> &ret, vector<vector<string>> &rets){
		ret.push_back(level_ques[len_i][idx]);
		if(ret.size() == level_ques.size()){
			rets.push_back(ret);
			return;
		}
		for(int i = 0; i < level_ques[len_i+1].size(); i++){
			if(isConnected(level_ques[len_i][idx], level_ques[len_i+1][i])){
				DFS(level_ques, len_i+1, i, ret, rets);
				ret.pop_back();
			}
		}
	}
	
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<vector<string>> rets;
		vector<string> ret;
		
		vector<vector<string>> level_ques;
		int len = ladderLength(start, end, dict, level_ques);
		if(len == 0)
			return rets;
		unordered_set<string> visited_set;
		visited_set.insert(start);
		ret.push_back(start);
		
		int len_i = 1;
		for(int i = 0; i < level_ques[len_i].size(); i++){
			DFS(level_ques, len_i, i, ret, rets);
			ret.pop_back();
		}
        return rets;
    }
};

//version 1: find the length of the shortest path using BFS, and do DFS to find paths
class Solution {
public:
	void DFS(string start, string end, unordered_set<string> &dict, unordered_set<string> &visited_set, vector<string> &ret, vector<vector<string>> &rets, int len){
		ret.push_back(start);
		if(ret.size() > len)
			return;
		if(start == end){
			rets.push_back(ret);
			return;
		}
		
		for(int i = 0; i < start.length(); i++){
			for(int j = 0; j < 26; j++){
				string t = start;
				t[i] = 'a'+j;
				if(dict.find(t) != dict.end() && visited_set.find(t) == visited_set.end()){
					DFS(t, end, dict, visited_set, ret, rets, len);
					visited_set.erase(t);
					ret.pop_back();
				}
			}
		}
	}
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
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<vector<string>> rets;
		vector<string> ret;
		
		int len = ladderLength(start, end, dict);
		if(len == 0)
			return rets;
		unordered_set<string> visited_set;
		visited_set.insert(start);
		ret.push_back(start);
		
		for(int i = 0; i < start.length(); i++){
			for(int j = 0; j < 26; j++){
				string t = start;
				t[i] = 'a'+j;
				if(dict.find(t) != dict.end() && visited_set.find(t) == visited_set.end()){
					DFS(t, end, dict, visited_set, ret, rets, len);
					visited_set.erase(t);
					ret.pop_back();
				}
			}
		}
        return rets;
    }
};


