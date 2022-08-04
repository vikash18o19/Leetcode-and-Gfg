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
    ListNode* middleNode(ListNode* head) {
        if(head->next==NULL){
            return head;
        }
        int count =0;
        ListNode* cur = head;
        while(cur!=NULL){
            count++;
            cur= cur->next;
        }
        //int val = (count%2!=0)?(count/2):(count/2)+1;
        int val = count/2;
        count = 0;
        while(head!=NULL){
            count++;
            head=head->next;
            if(count==val) break;
        }
        return head;
    }
};