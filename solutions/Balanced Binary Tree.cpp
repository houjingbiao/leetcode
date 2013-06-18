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
    int getDepth(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        else
            return 1 + max(getDepth(root->left), getDepth(root->right));
    }
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return true;
            
        if(!isBalanced(root->left) || !isBalanced(root->right))
            return false;
        else 
        {
            int leftDepth = getDepth(root->left);
            int rightDepth = getDepth(root->right);
            if(leftDepth >= rightDepth - 1 && leftDepth <= rightDepth + 1)
                return true;
            else
                return false;
        }
        
    }
};