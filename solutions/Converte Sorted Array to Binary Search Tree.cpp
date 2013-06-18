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
    void sortedArrayToBST(vector<int> &num, int pos, int len, TreeNode* root, bool isLeft)
    {
        if(len >= 1)
        {
            int mid = pos + len/2;
            TreeNode *node = new TreeNode(num[mid]);
            if(isLeft)
                root->left = node;
            else
                root->right = node;
            
            if(mid - pos > 0)
                sortedArrayToBST(num, pos, mid - pos, node, true);
            if(len - mid + pos - 1 > 0)
                sortedArrayToBST(num, mid+1, len - mid + pos - 1, node, false);
        }
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(num.size() == 0)
            return 0;
        int mid = (num.size() - 1)/2;
        TreeNode* root = new TreeNode(num[mid]);
        
        if(mid > 0)
            sortedArrayToBST(num, 0, mid, root, true);
        if(num.size() - mid - 1 > 0)
            sortedArrayToBST(num, mid+1, num.size()-mid-1, root, false);
        return root;
    }
};