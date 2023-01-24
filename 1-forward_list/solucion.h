#include <iostream>
using namespace std;

struct Node {
    int data ;
    Node* next;
};

void push_front(Node* &head, int data){
    Node* nodo = new Node;
    nodo->data = data;
    nodo->next = head;
    head = nodo;
}

void push_back(Node* &head, int data){
    Node* nodo = head;
    Node* temp = new Node; temp -> data = data; temp -> next = nullptr;

    if (head == nullptr){
        head = temp;
    } else {
        while (nodo -> next != nullptr) {
            nodo = nodo -> next ;
        }
        nodo -> next = temp;
    }
    
}

void invert(Node* &head){
    Node* nodo = nullptr; 
    while ( head != nullptr){
        push_front(nodo , head -> data );
        head = head -> next;
    }
    head = nodo;
}

Node* SortedMerge(Node* &head1 , Node* &head2){
    // Asumiendo que la lista ya esta ordenada
    Node* nodo = nullptr;
    while ( head1 != nullptr  && head2 != nullptr){
        if (head1 -> data < head2 -> data){
            push_back(nodo , head1 -> data);
            head1 = head1 -> next;
        } else {
            push_back(nodo , head2 -> data);
            head2 = head2 -> next;
        }
    }
    if (head1 == nullptr){
        while (head2 != nullptr){
            push_back(nodo , head2 -> data);
            head2 = head2 -> next;
        } 
    } else {
        while (head1 != nullptr){
            push_back(nodo , head1 -> data);
            head1 = head1 -> next;
        } 
    }
    return nodo;

}

Node* Intersect(Node* &head1 , Node* &head2){
   Node* temp = head2;
   Node* nodo = nullptr;
  /*  if (head1 == nullptr && head2 == nullptr) return nodo;
    while ( head1 != nullptr  ){
        if (head1 -> data == temp -> data){
            push_back(nodo , head1 -> data);
        } else {
            if (temp != nullptr){
                temp = temp -> next;
            } else {
                head1 = head1 -> next;
                temp = head2;
            }
            
        }
    } */
    return nodo;
    
}

void SortedInsert(Node* &head, int data){
    Node* nodo = head;
    Node* temp1 = new Node; temp1 -> data = data; temp1 -> next = nullptr;
    
    if (head == nullptr || data < head -> data){
        push_front(head , data);
    } else {    
        /* nodo = head -> next;
        while (nodo -> data > data){
            nodo = nodo -> next;
        }
        temp2 = nodo -> next;
        nodo -> next = temp1;
        temp1 -> next = temp2; */
        
        while( nodo -> next != nullptr && nodo -> next -> data < data){
            nodo = nodo -> next;
        }
        temp1 -> next =  nodo -> next;
        nodo -> next = temp1;



    }
}


void display(Node* head){
    for (Node* temp = head; temp != nullptr; temp = temp->next)    
        cout<<temp->data<<"->";
    cout<<"null\n";   
}
