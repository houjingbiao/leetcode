/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL)
            return head;
            
        ListNode *p = head;
        ListNode *q = p->next;
        while(q)
        {
            while(q && q->val == p->val)
            {
                p->next = q->next;
                q = q->next;
            }
            if(q)
            {
                p = q;
                q = q->next;
            }
        }
        return head;
    }
};