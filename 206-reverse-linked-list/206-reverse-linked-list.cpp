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
        stack<ListNode*> st;
        ListNode* cur = head;
        if(head==NULL) return head;
        while(cur!=NULL){
            st.push(cur);
            //cout<<st.top()->val<<"\n";
            cur=cur->next;
        }
        head=st.top();
        cur=st.top();
        st.pop();
        while(!st.empty()){
            cur->next =st.top(); 
            cur=cur->next;
            st.pop();
        }
        cur->next=NULL;
        return head;
    }
};