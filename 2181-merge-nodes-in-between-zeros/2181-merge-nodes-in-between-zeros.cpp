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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head->next;
        ListNode* cur = head->next;
        head=cur;
        while(true){
            while(temp->val!=0){
                if(temp!=cur){
                    cur->val=cur->val+temp->val;
                }
                temp=temp->next;
            }
            temp=temp->next;
            if(temp==NULL){
                cur->next=NULL;
                break;
            }
            else{
                cur->next=temp;
                cur=cur->next;
            }
        }
        return head;
    }
};