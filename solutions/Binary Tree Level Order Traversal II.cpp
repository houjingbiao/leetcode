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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> rets;
        if(root == NULL) return rets;
        
        TreeNode *p = root;
        queue<TreeNode*> myqueue;
        myqueue.push(p);
        
        while(!myqueue.empty())
        {
            myqueue.push(NULL);
            vector<int> ret;
            while(!myqueue.empty())
            {
                if(myqueue.front())
                {
                    ret.push_back(myqueue.front()->val);
                    if(myqueue.front()->left)
                       myqueue.push(myqueue.front()->left);
                    if(myqueue.front()->right)
                        myqueue.push(myqueue.front()->right);
                    myqueue.pop();
                }
                else
                {
                    myqueue.pop();
                    rets.insert(rets.begin(), ret);
                    break;
                }
            }
        }
        return rets;
    }
};