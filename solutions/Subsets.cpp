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

//version2: this is a version that just use the index updating

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &S){
        vector<vector<int>> ret;
        vector<int> subset;
        ret.push_back(subset);
        if(S.size() == 0)
            return ret;
        
        for(int len = 1; len < S.size(); len++)
        {
            subset.clear();
            vector<int> subsetIdx;
            
            for(int i = 0; i < len; i++)
                subsetIdx.push_back(i);
            
            while(subsetIdx[0]+len-1 < S.size() && subsetIdx[len-1] < S.size())
            {
                subset.clear();
                for(int i = 0; i < len; i++)
                    subset.push_back(S[subsetIdx[i]]);
                ret.push_back(subset);
                
                int m = len-1;
                for(; m >= 0; m--)
                {
                    if(subsetIdx[m]+len-m < S.size())
                    {
                        subsetIdx[m]++;
                        for(int k = m+1; k < len; k++)
                        {
                            subsetIdx[k] = subsetIdx[k-1]+1;
                        }
                        break;
                    }
                }
                if(m < 0)
                    break;
            }
        }
        ret.push_back(S);
        return ret;
    }
};