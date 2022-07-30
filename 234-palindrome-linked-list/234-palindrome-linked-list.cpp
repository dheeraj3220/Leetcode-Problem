class Solution {
public:
    ListNode* reverse(ListNode*head){
        if(head==NULL || head->next==NULL) return head;
        ListNode*smallans=reverse(head->next);
        ListNode*temp=head->next;
        temp->next=head;
        head->next=NULL;
        return smallans;
    }
    bool isPalindrome(ListNode* head) {
        ListNode*slow=head;
        ListNode*fast=head->next;
        while(fast!=NULL && fast->next!=NULL) {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*head2=slow->next;
        slow->next=NULL;
        head2=reverse(head2);
        while(head!=NULL && head2!=NULL){
            if(head->val==head2->val) {
                head=head->next;
                head2=head2->next;
            }
            else
                return false;
        }
        return true;
        
    }
};