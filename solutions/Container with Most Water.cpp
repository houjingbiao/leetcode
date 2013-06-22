class Solution {
public:
	int maxArea(vector<int> &height) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(height.size() < 2)
			return 0;
		int leftMax = height[0];
		int rightMax = height[height.size()-1];

		int iL = 0;
		int iR = height.size()-1;
		int area = (height.size()-1-0)*min(leftMax, rightMax);
		while(iL < iR)
		{
			if(leftMax < rightMax)
			{
				if(height[iL] > leftMax)
				{
					leftMax = height[iL];
					area = max(area, (iR - iL)*min(leftMax, rightMax));
				}
				else
					iL++;
			}
			else
			{
				if(height[iR] > rightMax)
				{
					rightMax = height[iR];
					area = max(area, (iR - iL)*min(leftMax, rightMax));
				}
				else
					iR--;
			}
		}
		return area;
	}
};