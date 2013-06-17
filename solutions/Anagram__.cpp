class Solution {
public:
    int str2num(string &str)
    {
        if(str.empty())
            return 1<<26;
        int ret = 0;
        for(int i = 0; i < str.length(); i++)
            ret |= (1<<(str[i] - 'a'));
        return ret;
    }

    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> rets;
        if(strs.size() == 0)
            return rets;
        vector<int> marks;
        vector<bool> isVisited(strs.size(), false);
        for(int i = 0; i < strs.size(); i++)
        {
            int mark = str2num(strs[i]);
            marks.push_back(mark);
        }
        int i = 0;
        int j = 0;
        for(; i < strs.size(); i++)
        {
            if(isVisited[i] == true)
                continue;
            //vector<string> ret;
            rets.push_back(strs[i]);
            int count = 1;
            isVisited[i] = true;
            /*for(j = i+1; j < strs.size(); j++)
            {
                if(isVisited[j] == false && strs[i].length() == strs[j].length() && marks[i] == marks[j])
                {
                    //rets.push_back(strs[j]);
                    //isVisited[j] = true;
                    //count++;
                }
            }*/
            if(count == 1)
                rets.pop_back();
        }
        return rets;
        
    }
};