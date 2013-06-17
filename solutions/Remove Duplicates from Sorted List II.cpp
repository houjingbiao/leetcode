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
        
        if(head == NULL || head->next == NULL)
            return head;
            
        ListNode mark(0);
        mark.next = head;
        
        ListNode *p = &mark;
        ListNode *q = mark.next;
        ListNode *r = q->next;
        
        while(p && q && r)
        {
            if(q->val != r->val)
            {
                p = q;
                q = r;
                r = r->next;
            }
            else
            {
                while(q && r && q->val == r->val)
                {
                    q = r;
                    r = r->next;
                }
                p->next = r;
                q->next = NULL;
                q = r;
                if(r)
                    r = r->next;
                else
                    r = NULL;
            }
        }
        
        return mark.next;
    }
};