/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	int getPath(TreeNode *root, int &maxPath){
		if(root == NULL) return 0;
		int leftPath = getPath(root->left, maxPath);
		int rightPath = getPath(root->right, maxPath);
		int sumPath = leftPath+rightPath+root->val;
		maxPath = max(maxPath, leftPath+root->val);
		maxPath = max(maxPath, rightPath+root->val);
		maxPath = max(maxPath, sumPath);
		maxPath = max(maxPath, root->val);
		int ret = max(leftPath+root->val, rightPath+root->val);
		return max(ret, root->val);
	}
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(root == NULL) return 0;
		int maxPath = -999999;
		int leftPath = getPath(root->left, maxPath);
		int rightPath = getPath(root->right, maxPath);
		int sumPath = leftPath+rightPath+root->val;
		maxPath = max(maxPath, leftPath+root->val);
		maxPath = max(maxPath, rightPath+root->val);
		maxPath = max(maxPath, sumPath);
		maxPath = max(maxPath, root->val);
        return maxPath;
    }
};