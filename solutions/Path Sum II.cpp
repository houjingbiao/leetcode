/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
//version 1: iterative
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<vector<int>> rets;
		if(root == NULL) return rets;
		vector<int> ret;
		stack<TreeNode*> path;
		path.push(root);
		ret.push_back(root->val);
		int curr_sum = root->val;
		
		while(!path.empty()){
			if(path.top()->left == NULL && path.top()->right == NULL){
				if(curr_sum == sum)  rets.push_back(ret);
				TreeNode *p = NULL;
				do{
					p = path.top();
					path.pop();
					ret.pop_back();
					curr_sum -= p->val;
				}while(!path.empty() && (path.top()->right == p || path.top()->right == NULL));
				if(path.empty()) return rets;
				p = path.top()->right;
				path.push(p);
				ret.push_back(p->val);
				curr_sum += p->val;
			}
			else{
				if(path.top()->left != NULL){
					TreeNode *p = path.top()->left;
					path.push(path.top()->left);
					curr_sum += p->val;
					ret.push_back(p->val);
				}
				else{
					TreeNode *p = path.top()->right;
					path.push(path.top()->right);
					curr_sum += p->val;
					ret.push_back(p->val);
				}
			}
		}
		return rets;
    }
};