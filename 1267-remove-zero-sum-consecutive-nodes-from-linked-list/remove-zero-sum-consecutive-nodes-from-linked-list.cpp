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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> mp;
        int sum = 0;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        mp[0] = dummy;
        ListNode* curr = dummy->next;
        while(curr){
            sum += curr->val;
            if(mp.find(sum) != mp.end()){
                ListNode* prev = mp[sum];
                ListNode* temp = prev->next;
                int total = sum;
                while(temp != curr){
                    total += temp->val;
                    mp.erase(total);
                    temp = temp->next;
                }
                prev->next = curr->next;
                curr = prev;
            }
            else{
                mp[sum] = curr;
            }
            curr = curr->next;
        }
        ListNode* res = dummy->next;
        delete(dummy);
        return res;
    }
};
