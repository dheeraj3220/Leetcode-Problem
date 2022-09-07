/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode*dummy=NULL;
        ListNode*nextPtr=head->next;
        while(head!=NULL){
            head->next=dummy;
            dummy=head;
            head=nextPtr;
           if(head!=NULL) nextPtr=head->next;
        }
        return dummy;
    }
};