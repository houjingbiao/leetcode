//version 1: complexity is O(nlogn)
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        
        int maxLen = 1;
        int curLen = 1;
        for(int i = num.size()-2; i >= 0; i--)
        {
            if(num[i] == num[i+1]-1)
                curLen++;
			else if(num[i] < num[i+1]-1){
                if(maxLen < curLen) maxLen = curLen;
				curLen = 1;
            }
        }
        return max(maxLen, curLen);
    }
};

//version 2:unordered_map + union_find
class Solution {
public:
	typedef struct Node{
		int data;
		int parent;
	} PSnode;

	int getData(int idx, PSnode* ps, int newparent){
		int ret = 0;
		if(ps[idx].parent == idx) 
			ret = ps[idx].data;
		else
			ret = getData(ps[idx].parent, ps, newparent);
		ps[idx].parent = newparent;
		return ret;
	}
	
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		PSnode* PS = new PSnode[num.size()];
		
        unordered_map<int, int> mymap;
		int maxLen = 1;
		for(int i=0; i<num.size(); i++){
			if(mymap.count(num[i]) != 0) continue;
			
			mymap[num[i]] = i;
			PS[i].parent = i;
			PS[i].data = 1;
			if(mymap.count(num[i]+1) > 0)
				PS[i].data += getData(mymap[num[i]+1], PS, i);
			if(mymap.count(num[i]-1) > 0)
				PS[i].data += getData(mymap[num[i]-1], PS, i);
				
			maxLen = maxLen > PS[i].data ? maxLen : PS[i].data;
		}
		delete[] PS;
		return maxLen;
    }
};