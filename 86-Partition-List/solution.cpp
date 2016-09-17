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
    ListNode* partition(ListNode* head, int x) {
        ListNode *firstStart = NULL, *first = NULL, *secondStart = NULL, *second = NULL, *ptr = head;
        
        while (ptr)
        {
            if (ptr->val < x)
            {
                if (NULL == firstStart)
                {
                    firstStart = first = ptr; 
                }
                else
                {
                    first->next = ptr;
                    first = ptr;
                }
                
            }
            else
            {
                if (NULL == secondStart)
                {
                    secondStart = second = ptr; 
                }
                else
                {
                    second->next = ptr;
                    second = ptr;
                }                
                
            }
            ptr = ptr->next;
        }
        if (first)
            first->next = secondStart;
            
        if (second)
            second->next = NULL;
        return firstStart ? firstStart : secondStart;
    }
};