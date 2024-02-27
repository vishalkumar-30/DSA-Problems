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
    ListNode* reverseList(ListNode* head){
        ListNode* curr=head, *prev=NULL, *future=head;
        while(curr){
            future = curr->next;
            curr->next = prev;
            prev = curr;
            curr = future;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        
        ListNode *s=head, *f=head;
        while(f->next && f->next->next ){
            s=s->next;
            f=f->next->next;
        }
        ListNode* newList = reverseList(s->next);
        ListNode *first=head, *second = newList;
        while(second){
            if(first->val != second->val){
                newList = reverseList(newList);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        newList = reverseList(newList);
        return true;
    }
};