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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(head == NULL) return head;
		ListNode *head_small = NULL;
		ListNode *head_large = NULL;
		ListNode *tail_small = NULL;
		ListNode *tail_large = NULL;
		ListNode *p = head;
		while(p){
			if(p->val >= x){
				while(p->next && p->next->val >= x)
					p = p->next;
				if(head_large == NULL)
					head_large = head;
				else
					tail_large->next = head;
					head = p->next;
				tail_large = p;
				p->next = NULL;
				p = head;
			}
			else{
				while(p->next && p->next->val < x)
					p = p->next;
				if(head_small == NULL)
					head_small = head;
				else
					tail_small->next = head;
				tail_small = p;
				head = p->next;
				p->next = NULL;
				p = head;
			}
		}
		if(head_small){
			tail_small->next = head_large;
			return head_small;
		}
		else
			return head_large;
    }
};