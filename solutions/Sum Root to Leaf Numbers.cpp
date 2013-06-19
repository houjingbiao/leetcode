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
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return 0;
        
        int ret = 0;
        int curVal = 0;
        vector<TreeNode*> stack;
        TreeNode *p = root;
        while(p != NULL)
        {
            if(p->left != NULL || p->right != NULL)
            {
                stack.push_back(p);
                curVal = curVal*10 + p->val;
                if(p->left)
                    p = p->left;
                else
                    p = p->right;
            }
            else
            {
                ret += curVal*10 + p->val;
                if(stack.size() == 0)
                    return ret;
                if(stack.back()->left == p && stack.back()->right != NULL)
                {
                    p = stack.back()->right;
                }
                else
                {
                    while(stack.size() > 0 && (stack.back()->right == p || stack.back()->right == NULL))
                    {
                        p = stack.back();
                        stack.pop_back();
                        curVal /= 10;
                    }
                    if(stack.size() == 0)
                        return ret;
                    else
                    {
                        p = stack.back()->right;
                    }
                }
            }
        }
        return ret;
    }
};