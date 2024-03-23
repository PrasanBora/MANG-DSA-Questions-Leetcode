class MyHashMap
{
    const int sz = 1000;
    struct Node 
    {
        int key ;
        int val;
        Node* next;
        
        Node( int k ,int v , Node* n = nullptr)
        {
            key = k;
            val = v;
            next = n;
        }
    };
    
    vector<Node* >mp;
    
public:
    MyHashMap() 
    {
        mp.resize(sz,nullptr);
    }
    
    int hash ( int key )
    {
        return key%sz;
    }
    
    void put(int key, int value) 
    {
        int index = hash(key);
        
        if( mp[index] == nullptr)
            mp[index] = new Node(key,value);
        else 
        {
           Node* current = mp[index];
           while( current->next != nullptr && current->key !=key)
           {
               current = current->next;
           }
            if( current->key == key )
                current->val = value;
            else 
                current->next = new Node(key,value); 
        }
    }
    
    int get(int key) 
    {
       int index = hash(key);
        Node * curr = mp[index];
        
        while( curr!=nullptr)
        {
            if(curr->key == key )
                return curr->val;
            
            curr = curr->next;
        }
        return -1;
    }
    
    void remove(int key) 
    {
       int index = hash(key);
        Node* curr = mp[index];
        Node * prev =nullptr;
        
        while(curr!=nullptr)
        {
            if( curr->key == key )
            {
                if(prev)
                    prev->next = curr->next;
                else 
                    mp[index] = curr->next;
            }
            prev = curr ;
            curr =curr->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */