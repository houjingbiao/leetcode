class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int n = matrix.size();
        if(n == 1)
            return;
        for(int i = 0; i < n/2; i++)
        {
            int len = n - (i*2) - 1;
            for(int j = i; j <i + len; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = temp;
            }
        }
    }
};

//another version
void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = matrix.size()-1;
        for(int x=n/2; x>=0; --x){
            for(int y=(n-1)/2; y>=0; --y){
                int cur_x = x,cur_y=y;
                for(int i=0; i<3; ++i){
                    int tmp = n-cur_x;
                    cur_x = cur_y;
                    cur_y = tmp;
                    swap(matrix[x][y], matrix[cur_x][cur_y]);
                }
            }
        }
    }


//3rd version
class Solution {
public:
    int offset[3][3] ={{1,1,0},{1,0,1},{0,1,0}}; //abs(n-x-y)
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = matrix.size()-1;
        for(int x=n/2; x>=0; --x){
            for(int y=(n-1)/2; y>=0; --y){
                int cur_x = x,cur_y=y;
                for(int i=0; i<3; ++i){
                    cur_x = cur_y;
                    cur_y = abs(n*offset[i][0]-x*offset[i][1]-y*offset[i][2]);
                    swap(matrix[x][y], matrix[cur_x][cur_y]);
                }
            }
        }
    }
};

//4th: 把脚标的除法计算，换成乘法 2*i < n 而不是 i < n/2
