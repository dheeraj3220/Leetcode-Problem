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
    ListNode* add(ListNode*l1,ListNode*l2,int carry){
        if(l1==NULL && l2==NULL && carry==0) return NULL;
        int sum=carry;
        sum+=l1==NULL?0:l1->val;
        sum+=l2==NULL?0:l2->val;
        ListNode*newNode=new ListNode(sum%10);
        carry=sum/10;
        if(l1) l1=l1->next;
        if(l2) l2=l2->next;
        newNode->next=add(l1,l2,carry);
        return newNode;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1,l2,0);
    }
};