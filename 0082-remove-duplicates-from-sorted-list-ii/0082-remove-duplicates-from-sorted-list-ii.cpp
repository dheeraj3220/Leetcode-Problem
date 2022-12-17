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
    ListNode* deleteDuplicates(ListNode* head,int prev=-101) {
        if(head==NULL) return head;
        if(prev==head->val || ((head->next) && head->val==head->next->val)){
            return deleteDuplicates(head->next,head->val);
        }
        else{
            head->next=deleteDuplicates(head->next,head->val);
            return head;
        }
    }
};