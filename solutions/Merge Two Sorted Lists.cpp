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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(l1 == NULL)
            return l2;
        else if(l2 == NULL)
            return l1;
            
        ListNode *ret = NULL;
        ListNode *p = NULL;
        if(l1->val <= l2->val)
        {
            p = l1;
            l1 = l1->next;
        }
        else
        {
            p = l2;
            l2 = l2->next;
        }
        p->next = NULL;
        ret = p;
        
        while(l1 || l2)
        {
            if(l1 == NULL)
            {
                p->next = l2;
                return ret;
            }
            else if(l2 == NULL)
            {
                p->next = l1;
                return ret;
            }
            else
            {
                if(l1->val <= l2->val)
                {
                    p->next = l1;
                    p = p->next;
                    l1 = l1->next;
                    p->next = NULL;
                }
                else
                {
                    p->next = l2;
                    p = p->next;
                    l2 = l2->next;
                    p->next = NULL;
                }
            }
        }
        return ret;
    }
};