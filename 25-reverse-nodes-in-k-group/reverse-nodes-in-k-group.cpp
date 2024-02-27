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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev = NULL, *first=head, *second=head, *temp=head;
        int cnt = 0;
        while(temp){
            temp=temp->next;
            cnt++;
        }
        if(k>cnt) return head;
        cnt=k;
        while(second && cnt){
            second = first->next;
            first->next=prev;
            prev = first;
            first = second;
            cnt--;
        }
        if(second) head->next = reverseKGroup(second, k);
        return prev;
    }
};