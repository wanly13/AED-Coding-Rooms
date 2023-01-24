#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
};

struct DoubleList{
    Node* head;
    Node* tail;
    DoubleList(){
        head = tail = nullptr;
    }
    public:
    void push_back(int data){
        //cout << "void push_back(" << data <<")" << endl;
        struct Node* nodo = new Node; nodo->data = data; nodo->next = NULL;
        if (head == NULL) {
            nodo -> prev = NULL;  
            head = tail = nodo; 
        }

        tail -> next = nodo;
        nodo -> prev = tail;
        tail = nodo;
        nodo -> next = NULL;    
    
       
    }
    
    void display() {
        struct Node* temp = head;
        while(temp != NULL){
            cout << temp -> data << " ";
            temp = temp -> next;
        }
    }
    
    bool is_palindrome(){
        //cout<<"bool is_palindrome();\n";
        if (head == NULL) return false;
        while( tail != head ){
            if(head -> data != tail -> data){
                return false;
            } else {
                if(head -> next = tail){
                    return true;
                }
                head = head -> next;
                tail = tail -> prev;
            }
        }
        return true;
    }


};

 


