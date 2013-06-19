class Solution {
public:
    bool isPlainDrome(string s, int pos, int len)
    {
        if(len == 0)
            return false;
        for(int i = 0, j = len - 1; i < j; i++, j--)
        {
            if(s[pos+i] != s[pos+j])
                return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> edges;
        vector<vector<int>> edges_visited;
        if(s.empty())
            return edges;
        
        for(int i = 0; i < s.length(); i++)    
        {
            vector<int> edge(1, 1);
            edges.push_back(edge);
        }
        
        for(int i = 0; i < s.length(); i++)
        {
            for(int len = 2; len < s.length() - i; len++)
            {
                if(isPlainDrome(s, i, len))
                    edges[i].push_back(len);
            }
        }
        
        int len = 0;
        int start = 0;
        int target = s.length - 1;
        vector<int> visited_index(edges.size(), 0);
        visited_index[]
        if(int i = edges.size()-1; i >= 0; i--)
        {
            if(edges[i][visited_index[i]] == s.length()-i-1)
            {
                
            }
            visited_index[i][]
            
            
            enges[0]
            edges[i][i] = 0;
        }
        
        
        return edges;
    }
};