class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> ret;
        vector<int> subset;
        ret.push_back(subset);
        int count = 1 << (S.size());
        for(int i = 1; i < count; i++)
        {
            subset.clear();
            int num = i;
            int digit_idx = 0;
            while(num > 0)
            {
                if(num%2)
                    subset.push_back(S[S.size() - 1 - digit_idx]);
                num = num >> 1;
                digit_idx++;
            }
            ret.push_back(subset);
        }
        return ret;
    }
};