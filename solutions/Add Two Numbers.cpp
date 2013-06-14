/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution2 {
public:
    int getListLen(ListNode *l1)
    {
        int count = 0;
        while(l1 != NULL)
        {
            count++;
            l1 = l1->next;
        }
        return count;
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        int len1 = getListLen(l1);
        int len2 = getListLen(l2);
        
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        if(len2 > len1)
        {
            p1 = l2;
            p2 = l1;
        }
        ListNode *ret = p1;
        
        int sum = 0;
        while(p1 || p2)
        {
            sum = sum + p1->val + (p2?p2->val:0);
            p1->val = sum%10;
            sum = sum >= 10? 1 : 0;
             
            p1 = p1->next;
            p2 = p2?p2->next:NULL;
        }

        if(sum == 1)
        {
            ListNode *newP = new ListNode(sum);
            p1 = ret;
            while(p1->next)
                p1 = p1->next;
            p1->next = newP;
        }
        
        return ret;
    }
};