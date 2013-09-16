//version 5: java from fengge
public int find(int[] A, int key) {
    if (A == null || A.length == 0) return -1;
    int low = 0, high = A.length-1; //the interval is [low, high]

    while (low <= high) {
        int mid = low + (high - low)/2;
        if (A[mid] == key)  
            return mid;
        if (A[low] <= A[mid]) {
            if (A[low] <= key && key < A[mid]) {
                high = mid - 1;
            }else {
                low = mid + 1;
            }
        }else {
            if (A[mid] < key && key <= A[high]) {
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
    }
    return -1;
}

//version 4:
class Solution {
public:
    int search(int A[], int n, int target) {
		if(n == 0)  return -1;
		int b = -1;
		int e = n - 1;//hjb: the interval is (b, e]
		while(e-b > 1){
			int mid = b+(e-b)/2;//int mid = (b+1)/2 + e/2;
			if( (A[mid] <= A[e] && target > A[mid] && target <= A[e])
				|| (A[mid] > A[e] && (target > A[mid] || target < A[b+1])))
				b = mid;
			else
				e = mid;
		}
		if(A[++b] == target)
			return b;
		return -1;
    }
};

//version 3:
class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(n == 0)  return -1;
		int b = -1;
		int e = n - 1;//hjb: the interval is (b, e]
		while(e-b > 1){
			int mid = b+(e-b)/2;//int mid = (b+1)/2 + e/2;
			if(A[mid] <= A[e]){
				if(target <= A[mid])
					e = mid;
				else{
					if(target <= A[e])
						b = mid;
					else
						e = mid;
				}
			}
			else{
				if(target <= A[mid]){
					if(target < A[b+1])
						b = mid;
					else
						e = mid;
				}
				else
					b = mid;
			}
		}
		b++;
		if(A[b] == target)
			return b;
		return -1;
    }
};


//version 2: 
class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(n == 0)  return -1;
		int b = -1;
		int e = n-1;
		while(e-b > 1){
			int mid = b+(e-b)/2;//int mid = (b+1)/2 + e/2;
			if(target <= A[mid]){
				if(A[mid] <= A[e])
					e = mid;
				else{
					if(target < A[b+1])
						b = mid;
					else
						e = mid;
				}
			}
			else{
				if(A[mid] <= A[e]){
					if(target > A[e])
						e = mid;
					else
						b = mid;
				}
				else
					b = mid;
			}
		}
		b++;
		if(A[b] == target)
			return b;
		return -1;
    }
};

//version 1: very long
class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(target < A[0] && target > A[n-1]) return -1;
        if(n == 1) {
            if(A[0] == target) return 0;
            else return -1;
        }
        
        int start = 0;
        int end = n-1;
        while(start < end){
            int mid = 0;
            mid = start/2 + end/2;
            if(target == A[start])  return start;
            else if(target == A[end])  return end;
            else if(target == A[mid])   return mid;
            else if(target > A[start]){
                if(A[start] <= A[mid]){
                    if(target <= A[mid])
                        end = mid;
                    else
                        start = mid + 1;
                }
                else
                    end = mid - 1;
            }
            else if(target < A[end]) {
                if(A[end] <= A[mid])
                    start = mid + 1;
                else {
                    if(target > A[mid]) 
						start = mid + 1;
                    else
                        end = mid;
                }
            }
            else
                return -1;
        }
        return -1;
    }
};