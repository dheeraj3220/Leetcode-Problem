
    
class LRUCache {
public:
    class Listnode{
    public:
    int key;
    int val;
    Listnode*next;
    Listnode*prev;
    Listnode(int key,int val){
        this->key= key;
        this->val=val;
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
        int p=temp->val;
         mapp.erase(key);
        deleteNode(temp);
        addNode(temp);
        mapp[key]=head->next; 
        return p;
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
            mapp.erase(temp->key);
            deleteNode(temp);            
        }
        
           addNode(newnode);
            mapp[key]=head->next;  
    }
};
