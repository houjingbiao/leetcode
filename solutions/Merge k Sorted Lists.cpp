bool myfunction (ListNode *i, ListNode* j) { return (i->val<j->val); }
class Solution {
public:
    void clearNULL(vector<ListNode *> &lists)
    {
        vector<ListNode *>::iterator it = lists.begin();
        for(; it != lists.end(); )
        {
            if(*it == NULL)
                it = lists.erase(it);
            else
                it++;
        }
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        clearNULL(lists);
        if(lists.size() == 0)
            return NULL;
        else if(lists.size() == 1)
            return (*lists.begin());

        sort(lists.begin(), lists.end(), myfunction);
        ListNode *head = *(lists.begin());
		ListNode *p = NULL;
        while(lists.size())
        {
			if(p == NULL)
				p = (*lists.begin());
			else
			{
				p->next = (*lists.begin());
				p = p->next;
			}
			ListNode *q = p->next;
			lists.erase(lists.begin());
            if( q != NULL)
            {
                vector<ListNode*>::iterator it = lists.begin();
                while(it != lists.end() &&  q->val > (*it)->val)
                    it++;
                lists.insert(it, q);
            }
			p->next = NULL;
        }
        return head;
    }
};