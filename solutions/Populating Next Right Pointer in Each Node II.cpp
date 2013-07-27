/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL || (root->left == NULL && root->right == NULL))
            return;

		TreeLinkNode *next_level_start = NULL;
		TreeLinkNode *next_level_end = NULL;
		TreeLinkNode *p = root;
		while(p){
			if(p->left||p->right)
			{
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