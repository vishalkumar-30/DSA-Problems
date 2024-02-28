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
private:
    void insert(Node* head){
        Node* temp = head;
        while(temp){
            Node* curr = new Node(temp->val);
            curr->next = temp->next;
            temp->next = curr;
            temp = temp->next->next;
        }
        return ;
    }
    void connect(Node* head){
        Node* temp = head;
       
        while(temp){
            Node* latest = temp->next;
            if(temp->random) latest->random = temp->random->next;
            else latest->random = NULL;
            temp = temp->next->next;
            // latest = latest->next->next;
        }
        return ;
    }
    Node* copy(Node* head){
        Node* dummy = new Node(-1);
        Node* temp = dummy;
        Node* curr = head;
        // temp->next = head->next;
        while(curr){
            temp->next = curr->next;
            temp = temp->next;

            curr->next = curr->next->next;
            curr = curr->next;
        }
        return dummy->next;
    }
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return head;
        insert(head);
        connect(head);
        return copy(head);

    }
};