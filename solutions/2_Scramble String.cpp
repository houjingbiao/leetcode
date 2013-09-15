//version 7: dfs + cache(unordered_map) + priming: small case 12ms, large case 40ms
//version 6: dfs + cache(unordered_map): small case 12ms, large case 560ms
//version 5: dfs + priming + cache(map) : small case 12ms, large case 52ms
//version 4: dfs + cache(map): small case 16ms, large case 1576ms
//version 3: dfs + priming: small case 12ms, large case 32ms
//version 2: dfs, only pass small case 8ms
//version 1: 3-d dp  small case 16ms, large case 620ms


//version 7: dfs + cache(unordered_map) + priming: small case 12ms, large case 40ms
typedef string::const_iterator Iterator;
typedef tuple<Iterator, Iterator, Iterator> Key;
// 定制一个哈希函数
namespace std {
	template<> struct hash<Key> {
	size_t operator()(const Key & x) const {
			Iterator first1, last1, first2;
			std::tie(first1, last1, first2) = x;
			int result = *first1;
			result = result * 31 + *last1;
			result = result * 31 + *first2;
			result = result * 31 + *(next(first2, distance(first1, last1)-1));
			return result;
		}
	};
};
class Solution {
public:
	unordered_map<Key, bool> cache;
	bool isScramble(string s1, string s2) {
		cache.clear();
		return isScramble(s1.begin(), s1.end(), s2.begin());
	}
	bool isScramble(Iterator first1, Iterator last1, Iterator first2) {
		auto length = distance(first1, last1);
		auto last2 = next(first2, length);
		if (length == 1)
			return *first1 == *first2;
		
		int A[26];
		std::fill(A, A+26, 0);
		for(int i = 0; i < len; i++) A[*(b1+i) - 'a']++;
		for(int i = 0; i < len; i++) A[*(b2+i) - 'a']--;
		for(int i = 0; i < 26; i++) if (A[i] != 0) return false;
		
		for (int i = 1; i < length; ++i)
			if ((cachedIsScramble(first1, first1 + i, first2)
				and cachedIsScramble(first1 + i, last1, first2 + i))
				or (cachedIsScramble(first1, first1 + i, last2 - i)
				and cachedIsScramble(first1 + i, last1, first2)))
				return true;
		return false;
	}
	bool cachedIsScramble(Iterator first1, Iterator last1, Iterator first2) {
		auto key = make_tuple(first1, last1, first2);
		auto pos = cache.find(key);
		return (pos != cache.end()) ?
		pos->second : (cache[key] = isScramble(first1, last1, first2));
	}
};

//version 6: dfs + cache(unordered_map): small case 12ms, large case 560ms
typedef string::const_iterator Iterator;
typedef tuple<Iterator, Iterator, Iterator> Key;
// 定制一个哈希函数
namespace std {
	template<> struct hash<Key> {
	size_t operator()(const Key & x) const {
			Iterator first1, last1, first2;
			std::tie(first1, last1, first2) = x;
			int result = *first1;
			result = result * 31 + *last1;
			result = result * 31 + *first2;
			result = result * 31 + *(next(first2, distance(first1, last1)-1));
			return result;
		}
	};
};
class Solution {
public:
	unordered_map<Key, bool> cache;
	bool isScramble(string s1, string s2) {
		cache.clear();
		return isScramble(s1.begin(), s1.end(), s2.begin());
	}
	bool isScramble(Iterator first1, Iterator last1, Iterator first2) {
		auto length = distance(first1, last1);
		auto last2 = next(first2, length);
		if (length == 1)
			return *first1 == *first2;
	
		for (int i = 1; i < length; ++i)
			if ((cachedIsScramble(first1, first1 + i, first2)
				and cachedIsScramble(first1 + i, last1, first2 + i))
				or (cachedIsScramble(first1, first1 + i, last2 - i)
				and cachedIsScramble(first1 + i, last1, first2)))
				return true;
		return false;
	}
	bool cachedIsScramble(Iterator first1, Iterator last1, Iterator first2) {
		auto key = make_tuple(first1, last1, first2);
		auto pos = cache.find(key);
		return (pos != cache.end()) ?
		pos->second : (cache[key] = isScramble(first1, last1, first2));
	}
};

