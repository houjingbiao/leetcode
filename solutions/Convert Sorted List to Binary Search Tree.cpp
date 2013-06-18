/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    void sortedListToBST(ListNode *head, int len, TreeNode *root, bool isLeft)
    {
        if(len > 0)
        {
            int mid = len/2;
            int i = 0;
            ListNode *preP = NULL;
            ListNode *p = head;
            while(i < mid && p)
            {
                preP = p;
                p = p->next;
                i++;
            }
            TreeNode *node = new TreeNode(p->val);
            if(isLeft)
                root->left = node;
            else
                root->right = node;
            if(head != p)
                sortedListToBST(head, mid, node, true);
            
            if(preP != NULL)
                preP->next = NULL;
            preP = p->next;
            p->next = NULL;
            delete p;
            if(preP != NULL)
                sortedListToBST(preP, len - mid - 1, node, false);
        }
    }
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL)
            return NULL;
        int len = 0;
        ListNode *p = head;
        while(p)
        {
            len++;
            p = p->next;
        }
        
        int mid = len/2;
        int i = 0;
        ListNode *preP = NULL;
        p = head;
        while(i < mid && p)
        {
            preP = p;
            p = p->next;
            i++;
        }
        TreeNode *root = new TreeNode(p->val);
        if(head != p)
            sortedListToBST(head, mid, root, true);

        if(preP != NULL)
            preP->next = NULL;
        preP = p->next;
        p->next = NULL;
        delete p;
        if(preP != NULL)
            sortedListToBST(preP, len - mid - 1, root, false);
            
        return root;
    }
};