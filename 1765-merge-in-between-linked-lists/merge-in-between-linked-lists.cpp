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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* left = NULL;
        ListNode* first = list1;
        ListNode *p = NULL;
        for(int i=0; i<=b; i++){
            if(a-1 == i) left=first;
            p=first;
            first = first->next;
        }
        ListNode *del = left->next;
        p->next = NULL;
        left->next = list2;
        ListNode* curr = list2;
        while(curr->next!=NULL){
            curr = curr->next;
        }
        curr->next = first;
        delete(del);
        return list1;
    }
};