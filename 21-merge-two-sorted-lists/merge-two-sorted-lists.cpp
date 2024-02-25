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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* p1 = list1, *p2 = list2;
        ListNode* res = new ListNode(-1);
        ListNode* p3 = res;
        while(p1!=NULL && p2!=NULL){
            if(p1->val<p2->val){
                p3->next = p1;
                p1=p1->next;
            }
            else{
                p3->next = p2;
                p2=p2->next;
            }
            p3=p3->next;
        }
        if(p1){
            p3->next=p1;
        }
        if(p2){
            p3->next=p2;
        }
        return res->next;
    }
};