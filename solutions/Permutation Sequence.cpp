class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		static int factorials[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 360880};
        string ret;	
		if(k > factorials[n])
			return ret;
		if(n == 1)
		{
			ret.push_back(1+'0');
			return ret;
		}
		k = k-1;
		vector<bool> marks(n, false);
		int n_curr = n;
		while(n_curr>0)
		{
			int idx = k/factorials[n_curr-1];
			for(int i = 1; i <= n; i++)
			{
				if(marks[i-1] == false)
				{
					if(idx <= 0)
					{
						ret.push_back(i+'0');
						marks[i-1] = true;
						break;
					}
					idx--;
				}
			}
			k = k%factorials[n_curr-1];
			n_curr--;
		}
		return ret;
	}
};