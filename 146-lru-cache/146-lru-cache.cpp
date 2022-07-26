
    
class LRUCache {
public:
    class Listnode{
    public:
    pair<int,int> val;
    Listnode*next;
    Listnode*prev;
    Listnode(pair<int,int> value){
        val.first= value.first;
        val.second=value.second;
    }
};
    int cap;
    Listnode*head=new Listnode({-1,-1});
    Listnode*tail=new Listnode({-1,-1});
    unordered_map<int,Listnode*> mapp;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void deleteNode(Listnode*delnode){
        Listnode*delpre=delnode->prev;
            Listnode*delnext=delnode->next;
            delpre->next=delnext;
            delnext->prev=delpre;
    }
    void addNode(Listnode*newnode){
            Listnode*temp=head->next;
            newnode->next=temp;
            newnode->prev=head;
            head->next=newnode;
            temp->prev=newnode;
    }
    
    int get(int key) {
        if(mapp.count(key)==0) return -1;
        Listnode*temp=mapp[key];
        pair p=temp->val;
         mapp.erase(key);
        deleteNode(temp);
        addNode(temp);
        mapp[key]=head->next; 
        return p.second;
    }
    
    void put(int key, int value) {
        Listnode*newnode=new Listnode({key,value});
        if(mapp.count(key)==1){
            Listnode*temp=mapp[key];
            mapp.erase(key);
            deleteNode(temp);
        }
        if( mapp.size()==cap){
            Listnode*temp=tail->prev;
            mapp.erase(temp->val.first);
            deleteNode(temp);            
        }
        
           addNode(newnode);
            mapp[key]=head->next;  
    }
};

// class LRUCache {
//   public:
//     class node {
//       public:
//         int key;
//       int val;
//       node * next;
//       node * prev;
//       node(int _key, int _val) {
//         key = _key;
//         val = _val;
//       }
//     };

//   node * head = new node(-1, -1);
//   node * tail = new node(-1, -1);

//   int cap;
//   unordered_map < int, node * > m;

//   LRUCache(int capacity) {
//     cap = capacity;
//     head -> next = tail;
//     tail -> prev = head;
//   }

//   void addnode(node * newnode) {
//     node * temp = head -> next;
//     newnode -> next = temp;
//     newnode -> prev = head;
//     head -> next = newnode;
//     temp -> prev = newnode;
//   }

//   void deletenode(node * delnode) {
//     node * delprev = delnode -> prev;
//     node * delnext = delnode -> next;
//     delprev -> next = delnext;
//     delnext -> prev = delprev;
//   }

//   int get(int key_) {
//     if (m.find(key_) != m.end()) {
//       node * resnode = m[key_];
//       int res = resnode -> val;
//       m.erase(key_);
//       deletenode(resnode);
//       addnode(resnode);
//       m[key_] = head -> next;
//       return res;
//     }

//     return -1;
//   }

//   void put(int key_, int value) {
//     if (m.find(key_) != m.end()) {
//       node * existingnode = m[key_];
//       m.erase(key_);
//       deletenode(existingnode);
//     }
//     if (m.size() == cap) {
//       m.erase(tail -> prev -> key);
//       deletenode(tail -> prev);
//     }

//     addnode(new node(key_, value));
//     m[key_] = head -> next;
//   }
// };