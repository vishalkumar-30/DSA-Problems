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
    ListNode* rotateRight(ListNode* head, int k) {
        if (k==0 || !head || !head->next) return head;
        int cnt=1;
        ListNode* temp = head, *prev = head;
        while(temp->next){
            temp = temp->next;
            cnt++;
        }
        if(k>cnt) k = k%cnt;
        temp = head;
        while(temp->next){
            temp = temp->next;
            k--;
            if(k>=0) continue;
            prev = prev->next;
        }
        temp->next = head;
        head = prev->next;
        prev->next = NULL;
        if(k>0)return rotateRight(head, k);
        return head;
    }
};