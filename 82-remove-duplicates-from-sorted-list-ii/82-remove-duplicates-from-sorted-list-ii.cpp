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
    
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return head;
        unordered_map<int,int> mp;
        ListNode* cur = head;
        ListNode temp;
        temp.next = head;
        ListNode* prev = &temp;
        unordered_map<int,int> m;
        while(cur!=NULL){
            if(mp.find(cur->val)!=mp.end()){
                m[cur->val]++;
                prev->next=cur->next;
                cur=cur->next;
                //prev=prev->next;
            }
            else{
                mp[cur->val]++;
                cur=cur->next;
                prev=prev->next;
            }
            
        }
        
        prev=&temp;
        cur=head;
        
        while(cur!=NULL){
            if(m.find(cur->val)!=m.end()){
                m[cur->val]++;
                prev->next=cur->next;
                cur=cur->next;
            }
            else{
                cur=cur->next;
                prev=prev->next;
            }
            
        }
        if(m.find(head->val)!=m.end()){
            return temp.next;
        }
        return head;
    }
};