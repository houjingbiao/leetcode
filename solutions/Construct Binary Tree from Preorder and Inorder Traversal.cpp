/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
 //recursive version:
class Solution {
public:
	TreeNode *buildTree(vector<int> &preorder, int pre_pos, vector<int> &inorder, int in_pos, int len) {
		if(len == 0 || pre_pos >= preorder.size() || in_pos >= preorder.size()) return NULL;

		TreeNode* root = new TreeNode(preorder[pre_pos]);
		int i = 0;
		while(i < len&& inorder[in_pos+i] != preorder[pre_pos])
			i++;
		root->left = buildTree(preorder, pre_pos+1, inorder, in_pos, i);
		root->right = buildTree(preorder, pre_pos+i+1, inorder, in_pos+i+1, len-i-1);
		return root;
	}
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		TreeNode* root = NULL;
		if(preorder.size() == 0) return root;
		
		root = buildTree(preorder, 0, inorder, 0, preorder.size());
		return root;
    }
};