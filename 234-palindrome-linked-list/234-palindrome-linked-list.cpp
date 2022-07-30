
// class Solution {
// public:
//     ListNode* reverse(ListNode*head){
//         if(head==NULL || head->next==NULL) return head;
//         ListNode*smallans=reverse(head->next);
//         ListNode*temp=head->next;
//         head->next=head;
//         head->next=NULL;
//         return smallans;
//     }
//     bool isPalindrome(ListNode* head) {
//         ListNode*slow=head;
//         ListNode*fast=head;
//         while(fast!=NULL && fast->next!=NULL) {
//             slow=slow->next;
//             fast=fast->next;
//             if(fast) fast=fast->next;
//         }
//         ListNode*head2=slow;
//         head2=reverse(head2);
//         while(head!=NULL && head2!=NULL){
//             if(head->val!=head2->val) return false; 
//                 head=head->next;
//                 head2=head2->next;
//         }
//         return true;
        
//     }
// };
class Solution {
public:
    ListNode* findMid(ListNode* head){
        ListNode* slow=head,*fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
            if(fast) fast=fast->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head){
        ListNode* prev=NULL,*curr=head,*temp=NULL;
        while(curr != NULL){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    bool compareList(ListNode* head1, ListNode* head2){
        while(head1!=NULL && head2!=NULL){
            if(head1->val != head2->val) return false;
            head1=head1->next;
            head2=head2->next;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;
        ListNode* h=head;
        ListNode* mid = findMid(h);
        ListNode* h2=reverseList(mid);
        return compareList(head,h2);
    }
};