/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */



// recursive version
class Solution {
public:
    bool areSymmetric(TreeNode *left, TreeNode *right)
    {
        if(left == NULL && right == NULL)
            return true;
        else if(left == NULL && right != NULL)
            return false;
        else if(left != NULL && right == NULL)
            return false;
        else if(left->val != right->val)
            return false;
        else if(areSymmetric(left->left, right->right) && areSymmetric(left->right, right->left))
            return true;
        else
            return false;
    }
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return true;
        else if(root->left == NULL && root->right != NULL)
            return false;
        else if(root->left != NULL && root->right == NULL)
            return false;
        else 
            return areSymmetric(root->left, root->right);
    }
};