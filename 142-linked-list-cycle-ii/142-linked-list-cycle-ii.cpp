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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL) return head;
        ListNode*slow=head;
        ListNode*fast=head;
        do{
            slow=slow->next;
            if(fast!=NULL && fast->next!=NULL) fast=fast->next->next;
            else return NULL;
        }while(fast!=slow);
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
        
        
    }
};