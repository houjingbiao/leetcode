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
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //return;
        if(root == NULL)
            return;
        vector<TreeNode*> stack;
        if(root->right)
            stack.push_back(root->right);
        
        TreeNode *p = root->left;
        TreeNode *q = root;
        q->left = NULL;
        while(1)
        {
            if(p == NULL)
            {
                if(stack.size() == 0)
                    return;
                else
                {
                    p = stack.back();
                    stack.pop_back();
                }
            }
            else
            {
                if(p->right)
                    stack.push_back(p->right);
                q->right = p;
                q = p;
                p = p->left;
                q->left = NULL;
            }
        }
    }
};