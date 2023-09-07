class Solution {
    private:
        ListNode* reverseList(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        // Recursive call
        ListNode* rest = reverseList(head->next);
        head->next->next = head;
        
        head->next = NULL;
 
        return rest;
    } 
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode*init=new ListNode(0);
        init->next=head;
        ListNode* start=head;
        ListNode* end=NULL, *prev=init;
        int pos=1;
        while(start && pos!=left){
            prev=start;
            start=start->next;
            pos++;
        }
        end=start;
        pos=0;
        while(end && pos<right-left){
            end=end->next;
            pos++;
        }
        if(!end) return init->next;
        ListNode* tempEnd = end->next;
        end->next=NULL;
        ListNode* temp = reverseList(start);
        prev->next=temp;
        start->next = tempEnd;
        return init->next;
    }
};
