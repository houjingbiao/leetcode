/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 
 //version 1:
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		TreeLinkNode *next_level_start = NULL;
		TreeLinkNode *next_level_end = NULL;
		TreeLinkNode *p = root;
		while(p){
			if(p->left)
			{
				if(next_level_start == NULL)
					next_level_start = p->left;
				if(next_level_end == NULL)
					next_level_end = p->left;
				else
				{
					next_level_end->next = p->left;
					next_level_end = next_level_end->next;
				}
			}
			if(p->right)
			{
				if(next_level_start == NULL)
					next_level_start = p->right;
				if(next_level_end == NULL)
					next_level_end = p->right;
				else
				{
					next_level_end->next = p->right;
					next_level_end = next_level_end->next;
				}
			}
			
			p = p->next;
			if(p == NULL && next_level_start != NULL)//to next level
			{
				if(next_level_end) next_level_end->next = NULL;
				p = next_level_start;
				next_level_start = NULL;
				next_level_end = NULL;
			}
		}
    }
};

//version from yinyuxiang: what differs from version 1 is that this version use two loops, which makes the procedure seem to be simply.
class Solution {
public:    
	void connect(TreeLinkNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		TreeLinkNode *next_level = root, *next, *pre;
		while(next_level != NULL){
			next = next_level;
			next_level = NULL;
			pre = NULL;
			while(next != NULL){
				if(next->left != NULL){
					if(pre != NULL){
						pre = pre->next = next->left;
					}else{
						next_level = pre = next->left;
					}
				}
				if(next->right != NULL){
					if(pre != NULL){
						pre = pre->next = next->right;
					}else{
						next_level = pre = next->right;
					}
				}
				next = next->next;
			}
		}
	}
}; 
