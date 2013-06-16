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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(m == n || head == NULL)
            return head;
        ListNode *start = NULL;
        ListNode *end = NULL;
        ListNode *p = NULL;
        ListNode *p0 = NULL;
        ListNode *p1 = NULL;
        ListNode *q = NULL;
        for(int i = 1; i <= n; i++)
        {
            if(i == 1)
            {
                p = NULL;
                q = head;
            }
            
            if(i == m-1)
                start = q;
            
            p = q;
            q = q->next;
                
            if(i == m)
            {
                if(start)
                    start->next = NULL;
                p0 = p;
                p1 = p;
            }
            
            if(i > m)
            {
                p->next = p0;
                p0 = p;
            }
            
            if(i == n)
                end = q;
        }
        if(start == NULL)
            head = p0;
        else
            start->next = p0;
        p1->next = end;
        return head;
    }
};