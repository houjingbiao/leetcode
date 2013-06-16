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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL || k == 0)
            return head;
        int count = 0;
        ListNode *p = head;
        while(p)
        {
            count++;
            p = p->next;
        }
        
        k = k%count;
        k = count - k;
        if(k == 0)
            return head;
        p = head;
        for(int i = 0; i < k; i++)
        {
            if(i == 0)
                p = head;
            else
                p = p->next;
        }
        
        ListNode *q = p->next;
        if(q == NULL)
            return head;
        ListNode *ret = q;
        while(q->next)
            q = q->next;
        q->next = head;
        p->next = NULL;
        return ret;
    }
};