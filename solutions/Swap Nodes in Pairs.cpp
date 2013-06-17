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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // for the first node
        if(head == NULL || head->next == NULL)
            return head;
            
        ListNode *ret = NULL;
        ListNode *p1 = head;
        ListNode *p2 = head->next;
        ListNode *start = NULL;
        if(p1 && p2)
        {
            p1->next = p2->next;
            p2->next = p1;
            start = p1;
            ret = p2;
        }
        while(start->next)
        {
            p1 = start->next;
            p2 = p1->next;
            if(p1 && p2)
            {
                p1->next = p2->next;
                p2->next = p1;
                start->next = p2;
                start = p1;
            }
            else
                return ret;
        }
        return ret;
    }
};