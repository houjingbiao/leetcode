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
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode mark(0);
        mark.next = head;
        
        int count = 0;
        ListNode *start = &mark;
        ListNode *p = head;
        while(p)
        {
            count++;
            if(count == k)
            {
                ListNode *q = start->next;
				start->next = p;
                start = q;
                ListNode* r = p->next;
                while(q != p)
                {
                    ListNode* s = q->next;
                    q->next = r;
                    r = q;
                    q = s;
                }
				p = p->next;
				q->next = r;
                count = 0;
            }
			else
				p = p->next;
        }
        return mark.next;
    }
};