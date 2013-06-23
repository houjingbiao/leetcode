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
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        if(root == NULL)
            return ret;
        
        stack<TreeNode*> mystack;
        //stack.push(root);
        TreeNode* p = root;
        while(p || !mystack.empty())
        {
            if(p == NULL){
                p = mystack.top();
                mystack.pop();
                ret.push_back(p->val);
                p = p->right;
            }else{
                if(p->left)
                {
                    mystack.push(p);
                    p = p->left;
                }
                else
                {
                    ret.push_back(p->val);
                    p = p->right;
                }
            }
            
        }
        return ret;
    }
};