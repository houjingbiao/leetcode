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
        if(root == NULL || root->left == NULL || root->right == NULL)
            return;
            
        queue<TreeLinkNode*> myqueue;
        myqueue.push(root);
        while(!myqueue.empty())
        {
            queue<TreeLinkNode*> newqueue;
            TreeLinkNode *p = myqueue.front();
            while(!myqueue.empty())
            {
                p->next = myqueue.front();
                myqueue.pop();
                if(p->left)
                    newqueue.push(p->left);
                if(p->right)
                    newqueue.push(p->right);
                p = p->next;
            }
            p->next = NULL;
            if(p->left)
                newqueue.push(p->left);
            if(p->right)
                newqueue.push(p->right);
            myqueue = newqueue;
        }
    }
};