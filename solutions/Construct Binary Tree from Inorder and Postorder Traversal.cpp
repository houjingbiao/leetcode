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
	TreeNode *buildTree(vector<int> &inorder, int in_pos, vector<int> &postorder, int post_pos, int len) {
		if(len == 0 || post_pos < 0 || in_pos < 0 || post_pos >= postorder.size() || in_pos >= inorder.size()) return NULL;

		TreeNode* root = new TreeNode(postorder[post_pos]);
		int i = 0;
		while(i < len && inorder[in_pos+i] != postorder[post_pos])
			i++;
		root->left = buildTree(inorder, in_pos, postorder, post_pos-(len-i), i);
		root->right = buildTree(inorder, in_pos+i+1, postorder, post_pos-1, len - i - 1);
		return root;
	}
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		TreeNode* root = NULL;
		if(postorder.size() == 0) return root;

		root = buildTree(inorder, 0, postorder, postorder.size()-1, postorder.size());
		return root;
	}
};


//version: yinyuxiang
class Solution {
public:
    unordered_set<int> visited;
    TreeNode *buildTree(int inorder[], int &n, int postorder[], int &m){
        if(n<0 || m<0 || visited.erase(inorder[n]) > 0){
            --n;
            return NULL;
        }  
        visited.insert(postorder[m]);
        TreeNode* node = new TreeNode(postorder[m]);
        if(postorder[m--] != inorder[n]){
            node->right = buildTree(inorder, n, postorder, m);
        }else{
            --n;
        }
        node->left = buildTree(inorder, n, postorder, m);
        return node;
    }
 
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(inorder.size() != postorder.size())
            return NULL;
        visited.clear();
        int n=inorder.size()-1, m=postorder.size()-1;
        return buildTree(inorder.data(), n, postorder.data(), m);
    }
};