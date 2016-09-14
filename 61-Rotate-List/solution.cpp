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
    int link_size(ListNode* head)
    {
        int res = 0;
        while (head)
        {
            head=head->next;
            res++;
        }
        return res;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *p = head, *q, *r = NULL;
        int len = link_size(head);
        
        if (len)
        {
            k %= len;
        }
        
        
        for(int i=0; i<k && p; i++)
        {
            if (p->next)
            {
                p = p->next;
            }
            else
            {
                p = head;
            }
        }
        if (p)
        {
            q = head;
            while(p->next)
            {
                p = p->next;
                q = q->next;
            }
            if (p!=q)
            {
                r = q->next;
                q->next = NULL;
                p->next = head;
            }
            else
            {
                r = head;
            }
        }
        return r;
    }
};