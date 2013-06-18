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
    int maxValue(TreeNode *root)
    {
        int maxn = root->val;
        
        if(root->left == NULL && root->right == NULL)
            return maxn;
        if(root->left)
        {
            int maxLeft = maxValue(root->left);
            if(maxLeft > maxn)
                maxn = maxLeft;
        }
        if(root->right)
        {
            int maxRight = maxValue(root->right);
            if(maxRight > maxn)
                maxn = maxRight;
        }
        return maxn;
    }
    int minValue(TreeNode *root)
    {
        int minn = root->val;
        
        if(root->left == NULL && root->right == NULL)
            return minn;
        if(root->left)
        {
            int minLeft = minValue(root->left);
            if(minLeft < minn)
                minn = minLeft ;
        }
        if(root->right)
        {
            int minRight = minValue(root->right);
            if(minRight < minn)
                minn = minRight ;
        }
        return minn;
    }
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(root == NULL)
            return true;
        else if(root->left == NULL && root->right == NULL)
            return true;
        else if(root->left && root->val <= maxValue(root->left))
            return false;
        else if(root->right && root->val >= minValue(root->right))
            return false;
        else if(!isValidBST(root->left) || !isValidBST(root->right))
            return false;
        else
            return true;
    }
};