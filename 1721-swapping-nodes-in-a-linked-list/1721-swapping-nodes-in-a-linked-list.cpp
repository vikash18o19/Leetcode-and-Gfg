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
    ListNode* swapNodes(ListNode* head, int k) {
        int count = 0;
        deque<ListNode*> q;
        ListNode* cur = head;
        ListNode* first;
        ListNode* sec;
        while(cur!=NULL){
            count++;
            if(count==k){
                first = cur;
            }
            q.push_back(cur);
            cur=cur->next;
        }
        count =1;
        while(count!=k){
            q.pop_back();
            count++;
        }
        sec = q.back();
        int temp = sec->val;
        sec->val = first->val;
        first->val = temp;
        return head;
        
    }
};