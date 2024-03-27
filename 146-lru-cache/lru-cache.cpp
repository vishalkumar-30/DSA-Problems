class LRUCache {
public:
    class doublylist{
        public:
        int key;
        int val;
        doublylist *right;
        doublylist *left;
        doublylist(int key, int val){
            this->key = key;
            this->val = val;
        }
    };

    doublylist *head = new doublylist(-1, -1);
    doublylist *tail = new doublylist(-1, -1);
    unordered_map<int, doublylist*>mp;
    int cap;

    void addnode(doublylist *node){
        doublylist *temp = head->right;
        node->right = temp;
        node->left = head;
        head->right = node;
        temp->left = node;
    }

    void deletenode(doublylist *node){
        doublylist * delprev = node->left;
        doublylist * delnext = node->right;
        delprev->right = delnext;
        delnext->left = delprev;
    }

    LRUCache(int capacity) {
        cap = capacity;
        head->right = tail;
        tail->left = head;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            doublylist *resnode = mp[key];
            int res = resnode->val;
            mp.erase(key);
            deletenode(resnode);
            addnode(resnode);
            mp[key] = head->right;
            return res;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
          doublylist * existingnode = mp[key];
          mp.erase(key);
          deletenode(existingnode);
        }
        if(mp.size() == cap){
            mp.erase(tail->left->key);
            deletenode(tail->left);
        }
        addnode(new doublylist(key, value));
        mp[key] = head->right;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */