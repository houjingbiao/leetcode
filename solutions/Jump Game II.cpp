//version 1: in fact, this is also BFS
class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function	
		if(n<=1) return 0;
		int curstep = 0;
		int lastMax = 0;
		int curMax = 0;
		int newMax = 0;
		while(lastMax <= curMax){
			curstep++;
			for(int i = lastMax; i <= curMax; i++){
				newMax = newMax < i+A[i] ? i+A[i] : newMax;
				if(newMax >= n-1) return curstep;
			}
			lastMax = curMax;
			curMax = newMax;
		}
		return curstep;
    }
};

//version: BFS
class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function		
		if(n<=1) return 0;
		int* steps = new int[n];
		for(int i = 0; i < n-1; i++)
			steps[i] = n;
		steps[n-1] = 0;
		int step = 0;
		while(step < n){
			for(int pos = 0; pos < n; pos++){
				if(steps[pos] == step){
					for(int i = 0; i < pos; i++){
						if(steps[i] > step && i + A[i] >= pos){
							steps[i] = step + 1;
							if(i == 0) return step+1;
						}
					}
				}
			}
			step++;
		}
		return 0;
    }
};

// only pass little case
class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function		
		if(n<=1) return 0;
		int* steps = new int[n];
		for(int i = 0; i < n; i++)
			steps[i] = n;
		steps[0] = 0;
		for(int i = 0; i < n-1; i++){
			for(int j = i+1; j <= i+A[i] && j < n; j++){
				steps[j] = steps[j] > steps[i]+1 ? steps[i]+1 : steps[j];
			}
		}
		int ret = steps[n-1];
		delete[] steps;
		return ret;
    }
};




//version 1: dp, only pass small case
class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int* B = new int[n];
		B[0] = 0;
		
		for(int i = 1; i < n; i++){
			B[i] = n;
			for(int j = 0; j < i; j++){
				if(j + A[j] >= i)
					B[i] =min(B[i], B[j]+1);
			}
		}
		int ret = B[n-1];
		delete[] B;
		return ret;
    }
};