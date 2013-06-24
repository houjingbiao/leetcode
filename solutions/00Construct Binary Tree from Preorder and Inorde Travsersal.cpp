 class Solution {
public:
	void buildSubTree(TreeNode *root, vector<int> &preorder, int prePos, int preEnd, vector<int> &inorder, int inPos, int inEnd, bool isLeft)
	{
		if(prePos > preEnd)
			return;
		TreeNode *p = new TreeNode(preorder[prePos]);
		if(isLeft)
			root->left = p;
		else
			root->right = p;

		int inPos_new = inPos;
		for(; inPos_new <= inEnd; inPos_new++)
			if(preorder[prePos] == inorder[inPos_new])
				break;

		int prePos_new = prePos;
		if(inPos_new - 1 >= inPos)
		{
			for(; prePos_new <= preEnd; prePos_new++)
				if(preorder[prePos_new] == inorder[inPos_new-1])
					break;
		}
		buildSubTree(root, preorder, prePos+1, prePos_new, inorder, inPos, inPos_new-1, true);
		buildSubTree(root, preorder, prePos_new+1, preorder.size()-1, inorder, inPos+1, inorder.size()-1, false);
	}
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		TreeNode *root = NULL;
		if(preorder.size() != inorder.size() || preorder.size() == 0)
			return root;

		root = new TreeNode(preorder[0]);
		int inpos = 0;
		for(; inpos < inorder.size(); inpos++)
			if(preorder[0] == inorder[inpos])
				break;
		int prepos = 0;
		if(inpos - 1 >= 0)
		{
			for(; prepos < preorder.size(); prepos++)
				if(preorder[prepos] == inorder[inpos-1])
					break;
		}
		buildSubTree(root, preorder, 1, prepos, inorder, 0, inpos-1, true);
		buildSubTree(root, preorder, prepos+1, preorder.size()-1, inorder, inpos+1, inorder.size()-1, false);
		return root;
	}
};