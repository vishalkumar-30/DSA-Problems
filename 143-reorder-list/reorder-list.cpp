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
private:
    ListNode* ReverseList(ListNode *head)
    {
        ListNode *p = head;
        ListNode *q = NULL;
        ListNode *r = NULL;
        while(p)
        {
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        head = q;
        return head;
    }
public:
    void reorderList(ListNode* head) {
        if(head == NULL || head->next==NULL) return;
        ListNode *slow=head, *fast=head, *prev=head;
        while(fast && fast->next)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=NULL;
        ListNode *l1=head, *l2=ReverseList(slow);
        while(l1 && l2){
            ListNode *L=l1->next;
            l1->next = l2;
            l1=l2;
            l2=L;
        }
    }
};