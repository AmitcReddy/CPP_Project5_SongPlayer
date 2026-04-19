/*****************************************
** File:    Queue.cpp
** Project: CMSC 202 Project 5, Fall 2025
** Author:  Amit Reddy
** Date:    11/18/2025
** Section: 32
** Email:   amitr2@@umbc.edu
**
** Description:
** Implements templated Queue class using linked list
*****************************************/                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      

#ifndef QUEUE_CPP
#define QUEUE_CPP
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Templated linked list                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
//Note: Because the linked list is a templated class,                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
//      there is only ONE file (Queue.cpp)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                

//Templated node class                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
template <class T>
class Node {
public:
  Node( const T& data ); //Constructor                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
  T GetData(); //Gets data from node                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
  void SetData( const T& data ); //Sets data in node                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
  Node<T>* GetNext(); //Gets next pointer                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
  void SetNext( Node<T>* next ); //Sets next pointer                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
private:
  T m_data;
  Node<T>* m_next;
};

//Overloaded constructor for Node                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
template <class T>
Node<T>::Node( const T& data ) {
   m_data = data;
   m_next = nullptr;
}

template <class T>
T Node<T>::GetData() {
  return m_data;
}

//Sets the data in a Node                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
template <class T>
void Node<T>::SetData( const T& data ) {
   m_data = data;
}

//Gets the pointer to the next Node                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
template <class T>
Node<T>* Node<T>::GetNext() {
   return m_next;
}

//Sets the next Node                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
template <class T>
void Node<T>::SetNext( Node<T>* next ) {
   m_next = next;
}

template <class T>
class Queue {
 public:
  // Name: Queue() Queue from a linked list - Default Constructor                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
  // Desc: Used to build a new linked queue (as a linked list)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
  // Preconditions: None                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
  // Postconditions: Creates a new queue where m_head and m_tail                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
  //                 point to nullptr and m_size = 0                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
  Queue();
  // Name: ~Queue() - Destructor                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
  // Desc: Used to destruct a Queue                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
  // Preconditions: There is a Queue                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
  // Postconditions: Queue is deallocated (including dynamically allocated nodes)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
  //                 Can just call Clear()                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
 ~Queue();
  // Name: Queue (Copy Constructor)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
  // Preconditions: Creates a copy of existing Queue in separate memory                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
  //                address (deep copy)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
  //                Requires one already existing Queue                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
  // Postconditions: Copy of existing Queue                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
  Queue(const Queue&);
  // Name: operator= (Overloaded Assignment Operator)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
  // Preconditions: When two Queue objects exist, sets one to equal another                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
  //                Requires two Queue objects                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
  // Postconditions: When completed, you have two Queues in                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
  //                 separate memory addresses with the same                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
  //                 number of nodes with the same values in each node                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
  Queue<T>& operator= (Queue&);
  // Name: PushBack                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
  // Preconditions: Takes in data. Creates new node.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
  //                Requires a Queue                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
  // Postconditions: Adds a new node to the end of the Queue.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
  void PushBack(const T&);
  // Name: PopFront                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
  // Preconditions: Queue with at least one node.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
  // Postconditions: Removes first node in the queue and                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
  //                 returns the data in the first node                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
  T PopFront();
  // Name: Display                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
  // Preconditions: Outputs the queue.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
  // Postconditions: Displays the data in each node of queue                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
  // Required (used only for queue testing)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
  void Display();
  // Name: Front                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
  // Preconditions: Requires a Queue with at least one node                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
  // Postconditions: Returns whatever data is pointed at by m_head -                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
  //                 Does NOT remove node                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
  T Front();
  // Name: IsEmpty                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
  // Preconditions: Requires a queue                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
  // Postconditions: Returns if the queue is empty.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
  bool IsEmpty();
  // Name: GetSize                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
  // Preconditions: Requires a queue                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
  // Postconditions: Returns m_size                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
  int GetSize();
  // Name: Find()                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
  // Preconditions: Requires a queue                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
  // Postconditions: Iterates and if it finds the thing, returns index, else -1                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
  int Find(T);
  // Name: Clear                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
  // Preconditions: Requires a queue                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
  // Postconditions: Deallocates and removes all nodes in a queue. No memory leaks                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
  void Clear();
  // Name: At                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
  // Precondition: Existing Queue                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
  // Postcondition: Returns object from Queue at a specific location                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
  // Desc: Iterates to node x and returns data from Queue                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
  T At (int x);
  // Name: Swap(int)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
  // Preconditions: Requires a queue                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
  // Postconditions: Swaps the nodes at the index with the node prior to it.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
  // Example: Swap(1) would swap the node 0 with node 1 so                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
  //          that node 1 would now be m_head                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
  // Desc: Swaps two nodes by updating the pointers (not just the value)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
  // Hint: Think about the special cases! Implement before Sort                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
  void Swap(int);
  // Name: Sort()                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
  // Preconditions: Requires a queue with a minimum of 2 nodes                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
  //                (otherwise notifies user)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
  // Postconditions: Sorts the Queue (uses overloaded <).                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
  // Desc: This is used to sort anything in the Queue assuming the                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
  //       < is overloaded                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
  //       Uses bubble sort and Swap function above.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
  //       Ensure working with queue_test before rest of project.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
  void Sort();
private:
  Node <T> *m_head; //Node pointer for the head                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
  Node <T> *m_tail; //Node pointer for the tail                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
  int m_size; //Number of nodes in queue                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
};

//**********Implement Queue Class Here***********
//**********All Functions Are Required Even If Not Used for Project**************
//**********No references to anything from Song/SongPlayer here*****************

