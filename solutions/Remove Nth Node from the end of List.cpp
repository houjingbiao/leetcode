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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        ListNode *p = head;
        int count = 0;
        while(p)
        {
            count++;
            p = p->next;
        }
        if(count == 0)
            return head;
        
        n = count - n;
        if(n == 0)
            return head->next;
        p = head;
        ListNode* q = head->next;
        int i = 1;
        while(p&&q && i < n)
        {
            i++;
            p = q;
            q = q->next;
        }
        if(i == n)
        {
            p->next = q->next;
            q->next = NULL;
        }
        return head;
    }
};