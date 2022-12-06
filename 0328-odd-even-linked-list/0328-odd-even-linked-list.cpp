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
    ListNode* oddEvenList(ListNode* head) {
        ListNode*odd=NULL,*even=NULL,*temp=head,*oddHead=NULL,*evenHead=NULL;
        int count=1;
        while(temp){
            if(count%2==0){
                if(even==NULL){
                    evenHead=temp;
                    even=temp;
                }
                else{
                    even->next=temp;
                    even=even->next;
                    // even->next=NULL;
                }
            }
            else{
                if(odd==NULL) {
                    oddHead=temp;
                    odd=temp;
                }
                else{
                    odd->next=temp;
                    odd=odd->next;
                    // odd->next=NULL;
                }
            }
            count++;
            temp=temp->next;
        }
        if(odd) odd->next=NULL;
        if(even) even->next=NULL;
        if(oddHead) odd->next=evenHead;
        else return evenHead;
        return oddHead;
    }
};