//-------------------------------------------------------
// Name: Queue (Default Constructor)
// Desc: Initializes empty Queue 
//-------------------------------------------------------
template <class T>
Queue<T>::Queue() {
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
}

//-------------------------------------------------------
// Name: ~Queue (Destructor)
// Desc: Deallocates Queue by calling Clear()
//-------------------------------------------------------
template <class T>
Queue<T>::~Queue() {
    Clear();
}

//-------------------------------------------------------
// Name: Queue (Copy Constructor)
// Desc: copies another Queue object
//-------------------------------------------------------
template <class T>
Queue<T>::Queue(const Queue<T>& source) {
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;

    // Iterate through source and push data
    Node<T>* curr = source.m_head;
    while (curr != nullptr) {
        PushBack(curr->GetData());
        curr = curr->GetNext();
    }
}

//-------------------------------------------------------
// Name: operator=
// Desc: Assignment operator deep copies another Queue
//-------------------------------------------------------
template <class T>
Queue<T>& Queue<T>::operator=(Queue<T>& source) {
    if (this != &source) {
        Clear();
        Node<T>* curr = source.m_head;
        while (curr != nullptr) {
            PushBack(curr->GetData());
            curr = curr->GetNext();
        }
    }
    return *this;
}

//-------------------------------------------------------
// Name: PushBack
// Desc: Adds a new node containing data to the end
//-------------------------------------------------------
template <class T>
void Queue<T>::PushBack(const T& data) {
    Node<T>* newNode = new Node<T>(data);

    if (m_head == nullptr) {          
        m_head = newNode;
        m_tail = newNode;
    } else {                           
        m_tail->SetNext(newNode);
        m_tail = newNode;
    }
    m_size++;
}

//-------------------------------------------------------
// Name: PopFront
// Desc: Removes and returns front node's data
//-------------------------------------------------------
template <class T>
T Queue<T>::PopFront() {
    if (IsEmpty()) {
        return T(); // Return default value
    }

    Node<T>* temp = m_head;
    T data = temp->GetData();
    m_head = m_head->GetNext();
    delete temp;
    m_size--;

    if (m_size == 0) {
        m_tail = nullptr;
    }

    return data;
}

//-------------------------------------------------------
// Name: Display
// Desc: Displays all data in queue (used for testing)
//-------------------------------------------------------
template <class T>
void Queue<T>::Display() {
    Node<T>* curr = m_head;
    while (curr != nullptr) {
        cout << curr->GetData() << endl;
        curr = curr->GetNext();
    }
}

//-------------------------------------------------------
// Name: Front
// Desc: Returns front data WITHOUT removing the node
//-------------------------------------------------------
template <class T>
T Queue<T>::Front() {
    return m_head->GetData();
}

//-------------------------------------------------------
// Name: IsEmpty
// Desc: Returns true if queue has no nodes
//-------------------------------------------------------
template <class T>
bool Queue<T>::IsEmpty() {
    return (m_size == 0);
}

//-------------------------------------------------------
// Name: GetSize
// Desc: Returns number of nodes in queue
//-------------------------------------------------------
template <class T>
int Queue<T>::GetSize() {
    return m_size;
}

//-------------------------------------------------------
// Name: Clear
// Desc: Removes all nodes and avoids memory leaks
//-------------------------------------------------------
template <class T>
void Queue<T>::Clear() {
    while (!IsEmpty()) {
        PopFront();
    }
}

//-------------------------------------------------------
// Name: At
// Desc: Returns data at a specific index in queue
//-------------------------------------------------------
template <class T>
T Queue<T>::At(int x) {
    if (x < 0 || x >= m_size) {
        return T(); // invalid index
    }

    Node<T>* curr = m_head;
    for (int i = 0; i < x; i++) {
        curr = curr->GetNext();
    }
    return curr->GetData();
}

//-------------------------------------------------------
// Name: Find
// Desc: Returns index of matching item, -1 if not found
//-------------------------------------------------------
template <class T>
int Queue<T>::Find(T data) {
    Node<T>* curr = m_head;
    int index = 0;

    while (curr != nullptr) {
        if (curr->GetData() == data) {
            return index;
        }
        curr = curr->GetNext();
        index++;
    }
    return -1;
}

//-------------------------------------------------------
// Name: Swap
// Desc: Swaps node at index with the node before it
// NOTE: Special cases for head must be handled
//-------------------------------------------------------
template <class T>
void Queue<T>::Swap(int index) {
    if (index <= 0 || index >= m_size) return;

    Node<T>* prevPrev = nullptr;
    Node<T>* prev = m_head;
    Node<T>* curr = m_head->GetNext();

    // Traverse to index
    for (int i = 1; i < index; i++) {
        prevPrev = prev;
        prev = curr;
        curr = curr->GetNext();
    }

    prev->SetNext(curr->GetNext());
    curr->SetNext(prev);

    if (prevPrev != nullptr) {
        prevPrev->SetNext(curr);
    } else {
        m_head = curr;
    }

    if (prev->GetNext() == nullptr) {
        m_tail = prev;
    }
}

//-------------------------------------------------------
// Name: Sort
// Desc: Uses bubble sort and Swap() to sort queue
//-------------------------------------------------------
template <class T>
void Queue<T>::Sort() {
    if (m_size < 2) {
        cout << "Sorting requires at least 2 nodes." << endl << endl;
        return;
    }

    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int i = 1; i < m_size; i++) {
            T curr = At(i);
            T prev = At(i - 1);

            // FIXED → Compare values directly (no *)
            if (prev > curr) { // ascending order (matches queue_test.cpp)
                Swap(i);
                swapped = true;
            }
        }
    }
}

#endif