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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        ListNode *pt1=headA, *pt2=headB;
        while(pt1 != pt2){
            pt1 = pt1==NULL? headB:pt1->next;
            pt2 = pt2==NULL? headA:pt2->next;
        }
        return pt1;
    }
};