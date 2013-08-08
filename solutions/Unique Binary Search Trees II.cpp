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
	TreeNode *deepCopy(TreeNode *root){
		if(root == NULL) return NULL;
		TreeNode *node = new TreeNode(root->val);
		node->left = deepCopy(root->left);
		node->right = deepCopy(root->right);
		return node;
	}
	
	void generateNewTreesWithbignode(TreeNode *root, int num, vector<TreeNode *> &rets_new){
		TreeNode *p = root;
		//bignode as root
		if(p){
			TreeNode *new_bignode = new TreeNode(num);
			new_bignode->left = deepCopy(p);
			rets_new.push_back(new_bignode);
		}
		
		//bignode as right subtree
		int right_count = 0;
		while(p){
			TreeNode *new_bignode = new TreeNode(num);
			TreeNode *new_root = deepCopy(root);
			TreeNode *p1 = new_root;
			for(int i=0; i < right_count; i++){
				p1 = p1->right;
			}
			new_bignode->left = p1->right;
			p1->right = new_bignode;
			rets_new.push_back(new_root);
			
			p = p->right;
			right_count++;
		}
	}
	
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<TreeNode *> rets;
		if(n == 0){
			rets.push_back(NULL);
			return rets;
		}
		TreeNode *node = new TreeNode(1);
		rets.push_back(node);
		for(int i = 2; i <= n; i++){
			vector<TreeNode *> rets_new;
			for(int j = 0; j < rets.size(); j++)
				generateNewTreesWithbignode(rets[j], i, rets_new);
			rets.clear();
			rets = rets_new;
		}
		return rets;
    }
};



//version 2: some bugs in it
class Solution {
public:
	TreeNode *deepCopy(TreeNode *root){
		if(root == NULL) return NULL;
		TreeNode *node = new TreeNode(root->val);
		node->left = deepCopy(root->left);
		node->right = deepCopy(root->right);
		return node;
	}
	void generateTrees(int b, int e, TreeNode *root, TreeNode *parent, int n, vector<TreeNode *> &rets, bool isLeft, bool judgeEnd){
		if(judgeEnd && b > e){
			rets.push_back(deepCopy(root));
		}
		else if(b <= e){
			for(int i = b; i <= e; i++){
				TreeNode *node = new TreeNode(i);
				if(isLeft)
					parent->left = node;
				else
					parent->right = node;
				generateTrees(b,   i-1, root, node, n, rets, true, judgeEnd && i == e);
				if(i < e)
					generateTrees(i+1, e,   root, node, n, rets, false, judgeEnd);
			}
		}
	}
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<TreeNode *> rets;
		if(n == 0){
			rets.push_back(NULL);
			return rets;
		}
		else if(n == 1){
			TreeNode *root = new TreeNode(n);
			rets.push_back(root);
			return rets;
		}
		else{
			for(int i = 1; i <= n; i++){
				TreeNode *root = new TreeNode(i);
				generateTrees(  1, i-1, root, root, n, rets, true, i == n);
				if(i < n)
					generateTrees(i+1,   n, root, root, n, rets, false, true);
			}
		}
		return rets;
    }
};



 
//version 1: not in order
class Solution {
public:
	TreeNode *deepCopy(TreeNode *root){
		if(root == NULL) return NULL;
		TreeNode *node = new TreeNode(root->val);
		node->left = deepCopy(root->left);
		node->right = deepCopy(root->right);
		return node;
	}
	void generateTrees(int count, int pos, TreeNode *root, TreeNode *parent, int n, vector<TreeNode *> &rets, bool isLeft){
		if(count == 0) return;
		else if(count == 1){
			TreeNode *node = new TreeNode(pos);
			if(isLeft)
				parent->left = node;
			else
				parent->right = node;
			if(pos == n)  rets.push_back(deepCopy(root));
			delete node;
			if(isLeft)
				parent->left = NULL;
			else
				parent->right = NULL;
		}
		else{
			TreeNode *node = new TreeNode(pos);
			if(isLeft)
				parent->left = node;
			else
				parent->right = node;
			for(int i = 0; i < count; i++){
				generateTrees(i,             pos+1,   root, node, n, rets, true);
				generateTrees(count - 1 - i, pos+1+i, root, node, n, rets, false);
				node->left = NULL;
				node->right = NULL;
			}
			delete node;
		}
	}
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<TreeNode *> rets;
		if(n == 0){
			rets.push_back(NULL);
			return rets;
		}
		else if(n == 1){
			TreeNode *root = new TreeNode(n);
			rets.push_back(root);
			return rets;
		}
		else{
			TreeNode *root = new TreeNode(1);
			for(int i = 0; i < n; i++){
				generateTrees(i,     1+1,   root, root, n, rets, true);
				generateTrees(n-1-i, 1+1+i, root, root, n, rets, false);
				root->left = NULL;
				root->right = NULL;
			}
			//delete root;
		}
		return rets;
    }
};