//version 5: dfs + priming + cache(map) : small case 12ms, large case 52ms
class Solution {
private:
    typedef string::iterator str_iterator;
	map<tuple<str_iterator, str_iterator, str_iterator>, bool> mycache;
	bool isScramble(string::iterator b1, string::iterator e1, string::iterator b2) {
		auto len = distance(b1, e1);
		if(len == 1)
			return *b1 == *b2;
		
		int A[26];
		std::fill(A, A+26, 0);
		for(int i = 0; i < len; i++) A[*(b1+i) - 'a']++;
		for(int i = 0; i < len; i++) A[*(b2+i) - 'a']--;
		for(int i = 0; i < 26; i++) if (A[i] != 0) return false;
		
		for(int i = 1; i < len; i++){
			if(isCachedScramble(b1, b1+i, b2) && isCachedScramble(b1+i, e1, b2+i)
				|| isCachedScramble(b1, b1+i, b2+len-i) && isCachedScramble(b1+i, e1, b2)){
				return true;
			}
		}
		return false;
	}
	bool isCachedScramble(string::iterator b1, string::iterator e1, string::iterator b2) {
		auto key = tuple<str_iterator, str_iterator, str_iterator>(b1, e1, b2);
		auto pos = mycache.find(key);
		return (pos != mycache.end()) ?
		pos->second : (mycache[key] = isScramble(b1, e1, b2));
	}
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		mycache.clear();
        return isScramble(s1.begin(), s1.end(), s2.begin());
    }
};

//version 4: dfs + cache(map): small case 16ms, large case 1576ms
class Solution {
private:
	typedef string::iterator str_iterator;
	map<tuple<str_iterator, str_iterator, str_iterator>, bool> mycache;
	bool isScramble(string::iterator b1, string::iterator e1, string::iterator b2) {
		auto len = distance(b1, e1);
		if(len == 1)
			return *b1 == *b2;
		
		for(int i = 1; i < len; i++){
			if(isCachedScramble(b1, b1+i, b2) && isCachedScramble(b1+i, e1, b2+i)
				|| isCachedScramble(b1, b1+i, b2+len-i) && isCachedScramble(b1+i, e1, b2)){
				return true;
			}
		}
		return false;
	}
	bool isCachedScramble(string::iterator b1, string::iterator e1, string::iterator b2) {
		auto key = tuple<str_iterator, str_iterator, str_iterator>(b1, e1, b2);
		auto pos = mycache.find(key);
		return (pos != mycache.end()) ?
		pos->second : (mycache[key] = isScramble(b1, e1, b2));
	}
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		mycache.clear();
        return isScramble(s1.begin(), s1.end(), s2.begin());
    }
};

//version 3: dfs + priming: small case 12ms, large case 32ms
class Solution {
private:
	bool isScramble(string::iterator b1, string::iterator e1, string::iterator b2) {
		auto len = distance(b1, e1);
		if(len == 1) return *b1 == *b2;
		
		int A[26];
		std::fill(A, A+26, 0);
		for(int i = 0; i < len; i++) A[*(b1+i) - 'a']++;
		for(int i = 0; i < len; i++) A[*(b2+i) - 'a']--;
		for(int i = 0; i < 26; i++) if (A[i] != 0) return false;
		
		for(int i = 1; i < len; i++){
			if(isScramble(b1, b1+i, b2) && isScramble(b1+i, e1, b2+i)
				|| isScramble(b1, b1+i, b2+len-i) && isScramble(b1+i, e1, b2))
				return true;
		}
		return false;
	}
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return isScramble(s1.begin(), s1.end(), s2.begin());
    }
};


//version 2: dfs, only pass small case 8ms
class Solution {
private:
	bool isScramble(string::iterator b1, string::iterator e1, string::iterator b2) {
		auto len = distance(b1, e1);
		if(len == 1)
			return *b1 == *b2;
		for(int i = 1; i < len; i++){ //hjb: len - 1 possile seperated positions
			if(isScramble(b1, b1+i, b2) && isScramble(b1+i, e1, b2+i)
				|| isScramble(b1, b1+i, b2+len-i) && isScramble(b1+i, e1, b2))
				return true;
		}
		return false;
	}
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		return isScramble(s1.begin(), s1.end(), s2.begin());
    }
};


//version 1: 3-d dp  small case 16ms, large case 620ms
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