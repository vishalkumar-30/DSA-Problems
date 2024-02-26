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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow=head, *fast=head;
        while(n){
            fast = fast->next;
            n--;
            // if(fast == NULL) break;
        } 
        if(fast == NULL) {
            ListNode *deleteNode = head;
            head = head->next;
            delete(deleteNode);
            return head;
        }
        while(fast->next!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *deleteNode = slow->next;
        slow->next = slow->next->next;
        delete(deleteNode);
        return head;
    }
};
