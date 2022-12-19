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
    ListNode* reverse(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* a = reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return a;
    }
    
    void reorderList(ListNode* head) 
    {
        if(head==NULL)
            return;
        if(head->next==NULL)
            return;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* rev =reverse(slow->next);
        slow->next=NULL;
        ListNode* temp=head;
        ListNode* t2=NULL;
        while(temp && rev)
        {
            ListNode* t1=temp->next;
            temp->next=rev;
            t2=rev;
            temp=t1;
            rev=rev->next;
            t2->next=t1;
            t2=t2->next;
        }
        if(rev!=NULL)
            t2->next=rev; 
    }
};