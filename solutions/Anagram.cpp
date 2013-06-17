class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<string> ret;
        
        map<string, vector<string>> dict;
        for(int i = 0; i < strs.size(); i++)
        {
            string key = strs[i];
            sort(key.begin(), key.end());
            dict[key].push_back(strs[i]);
        }
        
        map<string, vector<string>>::iterator it = dict.begin();
        for(; it != dict.end(); it++)
        {
            if( it->second.size() > 1)
                ret.insert(ret.end(), it->second.begin(), it->second.end());
        }
        return ret;
    }
};