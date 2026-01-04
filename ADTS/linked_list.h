#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H

#include<stdexcept>
#include<iostream>

// Represents the links/nodes in the linked list.
class Link{
public:
   Link *next = nullptr; // Next pointer, defaults to nullptr
   int value;          // Value

   Link(){}                   // Default Constructor
   Link(int v) : value(v){} // Build a new Link from v

   void* operator new(size_t sz);
   void operator delete(void* ptr);
};


//Iterator for our linked list
class LinkedListIterator{
public:
   Link* ptr = nullptr; // Points to the current link.

   int& operator*(){  // Dereference
        return ptr->value;
   };               
   LinkedListIterator& operator++(){   // Increment
        ptr = ptr->next;
        return *this;
   }; 

   bool operator !=(const LinkedListIterator& other){
       return ptr != other.ptr;
   }
};



// Our Linked List
class LinkedList{
public:
   Link* head = nullptr;

   LinkedList(){}
   ~LinkedList(){
        while (size() > 0){
            pop_back();
        }
   };

   void push_front(int t){
        Link *temp = new Link(t);
        temp->next = head;
        head = temp;
   };

   void pop_front(){
        Link *temp = head;
        head = head->next;
        delete temp;
   };

   void push_back(int t){
        Link *curr = head;
        if (head == nullptr){
            head = new Link(t);
        }else{
            while (curr->next != nullptr){
                curr = curr->next;
            }
            curr->next = new Link(t);
        }
   };
   void pop_back(){
        Link *curr = head;
        if (head->next == nullptr){
            delete head;
            head = nullptr;
        }else{
            while(curr->next->next != nullptr){
                curr = curr->next;
            }
            delete curr->next;
            curr->next = nullptr;
        }
   };

   size_t size(){
        size_t counter;
        Link *curr = head;
        while (curr != nullptr){
            curr = curr->next;
            ++counter;
        }
        return counter;
   };

   int& front(){
        return head->value;
   };
   int& back(){
        Link *curr = head;
        while (curr->next != nullptr){
            curr = curr->next;
        }
        return curr->value;
   };

   Link*  get_link(int i){
        int counter = 0;
        Link* curr = head;
        if (counter < 0){
            throw std::out_of_range("i out of bounds.");
        }else{
            while(counter < i){
                if (curr->next == nullptr){
                    throw std::out_of_range("i out of bounds.");
                }else{
                    curr = curr->next;
                }
                ++counter;
            }
            return curr;
        }
   };
   int& at(int i){
        int counter = 0;
        Link* curr = head;
        if (counter < 0){
            throw std::out_of_range("i out of bounds.");
        }else{
            while(counter < i){
                if (curr->next == nullptr){
                    throw std::out_of_range("i out of bounds.");
                }else{
                    curr = curr->next;
                }
                ++counter;
            }
            return curr->value;
        }
   };

   LinkedListIterator begin(){
        LinkedListIterator ptr;
        ptr.ptr = head;
        return ptr;
   };
   LinkedListIterator end(){
        LinkedListIterator ptr;
        ptr.ptr = nullptr;
        return ptr;
   };

   LinkedList *copy(){
        if (head == nullptr){   //empty list case
            return new LinkedList();
        }
        LinkedList* new_list = new LinkedList();
        //copy head
        new_list->head = new Link();
        new_list->head->value = head->value;

        Link *curr_old = head->next;
        Link *curr_new = new_list->head;

        while (curr_old != nullptr){
            curr_new->next = new Link();
            curr_new = curr_new->next;
            curr_new->value = curr_old->value;
            curr_old = curr_old->next;
        }

        curr_new->next = nullptr;
        return new_list;

   };
   
   void reverse(){
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        Link* curr = head;
        Link* temp;
        Link* prev = nullptr;
        while (curr != nullptr){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        head = prev;
   };
};

#endif // MYLINKEDLIST_H
