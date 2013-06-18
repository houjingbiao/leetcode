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


//iterative version
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return true;
        else
        {
            vector<TreeNode*> leftStack;
            vector<TreeNode*> rightStack;
            TreeNode *theLeft = root->left;
            TreeNode *theRight = root->right;
            
            while(true)
            {
                if(theLeft == NULL && theRight == NULL)
                {
                    if(leftStack.size() == 0 && rightStack.size() == 0)
                        return true;
                    else if(leftStack.size() != rightStack.size())
                        return false;
                    else
                    {
                        theLeft = leftStack.back();
                        leftStack.pop_back();
                        theRight = rightStack.back();
                        rightStack.pop_back();
                    }
                }
                else if(theLeft == NULL && theRight != NULL)
                    return false;
                else if(theLeft != NULL && theRight == NULL)
                    return false;
                else if(theLeft->val != theRight->val)
                    return false;
                else
                {
                    leftStack.push_back(theLeft->right);
                    theLeft = theLeft->left;
                    rightStack.push_back(theRight->left);
                    theRight = theRight->right;
                }
            }
            return true;
        }
    }
};