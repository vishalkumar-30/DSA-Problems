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
        if (head == NULL) {
            return NULL;
        }
        ListNode* point = head->next;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(point != NULL){
            point = curr->next;
            curr->next = prev;
            prev = curr;
            curr = point;
        }

        return prev==NULL?head:prev;
    }
};