/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
//version 3: iterative, judgeing loop by stack
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(root == NULL) return false;
		stack<TreeNode*> path;
		path.push(root);
		int curr_sum = root->val;
		
		while(!path.empty()){
			if(path.top()->left == NULL && path.top()->right == NULL){
				if(curr_sum == sum) return true;
				else{
					TreeNode *p = NULL;
					do{
						p = path.top();
						path.pop();
						curr_sum -= p->val;
					}while(!path.empty() && (path.top()->right == p || path.top()->right == NULL));
					if(path.empty()) return false;
					p = path.top()->right;
					path.push(p);
					curr_sum += p->val;
				}
			}
			else{
				if(path.top()->left != NULL){
					TreeNode *p = path.top()->left;
					path.push(path.top()->left);
					curr_sum += p->val;
				}
				else{
					TreeNode *p = path.top()->right;
					path.push(path.top()->right);
					curr_sum += p->val;
				}
			}
		}
		return false;
    }
};
 
//version 2: iterative
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(root == NULL) return false;
		stack<TreeNode*> path;
		TreeNode *p = root;
		int curr_sum = 0;
		while(p){
			curr_sum += p->val;
			if(p->left == NULL && p->right == NULL){
				if(curr_sum == sum)
					return true;
				else{
					while(!path.empty() && (path.top()->right == p || path.top()->right == NULL)){
						curr_sum -= p->val;
						p = path.top();
						path.pop();
					}
					if(path.empty()) return false;
					curr_sum -= p->val;
					p = path.top()->right;
				}
			}
			else{
				path.push(p);
				if(p->left != NULL)
					p = p->left;
				else
					p = p->right;
			}
		}
		return false;
    }
};


//version 1: recursive
class Solution {
public:
	bool hasPathSum(TreeNode *root, int sum, int curr_sum) {
		curr_sum += root->val;
		if(root->left == NULL && root->right == NULL && sum == curr_sum)
			return true;
		else if( (root->left && hasPathSum(root->left, sum, curr_sum))
			|| (root->right && hasPathSum(root->right, sum, curr_sum)))
			return true;
		return false;
	}
	
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(root == NULL) return false;
		int curr_sum = 0;
		return hasPathSum(root, sum, curr_sum);
    }
};