class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function		
		int* B = new int[n];
		for(int i = 0; i < n-1; i++)
			B[i] = 999999;
		B[n-1] = 0;
		for(int step = 0; step < n; step++){
			for(int pos = 0; pos < n; pos++){
				if(B[pos] == step){
					for(int i = 0; i < pos; i++){
						if(B[i] > step && i + A[i] >= pos){
							B[i] = B[pos] + 1;
							if(i == 0) return step+1;
						}
					}
				}
			}
		}
		return 0;
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