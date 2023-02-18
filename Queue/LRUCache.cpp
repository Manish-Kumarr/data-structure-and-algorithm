#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
    private:
        int cacheSize;
        unordered_map<int,int> umap;
        queue<int> q;
        
        queue<int> remove_key(queue<int> q, int key){
            queue<int> new_q;
            while (!q.empty()) {
                int front = q.front();
                q.pop();
                if (front != key)
                    new_q.push(front);
            }
            return new_q;
        }
    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        cacheSize = cap;
    }
    
    //Function to return value corresponding to the key.
    int GET(int key)
    {
        // your code here
        int x = -1;
        if(umap.find(key) == umap.end())
            return x;
        x = umap[key];
        q = remove_key(q,key);
        q.push(key);
        return x;
    }

    // Function for storing key-value pair.
    void SET(int key, int value)
    {
        if(umap.find(key) == umap.end()){
            if(umap.size() == cacheSize){
                int old = q.front();
                q.pop();
                umap.erase(old);
            }
        }else //agr key mil gyi remove that key and push back
            q = remove_key(q,key);
        
        //it will run in all case
        //key nhi mili jgh khali h, key mil gyi, 
        //key mil gyi jgh khali nhi h
        q.push(key);
        umap[key] = value;
    }
};


//Using DLL
class CacheNode
{
public:
    int key;
    int value;
    CacheNode *prev;
    CacheNode *next;
    CacheNode(int key, int value)
    {
        this->key = key;
        this->value = value;
        prev = next = NULL;
    }
};

class LRUCache
{
private:
    int capacity;
    unordered_map<int, CacheNode *> umap;
    CacheNode *head;
    CacheNode *tail;

    void add_to_front(CacheNode *node)
    {
        if (head == NULL)
        {
            head = node;
            tail = node;
        }
        else
        {
            head->prev = node;
            node->next = head;
            head = node;
        }
    }

    void move_to_front(CacheNode *node)
    {
        if (node == head)
            return;
        if (node == tail)
            tail = tail->prev;
        if (node->prev)
            node->prev->next = node->next;
        if (node->next)
            node->next->prev = node->prev;
        node->prev = NULL;
        node->next = head;
        head->prev = node;
        head = node;
    }

    void removeLRU()
    {
        if (tail)
        {
            umap.erase(tail->key);
            if (tail == head)
            {
                head = NULL;
                tail = NULL;
            }
            else
            {
                tail = tail->prev;
                delete tail->next;
                tail->next = NULL;
            }
        }
    }

public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        capacity = cap;
        head = tail = NULL;
    }

    // Function to return value corresponding to the key.
    int GET(int key)
    {
        // your code here
        if (umap.find(key) == umap.end())
            return -1;
        CacheNode *node = umap[key];
        move_to_front(node);
        return node->value;
    }

    // Function for storing key-value pair.
    void SET(int key, int value)
    {
        if (umap.find(key) == umap.end())
        {
            if (umap.size() == capacity)
                removeLRU();
            CacheNode *node = new CacheNode(key, value);
            add_to_front(node);
            umap[key] = node;
        }
        CacheNode *node = umap[key];
        node->value = value;
        move_to_front(node);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}