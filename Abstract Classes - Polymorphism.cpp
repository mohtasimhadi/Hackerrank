#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache : public Cache {
 public:
  LRUCache(int cp) {
    this->cp = cp;
    this->head = this->tail = nullptr;
  }

  void set(int k, int v) {
    auto it = mp.find(k);
    if (head == nullptr) {
      Node* n = new Node(k, v);
      head = tail = n;
      mp[k] = n;
    } else if (it != mp.end()) {
      Node* n = it->second;
      n->value = v;
      if (n != head) {
        if (n == tail) {
          tail = tail->next;
          tail->prev = nullptr;
        } else {
          n->prev->next = n->next;
          n->next->prev = n->prev;
        }
        head->next = n;
        n->prev = head;
        n->next = nullptr;
        head = n;
      }
    } else {
      if (mp.size() == cp) {
        Node* n = tail;
        tail->next->prev = nullptr;
        tail = tail->next;
        mp.erase(n->key);
        delete n;
      }
      Node* n = new Node(k, v);
      head->next = n;
      n->prev = head;
      head = n;
      mp[k] = n;
    }
  }

  int get(int k) {
    auto it = mp.find(k);
    if (it != mp.end()) {
      Node* n = it->second;
      if (n != head) {
        if (n == tail) {
          tail = tail->next;
          tail->prev = nullptr;
        } else {
          n->prev->next = n->next;
          n->next->prev = n->prev;
        }
        head->next = n;
        n->prev = head;
        n->next = nullptr;
        head = n;
      }
      return it->second->value;
    } else {
      return -1;
    }
  }
};


int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
