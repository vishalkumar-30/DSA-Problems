/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *temp=node, *ptr=node, *prev=NULL;
        int count=0;
        while(temp->next != NULL){
            count++;
            temp = temp->next;
        }
        for(int i=0; i<count; i++){
            ptr->val = ptr->next->val;
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next=NULL;
        delete ptr;
    }
};