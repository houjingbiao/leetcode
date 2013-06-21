//version: simple and forcely, 
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(height.size() == 0)
            return 0;
        int ret = 0;
        for(int i = 0; i < height.size(); i++)
        {
            int min = height[i];
	   if(ret > min*(height.size() - i))
                continue;
            for(int len = 1; i + len <= height.size(); len++)
            {
                min = (min <= height[i+len-1]) ? min: height[i+len-1];
                ret = (ret >= min*len)? ret : min*len;
                if(ret > min*(height.size() - i))
                    break;
            }
        }
        return ret;
    }
};


// a new version based on stack
class Solution
{
public:
	int largestRectangleArea(vector<int> &height){
		if(height.size() == 0)
			return 0;
		else if(height.size() == 1)
			return height[0];
		int m = 0;
		height.push_back(0);
		stack<int> stk;
		int i = 0;
		while(i < height.size())
		{
			if(stk.empty() || height[stk.top()] <= height[i])
				stk.push(i++);
			else
			{
				int t = stk.top();
				stk.pop();
				m = max(m, height[i]*(stk.empty()?i:i-1-stk.top()));
			}
		}
		return m;
	}

};