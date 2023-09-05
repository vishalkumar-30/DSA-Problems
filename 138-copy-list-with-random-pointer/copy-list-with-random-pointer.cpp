/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* itr=head;
        Node* fr=head;
        while(itr!=NULL){
            fr = itr->next;
            Node* copy = new Node(itr->val);
            itr->next = copy;
            copy->next = fr;
            itr = fr;
        }

        itr = head;
        while(itr){
            if(itr->random) itr->next->random = itr->random->next;
            itr = itr->next->next;
        }

        itr = head;
        Node* dumy = new Node(0);
        Node* copy = dumy;
        while(itr){
            fr=itr->next->next;
            copy->next = itr->next;
            itr->next = fr;
            copy = copy->next;
            itr = fr;
        }
        return dumy->next;
    }
};